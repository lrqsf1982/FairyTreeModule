#include "Mail.h"



Mail::Mail()
{
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
int Mail::Get_MailSerialNumber()
{
	return umailSerialNumber;
}

//设置邮件标题
void Mail::Set_MailHeadline(std::string smh)
{
	smailheadline = smh;
}

//获取邮件标题
string Mail::Get_MailHeadline()
{
	return smailheadline;
}

//设置邮件内容
void Mail::Set_MailContent(std::string smc)
{
	smailcontent = smc;
}

//获取邮件内容
string Mail::Get_MailContent()
{
	return smailcontent;
}

//领取(标记邮件领取状态)(false为未取，true为已取)
bool Mail::MailArticleGetState()
{
	bmailArtGetState = true;
	return bmailArtGetState;
}



//邮箱类
CMailbox::CMailbox()
{
}

CMailbox::~CMailbox()
{
}

//增加邮件
void CMailbox::AddMail(Mail* cmail)
{
	vecmail.push_back(cmail);
}

//删除邮件
void CMailbox::CloseMail(uint32 closemail)
{
	
	//通过邮件编号 查找要删除的邮件
	for (std::vector<Mail*>::iterator itmail = vecmail.begin(); itmail != vecmail.end(); itmail++)
	{
		if (closemail == (*itmail)->Get_MailSerialNumber())
		{
			//找到了 删除邮件
			vecmail.erase(itmail);
		}
	}

}
