#include "CharacterClass.h"



CharacterClass::CharacterClass()
{
	uroleID = 0; //角色ID

	sroleName = ""; //角色名字

	urolelevel = 0; //角色等级

	urolegrowthvalue = 0; //角色成长值
}


CharacterClass::~CharacterClass()
{
}

//设置角色ID
void CharacterClass::Set_Role_ID(uint32 srid)
{
	uroleID = srid;
}

//获取角色ID
int CharacterClass::Get_Role_ID()
{
	return uroleID;
}

//设置角色名字
void CharacterClass::Set_Role_Name(std::string srname)
{
	sroleName = srname;
}

//获取角色名字
string CharacterClass::Get_Role_Name()
{
	return sroleName;
}

//设置角色等级
void CharacterClass::Set_RoleLevel(uint32 srl)
{
	urolelevel += srl;
}

//获取角色等级
int CharacterClass::Get_RoleLevel()
{
	return urolelevel;
}

//设置角色成长值
void CharacterClass::Set_RoleGrowthValue(uint32 srgv)
{
	urolegrowthvalue += srgv;
}

//获取角色成长值
int CharacterClass::Get_RoleGrowthValue()
{
	return urolegrowthvalue;
}
