#include "Shop.h"



Shop::Shop()
{
	m_roleID = 0;//用户ID
	pwareArt = new CWarehouseArticle;
	ubuyGoodsTotalPrice = 0;//购买物品后的总价格
}


Shop::~Shop()
{
	delete pwareArt;
}

//结算(按金币) 物品编号 物品数量
bool Shop::ShopCloseAnGoldFun(uint32 ugoodsID, uint32 ugoodsNum)
{
	//1001 < 水资源类物品的ID范围 < 2001
	if (WATERCOMMODITYID < ugoodsID && ugoodsID < EQUIPPEDWITHID)
	{
		//通过物品编号查找是否是水资源类的
		for (std::vector<CWarehouseArticle*>::iterator itwater = vecwater.begin(); itwater != vecwater.end(); itwater++)
		{
			if (ugoodsID == (*itwater)->Get_CArticleSerialNumber())
			{
				//找到
				float utotalprice = 0.0f; //临时的总价格
										//根据物品的数量 * 金币(注:不是钻石) * 折扣 = 来计算总价格
				utotalprice = ugoodsNum * (*itwater)->Get_CArticleGoldPrice() * (*itwater)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	//2001 < 装备类物品的ID范围 < 3001
	if (EQUIPPEDWITHID < ugoodsID && ugoodsID < SPECIALPROPSID)
	{
		//通过物品编号查找是否是装备类的
		for (std::vector<CWarehouseArticle*>::iterator itequ = vecequ.begin(); itequ != vecequ.end(); itequ++)
		{
			if (ugoodsID == (*itequ)->Get_CArticleSerialNumber())
			{
				//找到
				float utotalprice = 0.0f; //临时的总价格
										//根据物品的数量 * 金币(注:不是钻石) * 折扣 = 来计算总价格
				utotalprice = ugoodsNum * (*itequ)->Get_CArticleGoldPrice() * (*itequ)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	//3001 < 特殊道具类物品的ID范围
	if (ugoodsID > SPECIALPROPSID)
	{
		//通过物品编号查找是否是特殊道具类的
		for (std::vector<CWarehouseArticle*>::iterator itspe = vecspe.begin(); itspe != vecspe.end(); itspe++)
		{
			if (ugoodsID == (*itspe)->Get_CArticleSerialNumber())
			{
				//找到
				float utotalprice = 0.0f; //临时的总价格
										//根据物品的数量 * 金币(注:不是钻石) * 折扣 = 来计算总价格
				utotalprice = ugoodsNum * (*itspe)->Get_CArticleGoldPrice() * (*itspe)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	return false;
}

//结算(按钻石) 物品编号 物品数量
bool Shop::ShopCloseAnJewelFun(uint32 ugoodsID, uint32 ugoodsNum)
{
	//1001 < 水资源类物品的ID范围 < 2001
	if (WATERCOMMODITYID < ugoodsID && ugoodsID < EQUIPPEDWITHID)
	{
		//通过物品编号查找是否是水资源类的
		for (std::vector<CWarehouseArticle*>::iterator itwater = vecwater.begin(); itwater != vecwater.end(); itwater++)
		{
			if (ugoodsID == (*itwater)->Get_CArticleSerialNumber())
			{
				//找到
				float utotalprice = 0.0f; //临时的总价格
										  //根据物品的数量 * 钻石(注:不是金币) * 折扣 = 来计算总价格
				utotalprice = ugoodsNum * (*itwater)->Get_CArticleJewelPrice() * (*itwater)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	//2001 < 装备类物品的ID范围 < 3001
	if (EQUIPPEDWITHID < ugoodsID && ugoodsID < SPECIALPROPSID)
	{
		//通过物品编号查找是否是装备类的
		for (std::vector<CWarehouseArticle*>::iterator itequ = vecequ.begin(); itequ != vecequ.end(); itequ++)
		{
			if (ugoodsID == (*itequ)->Get_CArticleSerialNumber())
			{
				//找到
				float utotalprice = 0.0f; //临时的总价格
										  //根据物品的数量 * 钻石(注:不是金币) * 折扣 = 来计算总价格
				utotalprice = ugoodsNum * (*itequ)->Get_CArticleJewelPrice() * (*itequ)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	//3001 < 特殊道具类物品的ID范围
	if (ugoodsID > SPECIALPROPSID)
	{
		//通过物品编号查找是否是特殊道具类的
		for (std::vector<CWarehouseArticle*>::iterator itspe = vecspe.begin(); itspe != vecspe.end(); itspe++)
		{
			if (ugoodsID == (*itspe)->Get_CArticleSerialNumber())
			{
				//找到
				float utotalprice = 0.0f; //临时的总价格
										  //根据物品的数量 * 钻石(注:不是金币) * 折扣 = 来计算总价格
				utotalprice = ugoodsNum * (*itspe)->Get_CArticleJewelPrice() * (*itspe)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}


	return false;
}

//打折 
void Shop::ShopDiscountFun(float sdf)
{
	//商店类给物品类(pwareArt)设置折扣
	pwareArt->Set_CArticleDiscount(sdf);
}


//增加水资源类商品
void Shop::ShopAddWaterCommodityFun(CWarehouseArticle * cwha)
{
	vecwater.push_back(cwha);
}

//增加装备类商品
void Shop::ShopAddEquipFun(CWarehouseArticle * cwha)
{
	vecequ.push_back(cwha);
}

//增加特殊道具类商品
void Shop::ShopAddSpecialFun(CWarehouseArticle * cwha)
{
	vecspe.push_back(cwha);
}

//设置购买物品后的总价格
void Shop::Set_ShopBuyGoodsTotalPrice(float sbgtp)
{
	ubuyGoodsTotalPrice = sbgtp;
}

//获取购买物品后的总价格
float Shop::Get_ShopBuyGoodsTotalPrice()
{
	return ubuyGoodsTotalPrice;
}

//获取物品类  遍历物品
CWarehouseArticle * Shop::Get_ArticleClass(uint32 uid)
{
	return storeItemInfo[uid];
}

//设置用户ID
void Shop::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//获取用户ID
uint32 Shop::Get_RoleID()
{
	return m_roleID;
}


