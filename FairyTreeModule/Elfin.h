#pragma once

#ifndef _ELFIN_H
#define _ELFIN_H

#include "Skill.h"
#include "Gamedefine.h"
#include <vector>

enum ElfinSkillType//��������
{
	EGOLD = 0,   //��
	EWOOD,		 //ľ
	EWATER,		 //ˮ
	EFIRE,		 //��
	ESOIL		 //��
	//EDARK		 //��
};

enum ElfinState//С����״̬
{
	FREETIME = 0,			//����
	WATERING,				//��ˮ
	PLUNDER,				//�Ӷ�
	PLANT,					//����
};
//С������
class Elfin
{
public:
	Elfin();
	~Elfin();
	//������Ӽ��ܸ�
	void Set_ESkillStyle(CSkill* ecsk);
	//����ɾ������
	void Set_EReduceSkillStyle(uint32 iderss);
	//��ȡ���ܸ�
	ElfinSkillType Get_ESkillStyle()const;

	//���õȼ�
	void Set_EGrade(uint32 beg);
	//��ȡ�ȼ�
	uint32 Get_EGrade()const;

	//������������
	void Set_EAddPhysicalPower(uint32 ueap);
	//���ü�������
	void Set_EReducePhysicalPower(uint32 uerp);

	//��ȡ��ǰ����
	uint32 Get_EPhysicalPower()const;

	//�����������
	void Set_EMaxPhysicalPower(uint32 uempp);
	//��ȡ�������
	uint32 Get_EMaxPhysicalPower()const;

	//�����������С�����ID
	uint32 Set_Get_EToID(ElfinSkillType m_type);
	//��ȡС�����ID
	uint32 Get_EToID()const;


	//��ȡ������
	CSkill* Get_CSkillClass()const;
	//�����Ӷ�״̬
	//void	m_uPlunderState(ElfinState state);
	//����Ӷ�

private:

	CSkill * m_skill;
	//���ܸ�(���)
	std::vector<CSkill*> m_vecSki;
	
	//С�����ID
	uint32 m_id;

	//��Ʒ(Ԥ��)
	//----------

	//�ȼ�
	uint32 m_level;

	//����
	uint32 m_curPhyPower;
	//�������
	uint32 m_maxphyPower;

	//ö�����͵ļ�������
	ElfinSkillType m_type;


	//bool	 m_uPlunderState;					//С�����Ӷ�״̬
	//UINT32	 m_uBePlunderId;					//���Ӷ���ID
	//UINT32	 m_uPlunderGoldNum;					//�Ѿ��Ӷ�Ľ������
	//����(�������¼���)
	//1:��(��һ���� ������) 2:ľ(��һ���� ������Ч�ʸ���) 3:ˮ(��һ���� ��ˮ)
	//4:��(��һ���� �ó��Ӷ�������ҽ�ң�����Ϊ����5��) 5:��(��һ���� �ܿ�����) 6:��(����)
};


#endif

