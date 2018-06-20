#include "rankinglist_table.h"

CDB_RankingList::CDB_RankingList() 
{
}
CDB_RankingList::~CDB_RankingList() 
{
}
//加载数据库到内存
bool CDB_RankingList::loadtable(void * dbcon)
{
	if (dbcon == 0)
		return false;

	MYSQL * con = (MYSQL *)dbcon;
	const char* tmpsql = "SELECT * FROM  `rankinglist`";
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
			CDB_RankingList* filedsinfo_db = new CDB_RankingList();
			int iIndex = 0;
			filedsinfo_db->m_iRoleID		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_iRankingListId	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_iTreeLevel		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_strRoleName	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;

			m_mapRankingListInfo[filedsinfo_db->m_iRoleID] = filedsinfo_db;

			if (iIndex != icount_fields)
			{
				printf("rankinglist table db wrong:\n");
			}
		}
		mysql_free_result(res);
		return true;
	}
	return false;
}

bool CDB_RankingList::Select_tb_RankingListid(UINT32 id) 
{
	bool bCharacterID = false;

	//判断合法性
	if (NULL == id)
		return bCharacterID;

	//执行SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "SELECT * FROM `rankinglist` WHERE RankingListId=%d", id);
	bCharacterID = Execute(SQL);

	if (false == bCharacterID)
	{
		fprintf(stderr, "select faile:\n", mysql_error(&m_sql));
	}
	return bCharacterID;
}
bool CDB_RankingList::Insert_tb_RankingListid(UINT32 id, const std::string & m_strRoleName)
{
	bool bKet = false;

	//判断合法性
	if (0 == id || id == m_iRoleID)
	{
		return bKet;
	}

	//输入SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "INSERT INTO `rankinglist`(RankingListId) VALUES(%d)", id);
	bKet = Execute(SQL);

	if (false == bKet)
	{
		//记录Execute错误
		fprintf(stderr, "insert faile:\n", mysql_error(&m_sql));
	}

	return bKet;
}
bool CDB_RankingList::Delete_tb_RankingListid(UINT32 id) 
{
	bool delete_id = false;

	//判断合法性
	if (0 == id)
	{
		return delete_id;
	}
	char SQL[256] = { 0 };

	sprintf(SQL, "DELETE FROM `rankinglist`where RankingListId=%d", id);
	delete_id = Execute(SQL);


	if (false == delete_id)
	{
		fprintf(stderr, "delete faile:\n", mysql_error(&m_sql));
		return false;
	}
	return delete_id;
}

int SaveRankToDB(std::string strsql, MysqlEncap & thread_db,UINT32 rankId) {
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon == NULL) {
		return -1;
	}
	char SQL[256] = { 0 };
	sprintf(SQL, "DELETE FROM `rankinglist`where RankingListId=%d", rankId);
	return 0;
}