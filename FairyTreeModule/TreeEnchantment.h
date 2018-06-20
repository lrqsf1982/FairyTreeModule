#pragma once

#ifndef _TREE_ENCHANTMENT_H
#define _TREE_ENCHANTMENT_H

#include "Gamedefine.h"
#include <map>

//�������
class TreeEnchantment
{
public:

	TreeEnchantment();

	~TreeEnchantment();

	//���õȼ�
	void Set_TEGrade(uint32 sg);

	//��ȡ�ȼ�
	uint32 Get_TEGrade();

	//���ý������ȼ�
	void Set_TEDefense(uint32 sted);

	//��ȡ�������ȼ�
	uint32 Get_TEDefense();

private:

	//�ȼ�
	uint32 m_level;

	//�������ȼ�
	uint32 m_defLevel;
};
#endif