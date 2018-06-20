#pragma once
#ifndef _TASK_LIST_CLASS_H_
#define _TASK_LIST_CLASS_H_
#include "mysql_encap.h"
//�����б�������
class CDB_TaskListClass :public MysqlEncap
{
public:
	bool Select_tb_TaskListClass_id(UINT32 id);
	bool Insert_tb_TaskListClass_id(UINT32 id);
	bool Delete_tb_TaskListClass_id(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_TaskListClass*>m_mapTaskListClassInfo;
private:
	UINT32		m_iTaskId;					//����ID
	UINT32		m_taskListNum;				//��������
	std::string		m_strTaskHead;				//�������
	std::string		m_strTaskDetails;			//��������
	MYSQL		m_sql;
};
#endif // !_TASK_LIST_CLASS_H_

