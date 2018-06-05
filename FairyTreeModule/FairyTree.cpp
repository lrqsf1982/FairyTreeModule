#include "FairyTree.h"



FairyTree::FairyTree()
{
	fgrade = 0;//等级

	uheightTree = 0;//树高 = 等级

	fgold = FGOLDNUMBER;//生产的金币

	fgoldtime = FMAXGOLDTIME; //生产金币的时间

	cfaiTreStoGol = 0;//神仙树存储金币

	uCoWaterNum = 0; //消耗水的数量

	uCoSunNum = 0; //消耗阳光的数量

	uCoGoldNum = 0; //消耗金币的数量

	uCoElfinPP = 0; //消耗小精灵体力的数量

}


FairyTree::~FairyTree()
{
}

//设置等级 
void FairyTree::Set_FGrade(uint32 fgr)
{
	
	
		//等级增加一级
		fgrade += fgr;

		//生产金币的时间增加
		//Set_FGoldTime(FMAXGOLDTIME);

		//生产金币的数量的增加
		Set_FGold(FGOLDNUMBER);
	
}

//获取等级
int FairyTree::Get_FGrade()
{
	return fgrade;
}

//设置树高
void FairyTree::Set_TreeHeight(uint32 sth)
{
	uheightTree += sth;
}

//获取树高
int FairyTree::Get_TreeHeight()
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
int FairyTree::Get_FGold()
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
int FairyTree::Get_FGoldTime()
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
int FairyTree::Get_FFaiTreStoGol()
{
	//得到总存储的金币数量
	return cfaiTreStoGol;
}

//设置消耗水的数量
void FairyTree::Set_ConsumptionWater(uint32 scw)
{
	uCoWaterNum = scw;
}

//获取消耗水的数量
int FairyTree::Get_ConsumptionWater()
{
	return uCoWaterNum;
}

//设置消耗阳光的数量
void FairyTree::Set_ConsumptionSunshine(uint32 scs)
{
	uCoSunNum = scs;
}

//获取消耗阳光的数量
int FairyTree::Get_ConsumptionSunshine()
{
	return uCoSunNum;
}

//设置消耗金币的数量
void FairyTree::Set_ConsumptionGold(uint32 scg)
{
	uCoGoldNum = scg;
}

//获取消耗金币的数量
int FairyTree::Get_ConsumptionGold()
{
	return uCoGoldNum;
}

//设置消耗小精灵体力的数量
void FairyTree::Set_ConsumptionElfinPP(uint32 scepp)
{
	uCoElfinPP = scepp;
}

//获取消耗小精灵体力的数量
int FairyTree::Get_ConsumptionElfinPP()
{
	return uCoElfinPP;
}






