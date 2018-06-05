#pragma once

#include "IBuffPacket.h"
#include "ClientCommand.h"
#include "IObject.h"
#include "Trace.h"
#include "ProcessMsg.h"

#include <string>

//定义客户端信令(TCP)
//默认命令ID必须是CLIENT_LINK_USER以后的数字，之前的命令ID是保留字
#define COMMAND_BASE            0x1000
#define COMMAND_BASE_ID         0x1201  //流解析数据包命令字 连接ID
#define COMMAND_RETURN_ALIVE    0xf000

#ifndef GAMEMSGCODE 
#define GAMEMSGCODE 3000
#endif

#define MESSAGE_FUNCTION_BEGIN(x) switch(x) {
#define MESSAGE_FUNCTION(x,y,z) case x: { y(z); break; }
#define MESSAGE_FUNCTION_TOW(x,y,z1,z2) case x: { y(z1, z2); break; }
#define MESSAGE_FUNCTION_THREE(x,y,z1,z2,z3) case x: { y(z1, z2, z3); break; }
#define MESSAGE_FUNCTION_END }

using namespace std;

class CBaseCommand : public CClientCommand
{
public:
    CBaseCommand(void);
    ~CBaseCommand(void);

    int DoMessage(IMessage* pMessage, bool& bDeleteFlag);
    void SetServerObject(CServerObject* pServerObject);

    void ReadIniFile(const char* pIniFileName);

private:
    int Do_Connect(IMessage* pMessage);
    int Do_DisConnect(IMessage* pMessage);
    int Do_ClientSendTimeout(IMessage* pMessage);
    int Do_Base(IMessage* pMessage);
    int Do_ClientSendOk(IMessage* pMessage);
	int Do_GameMessage(IMessage* pMessage);


private:
    CServerObject* m_pServerObject;
    int            m_nCount;
};
