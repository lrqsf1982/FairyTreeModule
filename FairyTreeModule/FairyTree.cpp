#include "FairyTree.h"
#include "XmlConfigManager.h"



FairyTree::FairyTree()
{
	m_lev = 1;//等级

	m_hei = 1;//树高 = 等级

	m_goldPro = XmlConfigManager::GetInstance()->TreeInfos[m_lev]->productivity;//生产的金币

	m_goldProTime = 0; //生产金币的时间

	m_treStoGol = 0;//神仙树存储金币
		  
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
		m_lev += 1;

		//生产金币的数量的增加
		Set_FGold(0);
		//设置树高
		Set_TreeHeight(m_goldPro);

	}
	
}

//获取等级
uint32 FairyTree::Get_FGrade()
{
	return m_lev;
}

//设置树高
void FairyTree::Set_TreeHeight(uint32 sth)
{
	m_hei = sth;
}

//获取树高
uint32 FairyTree::Get_TreeHeight()
{
	return m_hei;
}

//设置生产的金币 
void FairyTree::Set_FGold(uint32 fgo)
{
	//树的等级每增加一级 生产金币的数量就增加 固定值
	m_goldPro += fgo;
}

//获取生产的金币
uint32 FairyTree::Get_FGold()
{
	//每获得一次金币 就将金币存放进 池中
	Set_FAddFaiTreStoGol(m_goldPro);

	return m_goldPro;
}

//设置生产金币的时间
void FairyTree::Set_FGoldTime(uint32 ufgt)
{
	//树的等级每增加一级 生产金币的时间 是否需要增加 固定时间
	m_goldProTime += ufgt;
}

//获取生产金币的时间
uint32 FairyTree::Get_FGoldTime()
{
	return m_goldProTime;
}

//设置树存储金币
void FairyTree::Set_FAddFaiTreStoGol(uint32 ufftsg)
{
	//树的存储金币是否需要上限
	//树的等级每增加一级 是否需要将 树的存储金币增加 固定值
	m_treStoGol += ufftsg;
}

//设置减少树存储金币
void FairyTree::Set_FMinusFaiTreStoGol(uint32 ufmftsg)
{
	//当有用金币购买物品的时候 存储的金币就 减少(按物品的价格,数量来)
	m_treStoGol -= ufmftsg;
}

//获取树存储金币
uint32 FairyTree::Get_FFaiTreStoGol()
{
	//得到总存储的金币数量
	return m_treStoGol;
}


