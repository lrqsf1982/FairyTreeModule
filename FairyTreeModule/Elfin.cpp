#include "Elfin.h"



Elfin::Elfin()
{
	uEid = 0;//小精灵的ID

	_egrade = 0;//等级

	_ephysicalpower = SEGMAXPHYSICALPOWER;//体力 初始化体力为最大

	_emaxphysicalpower = SEGMAXPHYSICALPOWER;//最大体力

	estype = EGOLD;//枚举类型的技能属性
}


Elfin::~Elfin()
{
}

//设置添加技能格
void Elfin::Set_ESkillStyle(CSkill* ecsk)
{
	vec.push_back(ecsk);
}

//设置删除技能
void Elfin::Set_EReduceSkillStyle(uint32 iderss)
{

	//通过下标 查找对应的数据
	for (std::vector<CSkill*>::iterator itskill = vec.begin(); itskill != vec.end(); itskill++)
	{
		if (iderss == (*itskill)->Get_Skill_ID())
		{
			//找到 删除
			vec.erase(itskill);
		}
	}

}

//获取技能格
int Elfin::Get_ESkillStyle()
{
	//随机设置一个技能
	srand((uint32)time(0));
	rand();
	uint32 ucount = rand() % 5 + 0;
	switch (ucount)
	{
	case 0: {estype = EGOLD; break; }
	case 1: {estype = EWOOD; break;}
	case 2: {estype = EWATER; break; }
	case 3: {estype = EFIRE; break; }
	case 4: {estype = ESOIL; break; }
	}

	//返回技能
	return estype;
}

//设置等级
void Elfin::Set_EGrade(bool beg)
{
	if (beg)
	{
		_egrade += 1;

		//每增加一级 最大体力值就增加指定值
		Set_EMaxPhysicalPower(SEGMAXPHYSICALPOWER);

	}
}

//获取等级
int Elfin::Get_EGrade()
{
	return _egrade;
}

//设置增加体力
void Elfin::Set_EAddPhysicalPower(uint32 ueap)
{
	//如果当前体力值小于最大体力值
	if (_ephysicalpower < _emaxphysicalpower)
	{
		_ephysicalpower += ueap;
		//如果当前体力值大于最大体力值 那么当前体力值就等于最大体力值
		if (_ephysicalpower > _emaxphysicalpower)
		{
			_ephysicalpower = _emaxphysicalpower;
		}
	}
		
}

//设置减少体力
void Elfin::Set_EReducePhysicalPower(uint32 uerp)
{
	_ephysicalpower -= uerp;
	//如果当前体力 小于 0 那么当前体力值就等于0
	if (_ephysicalpower < 0)
	{
		_ephysicalpower = 0;
	}
}

//获取当前体力
int Elfin::Get_EPhysicalPower()
{
	return _ephysicalpower;
}

//设置最大体力
void Elfin::Set_EMaxPhysicalPower(uint32 uempp)
{
	//小精灵每升一级,最大体力就会相应增加
	_emaxphysicalpower += uempp;
}

//获取最大体力
int Elfin::Get_EMaxPhysicalPower()
{
	return _emaxphysicalpower;
}

//设置小精灵的ID
void Elfin::Set_EToID(uint32 etoid)
{
	uEid = etoid;
}

//获取小精灵的ID
int Elfin::Get_ID()
{
	return uEid;
}

