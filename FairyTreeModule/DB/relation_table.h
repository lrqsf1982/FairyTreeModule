#pragma once
#ifndef _RELATION_H 
#define _RELATION_H
#include "mysql_encap.h"
//��ϵ������
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
	UINT32		m_iFriendID;				//�ѷ�ID���(�洢��Ӧ��ɫID)
	UINT32		m_iEnemyID;					//�з�ID���
	MYSQL		m_sql;
};
#endif // 
