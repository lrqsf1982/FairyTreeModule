#pragma once

#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "Gamedefine.h"
#include <vector>
#include <map>


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
	uint32 Get_CArticleSerialNumber();

	//设置物品金币价格
	void Set_CArticleGoldPrice(uint32 cgp);
	//获取物品金币价格
	uint32 Get_CArticleGoldPrice();

	//设置物品钻石价格
	void Set_CArticleJewelPrice(uint32 cajp);
	//获取物品钻石价格
	uint32 Get_CArticleJewelPrice();

	//设置物品折扣
	void Set_CArticleDiscount(float cad);
	//获取物品折扣
	float Get_CArticleDiscount();

	//设置物品描述(Describe)
	void Set_CArticleDescribe(const std::string& scad);
	//获取物品描述(Describe)
	std::string Get_CArticleDescribe();

	//设置物品类型
	void Set_eArticleType(const EArticleCategory& ear);
	//获得物品类型
	EArticleCategory Get_eArticleType();

	//使用物品 通过物品编号 来确定使用的物品类别
	//void ArticleSerialNumberCategory();

	//设置物品名字
	void Set_WareName(const std::string& swn);
	//获取物品名字
	std::string Get_WareName();

	//设置用户ID
	void Set_RoleID(uint32 uid);
	//获取用户ID
	uint32 Get_RoleID();


private:

	//用户ID
	uint32 m_roleID;

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

	//物品名
	std::string warename;
};


//仓库类
class Warehouse
{
public:
	Warehouse();
	~Warehouse();

	//增加物品
	void AddArticle(uint32 uid);
	//删除物品
	void CloseArticle(uint32 uid);

	
	//获取物品水资源的数量
	uint32 Get_ArticleToWaterCount();
	//获取物品装备的数量
	uint32 Get_ArticleToEquipCount();
	//获取物品特殊道具的数量
	uint32 Get_ArticleToSepProCount();

	//设置用户ID
	void Set_RoleID(uint32 uid);
	//获取用户ID
	uint32 Get_RoleID();

	//物品类的map
	std::map<uint32, CWarehouseArticle*> map_warehouse;
private:

	//用户ID
	uint32 m_roleID;

	CWarehouseArticle * wareArt;

	//记录物品水资源的数量
	uint32 uWatercount;
	//记录物品装备的数量
	uint32 uEquipcount;
	//记录物品特殊道具的数量
	uint32 uSepProcount;
};

#endif
