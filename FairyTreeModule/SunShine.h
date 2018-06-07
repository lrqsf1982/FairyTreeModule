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

	//阳光的数量
	uint32 usunnum;
};


#endif
