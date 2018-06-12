#pragma once

#ifndef _RANKING_LIST_H
#define _RANKING_LIST_H

#include "Gamedefine.h"
#include <list>
#include "CharacterClass.h"

//排行榜类
class RankingList
{
public:
	RankingList();
	~RankingList();
	//增加角色
	void RankingList_AddCharacter(CharacterClass* uid);
	//删除角色
	void RankingList_DelCharacter(uint32 delc);

	//获取排行榜
	std::list<CharacterClass*> Get_Rankinglist();

	//设置用户ID
	void Set_RoleID(uint32 uid);
	//获取用户ID
	uint32 Get_RoleID();

private:

	//用户ID
	uint32 m_roleID;

	CharacterClass * pcharass;
	
	std::list<CharacterClass*> list_ranking;

};

//排行榜角色成长值排序
inline bool JudgeCharaLevel(CharacterClass* charaleve, CharacterClass* charalevel)
{
	return (charaleve->Get_RoleGrowthValue()) > (charalevel->Get_RoleGrowthValue());
}

#endif
