#include "FairyTree.h"



FairyTree::FairyTree()
{
	m_roleID = 0;//用户ID

	fgrade = 0;//等级

	uheightTree = 0;//树高 = 等级

	fgold = FGOLDNUMBER;//生产的金币

	fgoldtime = FMAXGOLDTIME; //生产金币的时间

	cfaiTreStoGol = 0;//神仙树存储金币
		  
	ucowaternum = 0;//消耗水的数量
	
	ucosunnum = 0;//阳光数量消耗
	
	ucogoldnum = 0;//金币数量消耗
	
	ucojewelnum = 0;//钻石数量消耗
	
	ucoeflinnum = 0;//小精灵体力消耗
	
	ucobreakthnum = 0;//突破所需

}


FairyTree::~FairyTree()
{
}

//设置等级 
void FairyTree::Set_FGrade(bool fgr)
{
	
	if (fgr)
	{
		//等级增加一级
		fgrade += 1;

		//生产金币的数量的增加
		Set_FGold(FGOLDNUMBER);
		//设置树高
		Set_TreeHeight(fgrade);

		CharacterClass characlass;
		characlass.Set_TreeToGread(fgrade);
	}
	
}

//获取等级
uint32 FairyTree::Get_FGrade()
{
	return fgrade;
}

//设置树高
void FairyTree::Set_TreeHeight(uint32 sth)
{
	uheightTree = sth;
}

//获取树高
uint32 FairyTree::Get_TreeHeight()
{
	return uheightTree;
}

//设置生产的金币 
void FairyTree::Set_FGold(uint32 fgo)
{
	//树的等级每增加一级 生产金币的数量就增加 固定值
	fgold = fgo;
}

//获取生产的金币
uint32 FairyTree::Get_FGold()
{
	//每获得一次金币 就将金币存放进 池中
	Set_FAddFaiTreStoGol(fgold);

	return fgold;
}

//设置生产金币的时间
void FairyTree::Set_FGoldTime(uint32 ufgt)
{
	//树的等级每增加一级 生产金币的时间 是否需要增加 固定时间
	fgoldtime += ufgt;
}

//获取生产金币的时间
uint32 FairyTree::Get_FGoldTime()
{
	return fgoldtime;
}

//设置树存储金币
void FairyTree::Set_FAddFaiTreStoGol(uint32 ufftsg)
{
	//树的存储金币是否需要上限
	//树的等级每增加一级 是否需要将 树的存储金币增加 固定值
	cfaiTreStoGol += ufftsg;
}

//设置减少树存储金币
void FairyTree::Set_FMinusFaiTreStoGol(uint32 ufmftsg)
{
	//当有用金币购买物品的时候 存储的金币就 减少(按物品的价格,数量来)
	cfaiTreStoGol -= ufmftsg;
}

//获取树存储金币
uint32 FairyTree::Get_FFaiTreStoGol()
{
	//得到总存储的金币数量
	return cfaiTreStoGol;
}

//设置消耗水的数量
void FairyTree::Set_FCoWaterNum(uint32 num)
{
	ucowaternum = num;
}

//获取消耗水的数量
uint32 FairyTree::Get_FCoWaterNum()
{
	return ucowaternum;
}

//设置阳光数量消耗
void FairyTree::Set_FCoSunNum(uint32 num)
{
	ucosunnum = num;
}

//获取阳光数量消耗
uint32 FairyTree::Get_FCoSunNum()
{
	return ucosunnum;
}

//设置金币数量消耗
void FairyTree::Set_FCoGoldNum(uint32 num)
{
	ucogoldnum = num;
}

//获取金币数量消耗
uint32 FairyTree::Get_FCoGoldNum()
{
	return ucogoldnum;
}

//设置钻石数量消耗
void FairyTree::Set_FCoJewelNum(uint32 num)
{
	ucojewelnum = num;
}

//获取钻石数量消耗
uint32 FairyTree::Get_FCoJewelNum()
{
	return ucojewelnum;
}

//设置小精灵体力消耗
void FairyTree::Set_FCoeflinNum(uint32 num)
{
	ucoeflinnum = num;
}

//获取小精灵体力消耗
uint32 FairyTree::Get_FCoeflinNum()
{
	return ucoeflinnum;
}

//设置突破所需
void FairyTree::Set_FCoBreakthNum(uint32 num)
{
	ucobreakthnum = num;
}

//获取突破所需
uint32 FairyTree::Get_FCoBreakthNum()
{
	return ucobreakthnum;
}

//设置用户ID
void FairyTree::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//获取用户ID
uint32 FairyTree::Get_RoleID()
{
	return m_roleID;
}


