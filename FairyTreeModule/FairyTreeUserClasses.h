#pragma once

#ifndef _FAIRY_TREE_USER_CLASSES_H
#define _FAIRY_TREE_USER_CLASSES_H

#include "Gamedefine.h"
#include <ace/OS_NS_sys_time.h>  
#include <ace/Date_Time.h> 

#include "Elfin.h"
#include "FairyTree.h"
#include "SunShine.h"
#include "Mail.h"
#include "RankingList.h"
#include "Relation.h"
#include "Shop.h"
#include "Skill.h"
#include "TaskClass.h"
#include "TreeEnchantment.h"
#include "Warehouse.h"
#include "CharacterClass.h"
#include "ResourceClass.h"



//神仙树用户类
class FairyTreeUserClasses
{
public:

	FairyTreeUserClasses();

	~FairyTreeUserClasses();

	//设置用户ID
	void Set_UserId(uint32 suid);

	//获得用户ID
	uint32 Get_UserId();

	//设置用户名
	void Set_UserName(const std::string& str);

	//获取用户名
	std::string Get_UserName();

	//设置微信ID
	void Set_UserWeChatID(uint32 uid);

	//获取微信ID
	uint32 Get_UserWeChatID();

	//设置成长值
	void Set_UserGrowthValue(uint32 val);

	//获取成长值
	uint32 Get_UserGrowthValue();

	//获取小精灵链表
	std::list<Elfin*> Get_ElfinList()  const;

	//获取神仙树
	FairyTree* Get_FairyTree();

	//获取阳光
	CSunshine* Get_SunShine();

	//获取树结界
	TreeEnchantment* Get_TreeEnchantment();

	//获取仓库
	Warehouse* Get_Warehouse();

	//获取邮箱
	CMailbox* Get_CMailbox();

	//获取任务列表类
	CTaskListClass* Get_CTaskListClass();

	//获取关系
	Relation* Get_Relation();

	//获取资源类
	ResourceClass* Get_Resource();

	//通过ID查找小精灵
	Elfin *GetElfinId(uint32);

private:
	uint32		m_roleID;				//用户ID

	std::string m_name;					//名字

	uint32		m_weChatID;				//微信ID
	
	uint32		m_groValue;				//成长值
            							   
	std::list<Elfin*> elfList;			//小精灵(链表)			
									 
	FairyTree* ptree;					//神仙树		
									  
	CSunshine* psun;					//太阳	

	TreeEnchantment* pchant;			//树结界(神仙门)

	Warehouse* phouse;					//仓库

	CMailbox* pmbox;					//邮箱

	CTaskListClass* ptasklist;			//任务列表类

	Relation* prelat;					//关系

	ResourceClass* pres;				//资源类
};

class CAllUserInfoInstance 
{
	CAllUserInfoInstance() {};

	static CAllUserInfoInstance* _instance;

	std::map<uint32, FairyTreeUserClasses*> ConnetedUser;

public:
	static CAllUserInfoInstance * GetInstance();
	
	std::map<uint32, FairyTreeUserClasses*>& GetUserMap();

	void SetUserMap(uint32 uid, FairyTreeUserClasses* pUser);
};
#endif