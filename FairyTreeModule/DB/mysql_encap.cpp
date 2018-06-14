#include <stdio.h>
#include <string.h>
#include <map>
#include <assert.h>
#include "mysql_encap.h"

MysqlEncap g_sqlconnect;
MysqlEncap g_serverconnect;
MysqlEncap g_configdb;

/*构造函数*/
MysqlEncap::MysqlEncap()
{
    m_isConnected = false;
    mysql_init(connect);
}

/*析构函数*/
MysqlEncap::~MysqlEncap()
{
    Clear();
}

/****************************************************
* 建立数据库连接
* ip: 数据库主机ip
* username: 登录mysql用户名
* password: 密码
****************************************************/
//连接数据库  
//bool MysqlEncap::Connect(const char* ip, const char* username,
//	const char* password)
//{
//	
//	//初始化mysql  
//	mysql_init(&sql_conn);  //连接mysql，数据库  
//	MYSQL* pMysql = NULL;
//	//返回false则连接失败，返回true则连接成功  
//	pMysql = mysql_real_connect(&sql_conn, ip, username, password, "gamebd", 3306, NULL, 0);
//
//	if (NULL == pMysql) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去  
//	{
//		printf("Error connecting to database:%s\n", mysql_error(&sql_conn));
//		return false;
//	}
//	else
//	{
//		printf("Connected...\n");
//		m_isConnected = true;
//		return true;
//	}
//}

UINT32 MysqlEncap::init(std::string strdbip, std::string dbname)
{
	int rt = FALSE;

	//con不为空表示已经连接
	if (connect != NULL)
	{
		rt = TRUE;
		return rt;
	}
	else
		rt = FALSE;

	m_strDBip = strdbip;
	m_strDBName = dbname;
	//数据库配置
	char dbuser[30] = "root";
	char dbpasswd[30] = "yichuan";
	printf("DB input over\n");
	connect = mysql_init((MYSQL*)0);


#ifdef WIN32
	mysql_options(connect, MYSQL_SET_CHARSET_NAME, "GBK");
#else
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "utf8");
#endif

	if (connect != NULL && mysql_real_connect(connect, strdbip.c_str(), dbuser, dbpasswd, dbname.c_str(), 3306/*TCP IP端口*/, NULL/*Unix Socket 连接类型*/, 0/*运行成ODBC数据库标志*/))
	{
		rt = TRUE;
		
		if (NULL == mysql_select_db(connect, dbname.c_str()))
		{
			printf("Select successfully the database!\n");
			//设置断线重连
			connect->reconnect = 1;

		}
	}
	else
	{

		printf("Unable to connect the database,check your configuration!\n");


		connect = NULL;
	}
	return rt;

}

/************************************************
* 关闭连接
************************************************/
//void MysqlEncap::CloseConnect()
//{
//    mysql_close(&sql_conn);
//    m_isConnected = false;
//}
void MysqlEncap::Clear()
{
	if (connect != NULL)
	{
		mysql_close(connect);
		connect = NULL;
	}
}
/************************************************
* 重新连接
************************************************/
bool MysqlEncap::ReConnect()
{
	//CloseConnect();
	Clear();

    if(mysql_real_connect(connect, m_strHostIp.c_str(), m_strUserName.c_str(), m_strPassWord.c_str(),
						NULL, 0, NULL, 0 ) )
    {
        fprintf(stderr,"Reconnect:%s\n", mysql_error(connect));
        return false;
    }

    if (mysql_query(connect, "set names utf8;") != 0)
    {
		throw mysql_error(connect);
    }

    m_isConnected = true;
    return true;
}
/************************************************
* 检查连接，如果连接断开则重连
************************************************/


/************************************************
* 查询语句
************************************************/

//执行查询语句(查询--只读)
bool MysqlEncap::ExecuteQuery(const char* sql, std::vector < std::map<std::string, std::string> >& vmResultData)
{
    printf("sql:%s\n",sql);
    //assert(sql == NULL);

    if(sql == NULL)
    {
        return false;
    }

    if(!m_isConnected)
    {
        fprintf(stderr,"connection was not established\n");
        m_bCommit = false;//如果有事务，出错不能提交
    }
	
	//添加mysql_ping(),保证连接存活
	mysql_ping(connect);

    try
    {
        if(mysql_real_query(connect, sql, strlen(sql)) != 0)
        {
            fprintf(stderr, "select query error:%s\n", mysql_error(connect));
            m_bCommit = false;
            return false;
        }

        //vmResultData.clear();
		
        MYSQL_RES* res = mysql_store_result(connect);

        if (res == NULL)
        {
            if (mysql_errno(connect) != 0)
            {
                fprintf(stderr, "select query error:%s\n", mysql_error(connect));
                m_bCommit = false;
                return false;
            }
            else
            {
                return true;
            }
        }

        int num_fields		= mysql_num_fields(res);	//函数返回结果集中字段的数
        MYSQL_FIELD* fields = mysql_fetch_fields(res);	//返回结果集中代表字段（列）的对象的数组
        MYSQL_ROW row;	//行数

        while ((row = mysql_fetch_row(res)) != NULL)
        {
			std::map<std::string, std::string> tmpresult;
            
            for (int i = 0; i < num_fields; i++)
            {
                if (row[i] != NULL)
                {
                    tmpresult[fields[i].name] = row[i];
                }
                else
                {
                    tmpresult[fields[i].name] = "";
                }
            }

            vmResultData.push_back(tmpresult);
        }

        mysql_free_result(res);
        return true;
    }
    catch(...)
    {
        ReConnect();//这种情况是在，执行语句没有出错的情况下，抛出的异常，另外isConnected = true
        m_isConnected = true;
        m_bCommit = false;//如果有事务，出错不能提交
        return false;
    }

    return false;
}

//执行SQL语句(增 删 查)
bool MysqlEncap::Execute(const char* sql)
{
    printf("sql:%s\n",sql);
    if(sql == NULL)
    {
        return false;
    }

    if(false == m_isConnected)
    {
        fprintf(stderr,"connection was not established\n");
        m_bCommit = false;//如果有事务，出错不能提交
        return false;
    }

    try
    {
		mysql_query(connect, "SET NAMES GBK");
		int iket = mysql_real_query(connect, sql, strlen(sql));
        if(iket != 0)
        {
            fprintf(stderr, "modify query error:%s\n",mysql_error(connect));
            m_bCommit = false;
            return false;
        }

        MYSQL_RES* res = mysql_store_result(connect);

        if (res == NULL)
        {
            if (mysql_errno(connect) != 0)
            {
                fprintf(stderr, "modify query error:%s\n",mysql_error(connect));
                m_bCommit = false;
                return false;
            }
            else
            {
				printf("Successfully\n");
                return true;
            }
        }
        else
        {
            //执行了查询操作
            fprintf(stderr, "Select Successfully:%s\n",mysql_error(connect));
            m_bCommit = false;
            return true;
        }

    }
    catch(...)
    {
        ReConnect();//这种情况是在，执行语句没有出错的情况下，抛出的异常，另外isConnected = true
        m_isConnected = true;
        m_bCommit = false;//如果有事务，出错不能提交
        return false;
    }

    return true;
}

bool MysqlEncap::StartTransaction()
{
    m_bCommit = true;
    return Execute("START TRANSACTION;");
}

bool MysqlEncap::EndTransaction()
{
    if(m_bCommit)
    {
        Execute("COMMIT;");
        return 1;
    }
    else
    {
        Execute("ROLLBACK;");
        return 0;
    }
}

/*************************************************
 * 转义字符串转为UTF-8,避免特殊字符
 * make sure sizeof(to) >= 2*strlen(from)+1
 *************************************************/
void MysqlEncap::EscapeString(char* dest, char* source)
{
    mysql_real_escape_string(connect, dest, source, strlen(source));
}

UINT MysqlEncap::GetLastInsertId()
{
    return (uint32_t)mysql_insert_id(connect);
}

int MysqlEncap::SetOptions(enum mysql_option option, const char* arg)
{
    return mysql_options(connect, option, arg);
}