#pragma once
#ifndef _FAIRYWELL_H
#define _FAIRYWELL_H
#include "mysql_encap.h"
//���ɾ�������
class CDB_CSunshine :public MysqlEncap
{
public:
	bool loadtable(void * dbcon);
	//ֻ��֧�ֶ�ID�Ĳ���
	bool Select_tb_FairyWellid(UINT32 id);
	bool Insert_tb_FairyWellid(UINT32 id, const std::string& name);
	bool Delete_tb_FairyWellid(UINT32 id);
	std::map<UINT32, CDB_CSunshine*>m_mapSunshineInfo;
private:
	UINT32 m_userId;				//��ɫID
	UINT32 m_iWellId;				//���ɾ�ID
	UINT32 m_iOrdinaryWater;		//��ͨˮ
	UINT32 m_iFairyWater;			//����ˮ
	MYSQL   m_sql;
};

#endif // _FAIRYWELL_H
