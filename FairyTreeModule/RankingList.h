#pragma once

#ifndef _RANKING_LIST_H
#define _RANKING_LIST_H

#include "define.h"
#include <list>
#include "CharacterClass.h"

//排行榜类
class RankingList
{
public:
	RankingList();
	~RankingList();
	//增加角色
	void RankingList_AddCharacter(CharacterClass* addch);
	//删除角色
	void RankingList_DelCharacter(uint32 delc);

	//获取得角色信息
	CharacterClass Get_CharaMessage(CharacterClass* addch);
	
private:
	//排行榜链表
	std::list<CharacterClass*> rlist;
	
};

//判断角色等级
inline bool JudgeCharaLevel(CharacterClass* charaleve, CharacterClass* charalevel)
{
	return (charaleve->Get_RoleLevel()) > (charalevel->Get_RoleLevel());
}

#endif
