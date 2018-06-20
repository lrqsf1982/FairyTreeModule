#include "FairyTreeUserClasses.h"



FairyTreeUserClasses::FairyTreeUserClasses()
{

	m_roleID = 10000; //用户ID
	m_name = "";//名字
	m_weChatID = 0;// 微信ID
	m_groValue = 0;;//成长值

	this->elfList.push_back(new Elfin);//小精灵(链表)
	ptree = new FairyTree;//神仙树
	psun = new CSunshine;//太阳
	pchant = new TreeEnchantment;//树结界(神仙门)
	phouse = new Warehouse;//仓库
	pmbox = new CMailbox;//邮箱
	ptasklist = new CTaskListClass;//任务列表类
	prelat = new Relation;//关系
	pres = new ResourceClass;//资源类

}


FairyTreeUserClasses::~FairyTreeUserClasses()
{
	delete ptree;
	ptree = nullptr;
	delete psun;
	psun = nullptr;
	delete pchant;
	pchant = nullptr;
	delete phouse;
	phouse = nullptr;
	delete pmbox;
	pmbox = nullptr;
	delete ptasklist;
	ptasklist = nullptr;
	delete prelat;
	prelat = nullptr;
	delete pres;
	pres = nullptr;
}


//通过ID查找小精灵
Elfin * FairyTreeUserClasses::GetElfinId(uint32 id) 
{
	std::list<Elfin *>::iterator it;
	for (it = elfList.begin(); it != elfList.end(); ++it)
	{
		if ((*it)->Get_EToID() == id)
			return *it;
	}
	return nullptr;
}
//设置用户ID
void FairyTreeUserClasses::Set_UserId(uint32 suid)
{
	//用户ID号
	m_roleID += suid;

}

//获得用户ID
uint32 FairyTreeUserClasses::Get_UserId()
{
	return m_roleID;
}
//设置用户名
void FairyTreeUserClasses::Set_UserName(const std::string & str)
{
	m_name = str;
}
//获取用户名
std::string FairyTreeUserClasses::Get_UserName()
{
	return m_name;
}
//设置微信ID
void FairyTreeUserClasses::Set_UserWeChatID(uint32 uid)
{
	m_weChatID = uid;
}
//获取微信ID
uint32 FairyTreeUserClasses::Get_UserWeChatID()
{
	return m_weChatID;
}
//设置成长值
void FairyTreeUserClasses::Set_UserGrowthValue(uint32 val)
{
	m_groValue = val;
}
//获取成长值
uint32 FairyTreeUserClasses::Get_UserGrowthValue()
{
	return m_groValue;
}

//获取小精灵
std::list<Elfin*> FairyTreeUserClasses::Get_ElfinList()const
{ 
	return elfList;
}

//获取神仙树
FairyTree* FairyTreeUserClasses::Get_FairyTree()
{
	return ptree;
}

//获取太阳
CSunshine* FairyTreeUserClasses::Get_SunShine()
{
	return psun;
}

//获取树结界
TreeEnchantment* FairyTreeUserClasses::Get_TreeEnchantment()
{
	return pchant;
}

//获取仓库
Warehouse* FairyTreeUserClasses::Get_Warehouse()
{
	return phouse;
}

//获取邮箱
CMailbox* FairyTreeUserClasses::Get_CMailbox()
{
	return pmbox;
}

//获取任务列表类
CTaskListClass* FairyTreeUserClasses::Get_CTaskListClass()
{
	return ptasklist;
}

//获取关系
Relation* FairyTreeUserClasses::Get_Relation()
{
	return prelat;
}
//获取资源类
ResourceClass * FairyTreeUserClasses::Get_Resource()
{
	return pres;
}





CAllUserInfoInstance* CAllUserInfoInstance::_instance = new CAllUserInfoInstance();
CAllUserInfoInstance * CAllUserInfoInstance::GetInstance()
{
	return _instance;
}

void CAllUserInfoInstance::SetUserMap(uint32 uid, FairyTreeUserClasses* pUser)
{
	ConnetedUser[uid] = pUser;
}

std::map<uint32, FairyTreeUserClasses*>& CAllUserInfoInstance::GetUserMap()
{
	return ConnetedUser;
}