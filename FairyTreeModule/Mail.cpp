#include "Mail.h"



Mail::Mail()
{
	m_SerNum = 0; //�ʼ����

	m_headline = ""; //�ʼ�����

	m_content = ""; //�ʼ�����

	m_artGetS = false; //�ʼ���Ʒ����ȡ״̬(falseΪδȡ��trueΪ��ȡ)
}


Mail::~Mail()
{
}

//�����ʼ����
void Mail::Set_MailSerialNumber(uint32 smsn)
{
	m_SerNum = smsn;
}

//��ȡ�ʼ����
uint32 Mail::Get_MailSerialNumber()
{
	return m_SerNum;
}

//�����ʼ�����
void Mail::Set_MailHeadline(const std::string& smh)
{
	m_headline = smh;
}

//��ȡ�ʼ�����
std::string Mail::Get_MailHeadline()
{
	return m_headline;
}

//�����ʼ�����
void Mail::Set_MailContent(const std::string& smc)
{
	m_content = smc;
}

//��ȡ�ʼ�����
std::string Mail::Get_MailContent()
{
	return m_content;
}

//��ȡ״̬(����ʼ���ȡ״̬)(falseΪδȡ��trueΪ��ȡ)
bool Mail::MailArticleGetState()
{
	m_artGetS = true;
	return m_artGetS;
}






//������
CMailbox::CMailbox()
{
	pmail = new Mail;
}

CMailbox::~CMailbox()
{
	delete pmail;
	pmail = nullptr;
}

//�����ʼ�
void CMailbox::AddMail(uint32 uid)
{
	map_mail[uid] = pmail;
}

//ɾ���ʼ�
void CMailbox::CloseMail(uint32 closemail)
{
	
	//ͨ���ʼ���� ����Ҫɾ�����ʼ�
	for (std::map<uint32, Mail*>::iterator itmail = map_mail.begin(); itmail != map_mail.end(); itmail++)
	{
		if (closemail == itmail->second->Get_MailSerialNumber())
		{
			//�ҵ��� ɾ���ʼ�
			map_mail.erase(itmail);
		}
	}

}

//�����ʼ�
Mail * CMailbox::ErgodicMail(uint32 uid)
{
	return map_mail[uid];
}

//��ȡ�ʼ����map
std::map<uint32, Mail*> CMailbox::Get_MailClassMap()
{
	return map_mail;
}
