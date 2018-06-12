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

	//领取(标记邮件领取状态)(false为未取，true为已取)
	bool MailArticleGetState();

	//
	std::map<uint32, uint32> GetPrizes() {
		return vecmailArt;
	}

	//设置用户ID
	void Set_RoleID(uint32 uid);
	//获取用户ID
	uint32 Get_RoleID();

private:

	//用户ID
	uint32 m_roleID;

	//邮件编号
	uint32 umailSerialNumber;

	//邮件标题
	std::string smailheadline;

	//邮件内容
	std::string smailcontent;

	//邮件物品 物品id是Key 数量为值
	std::map<uint32,uint32> vecmailArt;

	//邮件物品的领取状态(false为未取，true为已取)
	bool bmailArtGetState;
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

	//设置用户ID
	void Set_RoleID(uint32 uid);
	//获取用户ID
	uint32 Get_RoleID();

	//邮件类map
	std::map<uint32, Mail*> map_mail;
private:

	//用户ID
	uint32 m_roleID;

	Mail * pboxmail;

};


#endif
