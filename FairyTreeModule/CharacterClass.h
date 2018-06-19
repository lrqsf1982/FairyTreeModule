#pragma once

#ifndef _CHARACTER_CLASS_H
#define _CHARACTER_CLASS_H

#include "Gamedefine.h"
#include <map>
#include <ace/OS_NS_sys_time.h>  
#include <ace/Date_Time.h> 

//��ɫ��
class CharacterClass
{
public:
	CharacterClass();
	~CharacterClass();

	//���ý�ɫID
	void Set_Role_ID(uint32 srid);
	//��ȡ��ɫID
	uint32 Get_Role_ID()const;

	//���ý�ɫ����
	void Set_Role_Name(const std::string& srname);
	//��ȡ��ɫ����
	std::string Get_Role_Name() const;

	//���ý�ɫ�ɳ�ֵ
	void Set_RoleGrowthValue(uint32 srgv);
	//��ȡ��ɫ�ɳ�ֵ
	uint32 Get_RoleGrowthValue()const;

	//���ý�ɫ��ͷ���ַ
	void Set_HaracterHeadPortraitSite(const std::string& shps);
	//��ȡ��ɫ��ͷ���ַ
	std::string Get_HaracterHeadPortraitSite()const;

	//�������ĵȼ�
	void Set_TreeToGread(uint32 sttg);
	//��ȡ���ĵȼ�
	uint32 Get_TreeToGread()const;

	//����ʱ��
	ACE_Date_Time m_disconnecttime;
private:
	//��ɫID
	uint32 m_roleID;

	//��ɫ����
	std::string sroleName;

	//��ɫ�ɳ�ֵ
	uint32 urolegrowthvalue;

	//��ɫ(haracter)��ͷ��(HeadPortrait)��ַ(Site)
	std::string uharaHPSite;

	//���ĵȼ�
	uint32 utreeToGread;
};


#endif

