#pragma once
#ifndef _GOLD_H_
#define _GOLD_H_
#include "mysql_encap.h"
//金币类数据
class CDB_Gold :public MysqlEncap
{
public:
	bool loadtable(void * dbcon);
	//只能支持对ID的操作
	bool Select_tb_Goldid(UINT32 id);
	bool Insert_tb_Goldid(UINT32 id);
	bool Delete_tb_Goldid(UINT32 id);
	std::map<UINT32, CDB_Gold*>m_mapGoldInfo;
private:
	UINT32 m_userId;					//用户ID
	UINT32 m_iGoldNum;					//金币数量
	MYSQL   m_sql;
};
#endif // 
