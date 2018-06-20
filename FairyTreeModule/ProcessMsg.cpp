#include "ProcessMsg.h"
#include "FairyTreeUserClasses.h"
#include "MD5.h"

//����
//��¼����1
void Process_LoginRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{	
	//���ȴ����ݿ���Ա�id
	LoginRequest logreq;

	//���մӿͻ��˷��͹�����΢����Ϣ
	//��������Ӧ�Ĵ���

	//�Ա��˻��˺� ������ݿ����� ˵�����ǵ�һ�ε�½ ������ݿ���û�� ˵���ǵ�һ�ε�½
	//���Ϊ��˵���ǵ�һ�ε�½, ���Ϊ��˵������
	bool bcont = true;//bcont = ���ݿ�Ľӿں���();
	 //�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser;
	if (bcont)
	{
		faitreUser = new FairyTreeUserClasses;
		faitreUser->Set_UserId(1);//�������û���ID �� 1 �Ǵӵ�һ�����û� 10000 + 1��ʼ
		std::string xinName = "XinName";
		faitreUser->Set_UserName(xinName);//�������û������� ΢����
		faitreUser->Set_UserWeChatID(123456);//�������û���΢�ź�
		faitreUser->Set_UserGrowthValue(0);//�������û��ĳɳ�ֵ

										   //Ȼ���ڷ���Ӧ������
										   //Ӧ����
		
	}

	//��֮�Ͳ��ǵ�һ�ε�½
	else
	{
		//ֱ�ӵ�Ӧ����
		//Ȼ���ڷ���Ӧ������
		//Ӧ����
		
	}
Process_LoginResponse(pMsg, pServerObj, pMessage);

	//���õ�һ�ε�½�ĵ�ǰ�û���صĳ�ʼ����, ��Щ���ԴӶ�ȡ��xml�ļ���map ����
	//��:��ʼС���������, ��ʼ������������, ��ʼ������Ϸ��ҵ���Ϸid��,
	//��ʼ��Ϸ��ҵ�����, ΢��id��, ��ʼ��ҵ���Դ��(ˮ,���,����,��ʯ������),
	//��ʼ�ʼ�,����, �����б�, ̫��������, ��Ϸ��ҵĲֿ�, ��ʼ��Ϸ��ҵ������, 
	//�̵�(��Ʒ��id, ��Ʒ������, ��Ʒ�������ȵȵ�), �������а�, ��ϵ��, ��ɫ��, �ȵȵȵ�

	//�����Ϸ��Ҳ��ǵ�һ�ε�½,��ֱ����Ӧ����


	

}

//С��������2
void Process_ElfinRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//�յ����󷵻�����

	//Ӧ����
	Process_ElfinResponse(pMsg, pServerObj, pMessage);

}

//��ɫ��Ϣ����3
void Process_RollRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//RollRequest rollreq;

	//�յ���ɫ��Ϣ����
	//rollreq.roll();

	//Ӧ����
	Process_RollResponse(pMsg, pServerObj, pMessage);
}

//����������4
void Process_TreeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//TreeRequest ptreReq;

	//�յ������������� ��������
	//ptreReq.tree();

	//Ӧ����
	Process_TreeResponse(pMsg, pServerObj, pMessage);

}

//��Դ����5
void Process_ResourceRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//ResourceRequest rocrut;

	//�յ���Դ����
	//rocrut.resource();

	//Ӧ����
	Process_ResourceResponse(pMsg, pServerObj, pMessage);
}

//��ȡ�����б�����6
void Process_TasksRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//TasksRequest ptasReq;

	//��ȡ�����б�����
	//ptasReq.tasks();

	//Ӧ����
	Process_TasksResponse(pMsg, pServerObj, pMessage);
}

//�ʼ�����7
void Process_MailsRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//MailsRequest pmaiReq;

	//��ȡ�ʼ��б���Ϣ
	//pmaiReq.mails();

	//Ӧ����
	Process_MailsResponse(pMsg, pServerObj, pMessage);

}

//̫������8
void Process_SunRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//SunRequest pwelReq;

	//�յ�̫�������� ��������
	//pwelReq.sun();

	//Ӧ����
	Process_SunResponse(pMsg, pServerObj, pMessage);

}

//���������9
void Process_TreeEnchantmentRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//TreeEnchantmentRequest ptreEncReq;

	//�յ����� ��������
	//ptreEncReq.treeench();

	//Ӧ����
	Process_TreeEnchantmentResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�̵�������Ʒ����10
void Process_StoreAllRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//StoreAllRequest stoall;

	//�յ��̵�������Ʒ����
	//stoall.storeall();

	//Ӧ����
	Process_StoreAllResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�̵�װ������Ʒ����11
void Process_StoreEquRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//StoreEquRequest stoequ;

	//�յ��̵�װ������Ʒ����
	//stoequ.storeequ();

	//Ӧ����
	Process_StoreEquResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�̵�ˮ��Դ����Ʒ����12
void Process_StoreWaterRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//StoreWaterRequest stowatreq;

	//�յ��̵�ˮ��Դ����Ʒ����
	//stowatreq.storewater();

	//Ӧ����
	Process_StoreWaterResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�̵���������Ʒ����13
void Process_StoreSpePropsRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//StoreSpePropsRequest stospeproreq;

	//�յ��̵���������Ʒ����
	//stospeproreq.storespeprops();

	//Ӧ����
	Process_StoreSpePropsResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�ֿ�������Ʒ����14
void Process_WarehouseRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//WarehouseRequest warehreq;

	//�յ��ֿ�������Ʒ����
	//warehreq.warehouse();

	//Ӧ����
	Process_WarehouseResponse(pMsg, pServerObj, pMessage);

}

//ɾ���ʼ�����15
void Process_DelMailRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	DelMailRequest delmail;

	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//�յ�ɾ���ʼ�����
	if (delmail.id() == faitreUser->Get_CMailbox()->Get_MailClassMap()[delmail.id()]->Get_MailSerialNumber())
	{
		faitreUser->Get_CMailbox()->CloseMail(delmail.id());
	}

	//Ӧ����
	Process_DelMailResponse(pMsg, pServerObj, pMessage);

}

//������ȡ����16
void Process_ClaimedTaskRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	ClaimedTaskRequest clatask;

	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//�յ���ȡ�������� ������Ϊ��ǰ����״̬
	if (clatask.id() == faitreUser->Get_CTaskListClass()->Get_TaskMap()[clatask.id()]->Get_TSerialNumber())
	{
		faitreUser->Get_CTaskListClass()->Get_TaskMap()[clatask.id()]->Set_TaskStateResult(1);
	}

	//Ӧ����
	Process_ClaimedTaskResponse(pMsg, pServerObj, pMessage);

}

//����������17
void Process_RecTaskAwardRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	RecTaskAwardRequest rectaskaward;

	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//�յ����������� ������������Ʒ������û��Ĳֿ�����(?��Ʒ��������ʲô,��Ʒ�������Ƕ���)
	rectaskaward.id();

	//Ӧ����
	Process_RecTaskAwardResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�����б�����18
void Process_FriendsRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//�յ������б�����
	//FriendsRequest friendsreq;

	//friendsreq.friends();

	//Ӧ����
	Process_FriendsResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�����б�����19
void Process_EnemiesRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//EnemiesRequest enemreq;

	//�յ������б�����
	//enemreq.enemies();

	//Ӧ����
	Process_EnemiesResponse(pMsg, pServerObj, pMessage);

}

//����Ӷ�����20
void Process_PlunderRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//PlunderRequest ppluReq;

	// �õ���Ϣ����ID
	//uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	//FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//�Ӷ����� С�����ID
	//ppluReq.elfinid();

	//�յ��Ӷ����� �������һ���û�ID���ͻ���

	//Ӧ����
	Process_PlunderResponse(pMsg, pServerObj, pMessage);

}

//ʹ����Ʒ����21
void Process_UseItemRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	UseItemRequest useitereq;

	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];
	
	//�յ�ʹ����Ʒ���� С�����������ʹ����Ʒ,����������������,����С����ĵ�ǰ����ֵ����, (? �������ֵ����� ?)
	//����յ�����Ʒ��� ���� ��ǰ�û��Ĳֿ�map�����Ʒ���
	if (useitereq.itemid() == faitreUser->Get_Warehouse()->Get_ArticleMap()[useitereq.itemid()]->Get_CArticleSerialNumber())
	{
		//��ǰ�û��Ĳֿ�map�����Ʒͨ����Ʒ��� ɾ������Ʒ
		faitreUser->Get_Warehouse()->CloseArticle(useitereq.itemid());
		//С����ĵ�ǰ����ֵ���� 2 ����
		
		//�������ĵȼ��� 1
		faitreUser->Get_FairyTree()->Set_FGrade(true);
		//�����������߼� 1
		faitreUser->Get_FairyTree()->Set_TreeHeight(1);
		//�������Ĵ洢��ҵ��������� 2 ����
		faitreUser->Get_FairyTree()->Set_FAddFaiTreStoGol(2);
		//������������ʱ������ 5 ����
		faitreUser->Get_FairyTree()->Set_FGoldTime(5);
		//����������������������� 2 ����
		faitreUser->Get_FairyTree()->Set_FGold(2);
	}

	//Ӧ����
	Process_UseItemResponse(pMsg, pServerObj, pMessage);

}

//��������22
void Process_SettleAccountRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//�յ����� ��������

	//Ӧ����
	Process_SettleAccountResponse(pMsg, pServerObj, pMessage);
	
}

//�����ȡ���а��б�23
void Process_RankingRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//��ȡ���а��б�

	//Ӧ����
	Process_RankingResponse(pMsg, pServerObj, pMessage);

}

//������������24
void Process_ForgetSkillRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//�յ�����
	ForgetSkillRequest pforSkiReq;

	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//��������С����ļ���
	
	
	//Ӧ����
	Process_ForgetSkillResponse(pMsg, pServerObj, pMessage);

}

//ע������25
void Process_RegisterRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	RegisterRequest pregReq;
	//bool isHaveAccount=false;
	//���յ�����ʱ,�Ա����ݿ����Ƿ�����ͬ���˺���.�����,�ͷ��ش���(�˺��Ѵ���).
	//���û�оͽ�����ת����MD5��,���ҽ�(�˺�,����,����)�������ݿ�.�����سɹ�
	//if (isHaveAccount == FALSE)
	//{
		//TODO����������id,����ʼ����������,Ĭ�ϳ�ʼid,��ǰ�������+1,�����������ݿ�,100000
	//}
	//else
	//{//TODO
		//����һ���û���Ķ���,�����������ݿ��ж�Ӧid������
		//��������id���û���Ķ���ָ��,����map����
	//}
	//���سɹ�
	//uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���
	//FairyTreeUserClasses* faitreUser = new FairyTreeUserClasses();
	//CAllUserInfoInstance::GetInstance()->ConnetedUser[faitreUser->Get_RecordUserCount()] = faitreUser;
	//faitreUser->Set_UserId(1);
	//Ӧ����
	Process_RegisterResponse(pMsg, pServerObj, pMessage);

}

//̫����������26
void Process_SolarUpgradeRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//�յ�����̫��������
	SolarUpgradeRequest solReq;
	
	//�߼�����̫������

	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//̫���ĵȼ��� 1
	faitreUser->Get_SunShine()->Set_SunLevel(solReq.solar());
	

	//����Ӧ��
	Process_SolarUpgradeResponse(pMsg, pServerObj, pMessage);
}

//������������27
void Process_SkillUpgradeRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//�յ�������������
	SkillUpgradeRequest skiReq;

	//�߼�����������
	
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//������ǰ�û��µ�С����ļ��ܵĵȼ�
	


	Process_SkillUpgradeResponse(pMsg, pServerObj, pMessage);
}

//��������������28
void Process_TreeUpgradeRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//�յ�����������������
	TreeUpgradeRequest trReq;
	
	//�߼�����������������

	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//����������
	faitreUser->Get_FairyTree()->Set_FGrade(trReq.tree());


	Process_TreeUpgradeResponse(pMsg, pServerObj, pMessage);
}

//С������������29
void Process_ElfinUpgradeRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//�յ�С�������������
	ElfinUpgradeRequest elReq;

	//�߼�����С���������
	elReq.elfinid();
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//����С���������
	
	

	Process_ElfinUpgradeResponse(pMsg, pServerObj, pMessage);
}

//����������30
void Process_HeartBeatRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//�����κδ���
	Process_HeartBeatResponse(pMsg, pServerObj, pMessage);
}


//------------------------------------------------------------------------------------------------------------


//Ӧ��
//��¼Ӧ��1
void Process_LoginResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	LoginResponse* pLogin = pRes->release_login();
	pLogin = pRes->mutable_login();
	//--------------------------------------------------------------
	LoginRequest logreq;
	bool bcont = true;//�Ա����ݿ� bcont = ���ݿ�ĺ���();
	//����û����ǵ�һ�ε�½,���ص����ݾ��Ǵ����ݿ�����ֱ����.�����ظ��ͻ���
	if (bcont)
	{
		//����˻��˺Ŵ���,ֱ�ӷ���1����
		pLogin->set_result(LoginResponse_ResultType_PsswadError);
	}
	//���÷���Ϊ �ɹ� 0
	else
	{
		pLogin->set_result(LoginResponse_ResultType_Success);
	}

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3001)
	gameMsg.set_msg(Login_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_50] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(msgLen), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//С����Ӧ��2
void Process_ElfinResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ElfinResponse* pelf = pRes->release_elfin();
	pelf = pRes->mutable_elfin();
	//--------------------------------------------------------------

	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//��֯Ӧ����Ϣ����(ID,�ȼ�,����,�������,����)
	pelf->set_id(1000101);
	pelf->set_level(1); 
	pelf->set_power(10); 
	pelf->set_maxpower(10); 
	switch (ElfinSkillType::EGOLD)
	{
	case ElfinSkillType::EGOLD:
	{
		pelf->set_etype(ElfinResponse_Elfintype_Jin);
		break;
	}
	case ElfinSkillType::EWOOD:
	{
		pelf->set_etype(ElfinResponse_Elfintype_Mu);
		break;
	}
	case ElfinSkillType::EWATER:
	{
		pelf->set_etype(ElfinResponse_Elfintype_Shui);
		break;
	}
	case ElfinSkillType::EFIRE:
	{
		pelf->set_etype(ElfinResponse_Elfintype_Huo);
		break;
	}
	case ElfinSkillType::ESOIL:
	{
		pelf->set_etype(ElfinResponse_Elfintype_Tu);
		break;
	}
	}

	//--------------------------------------------------------------
	//������ϢӦ��(ö��  3011)
	gameMsg.set_msg(Elfin_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//��ɫ��ϢӦ��3
void Process_RollResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RollResponse* proll = pRes->release_roll();
	proll = pRes->mutable_roll();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//��֯Ӧ����Ϣ����(ID,����,�ɳ�ֵ,ͼƬ�ĵ�ַ)
	//proll->set_id(); 
	//proll->set_name();
	//proll->set_growrate();
	//proll->set_headurl();


	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3021)
	gameMsg.set_msg(Roll_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//������Ӧ��4
void Process_TreeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TreeResponse* ptree = pRes->release_tree();
	ptree = pRes->mutable_tree();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//��֯Ӧ����Ϣ����(�ȼ�,����,�����,ÿ�������Ľ��)
	ptree->set_level(faitreUser->Get_FairyTree()->Get_FGrade());
	ptree->set_hight(faitreUser->Get_FairyTree()->Get_TreeHeight());
	ptree->set_prodgold(faitreUser->Get_FairyTree()->Get_FFaiTreStoGol());

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3031)
	gameMsg.set_msg(Tree_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//��ԴӦ��5
void Process_ResourceResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ResourceResponse* presres = pRes->release_resource();
	presres = pRes->mutable_resource();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//��֯Ӧ����Ϣ����(���,��ͨˮ,����,��ʯ)
	//presres->set_gold();
	//presres->set_water();
	//presres->set_sunshine(faitreUser->Get_SunShine().Get_FSunNumber());
	//presres->set_diamond();

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3041)
	gameMsg.set_msg(Resource_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);


}

//��ȡ�����б�Ӧ��6
void Process_TasksResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TasksResponse* ptasks = pRes->release_tasks();
	ptasks = pRes->mutable_tasks();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];


	for (uint32 i = 0; i < faitreUser->Get_CTaskListClass()->GetTaskCount(); ++i)
	{
		TaskClass* taskclass = faitreUser->Get_CTaskListClass()->ErgodicTask(i);

		//��֯Ӧ����Ϣ����(ID,����,����,����,��ʽ)
		ptasks->set_id(taskclass->Get_TSerialNumber());
		ptasks->set_title(taskclass->Get_TTaskheadline());
		ptasks->set_details(taskclass->Get_TTaskContent());
		switch (taskclass->Get_TaskStateResult())
		{
		case NotYet:
		{
			ptasks->set_type(TasksResponse_TaskType_NotYet);
			break;
		}
		case Already:
		{
			ptasks->set_type(TasksResponse_TaskType_Already);
			break;
		}
		case Done:
		{
			ptasks->set_type(TasksResponse_TaskType_Done);
			break;
		}
		case Received:
		{
			ptasks->set_type(TasksResponse_TaskType_Received);
			break;
		}
		}
		
		/*Prize* spr1 = new Prize();
		Prize* spr2 = new Prize();
		Prize* spr3 = new Prize();
		TaskInfo* pTaskInfo = XmlConfigManager::GetInstance()->TaskInfos[taskclass->Get_TSerialNumber()];

		if (NULL != pTaskInfo->bonusitemnumOne)
		{
			spr1->set_id(pTaskInfo->bonusitemnumOne);
			spr1->set_number(pTaskInfo->numberOne);
			ptasks->set_allocated_prize1(spr1);
		}

		if (NULL != pTaskInfo->bonusitemnumTwo)
		{
			spr2->set_id(pTaskInfo->bonusitemnumTwo);
			spr2->set_number(pTaskInfo->numberTwo);
			ptasks->set_allocated_prize2(spr2);
		}

		if (NULL != pTaskInfo->bonusitemnumThree)
		{
			spr3->set_id(pTaskInfo->bonusitemnumThree);
			spr3->set_number(pTaskInfo->numberThree);
			ptasks->set_allocated_prize3(spr3);
		}*/

		//--------------------------------------------------------------
		//������ϢӦ��(ö�� 3051)
		gameMsg.set_msg(Tasks_Response);

		//�õ�����
		uint32 msgLen = gameMsg.ByteSize();
		//���л�����
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//�����ݷ���洢�������� ���̷���
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);

		/*delete[] spr1;
		delete[] spr2;
		delete[] spr3;*/
	}
}

//�ʼ�Ӧ��7
void Process_MailsResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	MailsResponse* pmail = pRes->release_mails();
	pmail = pRes->mutable_mails();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];
	
	for (uint32 i = 0; i < faitreUser->Get_CMailbox()->MailNumber(); i++)
	{
		Mail* mail = faitreUser->Get_CMailbox()->ErgodicMail(i);

		//��֯Ӧ����Ϣ����(ID,��ͷ,����ϸ��,���ͽ��,��Ʒ�ĸ�ʽ)
		pmail->set_id(mail->Get_MailSerialNumber());
		
		pmail->set_title(mail->Get_MailHeadline());
		
		pmail->set_details(mail->Get_MailContent());
		pmail->set_received(mail->MailArticleGetState());

		Prize* spr1 = new Prize();
		Prize* spr2 = new Prize();
		Prize* spr3 = new Prize();
		if (0 < mail->GetPrizes().size())
		{
			std::map<uint32, uint32>::iterator it = mail->GetPrizes().begin();
			spr1->set_id(it->first);
			spr1->set_number(it->second);
			pmail->set_allocated_prize1(spr1);
			it++;
			if (it!=mail->GetPrizes().end())
			{
				spr2->set_id(it->first);
				spr2->set_number(it->second);
				pmail->set_allocated_prize2(spr2);
				
			}
			it++;
			if (it != mail->GetPrizes().end())
			{
				spr3->set_id(it->first);
				spr3->set_number(it->second);
				pmail->set_allocated_prize3(spr3);
			}
		}
		//--------------------------------------------------------------
		//������ϢӦ��(ö�� 3061)
		gameMsg.set_msg(Mails_Response);

		//�õ�����
		uint32 msgLen = gameMsg.ByteSize();
		//���л�����
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//�����ݷ���洢�������� ���̷���
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);
		delete[] spr1;
		delete[] spr2;
		delete[] spr3;
	}

}

//̫��Ӧ��8
void Process_SunResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	SunResponse* pwel = pRes->release_sun();
	pwel = pRes->mutable_sun();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//��֯Ӧ����Ϣ����(�ȼ�,����)
	pwel->set_level(faitreUser->Get_SunShine()->Get_SunLevel());
	pwel->set_sunshine(faitreUser->Get_SunShine()->Get_FSunNumber());

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3071)
	gameMsg.set_msg(Sun_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);


}

//�����Ӧ��9
void Process_TreeEnchantmentResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TreeEnchantmentResponse* ptreeench = pRes->release_treeenchantment();
	ptreeench = pRes->mutable_treeenchantment();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//��֯Ӧ����Ϣ����(�����ȼ�,����)
	ptreeench->set_level(faitreUser->Get_TreeEnchantment()->Get_TEGrade());
	ptreeench->set_defenselevel(faitreUser->Get_TreeEnchantment()->Get_TEDefense());

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3081)
	gameMsg.set_msg(TreeEnchantment_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);


}

//��ȡ�̵�������ƷӦ��10
void Process_StoreAllResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreAllResponse* pstoall = pRes->release_storeall();
	pstoall = pRes->mutable_storeall();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//ѭ��������Ʒ��ID ����

		//��֯Ӧ����Ϣ����(ID,��Ҽ۸�,��ʯ�۸�,�ۿ�,����,����,����)
		//pstoall->set_id();
		//pstoall->set_goldprice();
		//pstoall->set_diaprice();
		//pstoall->set_discount();

	//--------------------------------------------------------------
		//������ϢӦ��(ö�� 3091)
		gameMsg.set_msg(StoreAll_Response);

		//�õ�����
		uint32 msgLen = gameMsg.ByteSize();
		//���л�����
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//�����ݷ���洢�������� ���̷���
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);

		


}

//��ȡ�̵�װ������ƷӦ��11
void Process_StoreEquResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreEquResponse* pstoequ = pRes->release_storeequ();
	pstoequ = pRes->mutable_storeequ();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	uint32 utemp = 10002;//װ����ID

	
		
			//��֯Ӧ����Ϣ����(ID,��Ҽ۸�,��ʯ�۸�,�ۿ�,����(װ����),����,����)
			//pstoequ->set_id();
			//pstoequ->set_goldprice();
			//pstoequ->set_diaprice();
			//pstoequ->set_discount();
			//pstoequ->set_type(Res_Equip);
		
		
	//--------------------------------------------------------------

	//������ϢӦ��(ö�� 3101)
	gameMsg.set_msg(StoreEqu_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//��ȡ�̵�ˮ��Դ����ƷӦ��12
void Process_StoreWaterResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreWaterResponse* pstowat = pRes->release_storewater();
	pstowat = pRes->mutable_storewater();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	uint32 utemp = 10001; //ˮ��Դ��ID
	
			//��֯Ӧ����Ϣ����(ID,��Ҽ۸�,��ʯ�۸�,�ۿ�,����(ˮ��Դ��),����,����)
			//pstowat->set_id();
		//	pstowat->set_goldprice();
			//pstowat->set_diaprice();
			//pstowat->set_discount();
		//	pstowat->set_type(Res_Water);
		
	

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3111)
	gameMsg.set_msg(StoreWater_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//��ȡ�̵���������ƷӦ��13
void Process_StoreSpePropsResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreSpePropsResponse* pstospe = pRes->release_storespeprops();
	pstospe = pRes->mutable_storespeprops();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	uint32 utemp = 10003; //������ID
	
			//��֯Ӧ����Ϣ����(ID,��Ҽ۸�,��ʯ�۸�,�ۿ�,����(������),����,����)
			//pstospe->set_id();
			//pstospe->set_goldprice();
			//pstospe->set_diaprice();
			//pstospe->set_discount();
			//pstospe->set_type(Res_SpeProps);

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3121)
	gameMsg.set_msg(StoreSpeProps_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//��ȡ�ֿ�������ƷӦ��14
void Process_WarehouseResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	WarehouseResponse* pwareh = pRes->release_warehouse();
	pwareh = pRes->mutable_warehouse();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];


	//ˮ��Դ��id
	uint32 uwid = 10001;
	//װ����id
	uint32 ueid = 10002;
	//������ߵ�id
	uint32 usid = 10003;

	//ѭ��������Ʒ��ID ���Ӧ����Ʒ����
	for (int i = 0; i < faitreUser->Get_Warehouse()->Get_ArticleMap().size(); ++i)
	{
		//��֯Ӧ����Ϣ����(ID,����)
		if (uwid == faitreUser->Get_Warehouse()->Get_ArticleMap()[i]->Get_CArticleSerialNumber())
		{
			pwareh->set_id(faitreUser->Get_Warehouse()->Get_ArticleMap()[i]->Get_CArticleSerialNumber());
			pwareh->set_number(faitreUser->Get_Warehouse()->Get_ArticleToWaterCount());
		}
		if (ueid == faitreUser->Get_Warehouse()->Get_ArticleMap()[i]->Get_CArticleSerialNumber())
		{
			pwareh->set_id(faitreUser->Get_Warehouse()->Get_ArticleMap()[i]->Get_CArticleSerialNumber());
			pwareh->set_number(faitreUser->Get_Warehouse()->Get_ArticleToEquipCount());
		}
		if (usid == faitreUser->Get_Warehouse()->Get_ArticleMap()[i]->Get_CArticleSerialNumber())
		{
			pwareh->set_id(faitreUser->Get_Warehouse()->Get_ArticleMap()[i]->Get_CArticleSerialNumber());
			pwareh->set_number(faitreUser->Get_Warehouse()->Get_ArticleToSepProCount());
		}
		
		//--------------------------------------------------------------
		//������ϢӦ��(ö�� 3131)
		gameMsg.set_msg(Warehouse_Response);

		//�õ�����
		uint32 msgLen = gameMsg.ByteSize();
		//���л�����
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//�����ݷ���洢�������� ���̷���
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);
	}
	
}

//ɾ���ʼ�Ӧ��15
void Process_DelMailResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	DelMailResponse* pdelmail = pRes->release_delmail();
	pdelmail = pRes->mutable_delmail();

	//--------------------------------------------------------------
	DelMailRequest delmail;

	//�õ���Ϣ����ID
	//uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	//FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//��֯Ӧ����Ϣ����(���bool,ID)
	pdelmail->set_success(true);
	pdelmail->set_id(delmail.id());

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3141)
	gameMsg.set_msg(DelMail_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//Ӧ����ȡ����16
void Process_ClaimedTaskResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ClaimedTaskResponse* pclatask = pRes->release_claimedtask();
	pclatask = pRes->mutable_claimedtask();

	//--------------------------------------------------------------
	ClaimedTaskRequest clatask;

	//�õ���Ϣ����ID
	//uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	//FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//��֯Ӧ����Ϣ����(���bool,ID)
	pclatask->set_success(true);
	pclatask->set_id(clatask.id());

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3151)
	gameMsg.set_msg(ClaimedTask_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//Ӧ��������17
void Process_RecTaskAwardResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RecTaskAwardResponse* prectask = pRes->release_rectaskaward();
	prectask = pRes->mutable_rectaskaward();

	//--------------------------------------------------------------
	RecTaskAwardRequest rectaskaward;

	//�õ���Ϣ����ID
	//uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	//FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//��֯Ӧ����Ϣ����(ID���,����,����,����)
	prectask->set_success(true);
	prectask->set_id(rectaskaward.id());
	
	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3161)
	gameMsg.set_msg(RecTaskAward_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//��ȡ�����б�Ӧ��18
void Process_FriendsResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	FriendsResponse* pfeds = pRes->release_friends();
	pfeds = pRes->mutable_friends();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	for (std::list<CharacterClass*>::iterator i = faitreUser->Get_Relation()->Get_RelationRfriendRanking().begin();
		i != faitreUser->Get_Relation()->Get_RelationRfriendRanking().end(); i++)
	{
		//��֯Ӧ����Ϣ����(ID,����,���ĵȼ�)
		pfeds->set_id((*i)->Get_Role_ID());
		pfeds->set_name((*i)->Get_Role_Name());
		pfeds->set_level((*i)->Get_TreeToGread());
		pfeds->set_headurl((*i)->Get_HaracterHeadPortraitSite());
		pfeds->set_growrate((*i)->Get_RoleGrowthValue());

		//--------------------------------------------------------------
		//������ϢӦ��(ö�� 3171)
		gameMsg.set_msg(Friends_Response);

		//�õ�����
		uint32 msgLen = gameMsg.ByteSize();
		uint32 len = msgLen + sizeof(uint32);
		//���л�����
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//�����ݷ���洢�������� ���̷���
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);
	}

}

//��ȡ�����б�Ӧ��19
void Process_EnemiesResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	EnemiesResponse* peneres = pRes->release_enemies();
	peneres = pRes->release_enemies();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	for (std::list<CharacterClass*>::iterator i = faitreUser->Get_Relation()->Get_RelationRenemyRanking().begin();
		i != faitreUser->Get_Relation()->Get_RelationRenemyRanking().end(); i++)
	{
		//��֯Ӧ����Ϣ����(ID,����,���ĵȼ�)
		peneres->set_id((*i)->Get_Role_ID());
		peneres->set_name((*i)->Get_Role_Name());
		peneres->set_level((*i)->Get_TreeToGread());
		peneres->set_headurl((*i)->Get_HaracterHeadPortraitSite());
		peneres->set_growrate((*i)->Get_RoleGrowthValue());

		//--------------------------------------------------------------
		//������ϢӦ��(ö�� 3181)
		gameMsg.set_msg(Enemies_Response);

		//�õ�����
		uint32 msgLen = gameMsg.ByteSize();
		uint32 len = msgLen + sizeof(uint32);
		//���л�����
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//�����ݷ���洢�������� ���̷���
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);
	}

}


//����Ӧ��20
void Process_PlunderResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	PlunderResponse* pplures = pRes->release_plunder();
	pplures = pRes->mutable_plunder();
	uint32 eID = pMsg.req().plunder().elfinid();
	//--------------------------pM------------------------------------
	///PlunderRequest ppluReq;
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];
	
	//��֯Ӧ����Ϣ����(������,���Ӷ��ߵ�ID,С�����ID,�������)
	pplures->set_success(true);
	srand((uint32)time(0));
	rand();//�����һ��
	//�û��ĳ�ʼID��
	uint32 roleInitID = 10001;
	uint32 uid = 0;
	//�����ǰ���û�ID ���� ������ɵ��û�ID
	uid = rand() % CAllUserInfoInstance::GetInstance()->GetUserMap().size() + roleInitID;
	Elfin * elfin;
	//�õ����Ӷ���ID
	elfin = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId]->GetElfinId(eID);
	elfin->SetPlunderState(ElfinState::PLUNDER);
	elfin->SetBePlunderId(uid);
	/*if ()
	{
		rand();
		uid = rand() % CAllUserInfoInstance::GetInstance()->GetUserMap().size() + roleInitID;
	}*/

	pplures->set_id(uid);
	pplures->set_elfinid(eID);

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3191)
	gameMsg.set_msg(Plunder_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//ʹ����ƷӦ��21
void Process_UseItemResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	UseItemResponse* puseres = pRes->release_useitem();
	puseres = pRes->mutable_useitem();

	//--------------------------------------------------------------
	UseItemRequest useitereq;

	//��֯Ӧ����Ϣ����(���,���������ƷID,С����ID)
	puseres->set_success(true);
	puseres->set_id(useitereq.itemid());
	puseres->set_elfinid(useitereq.elfinid());

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3201)
	gameMsg.set_msg(UseItem_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//����Ӧ��22
void Process_SettleAccountResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	SettleAccountResponse* psetres = pRes->release_settleaccount();
	psetres = pRes->mutable_settleaccount();

	//--------------------------------------------------------------
	SettleAccountRequest psetAccReq;

	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	//��֯Ӧ����Ϣ����(���,ID,����,�ܵļ۸�)
	psetres->set_success(true);
	psetres->set_id(psetAccReq.itemnum());
	psetres->set_number(psetAccReq.number());
	//�����ܵĽ�ҵļ۸�
	
	//psetres->set_goldprice();
	//�����ܵ���ʯ�ļ۸�

	//psetres->set_diaprice();

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3211)
	gameMsg.set_msg(SettleAccount_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//Ӧ���ȡ���а��б�23
void Process_RankingResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RankingResponse* pranres = pRes->release_ranking();
	pranres = pRes->mutable_ranking();

	//--------------------------------------------------------------
	//�õ���Ϣ����ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//�������û���ָ�� 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->GetUserMap()[uConId];

	uint32 urank = 1;//��ɫ����
	
		//��֯Ӧ����Ϣ����(ID,����,���ĵȼ�,���û�������)
	//	pranres->set_id();
		//pranres->set_name();
	//	pranres->set_level();
	//	pranres->set_growrate();
		pranres->set_ranking(urank);
	//	pranres->set_headurl();

	//--------------------------------------------------------------
		//������ϢӦ��(ö�� 3221)
		gameMsg.set_msg(Ranking_Response);

		//�õ�����
		uint32 msgLen = gameMsg.ByteSize();
		uint32 len = msgLen + sizeof(uint32);
		//���л�����
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//�����ݷ���洢�������� ���̷���
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);

		urank += 1; //��ɫ����
	
	
}

//��������Ӧ��24
void Process_ForgetSkillResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ForgetSkillResponse* pforres = pRes->release_forgetskill();
	pforres = pRes->mutable_forgetskill();

	//--------------------------------------------------------------
	ForgetSkillRequest pforSkiReq;

	//��֯Ӧ����Ϣ����(���,ID)
	pforres->set_success(true);
	pforres->set_skillid(pforSkiReq.skillid());
	pforres->set_elfinid(pforSkiReq.elfinid());

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3231)
	gameMsg.set_msg(ForgetSkill_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//ע��Ӧ��25
void Process_RegisterResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	/*GameMessage gameMsg;
	Response* presp = gameMsg.release_res();
	presp = gameMsg.mutable_res();
	RegisterResponse* pregister = presp->release_register_();
	pregister = presp->mutable_register_();*/

	//--------------------------------------------------------------
	//�������û���
	//FairyTreeUserClasses* faitreUser;

	//��֯Ӧ����Ϣ����(����ע����(0Ϊ�ɹ�,1Ϊʧ��))
	//pregister->set_success(true);

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3241)
	//gameMsg.set_msg(Register_Response);


	//�õ�����
	//uint32 msgLen = gameMsg.ByteSize();
	//uint32 len = msgLen + sizeof(uint32);
	//���л�����
	//char buff[MAX_BUFF_100] = { 0 };
	//memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	//gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	/*uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);*/
}

//̫������Ӧ��26
void Process_SolarUpgradeResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gamemsg;
	Response* pres = gamemsg.release_res();
	pres = gamemsg.mutable_res();
	SolarUpgradeResponse* psol = pres->release_solarupgrade();
	psol = pres->mutable_solarupgrade();

	//--------------------------------------------------------------
	//��֯Ӧ����Ϣ����(���� 0Ϊʧ�� 1 �ɹ�)
	psol->set_solar(true);

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3251)
	gamemsg.set_msg(SolarUpgrade_Response);

	//�õ�����
	uint32 msgLen = gamemsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gamemsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//��������Ӧ��27
void Process_SkillUpgradeResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gamemsg;
	Response* pres = gamemsg.release_res();
	pres = gamemsg.mutable_res();
	SkillUpgradeResponse* skRes = pres->release_skillupgrade();
	skRes = pres->mutable_skillupgrade();

	//--------------------------------------------------------------
	SkillUpgradeRequest skiReq;
	//��֯Ӧ����Ϣ����(���� 0Ϊʧ�� 1Ϊ�ɹ�, С�����Id, ���ܵ�ID)
	skRes->set_success(true);
	skRes->set_elfinid(skiReq.elfinid());
	skRes->set_skillid(skiReq.skillid());

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3261)
	gamemsg.set_msg(SkillUpgrade_Response);

	//�õ�����
	uint32 msgLen = gamemsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gamemsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//����������Ӧ��28
void Process_TreeUpgradeResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gamemsg;
	Response* pres = gamemsg.release_res();
	pres = gamemsg.mutable_res();
	TreeUpgradeResponse* trRes = pres->release_treeupgrade();
	trRes = pres->mutable_treeupgrade();

	//--------------------------------------------------------------
	//��֯Ӧ����Ϣ����(���� 0Ϊʧ�� 1Ϊ�ɹ�)
	trRes->set_success(true);

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3271)
	gamemsg.set_msg(TreeUpgrade_Response);

	//�õ�����
	uint32 msgLen = gamemsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gamemsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//С��������Ӧ��29
void Process_ElfinUpgradeResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gamemsg;
	Response* pres = gamemsg.release_res();
	pres = gamemsg.mutable_res();
	ElfinUpgradeResponse* elRes = pres->release_elfinupgrade();
	elRes = pres->mutable_elfinupgrade();

	//--------------------------------------------------------------
	ElfinUpgradeRequest elReq;
	//��֯Ӧ����Ϣ����(���� 0Ϊʧ�� 1Ϊ�ɹ�, С�����ID)
	elRes->set_success(true);
	elRes->set_elfinid(elReq.elfinid());

	//--------------------------------------------------------------
	//������ϢӦ��(ö�� 3281)
	gamemsg.set_msg(ElfinUpgrade_Response);

	//�õ�����
	uint32 msgLen = gamemsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gamemsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//������Ӧ��30
void Process_HeartBeatResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//�����κδ���
}

