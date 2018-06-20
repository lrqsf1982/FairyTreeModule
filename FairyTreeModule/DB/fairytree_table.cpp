#include "fairytree_table.h"
#include "character_table.h"
CDB_Character g_characterId;
UINT32 CDB_FairyTree::GetTreeId() 
{
	m_uTreeId = g_characterId.GetId();
	return m_uTreeId;
}
UINT32 CDB_FairyTree::GetTreeLevel() 
{
	return m_uLevel;
}
UINT32 CDB_FairyTree::GetTreeGold() 
{
	return m_uGold;
}
UINT32 CDB_FairyTree::GetTreeGoldTime() 
{
	return m_uGoldTime;
}
UINT32 CDB_FairyTree::GetTreeGoldNum() 
{
	return m_uStoreGoldNum;
}

bool CDB_FairyTree::loadtable(void * dbcon)
{
	if (dbcon == 0)
		return false;

	MYSQL * con = (MYSQL *)dbcon;
	const char* tmpsql = "SELECT * FROM  `fairytree`";
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
			CDB_FairyTree* filedsinfo_db = new CDB_FairyTree();
			int iIndex = 0;
			filedsinfo_db->m_userId			= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uTreeId		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uLevel			= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uGold			= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uGoldTime		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uStoreGoldNum	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;

			m_mapFairytreeInfo[filedsinfo_db->m_userId] = filedsinfo_db;

			if (iIndex != icount_fields)
			{
				printf("fairytree table db wrong:\n");
			}
		}
		mysql_free_result(res);
		return true;
	}
	return false;
}
bool CDB_FairyTree::Insert_tb_treeid(UINT32 id, const std::string& name)
{
	bool bKet = false;

	//判断合法性
	if (0 == id || id == m_uTreeId || name.empty())
	{
		return bKet;
	}

	//输入SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "INSERT INTO `fairytree`(uerId,fgrade,fgold,fgoldtime,cfaiTreStoGol) VALUES(%d, %d, %d,'%s',%d)", id,1, '1', 1, 1);
	bKet = Execute(SQL);

	if (false == bKet)
	{
		//记录Execute错误
		fprintf(stderr, "insert faile:\n", mysql_error(&m_sql));
	}

	return bKet;
}

bool CDB_FairyTree::Delete_tb_treeid(UINT32 id)
{
	bool delete_id = false;

	//判断合法性
	if (0 == id)
	{
		return delete_id;
	}
	char SQL[1024] = { 0 };

	sprintf(SQL, "DELETE FROM `fairytree`where uerId=%d", id);
	delete_id = Execute(SQL);


	if (false == delete_id)
	{
		fprintf(stderr, "delete faile:\n", mysql_error(&m_sql));
		return false;
	}
	return delete_id;
}

bool CDB_FairyTree::Select_tb_treeid(UINT32 id)
{
	bool bCharacterID = false;

	//判断合法性
	if (NULL == id)
		return bCharacterID;

	//执行SQL语句SELECT * FROM `character` WHERE `character`.uroleID = 1314 AND `character`.sroleName = 'abcdef'
	char SQL[256] = { 0 };
	sprintf(SQL, "SELECT * FROM `fairytree` WHERE fairytree=%d", id);
	bCharacterID = Execute(SQL);

	if (false == bCharacterID)
	{
		fprintf(stderr, "select faile:\n", mysql_error(&m_sql));
	}
	return bCharacterID;
}