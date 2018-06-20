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
const std::string    DB_KEY_TASK_			= "taskdata";			//����
const std::string    DB_KEY_FINISH_TASK_	= "taskfinishdata";		//�������
const std::string    DB_KEY_FRIEND_			= "Frienddata";			//�ѷ�����
const std::string    DB_KEY_MAIL			= "maildata";			//�ʼ�
const std::string    DB_KEY_SHOP_			= "Shop";				//�̵�
const std::string    DB_KEY_NEWS_			= "news";				//��Ϣ
const std::string    DB_KEY_INVITATION_DATA_= "invitationdata";		//����
const std::string    DB_KEY_RANK_DATA		= "RankData";			//����
const std::string	 MDB_KEY_CHAT_			= "charactertdata";		//��ɫ
const std::string    DB_KEY_PET_GUILD		= "elfinaguild";		//����

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

#endif // MEMDB_H