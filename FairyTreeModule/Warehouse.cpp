#include "Warehouse.h"


//��Ʒ��
CWarehouseArticle::CWarehouseArticle()
{
	m_artSerNum = 0; //��Ʒ���
}

CWarehouseArticle::~CWarehouseArticle()
{
}

//������Ʒ���
void CWarehouseArticle::Set_CArticleSerialNumber(uint32 casn)
{
	m_artSerNum = casn;
}

//��ȡ��Ʒ���
uint32 CWarehouseArticle::Get_CArticleSerialNumber()
{
	return m_artSerNum;
}

//�ֿ���
Warehouse::Warehouse()
{

	m_watNum = 0; //��¼��Ʒˮ��Դ������

	m_equNum = 0; //��¼��Ʒװ��������

	m_sepProNum = 0; //��¼��Ʒ������ߵ�����

	wareArt = new CWarehouseArticle;
}


Warehouse::~Warehouse()
{
	delete wareArt;
	wareArt = NULL;
}

//������Ʒ
void Warehouse::AddArticle(uint32 uid)
{
	//ˮ��Դ��id
	uint32 uwater = 10001;
	//װ����id
	uint32 uequip = 10002;
	//������ߵ�id
	uint32 useppro = 10003;
	if (map_warehouse[uid]->Get_CArticleSerialNumber() == uwater)
	{
		map_warehouse[uid] = wareArt;
		m_watNum += 1;
	}
	if (map_warehouse[uid]->Get_CArticleSerialNumber() == uequip)
	{
		map_warehouse[uid] = wareArt;
		m_equNum += 1;
	}
	if (map_warehouse[uid]->Get_CArticleSerialNumber() == useppro)
	{
		map_warehouse[uid] = wareArt;
		m_sepProNum += 1;
	}
	
	
}

//ɾ����Ʒ ͨ����Ʒ���
void Warehouse::CloseArticle(uint32 cloart)
{
	//ͨ����Ʒ��� ���ұ�����Ķ�Ӧ����
	for (std::map<uint32, CWarehouseArticle*>::iterator it = map_warehouse.begin(); it != map_warehouse.end(); it++)
	{
		if (cloart == it->second->Get_CArticleSerialNumber())
		{
			map_warehouse.erase(it);
		}
	}

}

//��ȡ��Ʒˮ��Դ������
uint32 Warehouse::Get_ArticleToWaterCount()
{
	return m_watNum;
}

//��ȡ��Ʒװ��������
uint32 Warehouse::Get_ArticleToEquipCount()
{
	return m_equNum;
}

//��ȡ��Ʒ������ߵ�����
uint32 Warehouse::Get_ArticleToSepProCount()
{
	return m_sepProNum;
}

//��ȡ��Ʒmap
std::map<uint32, CWarehouseArticle*> Warehouse::Get_ArticleMap()
{
	return map_warehouse;
}