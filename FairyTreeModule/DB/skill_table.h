#pragma once
#ifndef _SKILL_H_
#define _SKILL_H_
#include "mysql_encap.h"
//技能类数据
class CDB_Skill :public MysqlEncap
{
public:
	//只能支持对角色ID的操作
	bool Select_tb_Skillid(UINT32 id);
	bool Insert_tb_Skillid(UINT32 id);
	bool Delete_tb_Skillid(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_Skill*>m_mapSkillInfo;
private:
	uint32_t m_iSkillType;				//技能类型
	uint32_t m_iSkillLevel;				//技能等级
	uint32_t m_iSkillId;				//技能ID
	MYSQL    m_sql;
};
#endif
