#pragma once

#ifndef _TREE_ENCHANTMENT_H
#define _TREE_ENCHANTMENT_H

#include "Gamedefine.h"
#include <map>

//树结界类
class TreeEnchantment
{
public:

	TreeEnchantment();

	~TreeEnchantment();

	//设置等级
	void Set_TEGrade(uint32 sg);

	//获取等级
	uint32 Get_TEGrade();

	//设置结界防御等级
	void Set_TEDefense(uint32 sted);

	//获取结界防御等级
	uint32 Get_TEDefense();

private:

	//等级
	uint32 m_level;

	//结界防御等级
	uint32 m_defLevel;
};
#endif