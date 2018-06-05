#pragma once

#include "Skill.h"

CSkill::CSkill()
{
	skilltype = INITIATIVE; //技能类型

	uskillLevel = 0; //技能等级

	uskillID = 0; //技能ID

	skilldescribe = "";//技能描述
}

CSkill::~CSkill()
{
}

//设置技能类型
void CSkill::Set_Skill_Type(uint32 sst)
{
	switch (sst)
	{
	case 0: {skilltype = INITIATIVE; break; }
	case 1: {skilltype = PASSIVITY; break; }
	}
}

//获取技能类型
SkillType CSkill::Get_Skill_Type()
{
	return skilltype;
}

//设置技能等级
void CSkill::Set_Skill_Level(uint32 ssl)
{
	uskillLevel += ssl;
}

//获取技能等级
int CSkill::Get_Skill_Level()
{
	return uskillLevel;
}

//设置技能ID
void CSkill::Set_Skill_ID(uint32 ssid)
{
	uskillID = ssid;
}

//获取技能ID
int CSkill::Get_Skill_ID()
{
	return uskillID;
}

//设置技能描述
void CSkill::Set_Skill_Describe(std::string skill)
{
	skilldescribe = skill;
}

//获取技能描述
std::string CSkill::Get_Skill_Describe()
{
	return skilldescribe;
}
