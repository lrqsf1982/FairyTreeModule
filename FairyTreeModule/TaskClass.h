#pragma once

#ifndef _TASE_CLASS_H
#define _TASK_CLASS_H

#include "Gamedefine.h"
#include "Warehouse.h"
#include <map>

enum TaskState
{
	//未领取
	NotYet,
	//已经领取
	Already,
	//完成了
	Done,
	//已经领取奖品
	Received
};


//任务类
class TaskClass
{
public:
	TaskClass();
	~TaskClass();
	//设置任务编号
	void Set_TSerialNumber(uint32 tsn);
	// 获取任务编号
	uint32 Get_TSerialNumber();

	//设置任务标题
	void Set_TTaskheadline(const std::string& ttn);
	//获取任务标题
	std::string Get_TTaskheadline();

	//设置任务内容
	void Set_TTaskContent(const std::string& ttc);
	//获取任务内容
	std::string Get_TTaskContent();

	//设置任务奖励(物品类的表,(编号,数量))
	void Set_TTaskAward(uint32 stta, uint32 unum);
	//获取任务奖励(物品类的表,(编号,数量))
	std::map<uint32, uint32> Get_TTaskAward();

	//设置任务状态(result结果)
	void Set_TaskStateResult(uint32 num);
	//获取任务状态(result结果)
	TaskState Get_TaskStateResult();

	//设置任务当前完成度
	void Set_TaskCurComp(uint32 stcc);
	//获取任务当前完成度
	uint32 Get_TaskCurComp();

	//设置任务总的完成度
	void Set_TaskSumUpComp(uint32 stsuc);
	//获取任务总的完成度
	uint32 Get_TaskSumUpComp();

	//设置用户ID
	void Set_RoleID(uint32 uid);
	//获取用户ID
	uint32 Get_RoleID();

private:

	//用户ID
	uint32 m_roleID;

	//任务编号
	uint32 tserialnumber;

	//任务标题
	std::string staskheadline;

	//任务内容
	std::string staskcontent;

	//任务奖励(物品类的表,(编号,数量))
	std::map<uint32,uint32> mapware;
	

	//任务状态
	TaskState taskstate;

	//任务当前完成度
	uint32 taskCurComp;

	//任务总完成度
	uint32 taskSumUpComp;

};


//任务列表类
class CTaskListClass
{
public:
	CTaskListClass();
	~CTaskListClass();
	//增加任务
	void Add_Task(uint32 uid);
	//删除任务
	void Erase_Task(uint32 uid);
	//遍历任务
	TaskClass* ErgodicTask(uint32 uid);
	//任务个数
	uint32 GetTaskCount() { return (uint32)map_task.size(); }

	//设置用户ID
	void Set_RoleID(uint32 uid);
	//获取用户ID
	uint32 Get_RoleID();

	//任务类map
	std::map<uint32, TaskClass*> map_task;

	TaskClass * taskc;
private:

	//用户ID
	uint32 m_roleID;
	
	
};



#endif
