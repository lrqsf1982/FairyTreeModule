#pragma once

#ifndef _MAIL_H
#define _MAIL_H

#include "Gamedefine.h"
#include <map>
#include "Warehouse.h"


//�ʼ���
class Mail
{
public:
	Mail();
	~Mail();

	//�����ʼ����
	void Set_MailSerialNumber(uint32 smsn);
	//��ȡ�ʼ����
	uint32 Get_MailSerialNumber();

	//�����ʼ�����
	void Set_MailHeadline(const std::string& smh);
	//��ȡ�ʼ�����
	std::string Get_MailHeadline();

	//�����ʼ�����
	void Set_MailContent(const std::string& smc);
	//��ȡ�ʼ�����
	std::string Get_MailContent();

	//��ȡ״̬(����ʼ���ȡ״̬)(falseΪδȡ��trueΪ��ȡ)
	bool MailArticleGetState();

	//��Ʒmap<��Ʒ��ID,��Ʒ������>
	std::map<uint32, uint32> GetPrizes() {
		return m_vecArt;
	}

private:
	//�ʼ����
	uint32 m_SerNum;

	//�ʼ�����
	std::string m_headline;

	//�ʼ�����
	std::string m_content;

	//�ʼ���Ʒ ��Ʒid��Key ����Ϊֵ
	std::map<uint32,uint32> m_vecArt;

	//�ʼ���Ʒ����ȡ״̬(falseΪδȡ��trueΪ��ȡ)
	bool m_artGetS;
};


//������
class CMailbox
{
public:
	CMailbox();
	~CMailbox();
	//�����ʼ�
	void AddMail(uint32 uid);
	//ɾ���ʼ�
	void CloseMail(uint32 closemail);
	//�����ʼ�
	Mail* ErgodicMail(uint32 uid);
	//�ʼ�������
	uint32 MailNumber() { return (uint32)map_mail.size(); }

	//��ȡ�ʼ����map
	std::map<uint32, Mail*> Get_MailClassMap();
private:
	Mail * pmail;
	//�ʼ���map
	std::map<uint32, Mail*> map_mail;

};


#endif
