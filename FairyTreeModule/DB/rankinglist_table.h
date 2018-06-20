#pragma once
#ifndef _RANKING_LIST_H 
#define _RANKING_LIST_H
#include "mysql_encap.h"
//���а�������
class CDB_RankingList :public MysqlEncap
{
public:
	CDB_RankingList();
	~CDB_RankingList();
	//ֻ��֧�ֶ�ID�Ĳ���
	bool Select_tb_RankingListid(UINT32 id);
	bool Insert_tb_RankingListid(UINT32 id, const std::string & m_strRoleName);
	bool Delete_tb_RankingListid(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_RankingList*>m_mapRankingListInfo;
private:
	std::string   m_strRoleName;			//���а��ɫ����
	uint32_t m_iRoleID;				//���а��ɫID
	uint32_t m_iTreeLevel;			//��ɫ���ĵȼ�
	uint32_t m_iRankingListId;		//���а�ID(����)
	MYSQL	 m_sql;
};

#endif // 
