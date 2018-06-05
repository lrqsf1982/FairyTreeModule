#pragma once

#ifndef _RELATION_H
#define _RELATION_H

#include "define.h"
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

	//增加敌人
	void RAddEnemy(CharacterClass* cr);
	// 删除敌人 通过角色ID
	void RDelEnemy(uint32 udel);

private:
	//好友情况
	std::list<CharacterClass*> crfriendlist;

	//敌对情况
	std::list<CharacterClass*> crenemylist;
};

#endif
