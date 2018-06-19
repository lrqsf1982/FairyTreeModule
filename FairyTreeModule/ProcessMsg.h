#pragma once
#include "define.h"
#include "IObject.h"
#include "IBuffPacket.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/message.h"
#include "ProtobufMSG/Msg.pb.h"


#ifndef COMMAND_BASE_ID
#define COMMAND_BASE_ID 0x1201
#endif

extern "C"
{
//����
void Process_LoginRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);            //��¼����1
void Process_ElfinRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);            //С��������2
void Process_RollRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);             //��ɫ��Ϣ����3
void Process_TreeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);             //����������4
void Process_ResourceRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);         //��Դ����5
void Process_TasksRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);            //�����ȡ�����б�6
void Process_MailsRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);			  //�ʼ�����7
void Process_SunRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);              //��ȡ̫��������8
void Process_TreeEnchantmentRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);  //���������9
void Process_StoreAllRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);         //��ȡ�̵�������Ʒ����10
void Process_StoreEquRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);         //��ȡ�̵�װ������Ʒ����11
void Process_StoreWaterRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);       //��ȡ�̵�ˮ��Դ����Ʒ����12
void Process_StoreSpePropsRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);    //��ȡ�̵���������Ʒ����13
void Process_WarehouseRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);        //��ȡ�ֿ�������Ʒ����14
void Process_DelMailRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);          //ɾ���ʼ�����15
void Process_ClaimedTaskRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);      //������ȡ����16
void Process_RecTaskAwardRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //����������17
void Process_FriendsRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);          //��ȡ�����б�����18
void Process_EnemiesRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);          //��ȡ�����б�����19
void Process_PlunderRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //����Ӷ�����20
void Process_UseItemRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);          //ʹ����Ʒ����21
void Process_SettleAccountRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);    //��������22
void Process_RankingRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //�����ȡ���а��б�23
void Process_ForgetSkillRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);      //������������24
void Process_RegisterRequest    (const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);         //ע������25
void Process_SolarUpgradeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //̫����������26
void Process_SkillUpgradeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //������������27
void Process_TreeUpgradeRequest (const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);      //��������������28
void Process_ElfinUpgradeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //С������������29
void Process_HeartBeatRequest   (const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);        //����������30


//Ӧ��
void Process_LoginResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);           //��¼Ӧ��1
void Process_ElfinResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		      //С����Ӧ��2
void Process_RollResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);			  //��ɫ��ϢӦ��3
void Process_TreeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);			  //������Ӧ��4
void Process_ResourceResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //��ԴӦ��5
void Process_TasksResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);           //��ȡ�����б�Ӧ��6
void Process_MailsResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		      //�ʼ�Ӧ��7
void Process_SunResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);			  //��ȡ̫����Ӧ��8
void Process_TreeEnchantmentResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage); //�����Ӧ��9
void Process_StoreAllResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //��ȡ�̵�������ƷӦ��10
void Process_StoreEquResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //��ȡ�̵�װ������ƷӦ��11
void Process_StoreWaterResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);	  //��ȡ�̵�ˮ��Դ����ƷӦ��12
void Process_StoreSpePropsResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);	  //��ȡ�̵���������ƷӦ��13
void Process_WarehouseResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //��ȡ�ֿ�������ƷӦ��14
void Process_DelMailResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //ɾ���ʼ�Ӧ��15
void Process_ClaimedTaskResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);	  //Ӧ����ȡ����16
void Process_RecTaskAwardResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);	  //Ӧ��������17
void Process_FriendsResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //��ȡ�����б�Ӧ��18
void Process_EnemiesResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //��ȡ�����б�Ӧ��19
void Process_PlunderResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //����Ӷ�Ӧ��20
void Process_UseItemResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //ʹ����ƷӦ��21
void Process_SettleAccountResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);   //����Ӧ��22
void Process_RankingResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //Ӧ���ȡ���а��б�23
void Process_ForgetSkillResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //��������Ӧ��24
void Process_RegisterResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);        //ע��Ӧ��25
void Process_SolarUpgradeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);    //̫������Ӧ��26
void Process_SkillUpgradeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);    //��������Ӧ��27
void Process_TreeUpgradeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //����������Ӧ��28
void Process_ElfinUpgradeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);    //С��������Ӧ��29
void Process_HeartBeatResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);       //������Ӧ��30


}

