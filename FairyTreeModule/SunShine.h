#pragma once

#ifndef _FAIRY_WELL_H
#define _FAIRY_WELL_H

#include "Gamedefine.h"
#include <map>


//太阳类 读取阳光Xml文件
class CSunshine
{
public:
	CSunshine();
	~CSunshine();

	//设置等级
	void Set_SunLevel(bool setgrad);
	//获取等级
	uint32 Get_SunLevel();

	//设置阳光的产出能力
	void Set_FSunProCom(uint32 setpro);
	//获取阳光的产出能力
	uint32 Get_FSunProCom();

	//设置增加阳光的数量
	void Set_FAddSunNumber(uint32 unum);
	//设置减少阳光的数量
	void Set_FSubSunNum(uint32 unum);
	//获取阳光的数量
	uint32 Get_FSunNumber();
private:

	//等级
	uint32 m_lev;

	//阳光的产出能力
	uint32 m_proCom;

	//阳光的数量
	uint32 m_num;
};


#endif
