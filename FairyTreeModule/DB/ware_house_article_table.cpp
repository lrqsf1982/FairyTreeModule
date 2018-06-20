#include "ware_house_article_table.h"


bool CDB_WarehouseArticle::loadtable(void * dbcon)
{
	if (dbcon == 0)
		return false;

	MYSQL * con = (MYSQL *)dbcon;
	const char* tmpsql = "SELECT * FROM  `warehousearticle`";
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
			CDB_WarehouseArticle* filedsinfo_db = new CDB_WarehouseArticle();
			int iIndex = 0;
			filedsinfo_db->m_iArticleID			= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_iGoldPrice			= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_iJewelPrice		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_fArticleDescribe	= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;
			filedsinfo_db->m_strDescribe		= iIndex++ < icount_fields ? atoi(row[iIndex - 1]) : 0;

			m_mapWarehouseArticleInfo[filedsinfo_db->m_iArticleID] = filedsinfo_db;

			if (iIndex != icount_fields)
			{
				printf("warehousearticle table db wrong:\n");
			}
		}
		mysql_free_result(res);
		return true;
	}
	return false;
}

bool CDB_WarehouseArticle::Select_tb_WarehouseArticle_id(UINT32 id) 
{
	bool bCharacterID = false;

	//判断合法性
	if (NULL == id)
		return bCharacterID;

	//执行SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "SELECT * FROM `warehousearticle` WHERE uarticleSerialNumber=%d", id);
	bCharacterID = Execute(SQL);

	if (false == bCharacterID)
	{
		fprintf(stderr, "select faile:\n", mysql_error(&m_sql));
	}
	return bCharacterID;
}
bool CDB_WarehouseArticle::Insert_tb_WarehouseArticle_id(UINT32 id) 
{
	bool bKet = false;

	//判断合法性
	if (0 == id || id == m_iArticleID)
	{
		return bKet;
	}

	//输入SQL语句
	char SQL[256] = { 0 };
	sprintf(SQL, "INSERT INTO `warehousearticle`(uarticleSerialNumber,ugoldPrice,ujewelPrice,uarticleDiscount) VALUES(%d, %d,%d,%s)", id, 1, 1, '1');
	bKet = Execute(SQL);

	if (false == bKet)
	{
		//记录Execute错误
		fprintf(stderr, "insert faile:\n", mysql_error(&m_sql));
	}

	return bKet;
}
bool CDB_WarehouseArticle::Delete_tb_WarehouseArticle_id(UINT32 id) 
{
	bool delete_id = false;

	//判断合法性
	if (0 == id)
	{
		return delete_id;
	}
	char SQL[256] = { 0 };

	sprintf(SQL, "DELETE FROM `warehousearticle`where uarticleSerialNumber=%d", id);
	delete_id = Execute(SQL);


	if (false == delete_id)
	{
		fprintf(stderr, "delete faile:\n", mysql_error(&m_sql));
		return false;
	}
	return delete_id;
}