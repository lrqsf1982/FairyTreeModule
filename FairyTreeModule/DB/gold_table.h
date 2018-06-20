#pragma once
#ifndef _GOLD_H_
#define _GOLD_H_
#include "mysql_encap.h"
//���������
class CDB_Gold :public MysqlEncap
{
public:
	bool loadtable(void * dbcon);
	//ֻ��֧�ֶ�ID�Ĳ���
	bool Select_tb_Goldid(UINT32 id);
	bool Insert_tb_Goldid(UINT32 id);
	bool Delete_tb_Goldid(UINT32 id);
	std::map<UINT32, CDB_Gold*>m_mapGoldInfo;
private:
	UINT32 m_userId;					//�û�ID
	UINT32 m_iGoldNum;					//�������
	MYSQL   m_sql;
};
#endif // 
