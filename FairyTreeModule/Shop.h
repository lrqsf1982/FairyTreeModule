#pragma once

#ifndef _SHOP_H
#define _SHOP_H

#include "Warehouse.h"
#include <vector>
#include "Gamedefine.h"

#define WATERCOMMODITYID 1001 //ˮ��Դ����ƷID ������
#define EQUIPPEDWITHID   2001 //װ������ƷID ������
#define SPECIALPROPSID   3001 //�����������ƷID ������

//�̵���
class Shop
{
public:
	Shop();
	~Shop();
	//����(�����) ��Ʒ��� ��Ʒ����
	bool ShopCloseAnGoldFun(uint32 ugoodsID, uint32 ugoodsNum);

	//����(����ʯ) ��Ʒ��� ��Ʒ����
	bool ShopCloseAnJewelFun(uint32 ugoodsID, uint32 ugoodsNum);

	//����
	void ShopDiscountFun(float sdf);

	//����ˮ��Դ����Ʒ
	void ShopAddWaterCommodityFun(CWarehouseArticle* cwha);

	//����װ������Ʒ
	void ShopAddEquipFun(CWarehouseArticle* cwha);

	//���������������Ʒ
	void ShopAddSpecialFun(CWarehouseArticle* cwha);

	//���ù�����Ʒ����ܼ۸�
	void Set_ShopBuyGoodsTotalPrice(float sbgtp);
	//��ȡ������Ʒ����ܼ۸�
	float Get_ShopBuyGoodsTotalPrice();

	//��ȡ��Ʒ�� ˮ��Դ��
	std::vector<CWarehouseArticle*> Get_WarehouseWaterVector();

	//��ȡ��Ʒ�� װ����
	std::vector<CWarehouseArticle*> Get_WarehouseEquipVector();

	//��ȡ��Ʒ�� ������߱�
	std::vector<CWarehouseArticle*> Get_WarehouseSpeProVector();
private:
	//��Ʒ�� ������Ʒ
	CWarehouseArticle * pwareArt;

	//(WATERRESOURCECLASS)ˮ��Դ����Ʒ vector��
	std::vector<CWarehouseArticle*> vecwater;

	//(EQUIPPEDWITHCLASS)װ������Ʒ vector��
	std::vector<CWarehouseArticle*> vecequ;

	//(SPECIALPROPS)�����������Ʒ vector��
	std::vector<CWarehouseArticle*> vecspe;

	//������Ʒ����ܼ۸�
	float ubuyGoodsTotalPrice;

};


#endif
