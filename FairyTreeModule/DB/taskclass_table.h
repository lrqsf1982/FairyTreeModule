#pragma once
#ifndef _TASK_CLASS_H_
#define _TASK_CLASS_H_
#include "mysql_encap.h"
//任务类数据
class CDB_TaskClass :public MysqlEncap
{
public:
	bool Select_tb_TaskClassid(UINT32 id);
	bool Insert_tb_TaskClassid(UINT32 id);
	bool Delete_tb_TaskClassid(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_TaskClass*>m_mapTaskClassInfo;
private:
	uint32_t	m_iTaskId;				//任务ID
	std::string		m_strTaskHead;			//任务标题
	std::string		m_strTaskDetails;		//任务内容
	uint32_t	m_iTaskState;			//任务状态(0完成、1未完成、2领取奖励、3未领取奖励)
	uint32_t	m_iTaskCurCompProgress;	//任务完成进度
	uint32_t	m_iTaskSumCompProgress;	//任务总完成进度
	MYSQL		m_sql;
};
#endif // 
