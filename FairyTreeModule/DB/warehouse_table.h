#pragma once

#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "mysql_encap.h"
//�ֿ�������
class CDB_Warehouse :public MysqlEncap
{
public:
	bool Select_tb_Warehouse_id(UINT32 id);
	bool Insert_tb_Warehouse_id(UINT32 id);
	bool Delete_tb_Warehouse_id(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_Warehouse*>m_mapWarehouseInfo;
private:
	uint32_t	m_iWareHouseID;				//�ֿ�ID
	uint32_t	m_iArticleID;				//��Ʒ���
	uint32_t	m_iArticleNum;				//��Ʒ����
	MYSQL		m_sql;
};
#endif // 
