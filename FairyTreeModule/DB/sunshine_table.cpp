#include "sunshine_table.h"

bool CDB_CSunshine::loadtable(void * dbcon)
{
	if (dbcon == 0)
		return false;

	MYSQL * con = (MYSQL *)dbcon;
	const char* tmpsql = "SELECT * FROM  `fairywell`";
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
			CDB_CSunshine* filedsinfo_db = new CDB_CSunshine();
			int iIndex = 0;
			filedsinfo_db->m_userId			= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_iWellId		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_iOrdinaryWater = iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_iFairyWater	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			

			m_mapSunshineInfo[filedsinfo_db->m_userId] = filedsinfo_db;

			if (iIndex != icount_fields)
			{
				printf("fairywell table db wrong:\n");
			}
		}
		mysql_free_result(res);
		return true;
	}
	return false;
}
//�������ɾ�ID ����
bool CDB_CSunshine::Select_tb_FairyWellid(UINT32 id)
{
	bool bCharacterID = false;

	//�жϺϷ���
	if (NULL == id)
		return bCharacterID;

	//ִ��SQL���
	char SQL[256] = { 0 };
	sprintf(SQL, "SELECT * FROM `fairywell` WHERE wellId=%d", id);
	bCharacterID = Execute(SQL);

	if (false == bCharacterID)
	{
		fprintf(stderr, "select faile:\n", mysql_error(&m_sql));
	}
	return bCharacterID;
}

//�������ɾ�ID
bool CDB_CSunshine::Insert_tb_FairyWellid(UINT32 id, const std::string& name)
{
	bool bKet = false;

	//�жϺϷ���
	if (0 == id || id == m_iWellId || name.empty())
	{
		return bKet;
	}

	//����SQL���
	char SQL[256] = { 0 };
	sprintf(SQL, 
		"INSERT INTO `fairywell`(wellId,fwater,ffairywater,faiWelManWatTime,faiWelManFaiWatTime) VALUES(%d, %d,%d,%s,%s)", id, 1, 1,'1', '1');
	bKet = Execute(SQL);

	if (false == bKet)
	{
		//��¼Execute����
		fprintf(stderr, "insert faile:\n", mysql_error(&m_sql));
	}

	return bKet;
}

bool CDB_CSunshine::Delete_tb_FairyWellid(UINT32 id)
{
	bool delete_id = false;

	//�жϺϷ���
	if (0 == id)
	{
		return delete_id;
	}
	char SQL[256] = { 0 };

	sprintf(SQL, "DELETE FROM `fairywell`where wellId=%d", id);
	delete_id = Execute(SQL);


	if (false == delete_id)
	{
		fprintf(stderr, "delete faile:\n", mysql_error(&m_sql));
		return false;
	}
	return delete_id;
}