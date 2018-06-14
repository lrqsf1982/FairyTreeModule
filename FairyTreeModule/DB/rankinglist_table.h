#pragma once
#ifndef _RANKING_LIST_H 
#define _RANKING_LIST_H
#include "mysql_encap.h"
//排行榜类数据
class CDB_RankingList :public MysqlEncap
{
public:
	CDB_RankingList();
	~CDB_RankingList();
	//只能支持对ID的操作
	bool Select_tb_RankingListid(UINT32 id);
	bool Insert_tb_RankingListid(UINT32 id, const std::string & m_strRoleName);
	bool Delete_tb_RankingListid(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_RankingList*>m_mapRankingListInfo;
private:
	std::string   m_strRoleName;			//排行榜角色名字
	uint32_t m_iRoleID;				//排行榜角色ID
	uint32_t m_iTreeLevel;			//角色树的等级
	uint32_t m_iRankingListId;		//排行榜ID(排名)
	MYSQL	 m_sql;
};

#endif // 
