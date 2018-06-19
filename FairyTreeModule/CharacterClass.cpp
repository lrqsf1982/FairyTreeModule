#include "CharacterClass.h"



CharacterClass::CharacterClass()
{
	m_roleID = 0; //��ɫID

	sroleName = ""; //��ɫ����

	urolegrowthvalue = 0; //��ɫ�ɳ�ֵ

	uharaHPSite = ""; //��ɫ(haracter)��ͷ��(HeadPortrait)��ַ(Site)

	utreeToGread = 0; //���ĵȼ�
}


CharacterClass::~CharacterClass()
{
}

//���ý�ɫID
void CharacterClass::Set_Role_ID(uint32 srid)
{
	m_roleID = srid;
}

//��ȡ��ɫID
uint32 CharacterClass::Get_Role_ID()const
{
	return m_roleID;
}

//���ý�ɫ����
void CharacterClass::Set_Role_Name(const std::string& srname)
{
	sroleName = srname;
}

//��ȡ��ɫ����
std::string CharacterClass::Get_Role_Name()const
{
	return sroleName;
}

//���ý�ɫ�ɳ�ֵ
void CharacterClass::Set_RoleGrowthValue(uint32 srgv)
{
	urolegrowthvalue += srgv;
}

//��ȡ��ɫ�ɳ�ֵ
uint32 CharacterClass::Get_RoleGrowthValue()const
{
	return urolegrowthvalue;
}

//���ý�ɫ��ͷ���ַ
void CharacterClass::Set_HaracterHeadPortraitSite(const std::string& shps)
{
	uharaHPSite = shps;
}

//��ȡ��ɫ��ͷ���ַ
std::string CharacterClass::Get_HaracterHeadPortraitSite()const
{
	return uharaHPSite;
}

//�������ĵȼ�
void CharacterClass::Set_TreeToGread(uint32 sttg)
{
	utreeToGread = sttg;
}

//��ȡ���ĵȼ�
uint32 CharacterClass::Get_TreeToGread()const
{
	return utreeToGread;
}

