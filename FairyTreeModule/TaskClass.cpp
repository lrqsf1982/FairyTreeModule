#include "TaskClass.h"


TaskClass::TaskClass()
{
	m_taskNum = 0; //������

	m_taskHe = ""; //�������

	m_taskCon = ""; //��������

	m_taskState = NotYet; //����״̬

	m_curComp = 0; //����ǰ��ɶ�

	m_sumUpComp = 0; //������Ҫ�ܵ���ɶ�
}


TaskClass::~TaskClass()
{
}

//����������
void TaskClass::Set_TSerialNumber(uint32 tsn)
{
	m_taskNum = tsn;
}

// ��ȡ������
uint32 TaskClass::Get_TSerialNumber()
{
	return m_taskNum;
}

//�����������
void TaskClass::Set_TTaskheadline(const std::string& ttn)
{
	m_taskHe = ttn;
}

//��ȡ�������
std::string TaskClass::Get_TTaskheadline()
{
	return m_taskHe;
}

//������������
void TaskClass::Set_TTaskContent(const std::string& ttc)
{
	m_taskCon = ttc;
}

//��ȡ��������
std::string TaskClass::Get_TTaskContent()
{
	return m_taskCon;
}

//����������(��Ʒ��ı�,(���,����))
void TaskClass::Set_TTaskAward(uint32 stta, uint32 unum)
{
	map_queRew[stta] = unum;
}

//��ȡ������(��Ʒ��ı�,(���,����))
std::map<uint32, uint32> TaskClass::Get_TTaskAward()
{
	return map_queRew;
}

//����״̬(result���)
void TaskClass::Set_TaskStateResult(uint32 num)
{
	//��������״̬
	switch (num)
	{
	case 0: { m_taskState = NotYet; break; }
	case 1: { m_taskState = Already; break; }
	case 2: { m_taskState = Done; break; }
	case 3: { m_taskState = Received; break; }
	}
}

//��ȡ����״̬(result���)
TaskState TaskClass::Get_TaskStateResult()
{
	return m_taskState;
}

//��������ǰ��ɶ�
void TaskClass::Set_TaskCurComp(uint32 stcc)
{
	m_curComp += stcc;
}

//��ȡ����ǰ��ɶ�
uint32 TaskClass::Get_TaskCurComp()
{
	return m_curComp;
}

//����������Ҫ�ܵ���ɶ�
void TaskClass::Set_TaskSumUpComp(uint32 stsuc)
{
	m_sumUpComp = stsuc;
}

//��ȡ������Ҫ�ܵ���ɶ�
uint32 TaskClass::Get_TaskSumUpComp()
{
	return m_sumUpComp;
}





//�����б���
CTaskListClass::CTaskListClass()
{
	taskc = new TaskClass;
}

CTaskListClass::~CTaskListClass()
{
	delete taskc;
	taskc = NULL;
}

//��������
void CTaskListClass::Add_Task(uint32 uid)
{
	map_task[uid] = taskc;

}

//ɾ������
void CTaskListClass::Erase_Task(uint32 uid)
{
	for (std::map<uint32, TaskClass*>::iterator ittask = map_task.begin(); ittask != map_task.end(); ittask++)
	{
		if (uid == ittask->second->Get_TSerialNumber())
		{
			map_task.erase(ittask);
		}
	}

}

//��������
TaskClass * CTaskListClass::ErgodicTask(uint32 index)
{
	return map_task[index];
}
//�������
uint32 CTaskListClass::GetTaskCount()
{
	return (uint32)map_task.size();
}

//��ȡ����map
std::map<uint32, TaskClass*> CTaskListClass::Get_TaskMap()
{
	return map_task;
}

