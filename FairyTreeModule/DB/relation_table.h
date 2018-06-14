#pragma once
#ifndef _RELATION_H 
#define _RELATION_H
#include "mysql_encap.h"
//关系类数据
class CDB_Relation :public MysqlEncap
{
public:
	bool Select_tb_RankingListid(UINT32 id);
	bool Insert_tb_RankingListid(UINT32 id);
	bool Delete_tb_RankingListid(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_Relation*>m_mapRelationInfo;
private:
	UINT32		m_userID;
	UINT32		m_iFriendID;				//友方ID编号(存储相应角色ID)
	UINT32		m_iEnemyID;					//敌方ID编号
	MYSQL		m_sql;
};
#endif // 
