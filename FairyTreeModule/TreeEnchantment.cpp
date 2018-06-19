#include "TreeEnchantment.h"



TreeEnchantment::TreeEnchantment()
{
	m_level = 1;//等级
	m_defLevel = 1;//结界防御等级
}


TreeEnchantment::~TreeEnchantment()
{
}

//设置等级
void TreeEnchantment::Set_TEGrade(uint32 sg)
{
	m_level += sg;
}

//获取等级
uint32 TreeEnchantment::Get_TEGrade()
{
	return m_level;
}

//设置结界防御等级
void TreeEnchantment::Set_TEDefense(uint32 sted)
{
	m_defLevel += sted;
}

//获取结界防御等级
uint32 TreeEnchantment::Get_TEDefense()
{
	return m_defLevel;
}

