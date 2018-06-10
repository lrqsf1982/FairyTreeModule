#include "FairyTreeUserClasses.h"



FairyTreeUserClasses::FairyTreeUserClasses()
{
	uRecordUserCount = 0;//记录用户的个数

	userid = 10000; //用户ID

	udiamond = 0; //钻石

	uUpwaterNum = 0;//升级需要的普通水的数量
	
	uUpfairywaterNum = 0;//升级需要的神仙水的数量
	
	uUpgoldNum = 0;//升级需要的金币的数量
	
	uUpsunNum = 0;//升级需要的阳光的数量
	
	uUpelfinTiliNUM = 0;//升级需要的小精灵体力的数量
	
	uUpdiaNum = 0;//升级需要的钻石的数量
}


FairyTreeUserClasses::~FairyTreeUserClasses()
{
}

//设置记录用户的个数
void FairyTreeUserClasses::Set_RecordUserCount(uint32 ucon)
{
	//用户的个数加 1 
	uRecordUserCount += ucon;
	//用户的ID好加 1;
	Set_UserId(ucon);
}

//获取记录用户的个数
int FairyTreeUserClasses::Get_RecordUserCount()
{
	return uRecordUserCount;
}

//设置用户ID
void FairyTreeUserClasses::Set_UserId(uint32 suid)
{
	//用户ID号
	userid += suid;
	//角色ID号
	characlass.Set_Role_ID(userid);

}

//获得用户ID
int FairyTreeUserClasses::Get_UserId()
{
	return userid;
}

//获取小精灵
Elfin FairyTreeUserClasses::Get_Elfin()
{ 
	return elf;
}

//获取神仙树
FairyTree FairyTreeUserClasses::Get_FairyTree()
{
	return fairytree;
}

//获取太阳
CSunshine FairyTreeUserClasses::Get_SunShine()
{
	return sunshine;
}

//获取商店
Shop FairyTreeUserClasses::Get_Shop()
{
	return cshop;
}

//获取树结界
TreeEnchantment FairyTreeUserClasses::Get_TreeEnchantment()
{
	return treeenchantment;
}

//获取仓库
Warehouse FairyTreeUserClasses::Get_Warehouse()
{
	return warehouse;
}

//获取邮箱
CMailbox FairyTreeUserClasses::Get_CMailbox()
{
	return mailbox;
}

//获取任务类
CTaskListClass FairyTreeUserClasses::Get_CTaskListClass()
{
	return tasklist;
}

//获取关系
Relation FairyTreeUserClasses::Get_Relation()
{
	return relation;
}

//获取排行榜
RankingList FairyTreeUserClasses::Get_RankingList()
{
	return rankinglist;
}

//角色类
CharacterClass FairyTreeUserClasses::Get_Characlass()
{
	return characlass;
}

//获取技能
CSkill FairyTreeUserClasses::Get_CSkill()
{
	return skill;
}

//获取资源水
Water FairyTreeUserClasses::Get_Water()
{
	return water;
}

//获取资源金币
Gold FairyTreeUserClasses::Get_Gold()
{
	return gold;
}

//设置增加钻石
void FairyTreeUserClasses::Set_UserAddDiamond(uint32 sd)
{
	udiamond += sd;
}

//设置减少钻石
void FairyTreeUserClasses::Set_UserRedDiamond(uint32 surd)
{
	udiamond -= surd;
}

//获取钻石
int FairyTreeUserClasses::Get_UserDiamond()
{
	return udiamond;
}

//太阳升级函数
void FairyTreeUserClasses::vUpgradeSolarFun(uint32 uid)
{
	if (characlass.Get_Role_ID() == uid
		&& water.Get_WOrdinaryWater() >= vGetUpgradeWaterNum()
		&& gold.Get_GGoldNumber() >= vGetUpgradeGoldNum()
		&& sunshine.Get_FSunNumber() >= vGetUpgradeSunNum()
		&& Get_UserDiamond() >= vGetUpgradeDiamoNum()
		&& elf.Get_EPhysicalPower() >= vGetUpgradeElfinTiliNum())
	{
		sunshine.Set_FGrade(true);
	}
}

//小精灵升级函数
void FairyTreeUserClasses::vUpgradeElfinFun(uint32 uelfid)
{
	if (elf.Get_ID() == uelfid
		&& water.Get_WOrdinaryWater() >= vGetUpgradeWaterNum()
		&& gold.Get_GGoldNumber() >= vGetUpgradeGoldNum()
		&& sunshine.Get_FSunNumber() >= vGetUpgradeSunNum()
		&& Get_UserDiamond() >= vGetUpgradeDiamoNum())
	{
		elf.Set_EGrade(true);
	}

}

//神仙树升级函数
void FairyTreeUserClasses::vUpgradeFairyTreeFun(uint32 uid)
{
	if (characlass.Get_Role_ID() == uid
		&& water.Get_WOrdinaryWater() >= vGetUpgradeWaterNum()
		&& gold.Get_GGoldNumber() >= vGetUpgradeGoldNum()
		&& sunshine.Get_FSunNumber() >= vGetUpgradeSunNum()
		&& Get_UserDiamond() >= vGetUpgradeDiamoNum()
		&& elf.Get_EPhysicalPower() >= vGetUpgradeElfinTiliNum())
	{
		fairytree.Set_FGrade(true);
	}
}

//技能升级函数
void FairyTreeUserClasses::vUpgradeSkillFun(uint32 usklid)
{
	if (skill.Get_Skill_ID() == usklid
		&& water.Get_WOrdinaryWater() >= vGetUpgradeWaterNum()
		&& gold.Get_GGoldNumber() >= vGetUpgradeGoldNum()
		&& sunshine.Get_FSunNumber() >= vGetUpgradeSunNum()
		&& Get_UserDiamond() >= vGetUpgradeDiamoNum())
	{
		skill.Set_Skill_Level(true);
	}

}


//设置升级普通水消耗的数量
void FairyTreeUserClasses::vSetUpgradeWaterNum(uint32 num)
{
	uUpwaterNum += num;
}
//获取升级普通水消耗的数量
int FairyTreeUserClasses::vGetUpgradeWaterNum()
{
	return uUpwaterNum;
}
//设置升级神仙水消耗的数量
void FairyTreeUserClasses::vSetUpgradeFairyTreeNum(uint32 num)
{
	uUpfairywaterNum += num;
}
//获取升级神仙水消耗的数量
int FairyTreeUserClasses::vGetUpgradeFairyTreeWaterNum()
{
	return uUpfairywaterNum;
}
//设置升级金币消耗的数量
void FairyTreeUserClasses::vSetUpgradeGoldNum(uint32 num)
{
	uUpgoldNum += num;
}
//获取升级金币消耗的数量
int FairyTreeUserClasses::vGetUpgradeGoldNum()
{
	return uUpgoldNum;
}
//设置升级阳光消耗的数量
void FairyTreeUserClasses::vSetUpgradeSunNum(uint32 num)
{
	uUpsunNum += num;
}
//获取升级阳光消耗的数量
int FairyTreeUserClasses::vGetUpgradeSunNum()
{
	return uUpsunNum;
}
//设置升级小精灵体力消耗的数量
void FairyTreeUserClasses::vSetUpgradeElfinTiliNum(uint32 num)
{
	uUpelfinTiliNUM += num;
}
//获取升级小精灵体力消耗的数量
int FairyTreeUserClasses::vGetUpgradeElfinTiliNum()
{
	return uUpelfinTiliNUM;
}
//设置升级钻石消耗的数量
void FairyTreeUserClasses::vSetUpgradeDiamoNum(uint32 num)
{
	uUpdiaNum += num;
}
//获取升级钻石消耗的数量
int FairyTreeUserClasses::vGetUpgradeDiamoNum()
{
	return uUpdiaNum;
}

CAllUserInfoInstance* CAllUserInfoInstance::_instance = new CAllUserInfoInstance();
CAllUserInfoInstance * CAllUserInfoInstance::GetInstance()
{
	return _instance;
}
