#pragma once

#include "Skill.h"

CSkill::CSkill()
{
	skilltype = INITIATIVE; //技能类型

	uskillLevel = 0; //技能等级

	uskillID = 0; //技能ID

	skilldescribe = "";//技能描述

	upillageEffect = 0; //掠夺效果
	
	uwateringEffect = 0;//浇水效果
	
	ureserveGold = 0;//储存金币
	
	uplantEffect = 0;//栽培效果
	
	udodgeAbility = 0;//躲避能力
	
	urobAddition = 0;//抢劫加成
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
void CSkill::Set_Skill_Level(bool ssl)
{
	if (ssl)
	{
		uskillLevel += 1;
	}
	
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

//设置掠夺效果
void CSkill::Set_uPillageEffect(uint32 uset)
{
	upillageEffect = uset;
}

//获取掠夺效果
int CSkill::Get_uPillageEffect()
{
	return upillageEffect;
}

//设置浇水效果
void CSkill::Set_uWateringEffect(uint32 uset)
{
	uwateringEffect = uset;
}

//获取浇水效果
int CSkill::Get_uWateringEffect()
{
	return uwateringEffect;
}

//设置储存金币
void CSkill::Set_uReserveGold(uint32 uset)
{
	ureserveGold = uset;
}

//获取储存金币
int CSkill::Get_uReserveGold()
{
	return ureserveGold;
}

//设置栽培效果
void CSkill::Set_uPlantEffect(uint32 uset)
{
	uplantEffect = uset;
}

//获取栽培效果
int CSkill::Get_uPlantEffect()
{
	return uplantEffect;
}

//设置躲避能力
void CSkill::Set_uDodgeAbility(uint32 uset)
{
	udodgeAbility = uset;
}

//获取躲避能力
int CSkill::Get_uDodgeAbility()
{
	return udodgeAbility;
}

//设置抢劫加成
void CSkill::Set_uRobAddition(uint32 uset)
{
	urobAddition = uset;
}

//获取抢劫加成
int CSkill::Get_uRobAddition()
{
	return urobAddition;
}
