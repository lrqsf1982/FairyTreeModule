#include "BaseCommand.h"
#include "./ProtobufMsg/Msg.pb.h"

CBaseCommand::CBaseCommand(void)
{
    m_pServerObject = NULL;
    m_nCount        = 0;
}

CBaseCommand::~CBaseCommand(void)
{
}

void CBaseCommand::SetServerObject(CServerObject* pServerObject)
{
    m_pServerObject = pServerObject;
}

int CBaseCommand::DoMessage(IMessage* pMessage, bool& bDeleteFlag)
{
    //__ENTER_FUNCTION���Զ�����ĺ���׷��try�ĺ꣬���ڲ�׽���������ʹ��__THROW_FUNCTION()�׳���Ĵ���
    //����__THROW_FUNCTION("hello"); �����Զ���Log�ļ����µ�assert.log��¼�ļ�������������������������
    //�Ƽ���ʹ������꣬��סһ��Ҫ�ں����Ľ���ʹ��__LEAVE_FUNCTION����__LEAVE_FUNCTION_WITHRETURN��֮��ԡ�
    //__LEAVE_FUNCTION_WITHRETURN��__LEAVE_FUNCTION��ͬ��ǰ�߿���֧�ֺ����˳���ʱ�򷵻�һ������
    //������������Ƿ���һ��int
    //��ôĩβ����__LEAVE_FUNCTION_WITHRETURN(0); 0���Ƿ��ص�int����Ȼ��Ҳ֧�ֱ�����ͱ��������忴���Լ��ĺ�����
    //��������������κα����������ʹ��__LEAVE_FUNCTION���ɡ�
    __ENTER_FUNCTION();

	if (pMessage == NULL)
	{
		OUR_DEBUG((LM_ERROR, "[CBaseCommand::DoMessage] pMessage is NULL.\n"));
		return -1;
	}

    DO_TRACE("./", pMessage->GetMessageBase()->m_szTraceID);

    if(m_pServerObject == NULL)
    {
        OUR_DEBUG((LM_ERROR, "[CBaseCommand::DoMessage] m_pServerObject is NULL(%d).\n", bDeleteFlag));
        return -1;
    }
	
    //�������ӽ�����Ϣ
    MESSAGE_FUNCTION_BEGIN(pMessage->GetMessageBase()->m_u2Cmd);
    MESSAGE_FUNCTION(CLIENT_LINK_CONNECT,     Do_Connect,           pMessage);
    MESSAGE_FUNCTION(CLIENT_LINK_CDISCONNET,  Do_DisConnect,        pMessage);
    MESSAGE_FUNCTION(CLINET_LINK_SENDTIMEOUT, Do_ClientSendTimeout, pMessage);
    MESSAGE_FUNCTION(CLIENT_LINK_SENDOK,      Do_ClientSendOk,      pMessage);
    MESSAGE_FUNCTION(COMMAND_BASE,            Do_Base,              pMessage);
	MESSAGE_FUNCTION(GAMEMSGCODE,             Do_GameMessage,       pMessage);
    MESSAGE_FUNCTION_END;

    return 0;

    __LEAVE_FUNCTION_WITHRETURN(0);
}

int CBaseCommand::Do_GameMessage(IMessage* pMessage)
{
	_PacketInfo packetInfo;
	pMessage->GetPacketBody(packetInfo);
	
	GameMessage gameMsg;
	gameMsg.ParseFromArray(packetInfo.m_pData, packetInfo.m_nDataLen);
	MESSAGE_FUNCTION_BEGIN(gameMsg.msg());
	MESSAGE_FUNCTION_THREE(Login_Request,           Process_LoginRequest,           gameMsg, m_pServerObject, pMessage);//�����¼01
	MESSAGE_FUNCTION_THREE(Elfin_Request,           Process_ElfinRequest,           gameMsg, m_pServerObject, pMessage);//����С����02
	MESSAGE_FUNCTION_THREE(Roll_Request,            Process_RollRequest,            gameMsg, m_pServerObject, pMessage);//�����ɫ��Ϣ03
	MESSAGE_FUNCTION_THREE(Tree_Request,            Process_TreeRequest,            gameMsg, m_pServerObject, pMessage);//����������04
	MESSAGE_FUNCTION_THREE(Resource_Request,        Process_ResourceRequest,        gameMsg, m_pServerObject, pMessage);//������Դ05
	MESSAGE_FUNCTION_THREE(Tasks_Request,           Process_TasksRequest,           gameMsg, m_pServerObject, pMessage);//�����ȡ�����б�06
	MESSAGE_FUNCTION_THREE(Mails_Request,           Process_MailsRequest,           gameMsg, m_pServerObject, pMessage);//�����ȡ�ʼ��б�07
	MESSAGE_FUNCTION_THREE(Sun_Request,             Process_SunRequest,             gameMsg, m_pServerObject, pMessage);//����̫��08
	MESSAGE_FUNCTION_THREE(TreeEnchantment_Request, Process_TreeEnchantmentRequest, gameMsg, m_pServerObject, pMessage);//���������09
	MESSAGE_FUNCTION_THREE(StoreAll_Request,        Process_StoreAllRequest,        gameMsg, m_pServerObject, pMessage);//�����̵�������Ʒ10
	MESSAGE_FUNCTION_THREE(StoreEqu_Request,        Process_StoreEquRequest,        gameMsg, m_pServerObject, pMessage);//�����̵�װ������Ʒ11
	MESSAGE_FUNCTION_THREE(StoreWater_Request,      Process_StoreWaterRequest,      gameMsg, m_pServerObject, pMessage);//�����̵�ˮ��Դ����Ʒ12
	MESSAGE_FUNCTION_THREE(StoreSpeProps_Request,   Process_StoreSpePropsRequest,   gameMsg, m_pServerObject, pMessage);//�����̵���������Ʒ13
	MESSAGE_FUNCTION_THREE(Warehouse_Request,       Process_WarehouseRequest,       gameMsg, m_pServerObject, pMessage);//����ֿ�������Ʒ14
	MESSAGE_FUNCTION_THREE(DelMail_Request,         Process_DelMailRequest,         gameMsg, m_pServerObject, pMessage);//����ɾ���ʼ�15
	MESSAGE_FUNCTION_THREE(ClaimedTask_Request,     Process_ClaimedTaskRequest,     gameMsg, m_pServerObject, pMessage);//������ȡ����16
	MESSAGE_FUNCTION_THREE(RecTaskAward_Request,    Process_RecTaskAwardRequest,    gameMsg, m_pServerObject, pMessage);//����������17
	MESSAGE_FUNCTION_THREE(Friends_Request,         Process_FriendsRequest,         gameMsg, m_pServerObject, pMessage);//��������б�18
	MESSAGE_FUNCTION_THREE(Enemies_Request,         Process_EnemiesRequest,         gameMsg, m_pServerObject, pMessage);//��������б�19
	MESSAGE_FUNCTION_THREE(Plunder_Request,         Process_PlunderRequest,         gameMsg, m_pServerObject, pMessage);//�����Ӷ�20
	MESSAGE_FUNCTION_THREE(UseItem_Request,         Process_UseItemRequest,         gameMsg, m_pServerObject, pMessage);//������Ʒ21
	MESSAGE_FUNCTION_THREE(SettleAccount_Request,   Process_SettleAccountRequest,   gameMsg, m_pServerObject, pMessage);//�������22
	MESSAGE_FUNCTION_THREE(Ranking_Request,         Process_RankingRequest,         gameMsg, m_pServerObject, pMessage);//�����ȡ���а��б�23
	MESSAGE_FUNCTION_THREE(ForgetSkill_Request,     Process_ForgetSkillRequest,     gameMsg, m_pServerObject, pMessage);//������������24
	MESSAGE_FUNCTION_THREE(Register_Request,        Process_RegisterRequest,        gameMsg, m_pServerObject, pMessage);//ע������25
	MESSAGE_FUNCTION_THREE(SolarUpgrade_Request,    Process_SolarUpgradeRequest,    gameMsg, m_pServerObject, pMessage);//̫����������26
	MESSAGE_FUNCTION_THREE(SkillUpgrade_Request,    Process_SkillUpgradeRequest,    gameMsg, m_pServerObject, pMessage);//������������27
	MESSAGE_FUNCTION_THREE(TreeUpgrade_Request,     Process_TreeUpgradeRequest,     gameMsg, m_pServerObject, pMessage);//��������������28
	MESSAGE_FUNCTION_THREE(ElfinUpgrade_Request,    Process_ElfinUpgradeRequest,    gameMsg, m_pServerObject, pMessage);//С������������29
	MESSAGE_FUNCTION_THREE(HeartBeat_Request,       Process_HeartBeatRequest,       gameMsg, m_pServerObject, pMessage);//����������30
	MESSAGE_FUNCTION_END;

	return 0;

}

int CBaseCommand::Do_Connect(IMessage* pMessage)
{
    OUR_DEBUG((LM_ERROR, "[CBaseCommand::Do_Connect] (%d)TCP CLIENT_LINK_CONNECT OK.\n", pMessage->GetMessageBase()->m_u4ConnectID));

    //�жϵ�ǰ���������Ƿ�Խ��2000��
    int nConnectCount = m_pServerObject->GetConnectManager()->GetCount();

    if(nConnectCount > 2000)
    {
        OUR_DEBUG((LM_ERROR, "[CBaseCommand::Do_Connect]connect count is more(%d).\n", nConnectCount));
    }

    return 0;
}

int CBaseCommand::Do_DisConnect(IMessage* pMessage)
{
    //�������ӶϿ��¼�
    OUR_DEBUG((LM_ERROR, "[CBaseCommand::Do_DisConnect](%d)CLIENT_LINK_CDISCONNET OK.\n", pMessage->GetMessageBase()->m_u4ConnectID));

	//������˳���Ϸʱ��������ݿ�
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	//���ݿ�Ľӿ�

    return 0;
}

int CBaseCommand::Do_ClientSendTimeout(IMessage* pMessage)
{
    //������������Ϳͻ����������ӳ�����ֵ���¼�
    OUR_DEBUG((LM_ERROR, "[CBaseCommand::Do_DisConnect](%d)CLINET_LINK_SNEDTIMEOUT OK.\n", pMessage->GetMessageBase()->m_u4ConnectID));

    return 0;
}

int CBaseCommand::Do_Base(IMessage* pMessage)
{
    //OUR_DEBUG((LM_INFO, "[CBaseCommand::DoMessage] TcpTest CommandID = %d", COMMAND_BASE));
    //m_pServerObject->GetLogManager()->WriteToMail(LOG_SYSTEM, 1, "�����ʼ�", "����");

    IBuffPacket* pBodyPacket = m_pServerObject->GetPacketManager()->Create();

    if(NULL == pBodyPacket)
    {
        OUR_DEBUG((LM_ERROR, "[CBaseCommand::DoMessage] pBodyPacket is NULL.\n"));
        return -1;
    }

    _PacketInfo BodyPacket;
    pMessage->GetPacketBody(BodyPacket);

    //��ϢȾɫ����
    DO_TRACE("./", pMessage->GetMessageBase()->m_szTraceID);

    //���Լ�¼��������־
    //m_pServerObject->GetLogManager()->WriteLogBinary(LOG_SYSTEM, BodyPacket.m_pData, BodyPacket.m_nDataLen);

    IBuffPacket* pResponsesPacket = m_pServerObject->GetPacketManager()->Create();
    uint16 u2PostCommandID = COMMAND_BASE;

    //����ԭ���
    (*pResponsesPacket) << (uint32)BodyPacket.m_nDataLen;
    pResponsesPacket->WriteStream(BodyPacket.m_pData, BodyPacket.m_nDataLen);

    //(*pResponsesPacket) << u2PostCommandID;
    //(*pResponsesPacket) << u8ClientTime;
    int nMessageID = 1;

    m_pServerObject->GetPacketManager()->Delete(pBodyPacket);

    if(NULL != m_pServerObject->GetConnectManager())
    {
        //����ȫ������
        m_pServerObject->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
                pResponsesPacket,
                SENDMESSAGE_JAMPNOMAL,
                u2PostCommandID,
                PACKET_SEND_IMMEDIATLY,
                PACKET_IS_FRAMEWORK_RECYC,
                nMessageID);
    }
    else
    {
        OUR_DEBUG((LM_INFO, "[CBaseCommand::DoMessage] m_pConnectManager = NULL"));
        m_pServerObject->GetPacketManager()->Delete(pResponsesPacket);
    }

    //m_pServerObject->GetConnectManager()->CloseConnect(pMessage->GetMessageBase()->m_u4ConnectID);

    return 0;
}

void CBaseCommand::ReadIniFile(const char* pIniFileName)
{
    if(NULL == pIniFileName)
    {
        return;
    }
}

int CBaseCommand::Do_ClientSendOk(IMessage* pMessage)
{
    //�������ݷ��ͳɹ��¼�
    _PacketInfo HeadPacket;
    pMessage->GetPacketHead(HeadPacket);
    int nMessageID = 0;
    memcpy_safe(HeadPacket.m_pData, sizeof(int),(char* )&nMessageID, sizeof(int));

    OUR_DEBUG((LM_INFO, "[CBaseCommand::DoMessage]nMessageID=%d, ConnectID=%d.\n", nMessageID, pMessage->GetMessageBase()->m_u4ConnectID));

    return 0;
}
