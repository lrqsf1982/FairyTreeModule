#include "character_table.h"

UINT32  CDB_Character::GetId() 
{
	return m_uroleID;
}
const std::string& CDB_Character::GetName()
{
	return m_sroleName;
}
UINT32 CDB_Character::GetLevel() 
{
	return m_urolelevel;
}
UINT32 CDB_Character::GetGrowValue() 
{
	return m_urolegrowthvalue;
}
char  CDB_Character::GetunlineTime(char*temp)
{
	m_unlineTime = temp;
	return *m_unlineTime;
}
//从数据库加载
bool CDB_Character::loadtable(void * dbcon) 
{
	if (dbcon == 0)
		return false;

	MYSQL * con = (MYSQL *)dbcon;
	const char* tmpsql = "SELECT * FROM  `character`";
	int rt;
	rt = mysql_real_query(con, tmpsql, strlen(tmpsql));
	unsigned int  icount_fields = mysql_field_count(con);
	if (rt)
	{
		printf("Error making query: %s !!!\n", mysql_error(con));
		return false;
	}
	MYSQL_RES *res = mysql_store_result(con);//将结果保存在res结构体中
	if (res != 0)
	{
		MYSQL_ROW  row;
		while ((row = mysql_fetch_row(res)) != NULL)
		{
			CDB_Character* filedsinfo_db=new CDB_Character();
			UINT32 iIndex = 0;
			filedsinfo_db->m_uroleID			= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_sroleName			= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_urolelevel			= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_urolegrowthvalue	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			//filedsinfo_db->m_unlineTime			= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;

			m_mapcharacterInfo[filedsinfo_db->m_uroleID] = filedsinfo_db;

			if (iIndex != icount_fields)
			{
				printf("character table db wrong:\n");
			}
		}
		mysql_free_result(res);
		return true;
	}
	return false;
}
//查找角色ID 名字
bool CDB_Character::Select_tb_userid(UINT32 id)
{
	bool bCharacterID = false;

	//判断合法性
	if (NULL == id)
		return bCharacterID;

	//执行SQL语句SELECT * FROM `character` WHERE `character`.uroleID = 1314 AND `character`.sroleName = 'abcdef'
	char SQL[256] = { 0 };
	sprintf(SQL, "SELECT * FROM `character` WHERE uroleID=%d", id);
	bCharacterID = Execute(SQL);

	if (false == bCharacterID)
	{
		fprintf(stderr, "select faile:\n", mysql_error(&m_sql));
	}
	return bCharacterID;
}

//增加角色ID
bool CDB_Character::Insert_tb_userid(UINT32 id, const std::string& name)
{
	bool bKet = false;

	//判断合法性
	if (0 == id || id == m_uroleID || name.empty())
	{
		return bKet;
	}

	//输入SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "INSERT INTO `character`(uroleID,sroleName,urolelevel,urolegrowthvalue) VALUES(%d, '%s',%d,%d)", id, name.c_str(), 1, 1);
	bKet = Execute(SQL);

	if (false == bKet)
	{
		//记录Execute错误
		fprintf(stderr, "insert faile:\n", mysql_error(&m_sql));
	}

	return bKet;
}


bool CDB_Character::Delete_tb_userid(UINT32 id)
{
	bool delete_id = false;

	//判断合法性
	if (0 == id)
	{
		return delete_id;
	}
	char SQL[1024] = { 0 };

	sprintf(SQL, "DELETE FROM `character`where uroleID=%d",id);
	delete_id= Execute(SQL);

	
	if (false == delete_id)
	{
		fprintf(stderr, "delete faile:\n", mysql_error(&m_sql));
		return false;
	}
	return delete_id;
}