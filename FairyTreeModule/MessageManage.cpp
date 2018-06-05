#include "MessageManage.h"
#include "ProcessMsg.h"

std::map<GameMsgCode, void(*)(const GameMessage& , CServerObject*, IMessage*)> CMessageManage::MsgMap;

CMessageManage::CMessageManage()
{
	Init();
}

void CMessageManage::Init()
{
	//请求
	MsgMap[Login_Request] = Process_LoginRequest;                          //登录请求1
	MsgMap[Elfin_Request] = Process_ElfinRequest;						   //小精灵请求2
	MsgMap[Roll_Request] = Process_RollRequest;							   //角色信息请求3
	MsgMap[Tree_Request] = Process_TreeRequest;							   //神仙树请求4
	MsgMap[Resource_Request] = Process_ResourceRequest;					   //资源请求5
	MsgMap[Tasks_Request] = Process_TasksRequest;						   //请求获取任务列表6
	MsgMap[Mails_Request] = Process_MailsRequest;						   //邮件请求7
	MsgMap[Sun_Request] = Process_SunRequest;							   //获取太阳的请求8
	MsgMap[TreeEnchantment_Request] = Process_TreeEnchantmentRequest;	   //树结界请求9
	MsgMap[StoreAll_Request] = Process_StoreAllRequest;					   //获取商店所有物品请求10
	MsgMap[StoreEqu_Request] = Process_StoreEquRequest;					   //获取商店装备类物品请求11
	MsgMap[StoreWater_Request] = Process_StoreWaterRequest;				   //获取商店水资源类物品请求12
	MsgMap[StoreSpeProps_Request] = Process_StoreSpePropsRequest;		   //获取商店特殊类物品请求13
	MsgMap[Warehouse_Request] = Process_WarehouseRequest;				   //获取仓库所有物品请求14
	MsgMap[DelMail_Request] = Process_DelMailRequest;					   //删除邮件请求15
	MsgMap[ClaimedTask_Request] = Process_ClaimedTaskRequest;			   //请求领取任务16
	MsgMap[RecTaskAward_Request] = Process_RecTaskAwardRequest;			   //请求任务奖励17
	MsgMap[Friends_Request] = Process_FriendsRequest;					   //获取好友列表请求18
	MsgMap[Enemies_Request] = Process_EnemiesRequest;					   //获取敌人列表请求19
	MsgMap[Plunder_Request] = Process_PlunderRequest;					   //随机掠夺请求20
	MsgMap[UseItem_Request] = Process_UseItemRequest;					   //使用物品请求21
	MsgMap[SettleAccount_Request] = Process_SettleAccountRequest;		   //结账请求22
	MsgMap[Ranking_Request] = Process_RankingRequest;					   //请求获取排行榜列表23
	MsgMap[ForgetSkill_Request] = Process_ForgetSkillRequest;			   //遗忘技能请求24
	MsgMap[Register_Request] = Process_RegisterRequest;                    //注册请求25

	//应答
	MsgMap[Login_Response] = Process_LoginResponse;                        //登录应答1
	MsgMap[Elfin_Response] = Process_ElfinResponse;						   //小精灵应答2
	MsgMap[Roll_Response] = Process_RollResponse;						   //角色信息应答3
	MsgMap[Tree_Response] = Process_TreeResponse;						   //神仙树应答4
	MsgMap[Resource_Response] = Process_ResourceResponse;				   //资源应答5
	MsgMap[Tasks_Response] = Process_TasksResponse;						   //获取任务列表应答6
	MsgMap[Mails_Response] = Process_MailsResponse;						   //邮件应答7
	MsgMap[Sun_Response] = Process_SunResponse;						       //获取太阳的应答8
	MsgMap[TreeEnchantment_Response] = Process_TreeEnchantmentResponse;	   //树结界应答9
	MsgMap[StoreAll_Response] = Process_StoreAllResponse;				   //获取商店所有物品应答10
	MsgMap[StoreEqu_Response] = Process_StoreEquResponse;				   //获取商店装备类物品应答11
	MsgMap[StoreWater_Response] = Process_StoreWaterResponse;			   //获取商店水资源类物品应答12
	MsgMap[StoreSpeProps_Response] = Process_StoreSpePropsResponse;		   //获取商店特殊类物品应答13
	MsgMap[Warehouse_Response] = Process_WarehouseResponse;				   //获取仓库所有物品应答14
	MsgMap[DelMail_Response] = Process_DelMailResponse;					   //删除邮件应答15
	MsgMap[ClaimedTask_Response] = Process_ClaimedTaskResponse;			   //应答领取任务16
	MsgMap[RecTaskAward_Response] = Process_RecTaskAwardResponse;		   //应答任务奖励17
	MsgMap[Friends_Response] = Process_FriendsResponse;					   //获取好友列表应答18
	MsgMap[Enemies_Response] = Process_EnemiesResponse;					   //获取敌人列表应答19
	MsgMap[Plunder_Response] = Process_PlunderResponse;					   //随机掠夺应答20
	MsgMap[UseItem_Response] = Process_UseItemResponse;					   //使用物品应答21
	MsgMap[SettleAccount_Response] = Process_SettleAccountResponse;		   //结账应答22
	MsgMap[Ranking_Response] = Process_RankingResponse;					   //应答获取排行榜列表23
	MsgMap[ForgetSkill_Response] = Process_ForgetSkillResponse;			   //遗忘技能应答24
	MsgMap[Register_Response] = Process_RegisterResponse;                  //注册应答25
	
}

bool CMessageManage::Dispose(const GameMessage& msg, CServerObject* pServerObj, IMessage* pMessage)
{
	bool bKet = false;
	auto iter = MsgMap.find(msg.msg());
	if (iter != MsgMap.end())
	{
		iter->second(msg, pServerObj, pMessage);
		bKet = true;
	}
	return bKet;
}

