#include "FairyTreeUserClasses.h"



FairyTreeUserClasses::FairyTreeUserClasses()
{

	m_roleID = 10000; //�û�ID
	m_name = "";//����
	m_weChatID = 0;// ΢��ID
	m_groValue = 0;;//�ɳ�ֵ

	this->elfList.push_back(new Elfin);//С����(����)
	ptree = new FairyTree;//������
	psun = new CSunshine;//̫��
	pchant = new TreeEnchantment;//�����(������)
	phouse = new Warehouse;//�ֿ�
	pmbox = new CMailbox;//����
	ptasklist = new CTaskListClass;//�����б���
	prelat = new Relation;//��ϵ
	pres = new ResourceClass;//��Դ��

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


//ͨ��ID����С����
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
//�����û�ID
void FairyTreeUserClasses::Set_UserId(uint32 suid)
{
	//�û�ID��
	m_roleID += suid;

}

//����û�ID
uint32 FairyTreeUserClasses::Get_UserId()
{
	return m_roleID;
}
//�����û���
void FairyTreeUserClasses::Set_UserName(const std::string & str)
{
	m_name = str;
}
//��ȡ�û���
std::string FairyTreeUserClasses::Get_UserName()
{
	return m_name;
}
//����΢��ID
void FairyTreeUserClasses::Set_UserWeChatID(uint32 uid)
{
	m_weChatID = uid;
}
//��ȡ΢��ID
uint32 FairyTreeUserClasses::Get_UserWeChatID()
{
	return m_weChatID;
}
//���óɳ�ֵ
void FairyTreeUserClasses::Set_UserGrowthValue(uint32 val)
{
	m_groValue = val;
}
//��ȡ�ɳ�ֵ
uint32 FairyTreeUserClasses::Get_UserGrowthValue()
{
	return m_groValue;
}

//��ȡС����
std::list<Elfin*> FairyTreeUserClasses::Get_ElfinList()const
{ 
	return elfList;
}

//��ȡ������
FairyTree* FairyTreeUserClasses::Get_FairyTree()
{
	return ptree;
}

//��ȡ̫��
CSunshine* FairyTreeUserClasses::Get_SunShine()
{
	return psun;
}

//��ȡ�����
TreeEnchantment* FairyTreeUserClasses::Get_TreeEnchantment()
{
	return pchant;
}

//��ȡ�ֿ�
Warehouse* FairyTreeUserClasses::Get_Warehouse()
{
	return phouse;
}

//��ȡ����
CMailbox* FairyTreeUserClasses::Get_CMailbox()
{
	return pmbox;
}

//��ȡ�����б���
CTaskListClass* FairyTreeUserClasses::Get_CTaskListClass()
{
	return ptasklist;
}

//��ȡ��ϵ
Relation* FairyTreeUserClasses::Get_Relation()
{
	return prelat;
}
//��ȡ��Դ��
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