#include "TaskClass.h"


TaskClass::TaskClass()
{
	m_roleID = 0;//用户ID

	tserialnumber = 0; //任务编号

	staskheadline = ""; //任务标题

	staskcontent = ""; //任务内容

	taskstate = NotYet; //任务状态

	taskCurComp = 0; //任务当前完成度

	taskSumUpComp = 0; //任务总完成度
}


TaskClass::~TaskClass()
{
}

//设置任务编号
void TaskClass::Set_TSerialNumber(uint32 tsn)
{
	tserialnumber = tsn;
}

// 获取任务编号
uint32 TaskClass::Get_TSerialNumber()
{
	return tserialnumber;
}

//设置任务标题
void TaskClass::Set_TTaskheadline(const std::string& ttn)
{
	staskheadline = ttn;
}

//获取任务标题
std::string TaskClass::Get_TTaskheadline()
{
	return staskheadline;
}

//设置任务内容
void TaskClass::Set_TTaskContent(const std::string& ttc)
{
	staskcontent = ttc;
}

//获取任务内容
std::string TaskClass::Get_TTaskContent()
{
	return staskcontent;
}

//设置任务奖励(物品类的表,(编号,数量))
void TaskClass::Set_TTaskAward(uint32 stta, uint32 unum)
{
	mapware[stta] = unum;
}

//获取任务奖励(物品类的表,(编号,数量))
std::map<uint32, uint32> TaskClass::Get_TTaskAward()
{
	return mapware;
}

//任务状态(result结果)
void TaskClass::Set_TaskStateResult(uint32 num)
{
	//设置任务状态
	switch (num)
	{
	case 0: { taskstate = NotYet; break; }
	case 1: { taskstate = Already; break; }
	case 2: { taskstate = Done; break; }
	case 3: { taskstate = Received; break; }
	}
}

//获取任务状态(result结果)
TaskState TaskClass::Get_TaskStateResult()
{
	return taskstate;
}

//设置任务当前完成度
void TaskClass::Set_TaskCurComp(uint32 stcc)
{
	taskCurComp += stcc;
}

//获取任务当前完成度
uint32 TaskClass::Get_TaskCurComp()
{
	return taskCurComp;
}

//设置任务总的完成度
void TaskClass::Set_TaskSumUpComp(uint32 stsuc)
{
	taskSumUpComp = stsuc;
}

//获取任务总的完成度
uint32 TaskClass::Get_TaskSumUpComp()
{
	return taskSumUpComp;
}

//设置用户ID
void TaskClass::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//获取用户ID
uint32 TaskClass::Get_RoleID()
{
	return m_roleID;
}



//任务列表类
CTaskListClass::CTaskListClass()
{
	m_roleID = 0;//用户ID
	taskc = new TaskClass;
}

CTaskListClass::~CTaskListClass()
{
	delete taskc;
}

//增加任务
void CTaskListClass::Add_Task(uint32 uid)
{
	map_task[uid] = taskc;

}

//删除任务
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


//遍历任务
TaskClass * CTaskListClass::ErgodicTask(uint32 index)
{
	return map_task[index];
}

//设置用户ID
void CTaskListClass::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//获取用户ID
uint32 CTaskListClass::Get_RoleID()
{
	return m_roleID;
}

