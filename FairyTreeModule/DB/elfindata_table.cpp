#include "elfindata_table.h"

//从数据库加载
bool CDB_Elfin::loadtable(void * dbcon)
{
	if (dbcon == 0)
		return false;

	MYSQL * con = (MYSQL *)dbcon;
	const char* tmpsql = "SELECT * FROM  `elfindata`";
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
			CDB_Elfin* filedsinfo_db = new CDB_Elfin();
			int iIndex = 0;
			filedsinfo_db->m_userId				= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uID				= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uLevel				= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uCurPhysicalPower	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uMaxPhysicalPower	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uPlunderState		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uBePlunderId		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_uPlunderGoldNum	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			

			m_mapElfinInfo[filedsinfo_db->m_userId] = filedsinfo_db;

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
//查找小精灵ID 名字
bool CDB_Elfin::Select_tb_Elfinid(UINT32 id)
{
	bool bCharacterID = false;

	//判断合法性
	if (NULL == id)
		return bCharacterID;

	//执行SQL语句SELECT * FROM `character` WHERE `character`.uroleID = 1314 AND `character`.sroleName = 'abcdef'
	char SQL[256] = { 0 };
	sprintf(SQL, "SELECT * FROM `elfindata` WHERE ElfinId=%d", id);
	bCharacterID = Execute(SQL);

	if (false == bCharacterID)
	{
		fprintf(stderr, "select faile:\n", mysql_error(&m_sql));
	}
	return bCharacterID;
}

//增加小精灵ID
bool CDB_Elfin::Insert_tb_Elfinid(UINT32 id, const std::string& name)
{
	bool bKet = false;

	//判断合法性
	if (0 == id || id == m_uID || name.empty())
	{
		return bKet;
	}

	//输入SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "INSERT INTO `elfindata`(ElfinId,_egrade,_ephysicalpower,_emaxphysicalpower,ElfinSkillType) VALUES(%d, %d,%d,%d)", id, 1, 1, 1);
	bKet = Execute(SQL);

	if (false == bKet)
	{
		//记录Execute错误
		fprintf(stderr, "insert faile:\n", mysql_error(&m_sql));
	}

	return bKet;
}

bool CDB_Elfin::Delete_tb_Elfinid(UINT32 id)
{
	bool delete_id = false;

	//判断合法性
	if (0 == id)
	{
		return delete_id;
	}
	char SQL[1024] = { 0 };

	sprintf(SQL, "DELETE FROM `elfindata`where ElfinId=%d", id);
	delete_id = Execute(SQL);


	if (false == delete_id)
	{
		fprintf(stderr, "delete faile:\n", mysql_error(&m_sql));
		return false;
	}
	return delete_id;
}