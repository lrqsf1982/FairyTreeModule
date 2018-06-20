#pragma once

#include "Skill.h"

CSkill::CSkill()
{
	m_type = INITIATIVE; //技能类型

	m_Level = 0; //技能等级

	m_id = 0; //技能ID
}

CSkill::~CSkill()
{
}

//设置技能类型
void CSkill::Set_Skill_Type(uint32 sst)
{
	switch (sst)
	{
	case 0: {m_type = INITIATIVE; break; }
	case 1: {m_type = PASSIVITY; break; }
	}
}

//获取技能类型
SkillType CSkill::Get_Skill_Type()
{
	return m_type;
}

//设置技能等级
void CSkill::Set_Skill_Level(bool ssl)
{
	if (ssl)
	{
		//增加等级
		m_Level += 1;
	}
	
}

//获取技能等级
uint32 CSkill::Get_Skill_Level()
{
	return m_Level;
}

//设置技能ID
void CSkill::Set_Skill_ID(uint32 ssid)
{
	m_id = ssid;
}

//获取技能ID
uint32 CSkill::Get_Skill_ID()
{
	return m_id;
}