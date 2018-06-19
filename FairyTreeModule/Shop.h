#pragma once

#ifndef _SHOP_H
#define _SHOP_H

#include "Warehouse.h"
#include <vector>
#include "Gamedefine.h"

#define WATERCOMMODITYID 1001 //水资源类商品ID 大于它
#define EQUIPPEDWITHID   2001 //装备类商品ID 大于它
#define SPECIALPROPSID   3001 //特殊道具类商品ID 大于它

//商店类
class Shop
{
public:
	Shop();
	~Shop();
	//结算(按金币) 物品编号 物品数量
	bool ShopCloseAnGoldFun(uint32 ugoodsID, uint32 ugoodsNum);

	//结算(按钻石) 物品编号 物品数量
	bool ShopCloseAnJewelFun(uint32 ugoodsID, uint32 ugoodsNum);

	//打折
	void ShopDiscountFun(float sdf);

	//增加水资源类商品
	void ShopAddWaterCommodityFun(CWarehouseArticle* cwha);

	//增加装备类商品
	void ShopAddEquipFun(CWarehouseArticle* cwha);

	//增加特殊道具类商品
	void ShopAddSpecialFun(CWarehouseArticle* cwha);

	//设置购买物品后的总价格
	void Set_ShopBuyGoodsTotalPrice(float sbgtp);
	//获取购买物品后的总价格
	float Get_ShopBuyGoodsTotalPrice();

	//获取物品类 水资源表
	std::vector<CWarehouseArticle*> Get_WarehouseWaterVector();

	//获取物品类 装备表
	std::vector<CWarehouseArticle*> Get_WarehouseEquipVector();

	//获取物品类 特殊道具表
	std::vector<CWarehouseArticle*> Get_WarehouseSpeProVector();
private:
	//物品类 遍历物品
	CWarehouseArticle * pwareArt;

	//(WATERRESOURCECLASS)水资源类商品 vector表
	std::vector<CWarehouseArticle*> vecwater;

	//(EQUIPPEDWITHCLASS)装备类商品 vector表
	std::vector<CWarehouseArticle*> vecequ;

	//(SPECIALPROPS)特殊道具类商品 vector表
	std::vector<CWarehouseArticle*> vecspe;

	//购买物品后的总价格
	float ubuyGoodsTotalPrice;

};


#endif
