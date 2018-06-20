#pragma once
#ifndef _TASK_LIST_CLASS_H_
#define _TASK_LIST_CLASS_H_
#include "mysql_encap.h"
//任务列表类数据
class CDB_TaskListClass :public MysqlEncap
{
public:
	bool Select_tb_TaskListClass_id(UINT32 id);
	bool Insert_tb_TaskListClass_id(UINT32 id);
	bool Delete_tb_TaskListClass_id(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_TaskListClass*>m_mapTaskListClassInfo;
private:
	UINT32		m_iTaskId;					//任务ID
	UINT32		m_taskListNum;				//任务数量
	std::string		m_strTaskHead;				//任务标题
	std::string		m_strTaskDetails;			//任务内容
	MYSQL		m_sql;
};
#endif // !_TASK_LIST_CLASS_H_

