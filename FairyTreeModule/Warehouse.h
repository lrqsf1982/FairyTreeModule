#pragma once

#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "Gamedefine.h"
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

private:
	//物品编号
	uint32 m_artSerNum;

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

	//获取物品map
	std::map<uint32, CWarehouseArticle*> Get_ArticleMap();
private:
	CWarehouseArticle * wareArt;
	//物品类的map
	std::map<uint32, CWarehouseArticle*> map_warehouse;

	//记录物品水资源的数量
	uint32 m_watNum;
	//记录物品装备的数量
	uint32 m_equNum;
	//记录物品特殊道具的数量
	uint32 m_sepProNum;
};

#endif
