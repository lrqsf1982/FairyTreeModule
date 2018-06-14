#pragma once
#ifndef _USER_ALL_TABLE_H_ 
#define _USER_ALL_TABLE_H_

#include "character_table.h"
#include "elfindata_table.h"
#include "fairytree_table.h"
#include "sunshine_table.h"
#include "gold_table.h"
#include "mail_table.h"
#include "mailbox_table.h"
#include "rankinglist_table.h"
#include "relation_table.h"
#include "skill_table.h"
#include "taskclass_table.h"
#include "tasklistclass_table.h"
#include "tree_enchantmen_table.h"
#include "ware_house_article_table.h"
#include "warehouse_table.h"
#include "water_table.h"

#define	TIME_MAX 600
#define	TIME_THREEDAY 259200

//角色所有属性类型
//enum TYPE
//{
//	m_character_table,			//角色表
//	m_elfin_table,				//小精灵表
//	m_fairytree_table,			//阳光类表
//	m_sunshine_table,			//神仙井表
//	m_gold_table,				//金币表
//	m_mail_table,				//邮件表
//	m_mailbox_table,			//邮箱表
//	m_rankinglist_table,		//排行榜表
//	m_relation_table,			//关系表
//	m_shop_table,				//商店表
//	m_skill_table,				//技能表
//	m_taskcalss_table,			//任务表
//	m_tasklistclass_table,		//任务栏表
//	m_treeenchantment_table,	//树结界表
//	m_warehousearticle_table,	//物品类表
//	m_warehouse_table,			//仓库表
//	m_water_table				//水资源表
//};
//用户类表



class UserAllTableClass
{
public:
	CDB_Character			m_character_table;			//角色表
	CDB_Elfin				m_elfin_table;				//小精灵表
	CDB_FairyTree			m_fairytree_table;			//神仙树
	CDB_CSunshine			m_sunshine_table;			//阳光类表
	CDB_Gold				m_gold_table;				//金币表
	CDB_Mail				m_mail_table;				//邮件表
	CDB_Mailbox				m_mailbox_table;			//邮箱表
	CDB_RankingList			m_rankinglist_table;		//排行榜表
	CDB_Relation			m_relation_table;			//关系表
	CDB_Skill				m_skill_table;				//技能表
	CDB_TaskClass			m_taskcalss_table;			//任务表
	CDB_TaskListClass		m_tasklistclass_table;		//任务栏表
	CDB_TreeEnchantment		m_treeenchantment_table;	//树结界表
	CDB_WarehouseArticle	m_warehousearticle_table;	//物品类表
	CDB_Warehouse			m_warehouse_table;			//仓库表
	CDB_Water				m_water_table;				//水资源表
	char					m_UnlineTime;				//离线时间
	UINT32					m_StarTime;					//定时器开始时间
	bool					m_isbcurtime = false;		//是否到规定时间

	std::vector<UINT32>m_vecUnlineRole;					//用表存入离线玩家ID
	std::vector<UINT32>m_vecOnlineRole;					//用表存入三天内在线玩家ID

														
	//CThreadLock m_readdbmutex;							//线程读锁
	//CThreadLock m_writedbmutex;							//线程写锁
							
	std::vector<UserAllTableClass*>m_vec_alluser;		//玩家所有信息

	//数据库连接变量
	MysqlEncap m_WritedbConnect;

	UserAllTableClass();
	~UserAllTableClass();

	//template<typename T>
	//void deleteObject(T);

	//template<typename T>
	//void DeleteAllObject(T);

	//初始化玩家所有数据
	UINT32 InitAll(std::string const& strdbip, std::string const& dbname);

	//获取时间
	UINT32 GetTime();

	//服务器写入内存
	UINT32 WriteToMem(std::map<UINT32, UserAllTableClass*>& temp_map);

	//从内存加载角色表到数据库UINT32 userid, CDB_Character& db_conn, void*sql_db, std::vector< UserAllTableClass*>m_vecTemp
	UINT32 LoadUser_writefor_Table();

	//从数据库加载数据到内存

	UINT32 LoadUser_fromDB(UINT32 userid, const std::string& name);

	//从内存加载数据到数据库
	UINT32 LoadformMem_ToDB();

	//更新角色表到内存
	//bool UpdateUser_To_Table(UINT32 userid);

	//加载小精灵表到数据库
	UINT32 LoadElfin_For_Table(UINT32 id);
	//更新小精灵表到内存
	//UINT32 UpdateElfin_To_Table(UINT32 id);

	//加载神仙树表到数据库
	UINT32 LoadFairyTree_For_Table(UINT32 id);
	//更新神仙树表到内存
	//UINT32 UpdateFairyTree_To_Table(UINT32 id);

	//加载神仙井表到数据库
	UINT32 LoadFairyWell_For_Table(UINT32 id);
	//更新神仙井表到内存
	//UINT32 UpdateFairyWell_To_Table(UINT32 id);

	//加载金币表到数据库
	UINT32 LoadGold_For_Table(UINT32 id);
	//更新金币表到内存
	//UINT32 UpdateGold_To_Table(UINT32 id);

	//加载邮件表到数据库
	UINT32 LoadMail_For_Table(UINT32 id);
	//更新邮件表到内存
	//UINT32 UpdateMail_To_Table(UINT32 id);

	//加载邮箱表到数据库
	UINT32 LoadMailBox_For_Table(UINT32 id);
	//更新邮箱表到内存
	//UINT32 UpdateMailBox_To_Table(UINT32 id);

	//加载排行榜表到数据库
	UINT32 LoadRankingList_For_Table(UINT32 id);
	//更新排行榜表到内存
	//UINT32 UpdateRankingList_To_Table(UINT32 id);

	//加载关系表到数据库
	UINT32 LoadRelation_For_Table(UINT32 id);
	//更新关系表到内存
	//UINT32 UpdateRelation_To_Table(UINT32 id);

	////加载商店表到数据库
	//UINT32 LoadShop_For_Table(UINT32 id);
	////更新商店表到内存
	//UINT32 UpdateShop_To_Table(UINT32 id);

	//加载技能表到数据库
	UINT32 LoadSkill_For_Table(UINT32 id);
	//更新技能表到内存
	//UINT32 UpdateSkill_To_Table(UINT32 id);

	//加载任务表到数据库
	UINT32 LoadTaskClass_For_Table(UINT32 id);
	//更新任务表到内存
	//UINT32 UpdateTaskClass_To_Table(UINT32 id);

	//加载任务栏表到数据库
	UINT32 LoadTaskListClass_For_Table(UINT32 id);
	//更新任务栏表到内存
	//UINT32 UpdateTaskListClass_To_Table(UINT32 id);

	//加载树结界表到数据库
	UINT32 LoadTreeEnchantment_For_Table(UINT32 id);
	//更新树结界表到内存
	//UINT32 UpdateTreeEnchantment_To_Table(UINT32 id);

	//加载物品类表到数据库
	UINT32 LoadWarehouseArticle_For_Table(UINT32 id);
	//更新物品类表到内存
	//UINT32 UpdateWarehouseArticle_To_Table(UINT32 id);

	//加载仓库表到数据库
	UINT32 LoadWarehouse_For_Table(UINT32 id);
	//更新仓库表到内存
	//UINT32 UpdateWarehouse_To_Table(UINT32 id);

	//加载水资源表到数据库
	UINT32 LoadWater_For_Table(UINT32 id);
	//更新水资源表到内存
	//UINT32 UpdateWater_To_Table(UINT32 id);

	std::string m_strdbIP;
	std::string m_strdbName;
};
#endif 