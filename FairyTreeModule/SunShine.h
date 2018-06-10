#pragma once

#ifndef _FAIRY_WELL_H
#define _FAIRY_WELL_H

#include "define.h"
#include <map>

#define SOLARPROCAP 10 //太阳的生产能力


//太阳类 读取阳光Xml文件
class CSunshine
{
public:
	CSunshine();
	~CSunshine();
	//设置增加普通水
	void Set_FAddWater(uint32 fwa);
	//设置减少普通水
	void Set_FMinusWater(uint32 ufmw);
	//获取普通水
	int Get_FWater();

	//设置等级
	void Set_FGrade(bool setgrad);
	//获取等级
	int Get_FGrade();

	//设置阳光的产出能力
	void Set_FSunProCap(uint32 setpro);
	//获取阳光的产出能力
	int Get_FSunProCap();

	//设置阳光的生产时间
	void Set_FSunProTime(uint32 setftime);
	//获取阳光的生产时间
	int Get_FSunProTime();

	//设置增加阳光的数量
	void Set_FAddSunNumber(uint32 unum);
	//设置减少阳光的数量
	void Set_FSubSunNum(uint32 unum);
	//获取阳光的数量
	int Get_FSunNumber();

	//设置消耗水的数量
	void Set_SunCoWaterNum(uint32 num);
	//获取消耗水的数量
	int Get_SunCoWaterNum();

	//设置阳光数量消耗
	void Set_SunCoSunNum(uint32 num);
	//获取阳光数量消耗
	int Get_SunCoSunNum();

	//设置金币数量消耗
	void Set_SunCoGoldNum(uint32 num);
	//获取金币数量消耗
	int Get_SunCoGoldNum();

	//设置钻石数量消耗
	void Set_SunCoJewelNum(uint32 num);
	//获取钻石数量消耗
	int Get_SunCoJewelNum();

	//太阳的map
	std::map<uint32, CSunshine*> map_sunshine;
private:
	//普通水
	uint32 fwater;

	//等级
	uint32 ufgrade;

	//阳光的产出能力
	uint32 ufSunPCapa;

	//阳光的生产时间
	uint32 ufSunPTime;

	//阳光的数量
	uint32 usunnum;

	//消耗水的数量
	uint32 ucowaternum;
	//阳光数量消耗
	uint32 ucosunnum;
	//金币数量消耗
	uint32 ucogoldnum;
	//钻石数量消耗
	uint32 ucojewel;
};


#endif
