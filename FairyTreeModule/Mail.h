#pragma once

#ifndef _MAIL_H
#define _MAIL_H

#include "define.h"
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
	int Get_MailSerialNumber();

	//设置邮件标题
	void Set_MailHeadline(std::string smh);
	//获取邮件标题
	string Get_MailHeadline();

	//设置邮件内容
	void Set_MailContent(std::string smc);
	//获取邮件内容
	string Get_MailContent();

	//领取(标记邮件领取状态)(false为未取，true为已取)
	bool MailArticleGetState();

private:
	//邮件编号
	uint32 umailSerialNumber;

	//邮件标题
	std::string smailheadline;

	//邮件内容
	std::string smailcontent;

	//邮件物品 物品类名是Key 数量为值
	std::map<CWarehouseArticle*,int> vecmailArt;

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
	void AddMail(Mail* cmail);
	//删除邮件
	void CloseMail(uint32 closemail);

private:
	//商品的 map
	std::vector<Mail*> vecmail;
};


#endif
