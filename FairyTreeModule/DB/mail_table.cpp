#include "mail_table.h"
bool CDB_Mail::loadtable(void * dbcon) 
{
	if (dbcon == 0)
		return false;

	MYSQL * con = (MYSQL *)dbcon;
	const char* tmpsql = "SELECT * FROM  `mail`";
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
			CDB_Mail* filedsinfo_db = new CDB_Mail();
			int iIndex = 0;
			filedsinfo_db->m_userId			= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_iMailId		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_sMailHead		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_sMailContent	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;

			m_mapMailInfo[filedsinfo_db->m_userId] = filedsinfo_db;

			if (iIndex != icount_fields)
			{
				printf("mail table db wrong:\n");
			}
		}
		mysql_free_result(res);
		return true;
	}
	return false;
}
bool CDB_Mail::Select_tb_Mailid(UINT32 id) 
{
	bool bCharacterID = false;

	//判断合法性
	if (NULL == id)
		return bCharacterID;

	//执行SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "SELECT * FROM `mail` WHERE umailSerialNumber=%d", id);
	bCharacterID = Execute(SQL);

	if (false == bCharacterID)
	{
		fprintf(stderr, "select faile:\n", mysql_error(&m_sql));
	}
	return bCharacterID;
}
bool CDB_Mail::Insert_tb_Mailid(UINT32 id) 
{
	bool bKet = false;

	//判断合法性
	if (0 == id || id == m_iMailId)
	{
		return bKet;
	}

	//输入SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "INSERT INTO `mail`(userId,umailSerialNumber,smailheadline,smailcontent,mailArtName) VALUES(%d, %d,'%s','%s','%s')", id, '1', '1', '1');
	bKet = Execute(SQL);

	if (false == bKet)
	{
		//记录Execute错误
		fprintf(stderr, "insert faile:\n", mysql_error(&m_sql));
	}

	return bKet;
}
bool CDB_Mail::Delete_tb_Mailid(UINT32 id) 
{
	bool delete_id = false;

	//判断合法性
	if (0 == id)
	{
		return delete_id;
	}
	char SQL[256] = { 0 };

	sprintf(SQL, "DELETE FROM `mail`where umailSerialNumber=%d", id);
	delete_id = Execute(SQL);


	if (false == delete_id)
	{
		fprintf(stderr, "delete faile:\n", mysql_error(&m_sql));
		return false;
	}
	return delete_id;
}