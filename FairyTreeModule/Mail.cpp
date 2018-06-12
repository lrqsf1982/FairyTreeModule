#include "Mail.h"



Mail::Mail()
{
	m_roleID = 0;//用户ID

	umailSerialNumber = 0; //邮件编号

	smailheadline = ""; //邮件标题

	smailcontent = ""; //邮件内容

	bmailArtGetState = false; //邮件物品的领取状态(false为未取，true为已取)
}


Mail::~Mail()
{
}

//设置邮件编号
void Mail::Set_MailSerialNumber(uint32 smsn)
{
	umailSerialNumber = smsn;
}

//获取邮件编号
uint32 Mail::Get_MailSerialNumber()
{
	return umailSerialNumber;
}

//设置邮件标题
void Mail::Set_MailHeadline(const std::string& smh)
{
	smailheadline = smh;
}

//获取邮件标题
std::string Mail::Get_MailHeadline()
{
	return smailheadline;
}

//设置邮件内容
void Mail::Set_MailContent(const std::string& smc)
{
	smailcontent = smc;
}

//获取邮件内容
std::string Mail::Get_MailContent()
{
	return smailcontent;
}

//领取(标记邮件领取状态)(false为未取，true为已取)
bool Mail::MailArticleGetState()
{
	bmailArtGetState = true;
	return bmailArtGetState;
}

//设置用户ID
void Mail::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//获取用户ID
uint32 Mail::Get_RoleID()
{
	return m_roleID;
}



//邮箱类
CMailbox::CMailbox()
{
	m_roleID = 0;//用户ID
	pboxmail = new Mail;
}

CMailbox::~CMailbox()
{
	delete pboxmail;
}

//增加邮件
void CMailbox::AddMail(uint32 uid)
{
	map_mail[uid] = pboxmail;
}

//删除邮件
void CMailbox::CloseMail(uint32 closemail)
{
	
	//通过邮件编号 查找要删除的邮件
	for (std::map<uint32, Mail*>::iterator itmail = map_mail.begin(); itmail != map_mail.end(); itmail++)
	{
		if (closemail == itmail->second->Get_MailSerialNumber())
		{
			//找到了 删除邮件
			map_mail.erase(itmail);
		}
	}

}

//遍历邮件
Mail * CMailbox::ErgodicMail(uint32 uid)
{
	return map_mail[uid];
}

//设置用户ID
void CMailbox::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//获取用户ID
uint32 CMailbox::Get_RoleID()
{
	return m_roleID;
}
