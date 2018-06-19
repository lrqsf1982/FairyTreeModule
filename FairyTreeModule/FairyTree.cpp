#include "FairyTree.h"
#include "XmlConfigManager.h"



FairyTree::FairyTree()
{
	m_lev = 1;//�ȼ�

	m_hei = 1;//���� = �ȼ�

	m_goldPro = XmlConfigManager::GetInstance()->TreeInfos[m_lev]->productivity;//�����Ľ��

	m_goldProTime = 0; //������ҵ�ʱ��

	m_treStoGol = 0;//�������洢���
		  
}


FairyTree::~FairyTree()
{
}

//���õȼ� 
void FairyTree::Set_FGrade(bool fgr)
{
	
	if (fgr)
	{
		//�ȼ�����һ��
		m_lev += 1;

		//������ҵ�����������
		Set_FGold(0);
		//��������
		Set_TreeHeight(m_goldPro);

	}
	
}

//��ȡ�ȼ�
uint32 FairyTree::Get_FGrade()
{
	return m_lev;
}

//��������
void FairyTree::Set_TreeHeight(uint32 sth)
{
	m_hei = sth;
}

//��ȡ����
uint32 FairyTree::Get_TreeHeight()
{
	return m_hei;
}

//���������Ľ�� 
void FairyTree::Set_FGold(uint32 fgo)
{
	//���ĵȼ�ÿ����һ�� ������ҵ����������� �̶�ֵ
	m_goldPro += fgo;
}

//��ȡ�����Ľ��
uint32 FairyTree::Get_FGold()
{
	//ÿ���һ�ν�� �ͽ���Ҵ�Ž� ����
	Set_FAddFaiTreStoGol(m_goldPro);

	return m_goldPro;
}

//����������ҵ�ʱ��
void FairyTree::Set_FGoldTime(uint32 ufgt)
{
	//���ĵȼ�ÿ����һ�� ������ҵ�ʱ�� �Ƿ���Ҫ���� �̶�ʱ��
	m_goldProTime += ufgt;
}

//��ȡ������ҵ�ʱ��
uint32 FairyTree::Get_FGoldTime()
{
	return m_goldProTime;
}

//�������洢���
void FairyTree::Set_FAddFaiTreStoGol(uint32 ufftsg)
{
	//���Ĵ洢����Ƿ���Ҫ����
	//���ĵȼ�ÿ����һ�� �Ƿ���Ҫ�� ���Ĵ洢������� �̶�ֵ
	m_treStoGol += ufftsg;
}

//���ü������洢���
void FairyTree::Set_FMinusFaiTreStoGol(uint32 ufmftsg)
{
	//�����ý�ҹ�����Ʒ��ʱ�� �洢�Ľ�Ҿ� ����(����Ʒ�ļ۸�,������)
	m_treStoGol -= ufmftsg;
}

//��ȡ���洢���
uint32 FairyTree::Get_FFaiTreStoGol()
{
	//�õ��ܴ洢�Ľ������
	return m_treStoGol;
}


