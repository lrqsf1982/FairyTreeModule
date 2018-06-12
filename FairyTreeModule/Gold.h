#pragma once

#ifndef _GOLD_H
#define _GOLD_H

#include "Gamedefine.h"
#include <map>

//金币类
class Gold
{
public:
	Gold();
	~Gold();
	//设置增加金币的数量
	void Set_GAddGoldNumber(uint32 ggn);
	//设置减少金币的数量
	void Set_GReduceGoldNumber(uint32 grgn);
	//获取金币的数量
	uint32 Get_GGoldNumber();

	//设置用户ID
	void Set_RoleID(uint32 uid);
	//获取用户ID
	int Get_RoleID();

	//金币类map
	std::map<uint32, Gold*> map_gold;
private:

	//用户ID
	uint32 m_roleID;

	//金币的数量
	uint32 ugoldnumber;
};

#endif
