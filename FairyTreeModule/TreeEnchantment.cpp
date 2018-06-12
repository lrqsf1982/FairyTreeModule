#include "TreeEnchantment.h"



TreeEnchantment::TreeEnchantment()
{
	m_roleID = 0;//用户ID

	ugrade = 0;//等级

	udefense = 0; //结界防御

	bopenguard = false; //打开保护罩

	bcloseguard = false; //关闭保护罩

	bopenpitfall = false; //打开陷阱(预留)

	bclosepitfall = false;//关闭陷阱(预留) 

}


TreeEnchantment::~TreeEnchantment()
{
}

//设置等级
void TreeEnchantment::Set_TEGrade(uint32 sg)
{
	ugrade = sg;
}

//获取等级
uint32 TreeEnchantment::Get_TEGrade()
{
	return ugrade;
}

//设置结界防御
void TreeEnchantment::Set_TEDefense(uint32 sted)
{
	udefense = sted;
}

//获取结界防御
uint32 TreeEnchantment::Get_TEDefense()
{
	return udefense;
}

//打开保护罩 要打开保护罩调函数 传true
bool TreeEnchantment::OpenGuard(bool bog)
{
	//如果打开保护罩为真 那么关闭保护罩就为假
	bopenguard = bog;
	if (bopenguard)
		CloseGuard(false);
	
	return bopenguard;
}

//关闭保护罩 要关闭保护罩调函数 传true
bool TreeEnchantment::CloseGuard(bool bcg)
{
	//如果关闭保护罩为真 那么打开保护罩就为假
	bcloseguard = bcg;
	if (bcloseguard)
		OpenGuard(false);
	return bcloseguard;
}

//打开陷阱 要打开陷阱调函数 传true
bool TreeEnchantment::OpenPitfall(bool bop)
{
	//如果打开陷阱为真 那么关闭陷阱就为假
	bopenpitfall = bop;
	if (bopenpitfall)
		ClosePitfall(false);
	return bopenpitfall;
}

//关闭陷阱 要关闭陷阱调函数 传true
bool TreeEnchantment::ClosePitfall(bool bcp)
{
	//如果关闭陷阱为真 那么打开陷阱就为假
	bclosepitfall = bcp;
	if (bclosepitfall)
		OpenPitfall(false);
	return bclosepitfall;
}

//设置用户ID
void TreeEnchantment::Set_RoleID(uint32 uid)
{
	m_roleID = uid;//用户ID
}

//获取用户ID
uint32 TreeEnchantment::Get_RoleID()
{
	return m_roleID;
}


