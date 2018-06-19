#pragma once

#ifndef _RELATION_H
#define _RELATION_H

#include "Gamedefine.h"
#include <list>
#include "CharacterClass.h"

//��ϵ��
class Relation
{
public:
	Relation();
	~Relation();
	//���Ӻ���
	void RAddFriend(CharacterClass* cr);
	// ɾ������ ͨ����ɫID
	void RDelFriend(uint32 udel);

	//��ȡ��ϵ(����)
	std::list<CharacterClass*> Get_RelationRfriendRanking();
	//��ȡ��ϵ(�ж�)
	std::list<CharacterClass*> Get_RelationRenemyRanking();

	//���ӵ���
	void RAddEnemy(CharacterClass* cr);
	// ɾ������ ͨ����ɫID
	void RDelEnemy(uint32 udel);
private:
	CharacterClass * pharaCha;
	//�������
	std::list<CharacterClass*> crfriendlist;

	//�ж����
	std::list<CharacterClass*> crenemylist;
};

//��ϵ��ɫ�ɳ�ֵ����
inline bool RelationSort(CharacterClass* charaleve, CharacterClass* charalevel)
{
	return (charaleve->Get_RoleGrowthValue()) > (charalevel->Get_RoleGrowthValue());
}

#endif
