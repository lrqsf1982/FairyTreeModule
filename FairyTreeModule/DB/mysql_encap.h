#ifndef MYSQL_ENCAP_H_
#define MYSQL_ENCAP_H_

#define WIN32_LEAN_AND_MEAN

#include <mysql.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>


class MysqlEncap
{
public:
	MysqlEncap();
	~MysqlEncap();

	//连接数据库
	//bool Connect(const char *ip, const char *username, const char *password);
	MYSQL * connect;

	//初始化数据库
	UINT32 init(std::string strdbip, std::string dbname);

	//手动重连，默认是用的自动重连
	//UINT32 KeepAlive(uint32_t timeMargin, const char * who);

	//读取数据库的函数的实现
	MYSQL * GetConn() { return connect; }

	//关闭连接数据库
	//void CloseConnect();
	void Clear();
	//执行查询语句 
	bool ExecuteQuery(const char *sql, std::vector < std::map<std::string, std::string> >& vmResultData);

	//执行SQL语句
	bool Execute(const char *sql);

	//开始事物
	bool StartTransaction();

	//修改为：当返回值0的时候，是ROLLBACK，1--COMMIT

	//结束事物
	bool EndTransaction();

	//将带转义字符转为UTF-8
	void EscapeString(char *to, char *from);

	//获取最后插入的ID
	UINT GetLastInsertId();

	int  SetOptions(enum mysql_option option, const char* arg);

	std::string m_strDBip;
	std::string m_strDBName;


	//重新连接数据库
	bool ReConnect();

private:
	bool   m_isConnected;	//判断是否连接
	bool   m_bCommit;		//当用到事务时，该值用来选择是commit还是rollback	
	//MYSQL  sql_conn;		//数据库连接

	//保存连接信息，保证重连
	std::string m_strHostIp;
	std::string m_strUserName;
	std::string m_strPassWord;
};
extern MysqlEncap g_sqlconnect;
extern MysqlEncap g_serverconnect;
extern MysqlEncap g_configdb;
#endif