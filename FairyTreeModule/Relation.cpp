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

//���Ӻ���
void Relation::RAddFriend(CharacterClass* cr)
{
	crfriendlist.push_back(cr);
}

// ɾ������
void Relation::RDelFriend(uint32 udel)
{

	//ͨ����ɫID���� Ҫɾ���Ľ�ɫ
	for (std::list<CharacterClass*>::iterator it = crfriendlist.begin(); it != crfriendlist.end(); it++)
	{
		if (udel == (*it)->Get_Role_ID())
		{
			crfriendlist.erase(it);
		}
	}
	
}

//��ȡ��ϵ(����)
std::list<CharacterClass*> Relation::Get_RelationRfriendRanking()
{
	crfriendlist.sort(RelationSort);
	//�������ڻ�ȡ
	return crfriendlist;
}

//��ȡ��ϵ(�ж�)
std::list<CharacterClass*> Relation::Get_RelationRenemyRanking()
{
	crenemylist.sort(RelationSort);
	//�������ڻ�ȡ
	return crenemylist;
}

//���ӵ���
void Relation::RAddEnemy(CharacterClass* cr)
{
	crenemylist.push_back(cr);
}

// ɾ������
void Relation::RDelEnemy(uint32 udel)
{

	//ͨ����ɫID���� Ҫɾ���Ľ�ɫ
	for (std::list<CharacterClass*>::iterator it = crenemylist.begin(); it != crenemylist.end(); it++)
	{
		if (udel == (*it)->Get_Role_ID())
		{
			crenemylist.erase(it);
		}
	}

}

