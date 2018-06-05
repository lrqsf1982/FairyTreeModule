#include "RankingList.h"



RankingList::RankingList()
{
}


RankingList::~RankingList()
{
}


//增加角色
void RankingList::RankingList_AddCharacter(CharacterClass* addch)
{
	rlist.push_back(addch);
}

//删除角色
void RankingList::RankingList_DelCharacter(uint32 delc)
{

	//通过角色ID查找 要删除的角色
	for (std::list<CharacterClass*>::iterator itlist = rlist.begin(); itlist != rlist.end(); itlist++)
	{
		if (delc == (*itlist)->Get_Role_ID())
		{
			rlist.erase(itlist);
		}
	}

}

//获取得角色信息
CharacterClass RankingList::Get_CharaMessage(CharacterClass * addch)
{
	//根据等级进行排序
	rlist.sort(JudgeCharaLevel);

	return *addch;
}

