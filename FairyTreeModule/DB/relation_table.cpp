#include "relation_table.h"
bool CDB_Relation::loadtable(void * dbcon)
{
	if (dbcon == 0)
		return false;

	MYSQL * con = (MYSQL *)dbcon;
	const char* tmpsql = "SELECT * FROM  `relation`";
	int rt;
	rt = mysql_real_query(con, tmpsql, strlen(tmpsql));
	int  icount_fields = mysql_field_count(con);
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
			CDB_Relation* filedsinfo_db = new CDB_Relation();
			int iIndex = 0;
			filedsinfo_db->m_userID		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_iFriendID	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_iEnemyID	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			
			m_mapRelationInfo[filedsinfo_db->m_userID] = filedsinfo_db;

			if (iIndex != icount_fields)
			{
				printf("relation table db wrong:\n");
			}
		}
		mysql_free_result(res);
		return true;
	}
	return false;
}

bool CDB_Relation::Select_tb_RankingListid(UINT32 id) 
{
	bool bCharacterID = false;

	//判断合法性
	if (NULL == id)
		return bCharacterID;

	//执行SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "SELECT * FROM `relation` WHERE userId=%d", id);
	bCharacterID = Execute(SQL);

	if (false == bCharacterID)
	{
		fprintf(stderr, "select faile:\n", mysql_error(&m_sql));
	}
	return bCharacterID;
}
bool CDB_Relation::Insert_tb_RankingListid(UINT32 id) 
{
	bool bKet = false;

	//判断合法性
	if (0 == id || id == m_iFriendID || id == m_iEnemyID)
	{
		return bKet;
	}

	//输入SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "INSERT INTO `relation`(userId) VALUES(%d)", id);
	bKet = Execute(SQL);

	if (false == bKet)
	{
		//记录Execute错误
		fprintf(stderr, "insert faile:\n", mysql_error(&m_sql));
	}

	return bKet;
}
bool CDB_Relation::Delete_tb_RankingListid(UINT32 id) 
{
	bool delete_id = false;

	//判断合法性
	if (0 == id)
	{
		return delete_id;
	}
	char SQL[256] = { 0 };

	sprintf(SQL, "DELETE FROM `relation`where userId=%d", id);
	delete_id = Execute(SQL);


	if (false == delete_id)
	{
		fprintf(stderr, "delete faile:\n", mysql_error(&m_sql));
		return false;
	}
	return delete_id;
}