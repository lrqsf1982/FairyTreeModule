#pragma once

#ifndef _SKILL_H
#define _SKILL_H

#include "Gamedefine.h"

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
	uint32 Get_Skill_Level();

	//设置技能ID
	void Set_Skill_ID(uint32 ssid);
	//获取技能ID
	uint32 Get_Skill_ID();

private:
	//技能类型
	SkillType m_type;

	//技能等级
	uint32 m_Level;

	//技能ID
	uint32 m_id;

};


#endif

