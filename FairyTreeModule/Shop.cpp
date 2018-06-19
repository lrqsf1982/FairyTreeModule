#include "Shop.h"



Shop::Shop()
{
	pwareArt = new CWarehouseArticle;
	ubuyGoodsTotalPrice = 0;//������Ʒ����ܼ۸�
}


Shop::~Shop()
{
	delete pwareArt;
}

//����(�����) ��Ʒ��� ��Ʒ����
bool Shop::ShopCloseAnGoldFun(uint32 ugoodsID, uint32 ugoodsNum)
{
	//1001 < ˮ��Դ����Ʒ��ID��Χ < 2001
	if (WATERCOMMODITYID < ugoodsID && ugoodsID < EQUIPPEDWITHID)
	{
		//ͨ����Ʒ��Ų����Ƿ���ˮ��Դ���
		for (std::vector<CWarehouseArticle*>::iterator itwater = vecwater.begin(); itwater != vecwater.end(); itwater++)
		{
			if (ugoodsID == (*itwater)->Get_CArticleSerialNumber())
			{
				//�ҵ�
				float utotalprice = 0.0f; //��ʱ���ܼ۸�
										//������Ʒ������ * ���(ע:������ʯ) * �ۿ� = �������ܼ۸�
				//utotalprice = ugoodsNum * (*itwater)->Get_CArticleGoldPrice() * (*itwater)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	//2001 < װ������Ʒ��ID��Χ < 3001
	if (EQUIPPEDWITHID < ugoodsID && ugoodsID < SPECIALPROPSID)
	{
		//ͨ����Ʒ��Ų����Ƿ���װ�����
		for (std::vector<CWarehouseArticle*>::iterator itequ = vecequ.begin(); itequ != vecequ.end(); itequ++)
		{
			if (ugoodsID == (*itequ)->Get_CArticleSerialNumber())
			{
				//�ҵ�
				float utotalprice = 0.0f; //��ʱ���ܼ۸�
										//������Ʒ������ * ���(ע:������ʯ) * �ۿ� = �������ܼ۸�
				//utotalprice = ugoodsNum * (*itequ)->Get_CArticleGoldPrice() * (*itequ)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	//3001 < �����������Ʒ��ID��Χ
	if (ugoodsID > SPECIALPROPSID)
	{
		//ͨ����Ʒ��Ų����Ƿ�������������
		for (std::vector<CWarehouseArticle*>::iterator itspe = vecspe.begin(); itspe != vecspe.end(); itspe++)
		{
			if (ugoodsID == (*itspe)->Get_CArticleSerialNumber())
			{
				//�ҵ�
				float utotalprice = 0.0f; //��ʱ���ܼ۸�
										//������Ʒ������ * ���(ע:������ʯ) * �ۿ� = �������ܼ۸�
				//utotalprice = ugoodsNum * (*itspe)->Get_CArticleGoldPrice() * (*itspe)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	return false;
}

//����(����ʯ) ��Ʒ��� ��Ʒ����
bool Shop::ShopCloseAnJewelFun(uint32 ugoodsID, uint32 ugoodsNum)
{
	//1001 < ˮ��Դ����Ʒ��ID��Χ < 2001
	if (WATERCOMMODITYID < ugoodsID && ugoodsID < EQUIPPEDWITHID)
	{
		//ͨ����Ʒ��Ų����Ƿ���ˮ��Դ���
		for (std::vector<CWarehouseArticle*>::iterator itwater = vecwater.begin(); itwater != vecwater.end(); itwater++)
		{
			if (ugoodsID == (*itwater)->Get_CArticleSerialNumber())
			{
				//�ҵ�
				float utotalprice = 0.0f; //��ʱ���ܼ۸�
										  //������Ʒ������ * ��ʯ(ע:���ǽ��) * �ۿ� = �������ܼ۸�
				//utotalprice = ugoodsNum * (*itwater)->Get_CArticleJewelPrice() * (*itwater)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	//2001 < װ������Ʒ��ID��Χ < 3001
	if (EQUIPPEDWITHID < ugoodsID && ugoodsID < SPECIALPROPSID)
	{
		//ͨ����Ʒ��Ų����Ƿ���װ�����
		for (std::vector<CWarehouseArticle*>::iterator itequ = vecequ.begin(); itequ != vecequ.end(); itequ++)
		{
			if (ugoodsID == (*itequ)->Get_CArticleSerialNumber())
			{
				//�ҵ�
				float utotalprice = 0.0f; //��ʱ���ܼ۸�
										  //������Ʒ������ * ��ʯ(ע:���ǽ��) * �ۿ� = �������ܼ۸�
				//utotalprice = ugoodsNum * (*itequ)->Get_CArticleJewelPrice() * (*itequ)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	//3001 < �����������Ʒ��ID��Χ
	if (ugoodsID > SPECIALPROPSID)
	{
		//ͨ����Ʒ��Ų����Ƿ�������������
		for (std::vector<CWarehouseArticle*>::iterator itspe = vecspe.begin(); itspe != vecspe.end(); itspe++)
		{
			if (ugoodsID == (*itspe)->Get_CArticleSerialNumber())
			{
				//�ҵ�
				float utotalprice = 0.0f; //��ʱ���ܼ۸�
										  //������Ʒ������ * ��ʯ(ע:���ǽ��) * �ۿ� = �������ܼ۸�
				//utotalprice = ugoodsNum * (*itspe)->Get_CArticleJewelPrice() * (*itspe)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}


	return false;
}

//���� 
void Shop::ShopDiscountFun(float sdf)
{
	//�̵������Ʒ��(pwareArt)�����ۿ�
	//pwareArt = sdf;
}


//����ˮ��Դ����Ʒ
void Shop::ShopAddWaterCommodityFun(CWarehouseArticle * cwha)
{
	vecwater.push_back(cwha);
}

//����װ������Ʒ
void Shop::ShopAddEquipFun(CWarehouseArticle * cwha)
{
	vecequ.push_back(cwha);
}

//���������������Ʒ
void Shop::ShopAddSpecialFun(CWarehouseArticle * cwha)
{
	vecspe.push_back(cwha);
}

//���ù�����Ʒ����ܼ۸�
void Shop::Set_ShopBuyGoodsTotalPrice(float sbgtp)
{
	ubuyGoodsTotalPrice = sbgtp;
}

//��ȡ������Ʒ����ܼ۸�
float Shop::Get_ShopBuyGoodsTotalPrice()
{
	return ubuyGoodsTotalPrice;
}

//��ȡ��Ʒ�� ˮ��Դ��
std::vector<CWarehouseArticle*> Shop::Get_WarehouseWaterVector()
{
	return vecwater;
}

//��ȡ��Ʒ�� װ����
std::vector<CWarehouseArticle*> Shop::Get_WarehouseEquipVector()
{
	return vecequ;
}

//��ȡ��Ʒ�� ������߱�
std::vector<CWarehouseArticle*> Shop::Get_WarehouseSpeProVector()
{
	return vecspe;
}



