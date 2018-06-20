#include "DPMemDB.h"
//���ڴ��м��ؾ�������
uint32_t SaveElfinInMDB(uint64_t roleuid, SPetBaseDataClient &PetData, MYSQLDATA& thread_db);
uint32_t LoadElfinInMDB(uint64_t roleuid, uint64_t petUId, SPetBaseDataClient &PetData, MYSQLDATA& thread_db);

//��������
uint32_t SaveTaskInMDB(uint64_t qwRoleUID, std::string db);
uint32_t LoadTaskInMDB(uint64_t qwRoleUID, MyMemDB& db);
uint32_t SaveFinishTaskInMDB(uint64_t qwRoleUID, std::string db);
uint32_t LoadFinishTaskInMDB(uint64_t qwRoleUID, MyMemDB& db);

//��д��Ϣ
uint32_t LoadNewsInMDB(uint64_t qwRoleUID, MyMemDB& db);
uint32_t SavenewsInMDB(uint64_t qwRoleUID, std::string db);

//��������
uint32_t LoadFriendInMDB(uint64_t qwRoleUID, MyMemDB& db, MYSQLDATA& thread_db);
uint32_t SaveFriendInMDB(uint64_t qwRoleUID, std::string db, MYSQLDATA& thread_db);


//��д��������������Ϣ
uint32_t SaveInvitationRoleInMDB(uint32_t qwRoleUID, SFixBaseData &playerdata, SPetBaseDataClient& firstPetData, MYSQLDATA & thread_db);
uint32_t LoadInvitationRoleInMDB(uint32_t qwRoleUID, SFixBaseData &playerdata, SPetBaseDataClient& firstPetData);


//��д��ʱ����
uint32_t SaveTempCombatDataInMDB(std::string& key, std::string db, MYSQLDATA & thread_db);
uint32_t LoadTempCombatDataInMDB(std::string& key, MyMemDB& db, MYSQLDATA & thread_db);
uint32_t DelTempCombatDataInMDB(std::string& key, MYSQLDATA & thread_db);
uint32_t DelTempExpeditionCombatDataInMDB(uint64_t qwRoleUID, uint32_t dwExpeditionRoundID, MYSQLDATA & thread_db);

//���ڴ��ж�ȡ��ɫ��Ϣ
uint32_t getRoleInMDB(uint64_t qwRoleUID, SFixBaseData &RoleData, MYSQLDATA& thread_db);

//�ַ��������ݿ��ת��
std::string DataToString(char* data, size_t len);
void StringToData(std::string str, char* data, size_t& len, size_t maxLen);