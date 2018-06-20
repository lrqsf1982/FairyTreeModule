#pragma once

#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "mysql_encap.h"
//仓库类数据
class CDB_Warehouse :public MysqlEncap
{
public:
	bool Select_tb_Warehouse_id(UINT32 id);
	bool Insert_tb_Warehouse_id(UINT32 id);
	bool Delete_tb_Warehouse_id(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_Warehouse*>m_mapWarehouseInfo;
private:
	uint32_t	m_iWareHouseID;				//仓库ID
	uint32_t	m_iArticleID;				//物品编号
	uint32_t	m_iArticleNum;				//物品数量
	MYSQL		m_sql;
};
#endif // 
