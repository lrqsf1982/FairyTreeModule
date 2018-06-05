#pragma once
#ifndef _FAIRY_TREE_H
#define _FAIRY_TREE_H

#include "define.h"

//神仙树(FairyTree)能够储藏(store)金币(gold)的最大(max)数(number)
//#define FAIRYTREESTOREMAXNUMBER  1000

#define FMAXEXPERIENCE 100 //神仙树(FairyTree)的最大经验值

#define FMAXGOLDTIME 50 //生产金币的最大时间

#define FGOLDNUMBER 10 //生产金币的数量

//神仙树类
class FairyTree
{
public:
	FairyTree();
	~FairyTree();
	//设置等级 获取等级
	void Set_FGrade(uint32 fgr);
	int Get_FGrade();

	//设置树高
	void Set_TreeHeight(uint32 sth);
	//获取树高
	int Get_TreeHeight();

	//设置生产的金币 
	void Set_FGold(uint32 fgo);
	//获取金币
	int Get_FGold();

	//设置生产金币的时间
	void Set_FGoldTime(uint32 ufgt);
	//获取时间
	int Get_FGoldTime();

	//设置增加树存储金币
	void Set_FAddFaiTreStoGol(uint32 ufftsg);
	//设置减少树存储金币
	void Set_FMinusFaiTreStoGol(uint32 ufmftsg);
	//获取树存储金币
	int Get_FFaiTreStoGol();

	//设置消耗水的数量
	void Set_ConsumptionWater(uint32 scw);
	//获取消耗水的数量
	int Get_ConsumptionWater();

	//设置消耗阳光的数量
	void Set_ConsumptionSunshine(uint32 scs);
	//获取消耗阳光的数量
	int Get_ConsumptionSunshine();

	//设置消耗金币的数量
	void Set_ConsumptionGold(uint32 scg);
	//获取消耗金币的数量
	int Get_ConsumptionGold();

	//设置消耗小精灵体力的数量
	void Set_ConsumptionElfinPP(uint32 scepp);
	//获取消耗小精灵体力的数量
	int Get_ConsumptionElfinPP();
private:
	//等级
	uint32 fgrade;
	//树高 = 等级
	uint32 uheightTree;

	//生产的金币
	uint32 fgold;

	//生产金币的时间
	uint32 fgoldtime;

	//神仙树存储金币
	uint32 cfaiTreStoGol;

	//消耗水的数量
	uint32 uCoWaterNum;

	//消耗阳光的数量
	uint32 uCoSunNum;

	//消耗金币的数量
	uint32 uCoGoldNum;

	//消耗小精灵体力的数量
	uint32 uCoElfinPP;


};


#endif
