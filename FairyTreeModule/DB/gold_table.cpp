#include "gold_table.h"

bool CDB_Gold::loadtable(void * dbcon) 
{
	if (dbcon == 0)
		return false;

	MYSQL * con = (MYSQL *)dbcon;
	const char* tmpsql = "SELECT * FROM  `gold`";
	int rt;
	rt = mysql_real_query(con, tmpsql, strlen(tmpsql));
	int  icount_fields = mysql_field_count(con);
	if (rt)
	{
		printf("Error making query: %s !!!\n", mysql_error(con));
		return false;
	}
	MYSQL_RES *res = mysql_store_result(con);//�����������res�ṹ����
	if (res != 0)
	{
		MYSQL_ROW  row;
		while ((row = mysql_fetch_row(res)) != NULL)
		{
			CDB_Gold* filedsinfo_db = new CDB_Gold();
			int iIndex = 0;
			filedsinfo_db->m_userId		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_iGoldNum	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			
			m_mapGoldInfo[filedsinfo_db->m_userId] = filedsinfo_db;

			if (iIndex != icount_fields)
			{
				printf("gold table db wrong:\n");
			}
		}
		mysql_free_result(res);
		return true;
	}
	return false;
}
bool CDB_Gold::Select_tb_Goldid(UINT32 id)
{
	bool bCharacterID = false;

	//�жϺϷ���
	if (NULL == id)
		return bCharacterID;

	//ִ��SQL���SELECT * FROM `character` WHERE `character`.uroleID = 1314 AND `character`.sroleName = 'abcdef'
	char SQL[256] = { 0 };
	sprintf(SQL, "SELECT * FROM `gold` WHERE userId=%d", id);
	bCharacterID = Execute(SQL);

	if (false == bCharacterID)
	{
		fprintf(stderr, "select faile:\n", mysql_error(&m_sql));
	}
	return bCharacterID;
}
bool CDB_Gold::Insert_tb_Goldid(UINT32 id)
{
	bool bKet = false;

	//�жϺϷ���
	if (0 == id || id == m_userId)
	{
		return bKet;
	}

	//����SQL���
	char SQL[256] = { 0 };
	sprintf(SQL, "INSERT INTO `gold`(userId,ugoldnumber) VALUES(%d, %d)", id, 99999);
	bKet = Execute(SQL);

	if (false == bKet)
	{
		//��¼Execute����
		fprintf(stderr, "insert faile:\n", mysql_error(&m_sql));
	}

	return bKet;
}
bool CDB_Gold::Delete_tb_Goldid(UINT32 id)
{
	bool delete_id = false;

	//�жϺϷ���
	if (0 == id)
	{
		return delete_id;
	}
	char SQL[256] = { 0 };

	sprintf(SQL, "DELETE FROM `gold`where userId=%d", id);
	delete_id = Execute(SQL);


	if (false == delete_id)
	{
		fprintf(stderr, "delete faile:\n", mysql_error(&m_sql));
		return false;
	}
	return delete_id;
}