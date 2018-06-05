#pragma once

#ifndef _TREE_ENCHANTMENT_H
#define _TREE_ENCHANTMENT_H

#include "define.h"

//树结界类
class TreeEnchantment
{
public:
	TreeEnchantment();
	~TreeEnchantment();
	//设置等级
	void Set_TEGrade(uint32 sg);
	//获取等级
	int Get_TEGrade();

	//设置结界防御
	void Set_TEDefense(uint32 sted);
	//获取结界防御
	int Get_TEDefense();

	//打开保护罩
	bool OpenGuard(bool bog);
	//关闭保护罩
	bool CloseGuard(bool bcg);

	//打开陷阱
	bool OpenPitfall(bool bop);
	//关闭陷阱
	bool ClosePitfall(bool bcp);
private:
	//等级
	uint32 ugrade;
	//结界防御
	uint32 udefense;

	//保护罩
	bool bopenguard;//打开
	bool bcloseguard;//关闭

	//陷阱(预留)
	bool bopenpitfall;//打开
	bool bclosepitfall;//关闭
};



#endif
