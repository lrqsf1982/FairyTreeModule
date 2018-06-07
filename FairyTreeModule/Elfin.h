#pragma once

#ifndef _ELFIN_H
#define _ELFIN_H

#include "Skill.h"
#include "define.h"
#include <vector>
#include <windows.h>
#include <time.h>

#define SEGMAXPHYSICALPOWER 10 //最大体力的增长值

enum ElfinSkillType//技能类型
{
	EGOLD,   //金
	EWOOD,   //木
	EWATER,  //水
	EFIRE,   //火
	ESOIL   //土
	//EDARK    //暗
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
	int Get_ESkillStyle();

	//设置等级
	void Set_EGrade(bool beg);
	//获取等级
	int Get_EGrade();

	//设置增加体力
	void Set_EAddPhysicalPower(uint32 ueap);
	//设置减少体力
	void Set_EReducePhysicalPower(uint32 uerp);
	//获取当前体力
	int Get_EPhysicalPower();

	//设置最大体力
	void Set_EMaxPhysicalPower(uint32 uempp);
	//获取最大体力
	int Get_EMaxPhysicalPower();

	//设置小精灵的ID
	void Set_EToID(uint32 etoid);
	//获取小精灵的ID
	int Get_ID();
private:

	//技能格(多个)
	std::vector<CSkill*> vec;
	
	//小精灵的ID
	uint32 uEid;

	//物品(预留)
	//----------

	//等级
	uint32 _egrade;

	//体力
	uint32 _ephysicalpower;
	//最大体力
	uint32 _emaxphysicalpower;

	//枚举类型的技能属性
	ElfinSkillType estype;

	//类型(包括以下几种)
	//1:金(第一技能 储存金币) 2:木(第一技能 栽培树效率更高) 3:水(第一技能 浇水)
	//4:火(第一技能 擅长掠夺其他玩家金币，体力为正常5点) 5:土(第一技能 避开陷阱) 6:暗(待定)
};


#endif

