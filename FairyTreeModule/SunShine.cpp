#include "SunShine.h"



CSunshine::CSunshine()
{
	fwater = 0; //普通水

	ufgrade = 0; //等级

	ufSunPCapa = 0; //阳光的产出能力

	ufSunPTime = 0; //阳光的生产时间

	usunnum = 0; //阳光的数量
	 
	ucowaternum = 0;//消耗水的数量
	
	ucosunnum = 0;//阳光数量消耗
	
	ucogoldnum = 0;//金币数量消耗
	
	ucojewel = 0;//钻石数量消耗
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
void CSunshine::Set_FGrade(bool setgrad)
{
	if (setgrad)
	{
		ufgrade += 1;

		//太阳每增加一级 产出能力也会增加
		Set_FSunProCap(SOLARPROCAP);

		//那么升级所需要的物品数量也会增加
	}

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

//设置消耗水的数量
void CSunshine::Set_SunCoWaterNum(uint32 num)
{
	ucowaternum = num;
}

//获取消耗水的数量
int CSunshine::Get_SunCoWaterNum()
{
	return ucowaternum;
}

//设置阳光数量消耗
void CSunshine::Set_SunCoSunNum(uint32 num)
{
	ucosunnum = num;
}

//获取阳光数量消耗
int CSunshine::Get_SunCoSunNum()
{
	return ucosunnum;
}

//设置金币数量消耗
void CSunshine::Set_SunCoGoldNum(uint32 num)
{
	ucogoldnum = num;
}

//获取金币数量消耗
int CSunshine::Get_SunCoGoldNum()
{
	return ucogoldnum;
}

//设置钻石数量消耗
void CSunshine::Set_SunCoJewelNum(uint32 num)
{
	ucojewel = num;
}

//获取钻石数量消耗
int CSunshine::Get_SunCoJewelNum()
{
	return ucojewel;
}


