#pragma once
#ifndef _TASK_CLASS_H_
#define _TASK_CLASS_H_
#include "mysql_encap.h"
//����������
class CDB_TaskClass :public MysqlEncap
{
public:
	bool Select_tb_TaskClassid(UINT32 id);
	bool Insert_tb_TaskClassid(UINT32 id);
	bool Delete_tb_TaskClassid(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_TaskClass*>m_mapTaskClassInfo;
private:
	uint32_t	m_iTaskId;				//����ID
	std::string		m_strTaskHead;			//�������
	std::string		m_strTaskDetails;		//��������
	uint32_t	m_iTaskState;			//����״̬(0��ɡ�1δ��ɡ�2��ȡ������3δ��ȡ����)
	uint32_t	m_iTaskCurCompProgress;	//������ɽ���
	uint32_t	m_iTaskSumCompProgress;	//��������ɽ���
	MYSQL		m_sql;
};
#endif // 
