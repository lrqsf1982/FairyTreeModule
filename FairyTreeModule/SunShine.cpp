#include "SunShine.h"
#include "XmlConfigManager.h"



CSunshine::CSunshine()
{
	m_lev = 1; //�ȼ�

	m_proCom = XmlConfigManager::GetInstance()->SunInfos[m_lev]->producompet; //����Ĳ�������

	m_num = 0; //���������
}


CSunshine::~CSunshine()
{
}


//���õȼ�
void CSunshine::Set_SunLevel(bool setgrad)
{
	if (setgrad)
	{
		m_lev += 1;
	}
}

//��ȡ�ȼ�
uint32 CSunshine::Get_SunLevel()const
{
	return m_lev;
}

//��������Ĳ�������
void CSunshine::Set_FSunProCom(uint32 setpro)
{
	//ÿ�β�����������
	m_proCom += setpro;
}

//��ȡ����Ĳ�������
uint32 CSunshine::Get_FSunProCom()const
{
	return m_proCom;
}

//�����������������
void CSunshine::Set_FAddSunNumber(uint32 unum)
{
	m_num += unum;
}

//���ü������������
void CSunshine::Set_FSubSunNum(uint32 unum)
{
	m_num -= unum;
}

//��ȡ���������
uint32 CSunshine::Get_FSunNumber()const
{
	return m_num;
}