#include "SunShine.h"



CSunshine::CSunshine()
{
	fwater = 0; //普通水

	ufgrade = 0; //等级

	ufCoSun = 0; //消耗阳光数量

	ufCoGold = 0; //消耗金币数量

	ufSunPCapa = 0; //阳光的产出能力

	ufSunPTime = 0; //阳光的生产时间

	usunnum = 0; //阳光的数量
}


CSunshine::~CSunshine()
{
}

//设置增加普通水
void CSunshine::Set_FAddWater(uint32 fwa)
{
	//如果有购买普通水 或者 神仙井有生产普通水 普通水的数量就增加
	fwater += fwa;
}

//设置减少普通水
void CSunshine::Set_FMinusWater(uint32 ufmw)
{
	//如果有使用普通水 普通水的数量就减少
	fwater -= ufmw;
}

//获取普通水
int CSunshine::Get_FWater()
{
	//最终普通水的数量
	return fwater;
}


//设置等级
void CSunshine::Set_FGrade(uint32 setgrad)
{
	ufgrade = setgrad;
}

//获取等级
int CSunshine::Get_FGrade()
{
	return ufgrade;
}

//设置阳光的产出能力
void CSunshine::Set_FSunProCap(uint32 setpro)
{
	ufSunPCapa += setpro;
}

//获取阳光的产出能力
int CSunshine::Get_FSunProCap()
{
	return ufSunPCapa;
}

//设置阳光的生产时间
void CSunshine::Set_FSunProTime(uint32 setftime)
{
	ufSunPTime = setftime;
}

//获取阳光的生产时间
int CSunshine::Get_FSunProTime()
{
	return ufSunPTime;
}

//设置增加阳光的数量
void CSunshine::Set_FAddSunNumber(uint32 unum)
{
	usunnum += unum;
}

//设置减少阳光的数量
void CSunshine::Set_FSubSunNum(uint32 unum)
{
	usunnum -= unum;
}

//获取阳光的数量
int CSunshine::Get_FSunNumber()
{
	return usunnum;
}


