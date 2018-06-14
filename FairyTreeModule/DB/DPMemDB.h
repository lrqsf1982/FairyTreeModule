#ifndef MEMDB_H
#define MEMDB_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdint.h>
#include <string>

class SPetBaseDataClient;
class SFixProperty;
class SFixBaseData;
class MYSQLDATA;
#define MAX_COUNT_DEFAULT 255

const std::string    DB_KEY_ACTIVE_			= "activedata";
const std::string    DB_KEY_ACTIVE_NOTICE	= "active_notice";
const std::string    DB_KEY_TASK_			= "taskdata";			//任务
const std::string    DB_KEY_FINISH_TASK_	= "taskfinishdata";		//完成任务
const std::string    DB_KEY_FRIEND_			= "Frienddata";			//友方数据
const std::string    DB_KEY_MAIL			= "maildata";			//邮件
const std::string    DB_KEY_SHOP_			= "Shop";				//商店
const std::string    DB_KEY_NEWS_			= "news";				//消息
const std::string    DB_KEY_INVITATION_DATA_= "invitationdata";		//邀请
const std::string    DB_KEY_RANK_DATA		= "RankData";			//排行
const std::string	 MDB_KEY_CHAT_			= "charactertdata";		//角色
const std::string    DB_KEY_PET_GUILD		= "elfinaguild";		//精灵

class MyMemDB
{
public:
	bool bIsEnd;
	MyMemDB()
	{
		bIsEnd = false;
	}

	std::stringstream dbstream;
	const std::stringstream & getStream()
	{
		return dbstream;
	}

	struct Data
	{
		char* data;
		uint16_t len;
		uint16_t maxDataLen;
		Data(char* p = NULL, uint16_t l = 0) :data(p), len(l), maxDataLen(0) {}
	};

};
//从内存中加载精灵数据
uint32_t SaveElfinInMDB(uint64_t roleuid, SPetBaseDataClient &PetData, MYSQLDATA& thread_db);
uint32_t LoadElfinInMDB(uint64_t roleuid, uint64_t petUId, SPetBaseDataClient &PetData, MYSQLDATA& thread_db);

//任务数据
uint32_t SaveTaskInMDB(uint64_t qwRoleUID, std::string db);
uint32_t LoadTaskInMDB(uint64_t qwRoleUID, MyMemDB& db);
uint32_t SaveFinishTaskInMDB(uint64_t qwRoleUID, std::string db);
uint32_t LoadFinishTaskInMDB(uint64_t qwRoleUID, MyMemDB& db);

//读写消息
uint32_t LoadNewsInMDB(uint64_t qwRoleUID, MyMemDB& db);
uint32_t SavenewsInMDB(uint64_t qwRoleUID, std::string db);

//好友数据
uint32_t LoadFriendInMDB(uint64_t qwRoleUID, MyMemDB& db, MYSQLDATA& thread_db);
uint32_t SaveFriendInMDB(uint64_t qwRoleUID, std::string db, MYSQLDATA& thread_db);


//读写好友邀请的玩家信息
uint32_t SaveInvitationRoleInMDB(uint32_t qwRoleUID, SFixBaseData &playerdata, SPetBaseDataClient& firstPetData, MYSQLDATA & thread_db);
uint32_t LoadInvitationRoleInMDB(uint32_t qwRoleUID, SFixBaseData &playerdata, SPetBaseDataClient& firstPetData);


//读写临时数据
uint32_t SaveTempCombatDataInMDB(std::string& key, std::string db, MYSQLDATA & thread_db);
uint32_t LoadTempCombatDataInMDB(std::string& key, MyMemDB& db, MYSQLDATA & thread_db);
uint32_t DelTempCombatDataInMDB(std::string& key, MYSQLDATA & thread_db);
uint32_t DelTempExpeditionCombatDataInMDB(uint64_t qwRoleUID, uint32_t dwExpeditionRoundID, MYSQLDATA & thread_db);

//在内存中读取角色信息
uint32_t getRoleInMDB(uint64_t qwRoleUID, SFixBaseData &RoleData, MYSQLDATA& thread_db);

//字符串和数据块的转换
std::string DataToString(char* data, size_t len);
void StringToData(std::string str, char* data, size_t& len, size_t maxLen);

#endif // MEMDB_H