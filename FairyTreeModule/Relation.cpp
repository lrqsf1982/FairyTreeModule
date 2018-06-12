#include "Relation.h"



Relation::Relation()
{
	m_roleID = 0;//用户ID
	pharaCha = new CharacterClass;
}


Relation::~Relation()
{
	delete pharaCha;
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
	return crfriendlist;
}

//获取关系(敌对)
std::list<CharacterClass*> Relation::Get_RelationRenemyRanking()
{
	crenemylist.sort(RelationSort);
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

//设置用户ID
void Relation::Set_RoleID(uint32 uid)
{
	m_roleID = uid;//用户ID
}

//获取用户ID
uint32 Relation::Get_RoleID()
{
	return m_roleID;
}

