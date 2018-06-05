#pragma once

#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "define.h"
#include <vector>


//物品类别
enum EArticleCategory
{
	WATERRESOURCECLASS, //水资源类
	EQUIPPEDWITHCLASS, //装备类
	SPECIALPROPS //特殊道具类
};

//物品类
class CWarehouseArticle
{
public:
	CWarehouseArticle();
	~CWarehouseArticle();

	//设置物品编号
	void Set_CArticleSerialNumber(uint32 casn);
	//获取物品编号
	int Get_CArticleSerialNumber();

	//设置物品金币价格
	void Set_CArticleGoldPrice(uint32 cgp);
	//获取物品金币价格
	int Get_CArticleGoldPrice();

	//设置物品钻石价格
	void Set_CArticleJewelPrice(uint32 cajp);
	//获取物品钻石价格
	int Get_CArticleJewelPrice();

	//设置物品折扣
	void Set_CArticleDiscount(float cad);
	//获取物品折扣
	float Get_CArticleDiscount();

	//设置物品描述(Describe)
	void Set_CArticleDescribe(std::string& scad);
	//获取物品描述(Describe)
	string Get_CArticleDescribe();

	//使用物品 通过物品编号 来确定使用的物品类别
	virtual void ArticleSerialNumberCategory() = 0;

private:
	//物品编号
	uint32 uarticleSerialNumber;

	//物品金币价格
	uint32 ugoldPrice;

	//物品钻石价格
	uint32 ujewelPrice;

	//物品折扣
	float uarticleDiscount;

	//物品类别(水资源类,装备类,特殊道具类)
	EArticleCategory eartCat;

	//物品描述(Describe)
	std::string eartDescribe;
};


//仓库类(预留)
class Warehouse
{
public:
	Warehouse();
	~Warehouse();

	//增加物品
	void AddArticle(CWarehouseArticle* addart);
	//删除物品
	void CloseArticle(uint32 cloart);
private:
	//物品(预留)
	std::vector<CWarehouseArticle*> vec;
};

#endif
