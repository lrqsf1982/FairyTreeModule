#include "RankingList.h"



RankingList::RankingList()
{
	m_roleID = 0;//用户ID
	pcharass = new CharacterClass;
}


RankingList::~RankingList()
{
	delete pcharass;
}


//增加角色
void RankingList::RankingList_AddCharacter(CharacterClass* uid)
{
	list_ranking.push_back(uid);
}

//删除角色
void RankingList::RankingList_DelCharacter(uint32 delc)
{

	//通过角色ID查找 要删除的角色
	for (std::list<CharacterClass*>::iterator itlist = list_ranking.begin(); itlist != list_ranking.end(); itlist++)
	{
		if (delc == (*itlist)->Get_Role_ID())
		{
			list_ranking.erase(itlist);
			return;
		}
	}

}

//获取排行榜
std::list<CharacterClass*> RankingList::Get_Rankinglist()
{
	list_ranking.sort(JudgeCharaLevel);
	return list_ranking;
}

//设置用户ID
void RankingList::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//获取用户ID
uint32 RankingList::Get_RoleID()
{
	return m_roleID;
}


