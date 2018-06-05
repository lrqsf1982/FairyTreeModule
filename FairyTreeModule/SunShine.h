#pragma once

#ifndef _FAIRY_WELL_H
#define _FAIRY_WELL_H

#include "define.h"


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
	void Set_FGrade(uint32 setgrad);
	//获取等级
	int Get_FGrade();

	//设置消耗阳光数量
	void Set_FSunCoNum(uint32 setfsun);
	//获取消耗阳光数量
	int Get_FSunCoNum();

	//设置消耗金币数量
	void Set_FCoGoldNum(uint32 setfco);
	//获取消耗金币数量
	int Get_FCoGoldNum();

	//设置阳光的产出能力
	void Set_FSunProCap(uint32 setpro);
	//获取阳光的产出能力
	int Get_FSunProCap();

	//设置阳光的生产时间
	void Set_FSunProTime(uint32 setftime);
	//获取阳光的生产时间
	int Get_FSunProTime();
private:
	//普通水
	uint32 fwater;

	//等级
	uint32 ufgrade;

	//消耗阳光数量
	uint32 ufCoSun;

	//消耗金币数量
	uint32 ufCoGold;

	//阳光的产出能力
	uint32 ufSunPCapa;

	//阳光的生产时间
	uint32 ufSunPTime;
};


#endif
