#pragma once

#ifndef _FAIRY_WELL_H
#define _FAIRY_WELL_H

#include "Gamedefine.h"
#include <map>


//̫���� ��ȡ����Xml�ļ�
class CSunshine
{
public:
	CSunshine();
	~CSunshine();

	//���õȼ�
	void Set_SunLevel(bool setgrad);
	//��ȡ�ȼ�
	uint32 Get_SunLevel();

	//��������Ĳ�������
	void Set_FSunProCom(uint32 setpro);
	//��ȡ����Ĳ�������
	uint32 Get_FSunProCom();

	//�����������������
	void Set_FAddSunNumber(uint32 unum);
	//���ü������������
	void Set_FSubSunNum(uint32 unum);
	//��ȡ���������
	uint32 Get_FSunNumber();
private:

	//�ȼ�
	uint32 m_lev;

	//����Ĳ�������
	uint32 m_proCom;

	//���������
	uint32 m_num;
};


#endif
