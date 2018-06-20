#include "tasklistclass_table.h"
bool CDB_TaskListClass::loadtable(void * dbcon)
{
	if (dbcon == 0)
		return false;

	MYSQL * con = (MYSQL *)dbcon;
	const char* tmpsql = "SELECT * FROM  `tasklistclass`";
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
			CDB_TaskListClass* filedsinfo_db = new CDB_TaskListClass();
			int iIndex = 0;
			filedsinfo_db->m_iTaskId		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_strTaskHead	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_strTaskDetails = iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_taskListNum	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			
			m_mapTaskListClassInfo[filedsinfo_db->m_iTaskId] = filedsinfo_db;

			if (iIndex != icount_fields)
			{
				printf("tasklistclass table db wrong:\n");
			}
		}
		mysql_free_result(res);
		return true;
	}
	return false;
}

bool CDB_TaskListClass::Select_tb_TaskListClass_id(UINT32 id) 
{
	bool bCharacterID = false;

	//判断合法性
	if (NULL == id)
		return bCharacterID;

	//执行SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "SELECT * FROM `tasklistclass` WHERE TaskId=%d", id);
	bCharacterID = Execute(SQL);

	if (false == bCharacterID)
	{
		fprintf(stderr, "select faile:\n", mysql_error(&m_sql));
	}
	return bCharacterID;
}
bool CDB_TaskListClass::Insert_tb_TaskListClass_id(UINT32 id) 
{
	bool bKet = false;

	//判断合法性
	if (0 == id || id == m_iTaskId)
	{
		return bKet;
	}

	//输入SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "INSERT INTO `tasklistclass`(TaskId) VALUES(%d)", id);
	bKet = Execute(SQL);

	if (false == bKet)
	{
		//记录Execute错误
		fprintf(stderr, "insert faile:\n", mysql_error(&m_sql));
	}

	return bKet;
}
bool CDB_TaskListClass::Delete_tb_TaskListClass_id(UINT32 id) 
{
	bool delete_id = false;

	//判断合法性
	if (0 == id)
	{
		return delete_id;
	}
	char SQL[256] = { 0 };

	sprintf(SQL, "DELETE FROM `tasklistclass`where TaskId=%d", id);
	delete_id = Execute(SQL);


	if (false == delete_id)
	{
		fprintf(stderr, "delete faile:\n", mysql_error(&m_sql));
		return false;
	}
	return delete_id;
}