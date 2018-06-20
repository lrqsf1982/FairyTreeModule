#include "UserAllTable.h"
#include "TimerManager.h"



UserAllTableClass::UserAllTableClass() 
{
	InitAll(m_strdbIP, m_strdbName);
}

UserAllTableClass::~UserAllTableClass() {}

//初始化所有玩家到内存
UINT32 UserAllTableClass::InitAll(std::string const& strdbip, std::string const& dbname)
{
	CDB_Character role;
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();

	//加载玩家数据库
	m_character_table.loadtable(tmpcon);

	//记录玩家离线时间
	m_UnlineTime = role.GetunlineTime(m_character_table.m_unlineTime);

	//获取当前系统时间
	ACE_Time_Value now = ACE_OS::gettimeofday();
	
	//取个三天时间
	//ACE_Time_Value tv(TIME_THREEDAY, 0);

	std::map<UINT32, CDB_Character*>::iterator it;

	for (it = m_character_table.m_mapcharacterInfo.begin(); it != m_character_table.m_mapcharacterInfo.end(); ++it)
	{
		//用表存入离线玩家
		if (m_UnlineTime)
		{
			m_character_table.m_mapcharacterInfo.find(m_character_table.m_uroleID);
			m_vecUnlineRole.push_back(m_character_table.m_uroleID);
		}
		//用表存入在线玩家
		else
			m_vecOnlineRole.push_back(m_character_table.m_uroleID);
	}
	
	//加载最近3天在线玩家
	if (m_UnlineTime > TIME_THREEDAY)
		return 0;
	else 
	{
		if (tmpcon != NULL)
		{
			if (FALSE == thread_db.ReConnect())
			{
				printf("DB base is closed");
				return false;
			}
			std::vector<UINT32>::iterator it;
			for (it = m_vecOnlineRole.begin(); it != m_vecOnlineRole.end(); ++it) 
			{
				//加载玩家相关属性
				m_character_table.loadtable(tmpcon);
				m_elfin_table.loadtable(tmpcon);
				m_fairytree_table.loadtable(tmpcon);
				m_sunshine_table.loadtable(tmpcon);
				m_gold_table.loadtable(tmpcon);
				m_mail_table.loadtable(tmpcon);
				m_mailbox_table.loadtable(tmpcon);
				m_rankinglist_table.loadtable(tmpcon);
				m_relation_table.loadtable(tmpcon);
				m_skill_table.loadtable(tmpcon);
				m_taskcalss_table.loadtable(tmpcon);
				m_tasklistclass_table.loadtable(tmpcon);
				m_treeenchantment_table.loadtable(tmpcon);
				m_warehousearticle_table.loadtable(tmpcon);
				m_warehouse_table.loadtable(tmpcon);
				m_water_table.loadtable(tmpcon);
			}
			
		}
		
	}
	return true;
}

//从数据库加载玩家数据到内存
UINT32 UserAllTableClass::LoadUser_fromDB(UINT32 userid, const std::string& name)
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		//加载玩家数据库
		m_character_table.loadtable(tmpcon);

		//根据传进来的ID判断是否有该玩家
		if (userid == m_character_table.m_uroleID)
		{
			//加载玩家相关属性
			m_elfin_table.loadtable(tmpcon);
			m_fairytree_table.loadtable(tmpcon);
			m_sunshine_table.loadtable(tmpcon);
			m_gold_table.loadtable(tmpcon);
			m_mail_table.loadtable(tmpcon);
			m_mailbox_table.loadtable(tmpcon);
			m_rankinglist_table.loadtable(tmpcon);
			m_relation_table.loadtable(tmpcon);
			m_skill_table.loadtable(tmpcon);
			m_taskcalss_table.loadtable(tmpcon);
			m_tasklistclass_table.loadtable(tmpcon);
			m_treeenchantment_table.loadtable(tmpcon);
			m_warehousearticle_table.loadtable(tmpcon);
			m_warehouse_table.loadtable(tmpcon);
			m_water_table.loadtable(tmpcon);
		}
		else 
		{
			//传进来的ID没有就在数据库插入新玩家
			m_character_table.Insert_tb_userid(userid, name);
			printf("insert a new user into DBtable:\n");
		}
	}
	return true;
}

//获取时间
UINT32 UserAllTableClass::GetTime()
{
	//休息三天
	ACE_OS::sleep(TIME_THREEDAY);

	m_isbcurtime = FALSE;

	//没有到规定时间
	if (FALSE == m_isbcurtime)
	{
		//初始化时间

		//获取当前系统时间
		ACE_Time_Value now = ACE_OS::gettimeofday();

		//给定时间三天
		ACE_Time_Value timeout (TIME_THREEDAY,0);

		//返回实例给定的时间与当前是相减的值，即相对时间 
		ACE_Time_Value curtime = timeout.to_relative_time();
		
		

		m_isbcurtime = true;
	}
	return m_isbcurtime;
}


//从内存加载数据到数据库
UINT32 UserAllTableClass::LoadformMem_ToDB() 
{
	return true;
}
//删除用户属性类
//template<typename T>
//void UserAllTableClass::deleteObject(T)
//{
//	typename std::map<UINT32, T*>::iterator it;
//	for (it = m_character_table.m_mapcharacterInfo.begin(); it != m_character_table.m_mapcharacterInfo.end(); ++it)
//	{
//		delete it->second;
//		m_character_table.m_mapcharacterInfo.erase(it);
//	}
//}
//template<typename T>
//void UserAllTableClass::DeleteAllObject(T) 
//{
//	deleteObject(T);
//}



//加载小精灵表到内存
UINT32 UserAllTableClass::LoadElfin_For_Table(UINT32 id)
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_elfin_table.loadtable(tmpcon);
	}
	return true;
}

//加载神仙树表到内存
UINT32 UserAllTableClass::LoadFairyTree_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_fairytree_table.loadtable(tmpcon);
	}
	return true;
}

//加载阳光表到内存
UINT32 UserAllTableClass::LoadFairyWell_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_sunshine_table.loadtable(tmpcon);
	}
	return true;
}

//加载金币表到内存
UINT32 UserAllTableClass::LoadGold_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_gold_table.loadtable(tmpcon);
	}
	return true;
}

//加载邮件表到内存
UINT32 UserAllTableClass::LoadMail_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_mail_table.loadtable(tmpcon);
	}
	return true;
}

//加载邮箱表到内存
UINT32 UserAllTableClass::LoadMailBox_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_mailbox_table.loadtable(tmpcon);
	}
	return true;
}

//加载排行榜表到内存
UINT32 UserAllTableClass::LoadRankingList_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_rankinglist_table.loadtable(tmpcon);
	}
	return true;
}

//加载关系表到内存
UINT32 UserAllTableClass::LoadRelation_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_relation_table.loadtable(tmpcon);
	}
	return true;
}

////加载商店表到数据库
//UINT32 UserAllTableClass::LoadShop_For_Table(UINT32 id) {}
////更新商店表到内存
//UINT32 UserAllTableClass::UpdateShop_To_Table(UINT32 id) { return true; }

//加载技能表到内存
UINT32 UserAllTableClass::LoadSkill_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_skill_table.loadtable(tmpcon);
	}
	return true;
}

//加载任务表到内存
UINT32 UserAllTableClass::LoadTaskClass_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_taskcalss_table.loadtable(tmpcon);
	}
	return true;
}

//加载任务栏表到内存
UINT32 UserAllTableClass::LoadTaskListClass_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_tasklistclass_table.loadtable(tmpcon);
	}
	return true;
}

//加载树结界表到内存
UINT32 UserAllTableClass::LoadTreeEnchantment_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_treeenchantment_table.loadtable(tmpcon);
	}
	return true;
}

//加载物品类表到内存
UINT32 UserAllTableClass::LoadWarehouseArticle_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_warehousearticle_table.loadtable(tmpcon);
	}
	return true;
}

//加载仓库表到内存
UINT32 UserAllTableClass::LoadWarehouse_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_warehouse_table.loadtable(tmpcon);
	}
	return true;
}

//加载水资源表到内存
UINT32 UserAllTableClass::LoadWater_For_Table(UINT32 id) 
{
	//连接到数据库
	MysqlEncap & thread_db = g_serverconnect;
	MYSQL * tmpcon = thread_db.GetConn();
	if (tmpcon != NULL)
	{
		if (FALSE == thread_db.ReConnect())
		{
			printf("DB base is closed");
			return false;
		}
		m_water_table.loadtable(tmpcon);
	}
	return true;
}

//服务器写入内存
UINT32 UserAllTableClass::WriteToMem(std::map<UINT32, UserAllTableClass*>& temp_map)
{
	//对应每个表需要拷贝

	//std::map<UINT32, UserAllTableClass*>::iterator it;
	//m_writedbmutex.Lock();
	//for (it = temp_map.begin(); it != temp_map.end(); ++it) 
	//{
	//	m_vec_alluser.push_back((it->second));//将内存的数据压入到自己存放玩家所有数据的顺序表中
	//}
	//m_writedbmutex.UnLock();
	return 0;
}

//从内存定时回存到数据库
static int s_waitrolewritecount = 0;

UINT32 UserAllTableClass::LoadUser_writefor_Table()
{
	
	//if (s_waitrolewritecount == 0)
	//{
	//	//ACE_Thread 
	//}
	//mysql_autocommit(m_WritedbConnect.GetConn(), 0);//关闭自动提交

	//m_writedbmutex.Lock();
	//int iWriteCount = m_vec_alluser.size();

	//for (int i = 0; i < iWriteCount; i++)
	//{

	//}
	//m_writedbmutex.UnLock();

	//
	//mysql_commit(m_WritedbConnect.GetConn());//提交
	//mysql_autocommit(m_WritedbConnect.GetConn(), 1);//自动提交
	return 0;
}