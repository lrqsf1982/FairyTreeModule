#pragma once
#ifndef _MAILBOX_H_
#define _MAILBOX_H_
#include "mysql_encap.h"
//����������
class CDB_Mailbox :public MysqlEncap
{
public:
	bool loadtable(void * dbcon);
	//ֻ��֧�ֶ�ID�Ĳ���
	bool Select_tb_Mailboxid(UINT32 id);
	bool Insert_tb_Mailboxid(UINT32 id);
	bool Delete_tb_Mailboxid(UINT32 id);
	std::map<UINT32, CDB_Mailbox*>m_mapMailboxInfo;
private:
	uint32_t	m_iMailBoxId;				//����ID
	MYSQL		m_sql;
};
#endif // _MAILBOX_H_
