#include "Warehouse.h"


//物品类
CWarehouseArticle::CWarehouseArticle()
{
	m_roleID = 0;//用户ID

	uarticleSerialNumber = 0; //物品编号

	ugoldPrice = 0; //物品金币价格

	ujewelPrice = 0; //物品钻石价格

	uarticleDiscount = 1.0f; //物品折扣

	eartCat = WATERRESOURCECLASS; //水资源类

	eartDescribe = ""; //物品描述(Describe)

	warename = "";//物品名
}

CWarehouseArticle::~CWarehouseArticle()
{
}

//设置物品编号
void CWarehouseArticle::Set_CArticleSerialNumber(uint32 casn)
{
	uarticleSerialNumber = casn;
}

//获取物品编号
uint32 CWarehouseArticle::Get_CArticleSerialNumber()
{
	return uarticleSerialNumber;
}

//设置物品金币价格
void CWarehouseArticle::Set_CArticleGoldPrice(uint32 cgp)
{
	ugoldPrice = cgp;
}

//获取物品金币价格
uint32 CWarehouseArticle::Get_CArticleGoldPrice()
{
	return ugoldPrice;
}

//设置物品钻石价格
void CWarehouseArticle::Set_CArticleJewelPrice(uint32 cajp)
{
	ujewelPrice = cajp;
}

//获取物品钻石价格
uint32 CWarehouseArticle::Get_CArticleJewelPrice()
{
	return ujewelPrice;
}

//设置物品折扣
void CWarehouseArticle::Set_CArticleDiscount(float cad)
{
	uarticleDiscount = cad;
}

//获取物品折扣
float CWarehouseArticle::Get_CArticleDiscount()
{
	return uarticleDiscount;
}

//设置物品描述(Describe)
void CWarehouseArticle::Set_CArticleDescribe(const std::string& scad)
{
	eartDescribe = scad;
}

//获取物品描述(Describe)
std::string CWarehouseArticle::Get_CArticleDescribe()
{
	return eartDescribe;
}

//设置物品类型
void CWarehouseArticle::Set_eArticleType(const EArticleCategory& ear)
{
	eartCat = ear;
}

//获得物品类型
EArticleCategory CWarehouseArticle::Get_eArticleType()
{
	return eartCat;
}

//设置物品名字
void CWarehouseArticle::Set_WareName(const std::string& swn)
{
	warename = swn;
}

//获取物品名字
std::string CWarehouseArticle::Get_WareName()
{
	return warename;
}

//设置用户ID
void CWarehouseArticle::Set_RoleID(uint32 uid)
{
	m_roleID = uid;//用户ID
}

//获取用户ID
uint32 CWarehouseArticle::Get_RoleID()
{
	return m_roleID;
}





//仓库类
Warehouse::Warehouse()
{
	m_roleID = 0;//用户ID

	uWatercount = 0; //记录物品水资源的数量

	uEquipcount = 0; //记录物品装备的数量

	uSepProcount = 0; //记录物品特殊道具的数量

	wareArt = new CWarehouseArticle;
}


Warehouse::~Warehouse()
{
	delete wareArt;
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
		uWatercount += 1;
	}
	if (map_warehouse[uid]->Get_CArticleSerialNumber() == uequip)
	{
		map_warehouse[uid] = wareArt;
		uEquipcount += 1;
	}
	if (map_warehouse[uid]->Get_CArticleSerialNumber() == useppro)
	{
		map_warehouse[uid] = wareArt;
		uSepProcount += 1;
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
	return uWatercount;
}

//获取物品装备的数量
uint32 Warehouse::Get_ArticleToEquipCount()
{
	return uEquipcount;
}

//获取物品特殊道具的数量
uint32 Warehouse::Get_ArticleToSepProCount()
{
	return uSepProcount;
}

//设置用户ID
void Warehouse::Set_RoleID(uint32 uid)
{
}

//获取用户ID
uint32 Warehouse::Get_RoleID()
{
	return m_roleID;
}


