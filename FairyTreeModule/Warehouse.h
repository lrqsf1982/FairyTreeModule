#pragma once

#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "Gamedefine.h"
#include <map>


//��Ʒ���
enum EArticleCategory
{
	WATERRESOURCECLASS, //ˮ��Դ��
	EQUIPPEDWITHCLASS, //װ����
	SPECIALPROPS //���������
};

//��Ʒ��
class CWarehouseArticle
{
public:
	CWarehouseArticle();
	~CWarehouseArticle();

	//������Ʒ���
	void Set_CArticleSerialNumber(uint32 casn);
	//��ȡ��Ʒ���
	uint32 Get_CArticleSerialNumber();

private:
	//��Ʒ���
	uint32 m_artSerNum;

};


//�ֿ���
class Warehouse
{
public:
	Warehouse();
	~Warehouse();

	//������Ʒ
	void AddArticle(uint32 uid);
	//ɾ����Ʒ
	void CloseArticle(uint32 uid);

	
	//��ȡ��Ʒˮ��Դ������
	uint32 Get_ArticleToWaterCount();
	//��ȡ��Ʒװ��������
	uint32 Get_ArticleToEquipCount();
	//��ȡ��Ʒ������ߵ�����
	uint32 Get_ArticleToSepProCount();

	//��ȡ��Ʒmap
	std::map<uint32, CWarehouseArticle*> Get_ArticleMap();
private:
	CWarehouseArticle * wareArt;
	//��Ʒ���map
	std::map<uint32, CWarehouseArticle*> map_warehouse;

	//��¼��Ʒˮ��Դ������
	uint32 m_watNum;
	//��¼��Ʒװ��������
	uint32 m_equNum;
	//��¼��Ʒ������ߵ�����
	uint32 m_sepProNum;
};

#endif
