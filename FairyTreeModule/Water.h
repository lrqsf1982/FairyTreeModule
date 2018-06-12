#pragma once

#ifndef _WATER_H
#define _WATER_H

#include "Gamedefine.h"
#include <map>


//水资源类
class Water
{
public:
	Water();
	~Water();
	//设置增加普通水的数量
	void Set_WAddOrdinaryWater(uint32 sow);
	//设置减少普通水的数量
	void Set_ReduceOrdinaryWater(uint32 srow);
	//获取普通水的数量
	uint32 Get_WOrdinaryWater();

	//设置增加神仙水的数量
	void Set_WAddFairyWater(uint32 sfw);
	//设置减少神仙水的数量
	void Set_WReduceFairyWater(uint32 sfw);
	//获取神仙水的数量
	uint32 Get_WFairyWater();

	//设置用户ID
	void Set_RoleID(uint32 uid);
	//获取用户ID
	uint32 Get_RoleID();

	//水资源的map
	std::map<uint32, Water*> map_water;
private:

	//用户ID
	uint32 m_roleID;

	//普通水
	uint32 uordinarywater;

	//神仙水
	uint32 ufairywater;

};

#endif
