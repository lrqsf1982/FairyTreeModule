#include "Warehouse.h"


//物品类
CWarehouseArticle::CWarehouseArticle()
{
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
int CWarehouseArticle::Get_CArticleSerialNumber()
{
	return uarticleSerialNumber;
}

//设置物品金币价格
void CWarehouseArticle::Set_CArticleGoldPrice(uint32 cgp)
{
	ugoldPrice = cgp;
}

//获取物品金币价格
int CWarehouseArticle::Get_CArticleGoldPrice()
{
	return ugoldPrice;
}

//设置物品钻石价格
void CWarehouseArticle::Set_CArticleJewelPrice(uint32 cajp)
{
	ujewelPrice = cajp;
}

//获取物品钻石价格
int CWarehouseArticle::Get_CArticleJewelPrice()
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
void CWarehouseArticle::Set_CArticleDescribe(std::string & scad)
{
	eartDescribe = scad;
}

//获取物品描述(Describe)
string CWarehouseArticle::Get_CArticleDescribe()
{
	return eartDescribe;
}

//设置物品类型
void CWarehouseArticle::Set_eArticleType(EArticleCategory ear)
{
	eartCat = ear;
}

//获得物品类型
EArticleCategory CWarehouseArticle::Get_eArticleType()
{
	return eartCat;
}

//设置物品名字
void CWarehouseArticle::Set_WareName(std::string & swn)
{
	warename = swn;
}

//获取物品名字
string CWarehouseArticle::Get_WareName()
{
	return warename;
}





//仓库类
Warehouse::Warehouse()
{
}


Warehouse::~Warehouse()
{
}

//增加物品
void Warehouse::AddArticle(CWarehouseArticle* addart)
{
	vec.push_back(addart);
}

//删除物品 通过物品编号
void Warehouse::CloseArticle(uint32 cloart)
{
	
	//通过物品编号 查找表里面的对应数据
	for (std::vector<CWarehouseArticle*>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (cloart == (*it)->Get_CArticleSerialNumber())
		{
			//找到 删除
			vec.erase(it);
		}
	}

}
