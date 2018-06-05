#include "Water.h"



Water::Water()
{
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
int Water::Get_WOrdinaryWater()
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
int Water::Get_WFairyWater()
{
	return ufairywater;
}
