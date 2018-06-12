#include "Elfin.h"
#include <stdlib.h>
#include <time.h>

std::map<uint32, Elfin*> Elfin::map_elfin;

Elfin::Elfin()
{
	m_roleID = 0;//用户ID

	uEid = 0;//小精灵的ID

	_egrade = 0;//等级

	_ephysicalpower = SEGMAXPHYSICALPOWER;//体力 初始化体力为最大

	_emaxphysicalpower = SEGMAXPHYSICALPOWER;//最大体力

	estype = ElfinType::EGOLD;//枚举类型的技能属性

	ucowaternum = 0;//消耗水的数量
	
	ucosunnum = 0;//阳光数量消耗
	
	ucogoldnum = 0;//金币数量消耗
	
	ujewelnum = 0;//钻石消耗数量

	cskill = new CSkill;
}


Elfin::~Elfin()
{
	delete cskill;
}

//设置添加技能格
void Elfin::Set_ESkillStyle(CSkill* ecsk)
{
	vec.push_back(ecsk);
}

//设置删除技能 (也就是遗忘技能)
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
ElfinType Elfin::Get_ESkillStyle()
{
	//随机设置一个技能
	srand(time(NULL));
	ElfinType etype = (ElfinType)(rand() % 5);

	//返回技能
	return etype;
}

//设置等级
void Elfin::Set_EGrade(uint32 beg)
{
	
	_egrade += beg;

	//每增加一级 最大体力值就增加指定值
	Set_EMaxPhysicalPower(SEGMAXPHYSICALPOWER);

	
}

//获取等级
uint32 Elfin::Get_EGrade()
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
uint32 Elfin::Get_EPhysicalPower()
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
uint32 Elfin::Get_EMaxPhysicalPower()
{
	return _emaxphysicalpower;
}

//设置小精灵的ID
void Elfin::Set_EToID(uint32 etoid)
{
	uEid = etoid;
}

//获取小精灵的ID
uint32 Elfin::Get_ID()
{
	return uEid;
}

//设置消耗水的数量
void Elfin::Set_uCoWaterNum(uint32 num)
{
	ucowaternum = num;
}

//获取消耗水的数量
uint32 Elfin::Get_uCoWaterNum()
{
	return ucowaternum;
}

//设置阳光数量消耗
void Elfin::Set_uCoSunNum(uint32 num)
{
	ucosunnum = num;
}

//获取阳光数量消耗
uint32 Elfin::Get_uCoSunNum()
{
	return ucosunnum;
}

//设置金币数量消耗
void Elfin::Set_uCoGoldNum(uint32 num)
{
	ucogoldnum = num;
}

//获取金币数量消耗
uint32 Elfin::Get_uCoGoldNum()
{
	return ucogoldnum;
}

//设置钻石消耗数量
void Elfin::Set_uCoJewelNum(uint32 num)
{
	ujewelnum = num;
}

//获取钻石消耗数量
uint32 Elfin::Get_uCoJewelNum()
{
	return ujewelnum;
}

//设置用户ID
void Elfin::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//获取用户ID
uint32 Elfin::Get_RoleID()
{
	return 0;
}

