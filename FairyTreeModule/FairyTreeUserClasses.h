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



//�������û���
class FairyTreeUserClasses
{
public:

	FairyTreeUserClasses();

	~FairyTreeUserClasses();

	//�����û�ID
	void Set_UserId(uint32 suid);

	//����û�ID
	uint32 Get_UserId();

	//�����û���
	void Set_UserName(const std::string& str);

	//��ȡ�û���
	std::string Get_UserName();

	//����΢��ID
	void Set_UserWeChatID(uint32 uid);

	//��ȡ΢��ID
	uint32 Get_UserWeChatID();

	//���óɳ�ֵ
	void Set_UserGrowthValue(uint32 val);

	//��ȡ�ɳ�ֵ
	uint32 Get_UserGrowthValue();

	//��ȡС��������
	std::list<Elfin*> Get_ElfinList()  const;

	//��ȡ������
	FairyTree* Get_FairyTree();

	//��ȡ����
	CSunshine* Get_SunShine();

	//��ȡ�����
	TreeEnchantment* Get_TreeEnchantment();

	//��ȡ�ֿ�
	Warehouse* Get_Warehouse();

	//��ȡ����
	CMailbox* Get_CMailbox();

	//��ȡ�����б���
	CTaskListClass* Get_CTaskListClass();

	//��ȡ��ϵ
	Relation* Get_Relation();

	//��ȡ��Դ��
	ResourceClass* Get_Resource();

	//ͨ��ID����С����
	Elfin *GetElfinId(uint32);

private:
	uint32		m_roleID;				//�û�ID

	std::string m_name;					//����

	uint32		m_weChatID;				//΢��ID
	
	uint32		m_groValue;				//�ɳ�ֵ
            							   
	std::list<Elfin*> elfList;			//С����(����)			
									 
	FairyTree* ptree;					//������		
									  
	CSunshine* psun;					//̫��	

	TreeEnchantment* pchant;			//�����(������)

	Warehouse* phouse;					//�ֿ�

	CMailbox* pmbox;					//����

	CTaskListClass* ptasklist;			//�����б���

	Relation* prelat;					//��ϵ

	ResourceClass* pres;				//��Դ��
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