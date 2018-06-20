#pragma once
#ifndef _FAIRYTREE_TABLE_H_
#define _FAIRYTREE_TABLE_H_
#include "mysql_encap.h"

//神仙树类数据
class CDB_FairyTree :public MysqlEncap
{
public:
	bool loadtable(void * dbcon);
	bool Select_tb_treeid(UINT32 id);
	bool Insert_tb_treeid(UINT32 id, const std::string& name);
	bool Delete_tb_treeid(UINT32 id);

	UINT32 GetTreeId();
	UINT32 GetTreeLevel();
	UINT32 GetTreeGold();
	UINT32 GetTreeGoldTime();
	UINT32 GetTreeGoldNum();
	std::map<UINT32, CDB_FairyTree*>m_mapFairytreeInfo;
private:
	UINT32 m_userId;			//用户ID
	UINT32 m_uTreeId;			//神仙树ID
	UINT32 m_uLevel;			//神仙树等级
	UINT32 m_uGold;				//神仙树生产的金币
	UINT32 m_uGoldTime;			//神仙树生产金币时间
	UINT32 m_uStoreGoldNum;		//神仙树存储金币数量
	MYSQL  m_sql;
};
#endif
