#include "DPMemDB.h"
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