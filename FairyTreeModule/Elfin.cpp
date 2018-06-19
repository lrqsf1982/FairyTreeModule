#include "Elfin.h"
#include "XmlConfigManager.h"
#include <stdlib.h>
#include <time.h>


Elfin::Elfin()
{
	m_type = Get_ESkillStyle();//ö�����͵ļ�������

	m_id = Set_Get_EToID(m_type);//С�����ID

	m_level = 1;//�ȼ�

	m_maxphyPower = XmlConfigManager::GetInstance()->ElfinInfos[m_level]->physicalilmit;//�������

	m_curPhyPower = m_maxphyPower;//���� ��ʼ������Ϊ���
	
	m_skill = new CSkill;
}


Elfin::~Elfin()
{
	delete m_skill;
	m_skill = nullptr;
}

//������Ӽ��ܸ�
void Elfin::Set_ESkillStyle(CSkill* ecsk)
{
	m_vecSki.push_back(ecsk);
}

//����ɾ������ (Ҳ������������)
void Elfin::Set_EReduceSkillStyle(uint32 iderss)
{

	//ͨ���±� ���Ҷ�Ӧ������
	for (std::vector<CSkill*>::iterator itskill = m_vecSki.begin(); itskill != m_vecSki.end(); itskill++)
	{
		if (iderss == (*itskill)->Get_Skill_ID())
		{
			//�ҵ� ɾ��
			m_vecSki.erase(itskill);
		}
	}

}

//��ȡ���ܸ�
ElfinSkillType Elfin::Get_ESkillStyle()const
{
	//�������һ������
	srand(time(NULL));
	ElfinSkillType m_type = (ElfinSkillType)(rand() % 5);

	//���ؼ���
	return m_type;
}

//���õȼ�
void Elfin::Set_EGrade(uint32 beg)
{
	
	m_level += beg;

	
}

//��ȡ�ȼ�
uint32 Elfin::Get_EGrade()const
{
	return m_level;
}

//������������
void Elfin::Set_EAddPhysicalPower(uint32 ueap)
{
	//�����ǰ����ֵС���������ֵ
	if (m_curPhyPower < m_maxphyPower)
	{
		m_curPhyPower += ueap;
		//�����ǰ����ֵ�����������ֵ ��ô��ǰ����ֵ�͵����������ֵ
		if (m_curPhyPower > m_maxphyPower)
		{
			m_curPhyPower = m_maxphyPower;
		}
	}
		
}

//���ü�������
void Elfin::Set_EReducePhysicalPower(uint32 uerp)
{
	m_curPhyPower -= uerp;
	//�����ǰ���� С�� 0 ��ô��ǰ����ֵ�͵���0
	if (m_curPhyPower < 0)
	{
		m_curPhyPower = 0;
	}
}

//��ȡ��ǰ����
uint32 Elfin::Get_EPhysicalPower()const
{
	return m_curPhyPower;
}

//�����������
void Elfin::Set_EMaxPhysicalPower(uint32 uempp)
{
	//С����ÿ��һ��,��������ͻ���Ӧ����
	m_maxphyPower += uempp;
}

//��ȡ�������
uint32 Elfin::Get_EMaxPhysicalPower()const
{
	return m_maxphyPower;
}

//�����������С�����ID ����ȡ��
uint32 Elfin::Set_Get_EToID(ElfinSkillType m_type)
{
	switch (m_type)
	{
	case EGOLD: { m_id = 100001; break;	}
	case EWOOD: { m_id = 100002; break; }
	case EWATER: { m_id = 100003; break; }
	case EFIRE: { m_id = 100004; break; }
	case ESOIL: { m_id = 100005; break; }
	}
	return m_id;
}
//��ȡС�����ID
uint32 Elfin::Get_EToID()const
{
	return m_id;
}

//��ȡ������
CSkill * Elfin::Get_CSkillClass()const
{
	return m_skill;
}


