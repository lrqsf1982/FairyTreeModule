#pragma once
#ifndef _FAIRY_TREE_H
#define _FAIRY_TREE_H

#include "Gamedefine.h"
#include "CharacterClass.h"

//������(FairyTree)�ܹ�����(store)���(gold)�����(max)��(number)
//#define FAIRYTREESTOREMAXNUMBER  1000


//��������
class FairyTree
{
public:

	FairyTree();

	~FairyTree();

	//���õȼ�
	void Set_FGrade(bool fgr);

	// ��ȡ�ȼ�
	uint32 Get_FGrade()const;

	//��������
	void Set_TreeHeight(uint32 sth);

	//��ȡ����
	uint32 Get_TreeHeight()const;

	//���������Ľ�� 
	void Set_FGold(uint32 fgo);

	//��ȡ���
	uint32 Get_FGold()const;

	//����������ҵ�ʱ��
	void Set_FGoldTime(uint32 ufgt);

	//��ȡʱ��
	uint32 Get_FGoldTime()const;

	//�����������洢���
	void Set_FAddFaiTreStoGol(uint32 ufftsg);

	//���ü������洢���
	void Set_FMinusFaiTreStoGol(uint32 ufmftsg);

	//��ȡ���洢���
	uint32 Get_FFaiTreStoGol()const;

private:

	//�ȼ�
	uint32 m_lev;

	//���� = �ȼ�
	uint32 m_hei;

	//������ҵ�ʱ��
	uint32 m_goldProTime;

	//�������洢���
	uint32 m_treStoGol;

	//���������
	uint32 m_goldPro;

};
#endif