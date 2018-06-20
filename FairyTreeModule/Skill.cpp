#pragma once

#include "Skill.h"

CSkill::CSkill()
{
	m_type = INITIATIVE; //��������

	m_Level = 0; //���ܵȼ�

	m_id = 0; //����ID
}

CSkill::~CSkill()
{
}

//���ü�������
void CSkill::Set_Skill_Type(uint32 sst)
{
	switch (sst)
	{
	case 0: {m_type = INITIATIVE; break; }
	case 1: {m_type = PASSIVITY; break; }
	}
}

//��ȡ��������
SkillType CSkill::Get_Skill_Type()
{
	return m_type;
}

//���ü��ܵȼ�
void CSkill::Set_Skill_Level(bool ssl)
{
	if (ssl)
	{
		//���ӵȼ�
		m_Level += 1;
	}
	
}

//��ȡ���ܵȼ�
uint32 CSkill::Get_Skill_Level()
{
	return m_Level;
}

//���ü���ID
void CSkill::Set_Skill_ID(uint32 ssid)
{
	m_id = ssid;
}

//��ȡ����ID
uint32 CSkill::Get_Skill_ID()
{
	return m_id;
}