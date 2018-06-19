#include "TaskClass.h"


TaskClass::TaskClass()
{
	m_taskNum = 0; //任务编号

	m_taskHe = ""; //任务标题

	m_taskCon = ""; //任务内容

	m_taskState = NotYet; //任务状态

	m_curComp = 0; //任务当前完成度

	m_sumUpComp = 0; //任务需要总的完成度
}


TaskClass::~TaskClass()
{
}

//设置任务编号
void TaskClass::Set_TSerialNumber(uint32 tsn)
{
	m_taskNum = tsn;
}

// 获取任务编号
uint32 TaskClass::Get_TSerialNumber()
{
	return m_taskNum;
}

//设置任务标题
void TaskClass::Set_TTaskheadline(const std::string& ttn)
{
	m_taskHe = ttn;
}

//获取任务标题
std::string TaskClass::Get_TTaskheadline()
{
	return m_taskHe;
}

//设置任务内容
void TaskClass::Set_TTaskContent(const std::string& ttc)
{
	m_taskCon = ttc;
}

//获取任务内容
std::string TaskClass::Get_TTaskContent()
{
	return m_taskCon;
}

//设置任务奖励(物品类的表,(编号,数量))
void TaskClass::Set_TTaskAward(uint32 stta, uint32 unum)
{
	map_queRew[stta] = unum;
}

//获取任务奖励(物品类的表,(编号,数量))
std::map<uint32, uint32> TaskClass::Get_TTaskAward()
{
	return map_queRew;
}

//任务状态(result结果)
void TaskClass::Set_TaskStateResult(uint32 num)
{
	//设置任务状态
	switch (num)
	{
	case 0: { m_taskState = NotYet; break; }
	case 1: { m_taskState = Already; break; }
	case 2: { m_taskState = Done; break; }
	case 3: { m_taskState = Received; break; }
	}
}

//获取任务状态(result结果)
TaskState TaskClass::Get_TaskStateResult()
{
	return m_taskState;
}

//设置任务当前完成度
void TaskClass::Set_TaskCurComp(uint32 stcc)
{
	m_curComp += stcc;
}

//获取任务当前完成度
uint32 TaskClass::Get_TaskCurComp()
{
	return m_curComp;
}

//设置任务需要总的完成度
void TaskClass::Set_TaskSumUpComp(uint32 stsuc)
{
	m_sumUpComp = stsuc;
}

//获取任务需要总的完成度
uint32 TaskClass::Get_TaskSumUpComp()
{
	return m_sumUpComp;
}





//任务列表类
CTaskListClass::CTaskListClass()
{
	taskc = new TaskClass;
}

CTaskListClass::~CTaskListClass()
{
	delete taskc;
	taskc = NULL;
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
//任务个数
uint32 CTaskListClass::GetTaskCount()
{
	return (uint32)map_task.size();
}

//获取任务map
std::map<uint32, TaskClass*> CTaskListClass::Get_TaskMap()
{
	return map_task;
}

