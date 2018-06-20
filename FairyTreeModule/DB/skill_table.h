#pragma once
#ifndef _SKILL_H_
#define _SKILL_H_
#include "mysql_encap.h"
//����������
class CDB_Skill :public MysqlEncap
{
public:
	//ֻ��֧�ֶԽ�ɫID�Ĳ���
	bool Select_tb_Skillid(UINT32 id);
	bool Insert_tb_Skillid(UINT32 id);
	bool Delete_tb_Skillid(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_Skill*>m_mapSkillInfo;
private:
	uint32_t m_iSkillType;				//��������
	uint32_t m_iSkillLevel;				//���ܵȼ�
	uint32_t m_iSkillId;				//����ID
	MYSQL    m_sql;
};
#endif
