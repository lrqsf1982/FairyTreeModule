#pragma once

#ifndef _TASE_CLASS_H
#define _TASK_CLASS_H

#include "Gamedefine.h"
#include "Warehouse.h"
#include <map>

enum TaskState
{
	//δ��ȡ
	NotYet,
	//�Ѿ���ȡ
	Already,
	//�����
	Done,
	//�Ѿ���ȡ��Ʒ
	Received
};


//������
class TaskClass
{
public:
	TaskClass();
	~TaskClass();
	//����������
	void Set_TSerialNumber(uint32 tsn);
	// ��ȡ������
	uint32 Get_TSerialNumber();

	//�����������
	void Set_TTaskheadline(const std::string& ttn);
	//��ȡ�������
	std::string Get_TTaskheadline();

	//������������
	void Set_TTaskContent(const std::string& ttc);
	//��ȡ��������
	std::string Get_TTaskContent();

	//����������(��Ʒ��ı�,(���,����))
	void Set_TTaskAward(uint32 stta, uint32 unum);
	//��ȡ������(��Ʒ��ı�,(���,����))
	std::map<uint32, uint32> Get_TTaskAward();

	//��������״̬(result���)
	void Set_TaskStateResult(uint32 num);
	//��ȡ����״̬(result���)
	TaskState Get_TaskStateResult();

	//��������ǰ��ɶ�
	void Set_TaskCurComp(uint32 stcc);
	//��ȡ����ǰ��ɶ�
	uint32 Get_TaskCurComp();

	//����������Ҫ�ܵ���ɶ�
	void Set_TaskSumUpComp(uint32 stsuc);
	//��ȡ������Ҫ�ܵ���ɶ�
	uint32 Get_TaskSumUpComp();

private:
	//������
	uint32 m_taskNum;

	//�������
	std::string m_taskHe;

	//��������
	std::string m_taskCon;

	//������(��Ʒ��ı�,(���,����))
	std::map<uint32,uint32> map_queRew;

	//����״̬
	TaskState m_taskState;

	//����ǰ��ɶ�
	uint32 m_curComp;

	//������Ҫ�ܵ���ɶ�
	uint32 m_sumUpComp;

};


//�����б���
class CTaskListClass
{
public:
	CTaskListClass();
	~CTaskListClass();
	//��������
	void Add_Task(uint32 uid);
	//ɾ������
	void Erase_Task(uint32 uid);
	//��������
	TaskClass* ErgodicTask(uint32 uid);
	//�������
	uint32 GetTaskCount();

	//��ȡ����map
	std::map<uint32, TaskClass*> Get_TaskMap();
private:
	TaskClass * taskc;
	//������map
	std::map<uint32, TaskClass*> map_task;
};

#endif
