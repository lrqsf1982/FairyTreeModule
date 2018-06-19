#pragma once

#ifndef _SKILL_H
#define _SKILL_H

#include "Gamedefine.h"

//��������
enum SkillType
{
	INITIATIVE, //����
	PASSIVITY   //����
};

class CSkill
{
public:
	CSkill();
	~CSkill();
	//���ü�������
	void Set_Skill_Type(uint32 sst);
	//��ȡ��������
	SkillType Get_Skill_Type();

	//���ü��ܵȼ�
	void Set_Skill_Level(bool ssl);
	//��ȡ���ܵȼ�
	uint32 Get_Skill_Level();

	//���ü���ID
	void Set_Skill_ID(uint32 ssid);
	//��ȡ����ID
	uint32 Get_Skill_ID();

private:
	//��������
	SkillType m_type;

	//���ܵȼ�
	uint32 m_Level;

	//����ID
	uint32 m_id;

};


#endif

