#include "Warehouse.h"


//物品类
CWarehouseArticle::CWarehouseArticle()
{
	m_artSerNum = 0; //物品编号
}

CWarehouseArticle::~CWarehouseArticle()
{
}

//设置物品编号
void CWarehouseArticle::Set_CArticleSerialNumber(uint32 casn)
{
	m_artSerNum = casn;
}

//获取物品编号
uint32 CWarehouseArticle::Get_CArticleSerialNumber()
{
	return m_artSerNum;
}

//仓库类
Warehouse::Warehouse()
{

	m_watNum = 0; //记录物品水资源的数量

	m_equNum = 0; //记录物品装备的数量

	m_sepProNum = 0; //记录物品特殊道具的数量

	wareArt = new CWarehouseArticle;
}


Warehouse::~Warehouse()
{
	delete wareArt;
	wareArt = NULL;
}

//增加物品
void Warehouse::AddArticle(uint32 uid)
{
	//水资源的id
	uint32 uwater = 10001;
	//装备的id
	uint32 uequip = 10002;
	//特殊道具的id
	uint32 useppro = 10003;
	if (map_warehouse[uid]->Get_CArticleSerialNumber() == uwater)
	{
		map_warehouse[uid] = wareArt;
		m_watNum += 1;
	}
	if (map_warehouse[uid]->Get_CArticleSerialNumber() == uequip)
	{
		map_warehouse[uid] = wareArt;
		m_equNum += 1;
	}
	if (map_warehouse[uid]->Get_CArticleSerialNumber() == useppro)
	{
		map_warehouse[uid] = wareArt;
		m_sepProNum += 1;
	}
	
	
}

//删除物品 通过物品编号
void Warehouse::CloseArticle(uint32 cloart)
{
	//通过物品编号 查找表里面的对应数据
	for (std::map<uint32, CWarehouseArticle*>::iterator it = map_warehouse.begin(); it != map_warehouse.end(); it++)
	{
		if (cloart == it->second->Get_CArticleSerialNumber())
		{
			map_warehouse.erase(it);
		}
	}

}

//获取物品水资源的数量
uint32 Warehouse::Get_ArticleToWaterCount()
{
	return m_watNum;
}

//获取物品装备的数量
uint32 Warehouse::Get_ArticleToEquipCount()
{
	return m_equNum;
}

//获取物品特殊道具的数量
uint32 Warehouse::Get_ArticleToSepProCount()
{
	return m_sepProNum;
}

//获取物品map
std::map<uint32, CWarehouseArticle*> Warehouse::Get_ArticleMap()
{
	return map_warehouse;
}