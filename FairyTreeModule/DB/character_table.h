#pragma once
#ifndef _CHARACTER_TABLE_H_
#define _CHARACTER_TABLE_H_
#include <string>
#include "mysql_encap.h"


//��ɫ������   
class CDB_Character :public MysqlEncap
{
public:
	bool loadtable(void * dbcon);

	//ֻ��֧�ֶԽ�ɫID�Ĳ���
	bool Select_tb_userid(UINT32 id);
	bool Insert_tb_userid(UINT32 id, const std::string& name);
	bool Delete_tb_userid(UINT32 id);

	//��ȡ�������
	UINT32 GetId();
	const std::string& GetName();
	UINT32 GetLevel();
	UINT32 GetGrowValue();
	char GetunlineTime(char*temp);
	std::map<UINT32, CDB_Character*>m_mapcharacterInfo;

	UINT32	m_uroleID;					//��ɫID
	std::string	m_sroleName;				//��ɫ����
	UINT32	m_urolelevel;				//��ɫ�ȼ�
	UINT32	m_urolegrowthvalue;			//��ɫ�ɳ�ֵ
	char*	m_unlineTime=NULL;			//����ʱ��
	MYSQL   m_sql;
};

#endif 

