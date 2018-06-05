#include "ProcessMsg.h"

//请求
//登录请求1
void Process_LoginRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{	
	//首先从从数据库里对比密码
	LoginRequest logreq;

	//判断账号和密码(密码要转换成MD5码在与数据库里的密码进行对比)是否正确并返回结果给客户端
	logreq.account();

	char* pin = NULL;
	std::string pinput = logreq.passwd();
	uint32 ulen = pinput.length();
	memcpy_safe((char*)&pinput, (uint32)ulen, (char*)&pin, (uint32)ulen);
	char poutput[MAX_BUFF_50];
	CMD5 cmd5;
	cmd5.ENCODE_DATA(pin, ulen, poutput);
	

	//应答函数
	Process_LoginResponse(pMsg, pServerObj, pMessage);

}

//小精灵请求2
void Process_ElfinRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	ElfinRequest pelfReq;
	//收到请求返回数据
	pelfReq.elfin();

	//应答函数
	Process_ElfinResponse(pMsg, pServerObj, pMessage);

}

//角色信息请求3
void Process_RollRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	RollRequest rollreq;
	//收到角色信息请求
	rollreq.roll();

	//应答函数
	Process_RollResponse(pMsg, pServerObj, pMessage);
}

//神仙树请求4
void Process_TreeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	TreeRequest ptreReq;
	//收到神仙树的请求 返回数据
	ptreReq.tree();

	//应答函数
	Process_TreeResponse(pMsg, pServerObj, pMessage);

}

//资源请求5
void Process_ResourceRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	ResourceRequest rocrut;
	//收到资源请求
	rocrut.resource();

	//应答函数
	Process_ResourceResponse(pMsg, pServerObj, pMessage);
}

//获取任务列表请求6
void Process_TasksRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	TasksRequest ptasReq;
	//获取人物列表请求
	ptasReq.tasks();

	//应答函数
	Process_TasksResponse(pMsg, pServerObj, pMessage);
}

//邮件请求7
void Process_MailsRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	MailsRequest pmaiReq;
	//获取邮件列表信息
	pmaiReq.mails();

	//应答函数
	Process_MailsResponse(pMsg, pServerObj, pMessage);

}

//太阳请求8
void Process_SunRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	SunRequest pwelReq;
	//收到太阳的请求 返回数据
	pwelReq.sun();

	//应答函数
	Process_SunResponse(pMsg, pServerObj, pMessage);

}

//树结界请求9
void Process_TreeEnchantmentRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	TreeEnchantmentRequest ptreEncReq;
	//收到请求 返回数据
	ptreEncReq.well();

	//应答函数
	Process_TreeEnchantmentResponse(pMsg, pServerObj, pMessage);

}

//获取商店所有物品请求10
void Process_StoreAllRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	StoreAllRequest stoall;
	//收到商店所有物品请求
	stoall.storeall();

	//应答函数
	Process_StoreAllResponse(pMsg, pServerObj, pMessage);

}

//获取商店装备类物品请求11
void Process_StoreEquRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	StoreEquRequest stoequ;
	//收到商店装备类物品请求
	stoequ.storeequ();

	//应答函数
	Process_StoreEquResponse(pMsg, pServerObj, pMessage);

}

//获取商店水资源类物品请求12
void Process_StoreWaterRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	StoreWaterRequest stowatreq;
	//收到商店水资源类物品请求
	stowatreq.storewater();

	//应答函数
	Process_StoreWaterResponse(pMsg, pServerObj, pMessage);

}

//获取商店特殊类物品请求13
void Process_StoreSpePropsRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	StoreSpePropsRequest stospeproreq;
	//收到商店特殊类物品请求
	stospeproreq.storespeprops();

	//应答函数
	Process_StoreSpePropsResponse(pMsg, pServerObj, pMessage);

}

//获取仓库所有物品请求14
void Process_WarehouseRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	WarehouseRequest warehreq;
	//收到仓库所有物品请求
	warehreq.warehouse();

	//应答函数
	Process_WarehouseResponse(pMsg, pServerObj, pMessage);

}

//删除邮件请求15
void Process_DelMailRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	DelMailRequest delmail;
	//收到删除邮件请求
	delmail.id();

	//应答函数
	Process_DelMailResponse(pMsg, pServerObj, pMessage);

}

//请求领取任务16
void Process_ClaimedTaskRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	ClaimedTaskRequest clatask;
	//收到领取任务请求
	clatask.id();

	//应答函数
	Process_ClaimedTaskResponse(pMsg, pServerObj, pMessage);

}

//请求任务奖励17
void Process_RecTaskAwardRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	RecTaskAwardRequest rectaskaward;
	//收到任务奖励请求
	rectaskaward.id();

	//应答函数
	Process_RecTaskAwardResponse(pMsg, pServerObj, pMessage);

}

//获取好友列表请求18
void Process_FriendsRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	FriendsRequest friendsreq;
	//收到好友列表请求
	friendsreq.friends();

	//应答函数
	Process_FriendsResponse(pMsg, pServerObj, pMessage);

}

//获取敌人列表请求19
void Process_EnemiesRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	EnemiesRequest enemreq;
	//收到敌人列表请求
	enemreq.enemies();

	//应答函数
	Process_EnemiesResponse(pMsg, pServerObj, pMessage);

}

//随机掠夺请求20
void Process_PlunderRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	PlunderRequest ppluReq;
	//掠夺请求
	ppluReq.plunder();

	//应答函数
	Process_PlunderResponse(pMsg, pServerObj, pMessage);

}

//使用物品请求21
void Process_UseItemRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	UseItemRequest useitereq;
	//收到使用物品请求
	useitereq.id();

	//应答函数
	Process_UseItemResponse(pMsg, pServerObj, pMessage);

}

//结账请求22
void Process_SettleAccountRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	SettleAccountRequest psetAccReq;
	//收到请求 返回数据
	psetAccReq.itemnum();
	psetAccReq.number();

	//应答函数
	Process_SettleAccountResponse(pMsg, pServerObj, pMessage);
	
}

//请求获取排行榜列表23
void Process_RankingRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	RankingRequest pranReq;
	//获取排行榜列表
	pranReq.ranking();

	//应答函数
	Process_RankingResponse(pMsg, pServerObj, pMessage);

}

//遗忘技能请求24
void Process_ForgetSkillRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	ForgetSkillRequest pforSkiReq;
	//收到请求
	pforSkiReq.skillid();
	pforSkiReq.elfinid();

	//应答函数
	Process_ForgetSkillResponse(pMsg, pServerObj, pMessage);

}

//注册请求25
void Process_RegisterRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	RegisterRequest pregReq;
	//当收到请求时,对比数据库里是否有相同的账号名.如果有,就返回错误(账号已存在).
	//如果没有就将密码转换成MD5码,并且将账号和密码存入数据库.并返回成功
	pregReq.account();

	char* pin = NULL;
	std::string pinput = pregReq.passwd();
	uint32 ulen = pinput.length();
	memcpy_safe((char*)&pinput, (uint32)ulen, (char*)&pin, (uint32)ulen);
	char poutput[MAX_BUFF_50];
	CMD5 cmd5;
	cmd5.ENCODE_DATA(pin,ulen,poutput);
	

	//应答函数
	Process_RegisterResponse(pMsg, pServerObj, pMessage);

}


//------------------------------------------------------------------------------------------------------------


//应答
//登录应答1
void Process_LoginResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	LoginResponse* pLogin = pRes->release_login();
	pLogin = pRes->mutable_login();
	
	//返回结果 0为成功 1为账号或密码错误 2为未知错误

	//从数据库里对比密码
	std::string sname("admin");
	std::string spasswd("123456");

	if (sname == pMsg.req().login().account() && spasswd == pMsg.req().login().passwd())
	{
		//设置返回为 成功 0
		pLogin->set_result(LoginResponse_ResultType_Success);
	}
	else
	{
		//设置返回为 账号或密码错误 1
		pLogin->set_result(LoginResponse_ResultType_PsswadError);
	}

	//设置消息应答(枚举 3001)
	gameMsg.set_msg(Login_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_50] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(msgLen), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//小精灵应答2
void Process_ElfinResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ElfinResponse* pelf = pRes->release_elfin();
	pelf = pRes->mutable_elfin();

	//神仙树的用户信息
	//FairyTreeUserClasses* user;
	//组织应答消息内容(等级,经验,最大经验,体力,最大体力,类型)
	pelf->set_id(123456);
	pelf->set_level(1);
	pelf->set_power(100);
	pelf->set_maxpower(100);
	pelf->set_etype(ElfinResponse_Elfintype_Jin);
	
	

	//设置消息应答(枚举  3011)
	gameMsg.set_msg(Elfin_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//角色信息应答3
void Process_RollResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RollResponse* proll = pRes->release_roll();
	proll = pRes->mutable_roll();

	//组织应答消息内容(ID,名字)
	proll->set_id(12);                        
	std::string sname("JueSeXiaoXiYingDa");    
	proll->set_name(sname);                   



	//设置消息应答(枚举 3021)
	gameMsg.set_msg(Roll_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//神仙树应答4
void Process_TreeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TreeResponse* ptree = pRes->release_tree();
	ptree = pRes->mutable_tree();

	//组织应答消息内容(等级,经验,最大经验,每次生产的金币)
	ptree->set_level(1);
	ptree->set_hight(1);
	ptree->set_prodgold(5);  

	//设置消息应答(枚举 3031)
	gameMsg.set_msg(Tree_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//资源应答5
void Process_ResourceResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ResourceResponse* presres = pRes->release_resource();
	presres = pRes->mutable_resource();

	//组织应答消息内容(金币,普通水,神仙水)
	presres->set_gold(10);
	presres->set_water(20);
	presres->set_sunshine(1);
	presres->set_diamond(1);

	//设置消息应答(枚举 3041)
	gameMsg.set_msg(Resource_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//获取任务列表应答6
void Process_TasksResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TasksResponse* ptasks = pRes->release_tasks();
	ptasks = pRes->mutable_tasks();

	//组织应答消息内容(ID,名字,内容,类型,格式)
	ptasks->set_id(123456);
	std::string name("RenWuLieBiao");
	ptasks->set_title(name);
	std::string sn("HelloWorld");
	ptasks->set_details(sn);
	ptasks->set_type(TasksResponse_TaskType_Received);
	Prize* spr;
	ptasks->set_allocated_prize1(spr);
	ptasks->set_allocated_prize2(spr);
	ptasks->set_allocated_prize3(spr);

	//设置消息应答(枚举 3051)
	gameMsg.set_msg(Tasks_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//邮件应答7
void Process_MailsResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	MailsResponse* pmail = pRes->release_mails();
	pmail = pRes->mutable_mails();

	//组织应答消息内容(ID,标头,内容细节,发送结果,奖品的格式)
	pmail->set_id(10000001);
	std::string sname("YouJian");
	pmail->set_title(sname);
	std::string sn("HelloYouJian");
	pmail->set_details(sn);
	pmail->set_received(true);
	Prize* spr;
	pmail->set_allocated_prize1(spr);
	pmail->set_allocated_prize2(spr);
	pmail->set_allocated_prize3(spr);

	//设置消息应答(枚举 3061)
	gameMsg.set_msg(Mails_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//太阳应答8
void Process_SunResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	SunResponse* pwel = pRes->release_sun();
	pwel = pRes->mutable_sun();

	//组织应答消息内容(等级,阳光)
	pwel->set_level(1);
	pwel->set_sunshine(1);

	//设置消息应答(枚举 3071)
	//gameMsg.set_msg(Well_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//树结界应答9
void Process_TreeEnchantmentResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TreeEnchantmentResponse* ptreeench = pRes->release_treeenchantment();
	ptreeench = pRes->mutable_treeenchantment();

	//组织应答消息内容(保护罩状态,陷阱状态)
	ptreeench->set_level(1);
	ptreeench->set_defenselevel(1); 

	//设置消息应答(枚举 3081)
	gameMsg.set_msg(TreeEnchantment_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//获取商店所有物品应答10
void Process_StoreAllResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreAllResponse* pstoall = pRes->release_storeall();
	pstoall = pRes->mutable_storeall();

	//组织应答消息内容(ID,金币价格,钻石价格,折扣,类型,描述,名字)
	pstoall->set_id(1234);
	pstoall->set_goldprice(11);
	pstoall->set_diaprice(10);
	pstoall->set_discount(9);
	StdMode stdmode;
	pstoall->set_type(stdmode);
	std::string sds("商店所有物品:水,装备,特殊道具");
	pstoall->set_describe(sds);
	std::string name("SuoYouWuPing");
	pstoall->set_name(name);

	//设置消息应答(枚举 3091)
	gameMsg.set_msg(StoreAll_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//获取商店装备类物品应答11
void Process_StoreEquResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreEquResponse* pstoequ = pRes->release_storeequ();
	pstoequ = pRes->mutable_storeequ();

	//组织应答消息内容(ID,金币价格,钻石价格,折扣,类型(装备类),描述,名字)
	pstoequ->set_id(101);
	pstoequ->set_goldprice(1000);
	pstoequ->set_diaprice(200);
	pstoequ->set_discount(95);
	pstoequ->set_type(Res_Equip);
	std::string sds("商店物品:装备类");
	pstoequ->set_describe(sds);
	std::string name("ZhuangBei");
	pstoequ->set_name(name);

	//设置消息应答(枚举 3101)
	gameMsg.set_msg(StoreEqu_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//获取商店水资源类物品应答12
void Process_StoreWaterResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreWaterResponse* pstowat = pRes->release_storewater();
	pstowat = pRes->mutable_storewater();

	//组织应答消息内容(ID,金币价格,钻石价格,折扣,类型(水资源类),描述,名字)
	pstowat->set_id(100);
	pstowat->set_goldprice(500);
	pstowat->set_diaprice(50);
	pstowat->set_discount(95);
	pstowat->set_type(Res_Water);
	std::string sds("商店物品:水资源类");
	pstowat->set_describe(sds);
	std::string name("ShuiZiYuan");
	pstowat->set_name(name);

	//设置消息应答(枚举 3111)
	gameMsg.set_msg(StoreWater_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//获取商店特殊类物品应答13
void Process_StoreSpePropsResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreSpePropsResponse* pstospe = pRes->release_storespeprops();
	pstospe = pRes->mutable_storespeprops();

	//组织应答消息内容(ID,金币价格,钻石价格,折扣,类型(特殊类),描述,名字)
	pstospe->set_id(102);
	pstospe->set_goldprice(124);
	pstospe->set_diaprice(62);
	pstospe->set_discount(95);
	pstospe->set_type(Res_SpeProps);
	std::string sds("商店物品:特殊类");
	pstospe->set_describe(sds);
	std::string sname("TeShuDaoJu");
	pstospe->set_name(sname);

	//设置消息应答(枚举 3121)
	gameMsg.set_msg(StoreSpeProps_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//获取仓库所有物品应答14
void Process_WarehouseResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	WarehouseResponse* pwareh = pRes->release_warehouse();
	pwareh = pRes->mutable_warehouse();

	//组织应答消息内容(ID,名字,描述)
	pwareh->set_id(996);
	pwareh->set_number(1);
	
	//设置消息应答(枚举 3131)
	gameMsg.set_msg(Warehouse_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//删除邮件应答15
void Process_DelMailResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	DelMailResponse* pdelmail = pRes->release_delmail();
	pdelmail = pRes->mutable_delmail();

	//组织应答消息内容(结果,ID)
	pdelmail->set_success(true);
	pdelmail->set_id(135);

	//设置消息应答(枚举 3141)
	gameMsg.set_msg(DelMail_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//应答领取任务16
void Process_ClaimedTaskResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ClaimedTaskResponse* pclatask = pRes->release_claimedtask();
	pclatask = pRes->mutable_claimedtask();

	//组织应答消息内容(结果,ID)
	pclatask->set_success(true);
	pclatask->set_id(456);

	//设置消息应答(枚举 3151)
	gameMsg.set_msg(ClaimedTask_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//应答任务奖励17
void Process_RecTaskAwardResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RecTaskAwardResponse* prectask = pRes->release_rectaskaward();
	prectask = pRes->mutable_rectaskaward();

	//组织应答消息内容(ID编号,名字,描述,数量)
	Prize* spr;
	prectask->set_allocated_prize1(spr);
	prectask->set_allocated_prize2(spr);
	prectask->set_allocated_prize3(spr);
	

	//设置消息应答(枚举 3161)
	gameMsg.set_msg(RecTaskAward_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//获取好友列表应答18
void Process_FriendsResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	FriendsResponse* pfeds = pRes->release_friends();
	pfeds = pRes->mutable_friends();

	//组织应答消息内容(ID,名字,树的等级)
	pfeds->set_id(333);
	std::string name("FriendsName");
	pfeds->set_name(name);
	pfeds->set_level(1);

	//设置消息应答(枚举 3171)
	gameMsg.set_msg(Friends_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//获取敌人列表应答19
void Process_EnemiesResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	EnemiesResponse* peneres = pRes->release_enemies();
	peneres = pRes->release_enemies();

	//组织应答消息内容(ID,名字,树的等级)
	peneres->set_id(444);
	std::string name("EnemiesName");
	peneres->set_name(name);
	peneres->set_level(1);

	//设置消息应答(枚举 3181)
	gameMsg.set_msg(Enemies_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//抢夺应答20
void Process_PlunderResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	PlunderResponse* pplures = pRes->release_plunder();
	pplures = pRes->mutable_plunder();

	//组织应答消息内容(结果,ID,金币数量)
	pplures->set_success(true);
	pplures->set_id(798);
	pplures->set_goldnum(22);

	//设置消息应答(枚举 3191)
	gameMsg.set_msg(Plunder_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//使用物品应答21
void Process_UseItemResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	UseItemResponse* puseres = pRes->release_useitem();
	puseres = pRes->mutable_useitem();

	//组织应答消息内容(结果,ID)
	puseres->set_success(true);
	puseres->set_id(112233);

	//设置消息应答(枚举 3201)
	gameMsg.set_msg(UseItem_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//结账应答22
void Process_SettleAccountResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	SettleAccountResponse* psetres = pRes->release_settleaccount();
	psetres = pRes->mutable_settleaccount();

	//组织应答消息内容(结果,ID,数量,总的价格)
	psetres->set_success(true);
	psetres->set_id(755555);
	psetres->set_number(9);
	psetres->set_price(13579);

	//设置消息应答(枚举 3211)
	gameMsg.set_msg(SettleAccount_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//应答获取排行榜列表23
void Process_RankingResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RankingResponse* pranres = pRes->release_ranking();
	pranres = pRes->mutable_ranking();

	//组织应答消息内容(ID,名字,树的等级,该用户的排名)
	pranres->set_id(987654321);
	std::string name("排行榜列表");
	pranres->set_name(name);
	pranres->set_level(1);
	pranres->set_ranking(1);

	//设置消息应答(枚举 3221)
	gameMsg.set_msg(Ranking_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//遗忘技能应答24
void Process_ForgetSkillResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ForgetSkillResponse* pforres = pRes->release_forgetskill();
	pforres = pRes->mutable_forgetskill();

	//组织应答消息内容(结果,ID)
	pforres->set_success(true);
	pforres->set_skillid(123);
	pforres->set_elfinid(345);

	//设置消息应答(枚举 3231)
	gameMsg.set_msg(ForgetSkill_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

//注册应答25
void Process_RegisterResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* presp = gameMsg.release_res();
	presp = gameMsg.mutable_res();
	RegisterResponse* pregister = presp->release_register_();
	pregister = presp->mutable_register_();

	//组织应答消息内容(返回注册结果(0为成功,1为失败))
	pregister->set_success(true);

	//设置消息应答(枚举 3241)
	gameMsg.set_msg(Register_Response);


	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
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

