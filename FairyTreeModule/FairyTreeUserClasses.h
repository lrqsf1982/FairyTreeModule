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
#include "XmlConfigManager.h"
#include "CharacterClass.h"




//神仙树用户类
class FairyTreeUserClasses
{
public:
	FairyTreeUserClasses();
	~FairyTreeUserClasses();

	//设置记录用户的个数
	void Set_RecordUserCount(uint32 ucon);
	//获取记录用户的个数
	int Get_RecordUserCount();

	//设置用户ID
	void Set_UserId(uint32 suid);
	//获得用户ID
	int Get_UserId();

	//获取小精灵
	Elfin Get_Elfin();

	//获取神仙树
	FairyTree Get_FairyTree();

	//获取阳光
	CSunshine Get_SunShine();

	//获取商店
	Shop Get_Shop();

	//获取树结界
	TreeEnchantment Get_TreeEnchantment();

	//获取仓库
	Warehouse Get_Warehouse();

	//获取邮箱
	CMailbox Get_CMailbox();

	//获取任务类
	CTaskListClass Get_CTaskListClass();

	//获取关系
	Relation Get_Relation();

	//获取排行榜
	RankingList Get_RankingList();

	//角色类
	CharacterClass Get_Characlass();

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
	//获取钻石数量
	int Get_UserDiamond();

	//太阳升级函数
	void vUpgradeSolarFun(uint32 uid);
	//小精灵升级函数
	void vUpgradeElfinFun(uint32 uelfid);
	//神仙树升级函数
	void vUpgradeFairyTreeFun(uint32 uid);
	//技能升级函数
	void vUpgradeSkillFun(uint32 usklid);

	//设置升级普通水消耗的数量
	void vSetUpgradeWaterNum(uint32 num);
	//获取升级普通水消耗的数量
	int vGetUpgradeWaterNum();
	//设置升级神仙水消耗的数量
	void vSetUpgradeFairyTreeNum(uint32 num);
	//获取升级神仙水消耗的数量
	int vGetUpgradeFairyTreeWaterNum();
	//设置升级金币消耗的数量
	void vSetUpgradeGoldNum(uint32 num);
	//获取升级金币消耗的数量
	int vGetUpgradeGoldNum();
	//设置升级阳光消耗的数量
	void vSetUpgradeSunNum(uint32 num);
	//获取升级阳光消耗的数量
	int vGetUpgradeSunNum();
	//设置升级小精灵体力消耗的数量
	void vSetUpgradeElfinTiliNum(uint32 num);
	//获取升级小精灵体力消耗的数量
	int vGetUpgradeElfinTiliNum();
	//设置升级钻石消耗的数量
	void vSetUpgradeDiamoNum(uint32 num);
	//获取升级钻石消耗的数量
	int vGetUpgradeDiamoNum();
private:
	//记录用户的个数
	uint32 uRecordUserCount;

	//用户ID
	uint32 userid;

	//小精灵(链表)
	Elfin elf;

	//神仙树
	FairyTree fairytree;

	//太阳
	CSunshine sunshine;
	
	//商店
	Shop cshop;

	//树结界
	TreeEnchantment treeenchantment;

	//仓库
	Warehouse warehouse;

	//邮箱
	CMailbox mailbox;

	//任务类
	CTaskListClass tasklist;

	//关系
	Relation relation;

	//排行榜
	RankingList rankinglist;

	//角色类
	CharacterClass characlass;

	//技能
	CSkill skill;

	//资源(水, 金币)
	Water water;
	Gold gold;

	//钻石
	uint32 udiamond;

	//升级需要的普通水的数量
	uint32 uUpwaterNum;
	//升级需要的神仙水的数量
	uint32 uUpfairywaterNum;
	//升级需要的金币的数量
	uint32 uUpgoldNum;
	//升级需要的阳光的数量
	uint32 uUpsunNum;
	//升级需要的小精灵体力的数量
	uint32 uUpelfinTiliNUM;
	//升级需要的钻石的数量
	uint32 uUpdiaNum;
};

class CAllUserInfoInstance 
{
	CAllUserInfoInstance() {};
	static CAllUserInfoInstance* _instance;
public:
	static CAllUserInfoInstance * GetInstance();
	std::map<uint32, FairyTreeUserClasses*> ConnetedUser;

};
#endif

