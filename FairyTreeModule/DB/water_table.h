#pragma once

#ifndef _WATER_H_ 
#define _WATER_H_

#include "mysql_encap.h"

//水资源类数据
class CDB_Water :public MysqlEncap
{
public:
	bool Select_tb_Water_id(UINT32 id);
	bool Insert_tb_Water_id(UINT32 id);
	bool Delete_tb_Water_id(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_Water*>m_mapWareInfo;
private:
	uint32_t m_iWaterID;				//水的编号
	uint32_t m_iWaterNum;				//水的数量
	MYSQL	m_sql;
};
#endif // 
