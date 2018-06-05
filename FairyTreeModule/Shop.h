#pragma once

#ifndef _SHOP_H
#define _SHOP_H

#include "Warehouse.h"

#include "define.h"

#define WATERCOMMODITYID 10001 //水资源类商品ID 大于它
#define EQUIPPEDWITHID   20001 //装备类商品ID 大于它
#define SPECIALPROPSID   30001 //特殊道具类商品ID 大于它

//商店类
class Shop
{
public:
	Shop();
	~Shop();
	//结算 物品编号 物品数量
	bool ShopCloseAnAccountFun(uint32 ugoodsID, uint32 ugoodsNum);

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

private:
	//物品类
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
