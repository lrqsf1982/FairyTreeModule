#pragma once
#include <map>
#include "IObject.h"
#include "./ProtobufMSG/Msg.pb.h"

class CMessageManage
{
public:
	CMessageManage();
	static void Init();
	//dispose¥¶¿Ì
	bool Dispose(const GameMessage& msg, CServerObject* pServerObj, IMessage* pMessage);
private:
	static std::map<GameMsgCode, void(*)(const GameMessage&, CServerObject*, IMessage*)> MsgMap;
};

typedef ACE_Singleton<CMessageManage, ACE_Null_Mutex> App_MessageManage;
