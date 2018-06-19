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
//请求
void Process_LoginRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);            //登录请求1
void Process_ElfinRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);            //小精灵请求2
void Process_RollRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);             //角色信息请求3
void Process_TreeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);             //神仙树请求4
void Process_ResourceRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);         //资源请求5
void Process_TasksRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);            //请求获取任务列表6
void Process_MailsRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);			  //邮件请求7
void Process_SunRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);              //获取太阳的请求8
void Process_TreeEnchantmentRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);  //树结界请求9
void Process_StoreAllRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);         //获取商店所有物品请求10
void Process_StoreEquRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);         //获取商店装备类物品请求11
void Process_StoreWaterRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);       //获取商店水资源类物品请求12
void Process_StoreSpePropsRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);    //获取商店特殊类物品请求13
void Process_WarehouseRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);        //获取仓库所有物品请求14
void Process_DelMailRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);          //删除邮件请求15
void Process_ClaimedTaskRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);      //请求领取任务16
void Process_RecTaskAwardRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //请求任务奖励17
void Process_FriendsRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);          //获取好友列表请求18
void Process_EnemiesRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);          //获取敌人列表请求19
void Process_PlunderRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //随机掠夺请求20
void Process_UseItemRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);          //使用物品请求21
void Process_SettleAccountRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);    //结账请求22
void Process_RankingRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //请求获取排行榜列表23
void Process_ForgetSkillRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);      //遗忘技能请求24
void Process_RegisterRequest    (const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);         //注册请求25
void Process_SolarUpgradeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //太阳升级请求26
void Process_SkillUpgradeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //技能升级请求27
void Process_TreeUpgradeRequest (const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);      //神仙树升级请求28
void Process_ElfinUpgradeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //小精灵升级请求29
void Process_HeartBeatRequest   (const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);        //心跳包请求30


//应答
void Process_LoginResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);           //登录应答1
void Process_ElfinResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		      //小精灵应答2
void Process_RollResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);			  //角色信息应答3
void Process_TreeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);			  //神仙树应答4
void Process_ResourceResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //资源应答5
void Process_TasksResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);           //获取任务列表应答6
void Process_MailsResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		      //邮件应答7
void Process_SunResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);			  //获取太阳的应答8
void Process_TreeEnchantmentResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage); //树结界应答9
void Process_StoreAllResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //获取商店所有物品应答10
void Process_StoreEquResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //获取商店装备类物品应答11
void Process_StoreWaterResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);	  //获取商店水资源类物品应答12
void Process_StoreSpePropsResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);	  //获取商店特殊类物品应答13
void Process_WarehouseResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //获取仓库所有物品应答14
void Process_DelMailResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //删除邮件应答15
void Process_ClaimedTaskResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);	  //应答领取任务16
void Process_RecTaskAwardResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);	  //应答任务奖励17
void Process_FriendsResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //获取好友列表应答18
void Process_EnemiesResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //获取敌人列表应答19
void Process_PlunderResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //随机掠夺应答20
void Process_UseItemResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //使用物品应答21
void Process_SettleAccountResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);   //结账应答22
void Process_RankingResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);		  //应答获取排行榜列表23
void Process_ForgetSkillResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //遗忘技能应答24
void Process_RegisterResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);        //注册应答25
void Process_SolarUpgradeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);    //太阳升级应答26
void Process_SkillUpgradeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);    //技能升级应答27
void Process_TreeUpgradeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);     //神仙树升级应答28
void Process_ElfinUpgradeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);    //小精灵升级应答29
void Process_HeartBeatResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage);       //心跳包应答30


}

