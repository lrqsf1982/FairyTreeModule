#pragma once

#ifndef _CHARACTER_CLASS_H
#define _CHARACTER_CLASS_H

#include "define.h"
#include <map>

//角色类
class CharacterClass
{
public:
	CharacterClass();
	~CharacterClass();

	//设置角色ID
	void Set_Role_ID(uint32 srid);
	//获取角色ID
	int Get_Role_ID();

	//设置角色名字
	void Set_Role_Name(std::string srname);
	//获取角色名字
	string Get_Role_Name();

	//设置角色成长值
	void Set_RoleGrowthValue(uint32 srgv);
	//获取角色成长值
	int Get_RoleGrowthValue();

	//角色类map
	std::map<uint32, CharacterClass*> map_haracter;
private:
	//角色ID
	uint32 uroleID;

	//角色名字
	std::string sroleName;

	//角色成长值
	uint32 urolegrowthvalue;

};


#endif

