#pragma once
#ifndef _DBTB_F_ELFINDATA_H_
#define _DBTB_F_ELFINDATA_H_
#include "mysql_encap.h"
//С����������
class CDB_Elfin:public MysqlEncap
{
public:
	bool loadtable(void * dbcon);
	//ֻ��֧�ֶ�ID�Ĳ���
	bool Select_tb_Elfinid(UINT32 id);
	bool Insert_tb_Elfinid(UINT32 id, const std::string& name);
	bool Delete_tb_Elfinid(UINT32 id);
	std::map<UINT32, CDB_Elfin*>m_mapElfinInfo;
private:
	uint32_t m_userId;							//�û�ID
	uint32_t m_uID;								//С�����ID
	uint32_t m_uLevel;							//С����ȼ�
	uint32_t m_uCurPhysicalPower;				//С����ǰ������
	uint32_t m_uMaxPhysicalPower;				//С�����������
	bool	 m_uPlunderState;					//С�����Ӷ�״̬
	UINT32	 m_uBePlunderId;					//���Ӷ���ID
	UINT32	 m_uPlunderGoldNum;					//�Ѿ��Ӷ�Ľ������
	MYSQL    m_sql;
};
#endif
