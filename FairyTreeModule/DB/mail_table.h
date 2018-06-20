#pragma once
#ifndef _MAIL_H 
#define _MAIL_H
#include "mysql_encap.h"
//�ʼ�������
class CDB_Mail :public MysqlEncap
{
public:
	bool loadtable(void * dbcon);
	//ֻ��֧�ֶ�ID�Ĳ���
	bool Select_tb_Mailid(UINT32 id);
	bool Insert_tb_Mailid(UINT32 id);
	bool Delete_tb_Mailid(UINT32 id);
	std::map<UINT32, CDB_Mail*>m_mapMailInfo;
private:
	UINT32		m_userId;				//�û�ID
	UINT32		m_iMailId;				//�ʼ�ID
	std::string		m_sMailHead;			//�ʼ�����
	std::string		m_sMailContent;			//�ʼ�����
	MYSQL		m_sql;
};
#endif // 
