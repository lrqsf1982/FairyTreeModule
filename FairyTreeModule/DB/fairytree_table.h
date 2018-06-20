#pragma once
#ifndef _FAIRYTREE_TABLE_H_
#define _FAIRYTREE_TABLE_H_
#include "mysql_encap.h"

//������������
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
	UINT32 m_userId;			//�û�ID
	UINT32 m_uTreeId;			//������ID
	UINT32 m_uLevel;			//�������ȼ�
	UINT32 m_uGold;				//�����������Ľ��
	UINT32 m_uGoldTime;			//�������������ʱ��
	UINT32 m_uStoreGoldNum;		//�������洢�������
	MYSQL  m_sql;
};
#endif
