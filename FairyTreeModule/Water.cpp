#include "Water.h"



Water::Water()
{
	m_roleID = 0;//用户ID
	uordinarywater = 0; //普通水
	ufairywater = 0; //神仙水
}


Water::~Water()
{
}

//设置增加普通水的数量
void Water::Set_WAddOrdinaryWater(uint32 sow)
{
	uordinarywater += sow;
}

//设置减少普通水的数量
void Water::Set_ReduceOrdinaryWater(uint32 srow)
{
	uordinarywater -= srow;
}

//获取普通水的数量
uint32 Water::Get_WOrdinaryWater()
{
	return uordinarywater;
}

//设置增加神仙水的数量
void Water::Set_WAddFairyWater(uint32 sfw)
{
	ufairywater += sfw;
}

//设置减少神仙水的数量
void Water::Set_WReduceFairyWater(uint32 sfw)
{
	ufairywater -= sfw;
}

//获取神仙水的数量
uint32 Water::Get_WFairyWater()
{
	return ufairywater;
}

//设置用户ID
void Water::Set_RoleID(uint32 uid)
{
	m_roleID = uid;//用户ID
}

//获取用户ID
uint32 Water::Get_RoleID()
{
	return m_roleID;
}
