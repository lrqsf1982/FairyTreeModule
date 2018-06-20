#pragma once
#ifndef _MAIL_H 
#define _MAIL_H
#include "mysql_encap.h"
//邮件类数据
class CDB_Mail :public MysqlEncap
{
public:
	bool loadtable(void * dbcon);
	//只能支持对ID的操作
	bool Select_tb_Mailid(UINT32 id);
	bool Insert_tb_Mailid(UINT32 id);
	bool Delete_tb_Mailid(UINT32 id);
	std::map<UINT32, CDB_Mail*>m_mapMailInfo;
private:
	UINT32		m_userId;				//用户ID
	UINT32		m_iMailId;				//邮件ID
	std::string		m_sMailHead;			//邮件标题
	std::string		m_sMailContent;			//邮件内容
	MYSQL		m_sql;
};
#endif // 
