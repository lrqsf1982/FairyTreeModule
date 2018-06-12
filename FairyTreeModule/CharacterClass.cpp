#include "CharacterClass.h"



CharacterClass::CharacterClass()
{
	m_roleID = 0; //角色ID

	sroleName = ""; //角色名字

	urolegrowthvalue = 0; //角色成长值

	uharaHPSite = ""; //角色(haracter)的头像(HeadPortrait)地址(Site)

	utreeToGread = 0; //树的等级
}


CharacterClass::~CharacterClass()
{
}

//设置角色ID
void CharacterClass::Set_Role_ID(uint32 srid)
{
	m_roleID = srid;
}

//获取角色ID
uint32 CharacterClass::Get_Role_ID()
{
	return m_roleID;
}

//设置角色名字
void CharacterClass::Set_Role_Name(const std::string& srname)
{
	sroleName = srname;
}

//获取角色名字
std::string CharacterClass::Get_Role_Name()
{
	return sroleName;
}

//设置角色成长值
void CharacterClass::Set_RoleGrowthValue(uint32 srgv)
{
	urolegrowthvalue += srgv;
}

//获取角色成长值
uint32 CharacterClass::Get_RoleGrowthValue()
{
	return urolegrowthvalue;
}

//设置角色的头像地址
void CharacterClass::Set_HaracterHeadPortraitSite(const std::string& shps)
{
	uharaHPSite = shps;
}

//获取角色的头像地址
std::string CharacterClass::Get_HaracterHeadPortraitSite()
{
	return uharaHPSite;
}

//设置树的等级
void CharacterClass::Set_TreeToGread(uint32 sttg)
{
	utreeToGread = sttg;
}

//获取树的等级
uint32 CharacterClass::Get_TreeToGread()
{
	return utreeToGread;
}
