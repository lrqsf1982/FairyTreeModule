#pragma once
#ifndef _FAIRYWELL_H
#define _FAIRYWELL_H
#include "mysql_encap.h"
//神仙井类数据
class CDB_CSunshine :public MysqlEncap
{
public:
	bool loadtable(void * dbcon);
	//只能支持对ID的操作
	bool Select_tb_FairyWellid(UINT32 id);
	bool Insert_tb_FairyWellid(UINT32 id, const std::string& name);
	bool Delete_tb_FairyWellid(UINT32 id);
	std::map<UINT32, CDB_CSunshine*>m_mapSunshineInfo;
private:
	UINT32 m_userId;				//角色ID
	UINT32 m_iWellId;				//神仙井ID
	UINT32 m_iOrdinaryWater;		//普通水
	UINT32 m_iFairyWater;			//神仙水
	MYSQL   m_sql;
};

#endif // _FAIRYWELL_H
