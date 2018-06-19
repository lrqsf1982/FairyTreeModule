#include "Elfin.h"
#include "XmlConfigManager.h"
#include <stdlib.h>
#include <time.h>


Elfin::Elfin()
{
	m_type = Get_ESkillStyle();//枚举类型的技能属性

	m_id = Set_Get_EToID(m_type);//小精灵的ID

	m_level = 1;//等级

	m_maxphyPower = XmlConfigManager::GetInstance()->ElfinInfos[m_level]->physicalilmit;//最大体力

	m_curPhyPower = m_maxphyPower;//体力 初始化体力为最大
	
	m_skill = new CSkill;
}


Elfin::~Elfin()
{
	delete m_skill;
	m_skill = nullptr;
}

//设置添加技能格
void Elfin::Set_ESkillStyle(CSkill* ecsk)
{
	m_vecSki.push_back(ecsk);
}

//设置删除技能 (也就是遗忘技能)
void Elfin::Set_EReduceSkillStyle(uint32 iderss)
{

	//通过下标 查找对应的数据
	for (std::vector<CSkill*>::iterator itskill = m_vecSki.begin(); itskill != m_vecSki.end(); itskill++)
	{
		if (iderss == (*itskill)->Get_Skill_ID())
		{
			//找到 删除
			m_vecSki.erase(itskill);
		}
	}

}

//获取技能格
ElfinSkillType Elfin::Get_ESkillStyle()const
{
	//随机设置一个技能
	srand(time(NULL));
	ElfinSkillType m_type = (ElfinSkillType)(rand() % 5);

	//返回技能
	return m_type;
}

//设置等级
void Elfin::Set_EGrade(uint32 beg)
{
	
	m_level += beg;

	
}

//获取等级
uint32 Elfin::Get_EGrade()const
{
	return m_level;
}

//设置增加体力
void Elfin::Set_EAddPhysicalPower(uint32 ueap)
{
	//如果当前体力值小于最大体力值
	if (m_curPhyPower < m_maxphyPower)
	{
		m_curPhyPower += ueap;
		//如果当前体力值大于最大体力值 那么当前体力值就等于最大体力值
		if (m_curPhyPower > m_maxphyPower)
		{
			m_curPhyPower = m_maxphyPower;
		}
	}
		
}

//设置减少体力
void Elfin::Set_EReducePhysicalPower(uint32 uerp)
{
	m_curPhyPower -= uerp;
	//如果当前体力 小于 0 那么当前体力值就等于0
	if (m_curPhyPower < 0)
	{
		m_curPhyPower = 0;
	}
}

//获取当前体力
uint32 Elfin::Get_EPhysicalPower()const
{
	return m_curPhyPower;
}

//设置最大体力
void Elfin::Set_EMaxPhysicalPower(uint32 uempp)
{
	//小精灵每升一级,最大体力就会相应增加
	m_maxphyPower += uempp;
}

//获取最大体力
uint32 Elfin::Get_EMaxPhysicalPower()const
{
	return m_maxphyPower;
}

//设置随机分配小精灵的ID 并获取它
uint32 Elfin::Set_Get_EToID(ElfinSkillType m_type)
{
	switch (m_type)
	{
	case EGOLD: { m_id = 100001; break;	}
	case EWOOD: { m_id = 100002; break; }
	case EWATER: { m_id = 100003; break; }
	case EFIRE: { m_id = 100004; break; }
	case ESOIL: { m_id = 100005; break; }
	}
	return m_id;
}
//获取小精灵的ID
uint32 Elfin::Get_EToID()const
{
	return m_id;
}

//获取技能类
CSkill * Elfin::Get_CSkillClass()const
{
	return m_skill;
}


