#include "TreeEnchantment.h"



TreeEnchantment::TreeEnchantment()
{
	m_level = 1;//�ȼ�
	m_defLevel = 1;//�������ȼ�
}


TreeEnchantment::~TreeEnchantment()
{
}

//���õȼ�
void TreeEnchantment::Set_TEGrade(uint32 sg)
{
	m_level += sg;
}

//��ȡ�ȼ�
uint32 TreeEnchantment::Get_TEGrade()
{
	return m_level;
}

//���ý������ȼ�
void TreeEnchantment::Set_TEDefense(uint32 sted)
{
	m_defLevel += sted;
}

//��ȡ�������ȼ�
uint32 TreeEnchantment::Get_TEDefense()
{
	return m_defLevel;
}

