#pragma once

#ifndef _ELFIN_H
#define _ELFIN_H

#include "Skill.h"
#include "define.h"
#include <vector>
#include <windows.h>
#include <time.h>
#include <map>

#define SEGMAXPHYSICALPOWER 10 //最大体力的增长值

enum ElfinType//技能类型
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
	ElfinType Get_ESkillStyle();

	//设置等级
	void Set_EGrade(uint32 beg);
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

	//设置消耗水的数量
	void Set_uCoWaterNum(uint32 num);
	//获取消耗水的数量
	int Get_uCoWaterNum();

	//设置阳光数量消耗
	void Set_uCoSunNum(uint32 num);
	//获取阳光数量消耗
	int Get_uCoSunNum();

	//设置金币数量消耗
	void Set_uCoGoldNum(uint32 num);
	//获取金币数量消耗
	int Get_uCoGoldNum();

	//设置钻石消耗数量
	void Set_uCoJewelNum(uint32 num);
	//获取钻石消耗数量
	int Get_uCoJewelNum();

	//小精灵的map
	std::map<uint32, Elfin*> map_elfin;
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
	ElfinType estype;

	//消耗水的数量
	uint32 ucowaternum;
	//阳光数量消耗
	uint32 ucosunnum;
	//金币数量消耗
	uint32 ucogoldnum;
	//钻石消耗数量
	uint32 ujewelnum;

	//类型(包括以下几种)
	//1:金(第一技能 储存金币) 2:木(第一技能 栽培树效率更高) 3:水(第一技能 浇水)
	//4:火(第一技能 擅长掠夺其他玩家金币，体力为正常5点) 5:土(第一技能 避开陷阱) 6:暗(待定)
};


#endif

