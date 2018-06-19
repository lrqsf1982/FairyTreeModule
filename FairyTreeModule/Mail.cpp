#include "Mail.h"



Mail::Mail()
{
	m_SerNum = 0; //邮件编号

	m_headline = ""; //邮件标题

	m_content = ""; //邮件内容

	m_artGetS = false; //邮件物品的领取状态(false为未取，true为已取)
}


Mail::~Mail()
{
}

//设置邮件编号
void Mail::Set_MailSerialNumber(uint32 smsn)
{
	m_SerNum = smsn;
}

//获取邮件编号
uint32 Mail::Get_MailSerialNumber()
{
	return m_SerNum;
}

//设置邮件标题
void Mail::Set_MailHeadline(const std::string& smh)
{
	m_headline = smh;
}

//获取邮件标题
std::string Mail::Get_MailHeadline()
{
	return m_headline;
}

//设置邮件内容
void Mail::Set_MailContent(const std::string& smc)
{
	m_content = smc;
}

//获取邮件内容
std::string Mail::Get_MailContent()
{
	return m_content;
}

//领取状态(标记邮件领取状态)(false为未取，true为已取)
bool Mail::MailArticleGetState()
{
	m_artGetS = true;
	return m_artGetS;
}






//邮箱类
CMailbox::CMailbox()
{
	pmail = new Mail;
}

CMailbox::~CMailbox()
{
	delete pmail;
	pmail = nullptr;
}

//增加邮件
void CMailbox::AddMail(uint32 uid)
{
	map_mail[uid] = pmail;
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

//获取邮件类的map
std::map<uint32, Mail*> CMailbox::Get_MailClassMap()
{
	return map_mail;
}
