#pragma once
#ifndef _FAIRY_TREE_H
#define _FAIRY_TREE_H

#include "Gamedefine.h"
#include "CharacterClass.h"
#include <map>

//神仙树(FairyTree)能够储藏(store)金币(gold)的最大(max)数(number)
//#define FAIRYTREESTOREMAXNUMBER  1000


#define FMAXGOLDTIME 50 //生产金币的最大时间

#define FGOLDNUMBER 10 //生产金币的数量

//神仙树类
class FairyTree
{
public:
	FairyTree();
	~FairyTree();
	//设置等级
	void Set_FGrade(bool fgr);
	// 获取等级
	uint32 Get_FGrade();

	//设置树高
	void Set_TreeHeight(uint32 sth);
	//获取树高
	uint32 Get_TreeHeight();

	//设置生产的金币 
	void Set_FGold(uint32 fgo);
	//获取金币
	uint32 Get_FGold();

	//设置生产金币的时间
	void Set_FGoldTime(uint32 ufgt);
	//获取时间
	uint32 Get_FGoldTime();

	//设置增加树存储金币
	void Set_FAddFaiTreStoGol(uint32 ufftsg);
	//设置减少树存储金币
	void Set_FMinusFaiTreStoGol(uint32 ufmftsg);
	//获取树存储金币
	uint32 Get_FFaiTreStoGol();

	//设置消耗水的数量
	void Set_FCoWaterNum(uint32 num);
	//获取消耗水的数量
	uint32 Get_FCoWaterNum();

	//设置阳光数量消耗
	void Set_FCoSunNum(uint32 num);
	//获取阳光数量消耗
	uint32 Get_FCoSunNum();

	//设置金币数量消耗
	void Set_FCoGoldNum(uint32 num);
	//获取金币数量消耗
	uint32 Get_FCoGoldNum();

	//设置钻石数量消耗
	void Set_FCoJewelNum(uint32 num);
	//获取钻石数量消耗
	uint32 Get_FCoJewelNum();

	//设置小精灵体力消耗
	void Set_FCoeflinNum(uint32 num);
	//获取小精灵体力消耗
	uint32 Get_FCoeflinNum();

	//设置突破所需
	void Set_FCoBreakthNum(uint32 num);
	//获取突破所需
	uint32 Get_FCoBreakthNum();

	//设置用户ID
	void Set_RoleID(uint32 uid);
	//获取用户ID
	uint32 Get_RoleID();

	//神仙树的map
	std::map<uint32, FairyTree*> map_fairytree;
private:

	//用户ID
	uint32 m_roleID;

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
	uint32 ucowaternum;
	//阳光数量消耗
	uint32 ucosunnum;
	//金币数量消耗
	uint32 ucogoldnum;
	//钻石数量消耗
	uint32 ucojewelnum;
	//小精灵体力消耗
	uint32 ucoeflinnum;
	//突破所需
	uint32 ucobreakthnum;


};


#endif
