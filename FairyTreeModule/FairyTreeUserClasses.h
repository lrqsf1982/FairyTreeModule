#pragma once

#ifndef _FAIRY_TREE_USER_CLASSES_H
#define _FAIRY_TREE_USER_CLASSES_H

#include "define.h"
#include "Elfin.h"
#include "FairyTree.h"
#include "SunShine.h"
#include "Gold.h"
#include "Mail.h"
#include "RankingList.h"
#include "Relation.h"
#include "Shop.h"
#include "Skill.h"
#include "TaskClass.h"
#include "TreeEnchantment.h"
#include "Warehouse.h"
#include "Water.h"
#include "./TinyXML/tinyxml.h"
#include "./TinyXML/tinyxml.h"



//神仙树用户类
class FairyTreeUserClasses
{
public:
	FairyTreeUserClasses();
	~FairyTreeUserClasses();

	//获取小精灵
	Elfin* Get_Elfin(uint32 id);

	//获取神仙树
	FairyTree Get_FairyTree();

	//获取神仙井
	CSunshine Get_SunShine();

	//获取树结界
	TreeEnchantment Get_TreeEnchantment();

	//获取仓库
	Warehouse Get_Warehouse();

	//获取商店
	Shop Get_Shop();

	//获取邮箱
	CMailbox Get_CMailbox();

	//获取任务列表
	CTaskListClass Get_CTaskListClass();

	//获取关系
	Relation Get_Relation();

	//获取排行榜
	RankingList Get_RankingList();

	//获取技能
	CSkill Get_CSkill();

	//获取资源水
	Water Get_Water();

	//获取资源金币
	Gold Get_Gold();

	//设置增加钻石
	void Set_UserAddDiamond(uint32 sd);
	//设置减少钻石
	void Set_UserRedDiamond(uint32 surd);
	//获取钻石
	int Get_UserDiamond();

private:
	//小精灵(链表)
	std::list<Elfin*> slistElfin;

	//神仙树
	FairyTree fairytree;

	//太阳
	CSunshine sunshine;

	//树结界
	TreeEnchantment treeenchantment;

	//仓库
	Warehouse warehouse;

	//商店
	Shop shop;

	//邮箱
	CMailbox mailbox;

	//任务列表
	CTaskListClass tasklist;

	//关系
	Relation relation;

	//排行榜
	RankingList rankinglist;

	//技能
	CSkill skill;

	//资源(水, 金币)
	Water water;
	Gold gold;

	//钻石
	uint32 udiamond;

};

//读Xml文件
//bool bPaintXml(const char* pfilepath);


#endif

