#include "Gold.h"



Gold::Gold()
{
	m_roleID = 0;//用户ID

	ugoldnumber = 0; //金币的数量
}


Gold::~Gold()
{
}

//设置增加金币的数量
void Gold::Set_GAddGoldNumber(uint32 ggn)
{
	ugoldnumber += ggn;
}

//设置减少金币的数量
void Gold::Set_GReduceGoldNumber(uint32 grgn)
{
	ugoldnumber -= grgn;
}

//获取金币的数量
uint32 Gold::Get_GGoldNumber()
{
	return ugoldnumber;
}

//设置用户ID
void Gold::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//获取用户ID
int Gold::Get_RoleID()
{
	return m_roleID;
}
