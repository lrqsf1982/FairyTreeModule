#include "Gold.h"



Gold::Gold()
{
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
int Gold::Get_GGoldNumber()
{
	return ugoldnumber;
}
