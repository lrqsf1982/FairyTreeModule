#pragma once

#ifndef _MAIL_H
#define _MAIL_H

#include "Gamedefine.h"
#include <map>
#include "Warehouse.h"


//邮件类
class Mail
{
public:
	Mail();
	~Mail();

	//设置邮件编号
	void Set_MailSerialNumber(uint32 smsn);
	//获取邮件编号
	uint32 Get_MailSerialNumber();

	//设置邮件标题
	void Set_MailHeadline(const std::string& smh);
	//获取邮件标题
	std::string Get_MailHeadline();

	//设置邮件内容
	void Set_MailContent(const std::string& smc);
	//获取邮件内容
	std::string Get_MailContent();

	//领取状态(标记邮件领取状态)(false为未取，true为已取)
	bool MailArticleGetState();

	//奖品map<奖品的ID,奖品的数量>
	std::map<uint32, uint32> GetPrizes() {
		return m_vecArt;
	}

private:
	//邮件编号
	uint32 m_SerNum;

	//邮件标题
	std::string m_headline;

	//邮件内容
	std::string m_content;

	//邮件奖品 奖品id是Key 数量为值
	std::map<uint32,uint32> m_vecArt;

	//邮件奖品的领取状态(false为未取，true为已取)
	bool m_artGetS;
};


//邮箱类
class CMailbox
{
public:
	CMailbox();
	~CMailbox();
	//增加邮件
	void AddMail(uint32 uid);
	//删除邮件
	void CloseMail(uint32 closemail);
	//遍历邮件
	Mail* ErgodicMail(uint32 uid);
	//邮件的数量
	uint32 MailNumber() { return (uint32)map_mail.size(); }

	//获取邮件类的map
	std::map<uint32, Mail*> Get_MailClassMap();
private:
	Mail * pmail;
	//邮件类map
	std::map<uint32, Mail*> map_mail;

};


#endif
