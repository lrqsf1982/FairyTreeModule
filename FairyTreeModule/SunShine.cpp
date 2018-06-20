#include "SunShine.h"
#include "XmlConfigManager.h"



CSunshine::CSunshine()
{
	m_lev = 1; //等级

	m_proCom = XmlConfigManager::GetInstance()->SunInfos[m_lev]->producompet; //阳光的产出能力

	m_num = 0; //阳光的数量
}


CSunshine::~CSunshine()
{
}


//设置等级
void CSunshine::Set_SunLevel(bool setgrad)
{
	if (setgrad)
	{
		m_lev += 1;
	}
}

//获取等级
uint32 CSunshine::Get_SunLevel()const
{
	return m_lev;
}

//设置阳光的产出能力
void CSunshine::Set_FSunProCom(uint32 setpro)
{
	//每次产出多少阳光
	m_proCom += setpro;
}

//获取阳光的产出能力
uint32 CSunshine::Get_FSunProCom()const
{
	return m_proCom;
}

//设置增加阳光的数量
void CSunshine::Set_FAddSunNumber(uint32 unum)
{
	m_num += unum;
}

//设置减少阳光的数量
void CSunshine::Set_FSubSunNum(uint32 unum)
{
	m_num -= unum;
}

//获取阳光的数量
uint32 CSunshine::Get_FSunNumber()const
{
	return m_num;
}