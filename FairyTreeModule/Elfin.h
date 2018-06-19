#pragma once

#ifndef _ELFIN_H
#define _ELFIN_H

#include "Skill.h"
#include "Gamedefine.h"
#include <vector>

enum ElfinSkillType//技能类型
{
	EGOLD = 0,   //金
	EWOOD,		 //木
	EWATER,		 //水
	EFIRE,		 //火
	ESOIL		 //土
	//EDARK		 //暗
};

enum ElfinState//小精灵状态
{
	FREETIME = 0,			//空闲
	WATERING,				//浇水
	PLUNDER,				//掠夺
	PLANT,					//栽培
};
//小精灵类
class Elfin
{
public:
	Elfin();
	~Elfin();
	//设置添加技能格
	void Set_ESkillStyle(CSkill* ecsk);
	//设置删除技能
	void Set_EReduceSkillStyle(uint32 iderss);
	//获取技能格
	ElfinSkillType Get_ESkillStyle()const;

	//设置等级
	void Set_EGrade(uint32 beg);
	//获取等级
	uint32 Get_EGrade()const;

	//设置增加体力
	void Set_EAddPhysicalPower(uint32 ueap);
	//设置减少体力
	void Set_EReducePhysicalPower(uint32 uerp);

	//获取当前体力
	uint32 Get_EPhysicalPower()const;

	//设置最大体力
	void Set_EMaxPhysicalPower(uint32 uempp);
	//获取最大体力
	uint32 Get_EMaxPhysicalPower()const;

	//设置随机分配小精灵的ID
	uint32 Set_Get_EToID(ElfinSkillType m_type);
	//获取小精灵的ID
	uint32 Get_EToID()const;


	//获取技能类
	CSkill* Get_CSkillClass()const;
	//设置掠夺状态
	//void	m_uPlunderState(ElfinState state);
	//获得掠夺

private:

	CSkill * m_skill;
	//技能格(多个)
	std::vector<CSkill*> m_vecSki;
	
	//小精灵的ID
	uint32 m_id;

	//物品(预留)
	//----------

	//等级
	uint32 m_level;

	//体力
	uint32 m_curPhyPower;
	//最大体力
	uint32 m_maxphyPower;

	//枚举类型的技能属性
	ElfinSkillType m_type;


	//bool	 m_uPlunderState;					//小精灵掠夺状态
	//UINT32	 m_uBePlunderId;					//被掠夺者ID
	//UINT32	 m_uPlunderGoldNum;					//已经掠夺的金币数量
	//类型(包括以下几种)
	//1:金(第一技能 储存金币) 2:木(第一技能 栽培树效率更高) 3:水(第一技能 浇水)
	//4:火(第一技能 擅长掠夺其他玩家金币，体力为正常5点) 5:土(第一技能 避开陷阱) 6:暗(待定)
};


#endif

