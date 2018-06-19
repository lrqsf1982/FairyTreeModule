// Base.cpp : һ��TCP�Ĳ�����
//����PurenessScopeServer�Ĳ��Ժ�ʹ��
//���ǵ�����˳��static CBaseCommand��Ϊָ�룬������֤ACE��ȫ�ֶ�������˳��һ�¡�
//add by freeeyes
//2011-09-20

#include "BaseCommand.h"
#include "IObject.h"
#include "./ProtobufMSG/Msg.pb.h"
#include "XmlConfigManager.h"

#include "ace/svc_export.h"

static const char* g_szDesc      = "��������ս��Ϸ";       //ģ�����������
static const char* g_szName      = "������";           //ģ�������
static const char* g_szModuleKey = "��Ϸ";           //ģ���Key

#ifdef WIN32
#ifdef TEST_TCP_BUILD_DLL
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif
#else
#define DECLDIR ACE_Svc_Export
#endif

extern "C"
{
    DECLDIR int LoadModuleData(CServerObject* pServerObject);
    DECLDIR int UnLoadModuleData();
    DECLDIR int InitModule(CServerObject* pServerObject);
    DECLDIR const char* GetDesc();
    DECLDIR const char* GetName();
    DECLDIR const char* GetModuleKey();
    DECLDIR int DoModuleMessage(uint16 u2CommandID, IBuffPacket* pBuffPacket, IBuffPacket* pReturnBuffPacket);
    DECLDIR bool GetModuleState(uint32& u4ErrorID);
}

CBaseCommand*        g_BaseCommand   = NULL;
CServerObject*       g_pServerObject = NULL;


int LoadModuleData(CServerObject* pServerObject)
{
    g_pServerObject = pServerObject;

    if(NULL != g_BaseCommand)
    {
        SAFE_DELETE(g_BaseCommand);
    }

    g_BaseCommand = new CBaseCommand();

	XmlConfigManager* pxmlConfigManager = XmlConfigManager::GetInstance();//��ʼXml���ݵ��ڴ���

    OUR_DEBUG((LM_INFO, "[Base LoadModuleData] Begin.\n"));

    if(g_pServerObject != NULL)
    {
        g_BaseCommand->SetServerObject(pServerObject);
    }
    else
    {
        OUR_DEBUG((LM_INFO, "[Base LoadModuleData] pServerObject is NULL.\n"));
		return -1;
    }

    IMessageManager* pMessageManager = g_pServerObject->GetMessageManager();

    if(NULL != pMessageManager)
    {
        pMessageManager->AddClientCommand(COMMAND_BASE, g_BaseCommand, g_szName);

        //���԰�ָ���ļ����˿�
        //_ClientIPInfo objClientIPInfo;
        //sprintf_safe(objClientIPInfo.m_szClientIP, MAX_BUFF_50, "0.0.0.0", objClientIPInfo);
        //objClientIPInfo.m_nPort = 10002;
        //pMessageManager->AddClientCommand(COMMAND_BASE, &g_BaseCommand, g_szName);

        pMessageManager->AddClientCommand(CLIENT_LINK_CONNECT, g_BaseCommand, g_szName);
        pMessageManager->AddClientCommand(CLIENT_LINK_CDISCONNET, g_BaseCommand, g_szName);
        pMessageManager->AddClientCommand(CLINET_LINK_SENDTIMEOUT, g_BaseCommand, g_szName);
        pMessageManager->AddClientCommand(CLIENT_LINK_SENDOK, g_BaseCommand, g_szName);


		pMessageManager->AddClientCommand(Login_Request,            g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Login_Response,           g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Elfin_Request,            g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Elfin_Response,           g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Roll_Request,             g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Roll_Response,            g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Tree_Request,             g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Tree_Response,            g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Resource_Request,         g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Resource_Response,        g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Tasks_Request,            g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Tasks_Response,           g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Mails_Request,            g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Mails_Response,           g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Sun_Request,              g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Sun_Response,             g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(TreeEnchantment_Request,  g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(TreeEnchantment_Response, g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(StoreAll_Request,         g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(StoreAll_Response,        g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(StoreEqu_Request,         g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(StoreEqu_Response,        g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(StoreWater_Request,       g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(StoreWater_Response,      g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(StoreSpeProps_Request,    g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(StoreSpeProps_Response,   g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Warehouse_Request,        g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Warehouse_Response,       g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(DelMail_Request,          g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(DelMail_Response,         g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(ClaimedTask_Request,      g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(ClaimedTask_Response,     g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(RecTaskAward_Request,     g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(RecTaskAward_Response,    g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Friends_Request,          g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Friends_Response,         g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Enemies_Request,          g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Enemies_Response,         g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Plunder_Request,          g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Plunder_Response,         g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(UseItem_Request,          g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(UseItem_Response,         g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(SettleAccount_Request,    g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(SettleAccount_Response,   g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Ranking_Request,          g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Ranking_Response,         g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(ForgetSkill_Request,      g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(ForgetSkill_Response,     g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Register_Request,         g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(Register_Response,        g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(SolarUpgrade_Request,     g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(SolarUpgrade_Response,    g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(SkillUpgrade_Request,     g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(SkillUpgrade_Response,    g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(TreeUpgrade_Request,      g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(TreeUpgrade_Response,     g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(ElfinUpgrade_Request,     g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(ElfinUpgrade_Response,    g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(HeartBeat_Request,        g_BaseCommand, g_szName);
		pMessageManager->AddClientCommand(HeartBeat_Response,       g_BaseCommand, g_szName);

    }
    else
    {
        OUR_DEBUG((LM_INFO, "[Base LoadModuleData] pMessageManager = NULL.\n"));
		return -1;
    }

    //��ʾ�����˿���Ϣ
    uint32 u4ListenCount = pServerObject->GetControlListen()->GetListenCount();

    for (uint32 i = 0; i < u4ListenCount; i++)
    {
        _ControlInfo objControlInfo;
        pServerObject->GetControlListen()->ShowListen(i, objControlInfo);
        OUR_DEBUG((LM_INFO, "[Base LoadModuleData] Listen IP=%s, Pord=%d.\n", objControlInfo.m_szListenIP, objControlInfo.m_u4Port));
    }

    //��ʾ��ܹ����߳�ID
    OUR_DEBUG((LM_INFO, "[Base LoadModuleData] *********************************.\n"));

    uint32 u4WorkThread = pMessageManager->GetWorkThreadCount();
    OUR_DEBUG((LM_INFO, "[Base LoadModuleData] WorkThreadCount=%d.\n", u4WorkThread));

    for(uint32 u4Index = 0; u4Index < u4WorkThread; u4Index++)
    {
        OUR_DEBUG((LM_INFO, "[Base LoadModuleData] WorkThreadID=%d.\n", pMessageManager->GetWorkThreadByIndex(u4Index)));
    }

    OUR_DEBUG((LM_INFO, "[Base LoadModuleData] *********************************.\n"));

    g_BaseCommand->ReadIniFile(pServerObject->GetModuleInfo()->GetModuleParam(g_szName));

    OUR_DEBUG((LM_INFO, "[Base LoadModuleData] End.\n"));

    return 0;
}

int UnLoadModuleData()
{
    //ж�ز�������Զ����ò�����գ�����Ҫ���ֶ�pMessageManager->DelClientCommand
    OUR_DEBUG((LM_INFO, "[Base UnLoadModuleData] Begin.\n"));

    SAFE_DELETE(g_BaseCommand);

    OUR_DEBUG((LM_INFO, "[Base UnLoadModuleData] End.\n"));
    return 0;
}

int InitModule(CServerObject* pServerObject)
{
    OUR_DEBUG((LM_INFO, "[InitModule] Begin.\n"));
    ACE_UNUSED_ARG(pServerObject);
    return 0;
}

const char* GetDesc()
{
    return g_szDesc;
}

const char* GetName()
{
    return g_szName;
}

const char* GetModuleKey()
{
    return g_szModuleKey;
}

//����ģ���ĵ��ýӿ�
int DoModuleMessage(uint16 u2CommandID, IBuffPacket* pBuffPacket, IBuffPacket* pReturnBuffPacket)
{
    OUR_DEBUG((LM_INFO, "[DoModuleMessage] u2CommandID=%d, size=%d, return=%d.\n",
               u2CommandID,
               pBuffPacket->GetPacketLen(),
               pReturnBuffPacket->GetPacketLen()));
    return 0;
}


//�������ʹ�ã����ڿ�ܶ�ʱѲ����״̬
//Ĭ�����ﷵ��true���������Ҫ�Կ���ڲ�ϸ������ء�
//��������ʵ��֮�����ݴ���Ĳ�ͬ������false��ͬʱ������ErrorID
//��ܻ����������ã������ʼ���ָ��������
bool GetModuleState(uint32& u4ErrorID)
{
    OUR_DEBUG((LM_INFO, "[GetModuleState] u4ErrorID=%d.\n",
               u4ErrorID));
    return true;
}

