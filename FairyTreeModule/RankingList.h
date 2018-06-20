#pragma once

#ifndef _RANKING_LIST_H
#define _RANKING_LIST_H

#include "Gamedefine.h"
#include <list>
#include <map>
#include "CharacterClass.h"

//���а���
class RankingList
{
public:

	RankingList();

	~RankingList();

	//���ӽ�ɫ
	void RankingList_AddCharacter(CharacterClass* uid);

	//ɾ����ɫ
	void RankingList_DelCharacter(uint32 delc);

	//��ȡ���а��ɫ��list
	std::list<CharacterClass*> Get_Rankinglist();

private:

	CharacterClass * pcharass;
	
	//��ɫ��list
	std::list<CharacterClass*> list_ranking;
};

//���а��ɫ�ɳ�ֵ����
inline bool JudgeCharaLevel(CharacterClass* charaleve, CharacterClass* charalevel)
{
	return (charaleve->Get_RoleGrowthValue()) > (charalevel->Get_RoleGrowthValue());
}
#endif