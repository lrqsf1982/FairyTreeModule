#pragma once
#ifndef _MAILBOX_H_
#define _MAILBOX_H_
#include "mysql_encap.h"
//邮箱类数据
class CDB_Mailbox :public MysqlEncap
{
public:
	bool loadtable(void * dbcon);
	//只能支持对ID的操作
	bool Select_tb_Mailboxid(UINT32 id);
	bool Insert_tb_Mailboxid(UINT32 id);
	bool Delete_tb_Mailboxid(UINT32 id);
	std::map<UINT32, CDB_Mailbox*>m_mapMailboxInfo;
private:
	uint32_t	m_iMailBoxId;				//邮箱ID
	MYSQL		m_sql;
};
#endif // _MAILBOX_H_
