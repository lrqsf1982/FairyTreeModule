#include "Relation.h"



Relation::Relation()
{
	pharaCha = new CharacterClass;
}


Relation::~Relation()
{
	delete pharaCha;
	pharaCha = nullptr;
}

//增加好友
void Relation::RAddFriend(CharacterClass* cr)
{
	crfriendlist.push_back(cr);
}

// 删除好友
void Relation::RDelFriend(uint32 udel)
{

	//通过角色ID查找 要删除的角色
	for (std::list<CharacterClass*>::iterator it = crfriendlist.begin(); it != crfriendlist.end(); it++)
	{
		if (udel == (*it)->Get_Role_ID())
		{
			crfriendlist.erase(it);
		}
	}
	
}

//获取关系(好友)
std::list<CharacterClass*> Relation::Get_RelationRfriendRanking()
{
	crfriendlist.sort(RelationSort);
	//先排序在获取
	return crfriendlist;
}

//获取关系(敌对)
std::list<CharacterClass*> Relation::Get_RelationRenemyRanking()
{
	crenemylist.sort(RelationSort);
	//先排序在获取
	return crenemylist;
}

//增加敌人
void Relation::RAddEnemy(CharacterClass* cr)
{
	crenemylist.push_back(cr);
}

// 删除敌人
void Relation::RDelEnemy(uint32 udel)
{

	//通过角色ID查找 要删除的角色
	for (std::list<CharacterClass*>::iterator it = crenemylist.begin(); it != crenemylist.end(); it++)
	{
		if (udel == (*it)->Get_Role_ID())
		{
			crenemylist.erase(it);
		}
	}

}

