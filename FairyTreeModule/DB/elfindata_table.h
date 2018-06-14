#pragma once
#ifndef _DBTB_F_ELFINDATA_H_
#define _DBTB_F_ELFINDATA_H_
#include "mysql_encap.h"
//小精灵类数据
class CDB_Elfin:public MysqlEncap
{
public:
	bool loadtable(void * dbcon);
	//只能支持对ID的操作
	bool Select_tb_Elfinid(UINT32 id);
	bool Insert_tb_Elfinid(UINT32 id, const std::string& name);
	bool Delete_tb_Elfinid(UINT32 id);
	std::map<UINT32, CDB_Elfin*>m_mapElfinInfo;
private:
	uint32_t m_userId;							//用户ID
	uint32_t m_uID;								//小精灵的ID
	uint32_t m_uLevel;							//小精灵等级
	uint32_t m_uCurPhysicalPower;				//小精当前灵体力
	uint32_t m_uMaxPhysicalPower;				//小精灵最大体力
	bool	 m_uPlunderState;					//小精灵掠夺状态
	UINT32	 m_uBePlunderId;					//被掠夺者ID
	UINT32	 m_uPlunderGoldNum;					//已经掠夺的金币数量
	MYSQL    m_sql;
};
#endif
