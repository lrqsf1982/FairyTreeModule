#include "Relation.h"



Relation::Relation()
{
}


Relation::~Relation()
{
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