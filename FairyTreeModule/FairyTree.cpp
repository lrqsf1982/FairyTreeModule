#include "FairyTree.h"



FairyTree::FairyTree()
{
	fgrade = 0;//等级

	uheightTree = 0;//树高 = 等级

	fgold = FGOLDNUMBER;//生产的金币

	fgoldtime = FMAXGOLDTIME; //生产金币的时间

	cfaiTreStoGol = 0;//神仙树存储金币

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
	}
	
}

//获取等级
int FairyTree::Get_FGrade()
{
	return fgrade;
}

//设置树高
void FairyTree::Set_TreeHeight(uint32 sth)
{
	uheightTree = sth;
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


