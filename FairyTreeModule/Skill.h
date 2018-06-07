#pragma once

#ifndef _SKILL_H
#define _SKILL_H

#include "define.h"

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

private:
	//技能类型
	SkillType skilltype;

	//技能等级
	uint32 uskillLevel;

	//技能ID
	uint32 uskillID;

	//技能描述
	std::string skilldescribe;

	//特效(保留)

	//声音(保留)

	//技能效果
};


//技能效果 写成基类 派生类


#endif

