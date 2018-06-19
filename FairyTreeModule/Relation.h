#pragma once

#ifndef _RELATION_H
#define _RELATION_H

#include "Gamedefine.h"
#include <list>
#include "CharacterClass.h"

//关系类
class Relation
{
public:
	Relation();
	~Relation();
	//增加好友
	void RAddFriend(CharacterClass* cr);
	// 删除好友 通过角色ID
	void RDelFriend(uint32 udel);

	//获取关系(好友)
	std::list<CharacterClass*> Get_RelationRfriendRanking();
	//获取关系(敌对)
	std::list<CharacterClass*> Get_RelationRenemyRanking();

	//增加敌人
	void RAddEnemy(CharacterClass* cr);
	// 删除敌人 通过角色ID
	void RDelEnemy(uint32 udel);
private:
	CharacterClass * pharaCha;
	//好友情况
	std::list<CharacterClass*> crfriendlist;

	//敌对情况
	std::list<CharacterClass*> crenemylist;
};

//关系角色成长值排序
inline bool RelationSort(CharacterClass* charaleve, CharacterClass* charalevel)
{
	return (charaleve->Get_RoleGrowthValue()) > (charalevel->Get_RoleGrowthValue());
}

#endif
