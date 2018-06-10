#pragma once

#ifndef _SKILL_H
#define _SKILL_H

#include "define.h"
#include <map>

//技能类型
enum SkillType
{
	INITIATIVE, //主动
	PASSIVITY   //被动
};

class CSkill
{
public:
	CSkill();
	~CSkill();
	//设置技能类型
	void Set_Skill_Type(uint32 sst);
	//获取技能类型
	SkillType Get_Skill_Type();

	//设置技能等级
	void Set_Skill_Level(bool ssl);
	//获取技能等级
	int Get_Skill_Level();

	//设置技能ID
	void Set_Skill_ID(uint32 ssid);
	//获取技能ID
	int Get_Skill_ID();

	//设置技能描述
	void Set_Skill_Describe(std::string skill);
	//获取技能描述
	std::string Get_Skill_Describe();
	
	//设置掠夺效果
	void Set_uPillageEffect(uint32 uset);
	//获取掠夺效果
	int Get_uPillageEffect();

	//设置浇水效果
	void Set_uWateringEffect(uint32 uset);
	//获取浇水效果
	int Get_uWateringEffect();

	//设置储存金币
	void Set_uReserveGold(uint32 uset);
	//获取储存金币
	int Get_uReserveGold();

	//设置栽培效果
	void Set_uPlantEffect(uint32 uset);
	//获取栽培效果
	int Get_uPlantEffect();

	//设置躲避能力
	void Set_uDodgeAbility(uint32 uset);
	//获取躲避能力
	int Get_uDodgeAbility();

	//设置抢劫加成
	void Set_uRobAddition(uint32 uset);
	//获取抢劫加成
	int Get_uRobAddition();

	//技能map
	std::map<uint32, CSkill*> map_skill;
private:
	//技能类型
	SkillType skilltype;

	//技能等级
	uint32 uskillLevel;

	//技能ID
	uint32 uskillID;

	//技能描述
	std::string skilldescribe;

	//掠夺效果
	uint32 upillageEffect;
	//浇水效果
	uint32 uwateringEffect;
	//储存金币
	uint32 ureserveGold;
	//栽培效果
	uint32 uplantEffect;
	//躲避能力
	uint32 udodgeAbility;
	//抢劫加成
	uint32 urobAddition;

	//特效(保留)

	//声音(保留)

	//技能效果
};


//技能效果 写成基类 派生类


#endif

