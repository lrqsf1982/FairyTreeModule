#pragma once
#ifndef _FAIRY_TREE_H
#define _FAIRY_TREE_H

#include "Gamedefine.h"
#include "CharacterClass.h"

//神仙树(FairyTree)能够储藏(store)金币(gold)的最大(max)数(number)
//#define FAIRYTREESTOREMAXNUMBER  1000


//神仙树类
class FairyTree
{
public:

	FairyTree();

	~FairyTree();

	//设置等级
	void Set_FGrade(bool fgr);

	// 获取等级
	uint32 Get_FGrade()const;

	//设置树高
	void Set_TreeHeight(uint32 sth);

	//获取树高
	uint32 Get_TreeHeight()const;

	//设置生产的金币 
	void Set_FGold(uint32 fgo);

	//获取金币
	uint32 Get_FGold()const;

	//设置生产金币的时间
	void Set_FGoldTime(uint32 ufgt);

	//获取时间
	uint32 Get_FGoldTime()const;

	//设置增加树存储金币
	void Set_FAddFaiTreStoGol(uint32 ufftsg);

	//设置减少树存储金币
	void Set_FMinusFaiTreStoGol(uint32 ufmftsg);

	//获取树存储金币
	uint32 Get_FFaiTreStoGol()const;

private:

	//等级
	uint32 m_lev;

	//树高 = 等级
	uint32 m_hei;

	//生产金币的时间
	uint32 m_goldProTime;

	//神仙树存储金币
	uint32 m_treStoGol;

	//生产力金币
	uint32 m_goldPro;

};
#endif