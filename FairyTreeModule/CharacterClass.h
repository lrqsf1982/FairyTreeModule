#pragma once

#ifndef _CHARACTER_CLASS_H
#define _CHARACTER_CLASS_H

#include "Gamedefine.h"
#include <map>
#include <ace/OS_NS_sys_time.h>  
#include <ace/Date_Time.h> 

//角色类
class CharacterClass
{
public:
	CharacterClass();
	~CharacterClass();

	//设置角色ID
	void Set_Role_ID(uint32 srid);
	//获取角色ID
	uint32 Get_Role_ID()const;

	//设置角色名字
	void Set_Role_Name(const std::string& srname);
	//获取角色名字
	std::string Get_Role_Name() const;

	//设置角色成长值
	void Set_RoleGrowthValue(uint32 srgv);
	//获取角色成长值
	uint32 Get_RoleGrowthValue()const;

	//设置角色的头像地址
	void Set_HaracterHeadPortraitSite(const std::string& shps);
	//获取角色的头像地址
	std::string Get_HaracterHeadPortraitSite()const;

	//设置树的等级
	void Set_TreeToGread(uint32 sttg);
	//获取树的等级
	uint32 Get_TreeToGread()const;

	//离线时间
	ACE_Date_Time m_disconnecttime;
private:
	//角色ID
	uint32 m_roleID;

	//角色名字
	std::string sroleName;

	//角色成长值
	uint32 urolegrowthvalue;

	//角色(haracter)的头像(HeadPortrait)地址(Site)
	std::string uharaHPSite;

	//树的等级
	uint32 utreeToGread;
};


#endif

