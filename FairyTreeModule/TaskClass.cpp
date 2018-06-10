#include "TaskClass.h"


TaskClass::TaskClass()
{
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
int TaskClass::Get_TSerialNumber()
{
	return tserialnumber;
}

//设置任务标题
void TaskClass::Set_TTaskheadline(std::string ttn)
{
	staskheadline = ttn;
}

//获取任务标题
string TaskClass::Get_TTaskheadline()
{
	return staskheadline;
}

//设置任务内容
void TaskClass::Set_TTaskContent(std::string ttc)
{
	staskcontent = ttc;
}

//获取任务内容
string TaskClass::Get_TTaskContent()
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
TaskState TaskClass::TaskStateResult()
{
	//设置任务状态
	return taskstate;
}

//设置任务当前完成度
void TaskClass::Set_TaskCurComp(uint32 stcc)
{
	taskCurComp += stcc;
}

//获取任务当前完成度
int TaskClass::Get_TaskCurComp()
{
	return taskCurComp;
}

//设置任务总的完成度
void TaskClass::Set_TaskSumUpComp(uint32 stsuc)
{
	taskSumUpComp = stsuc;
}

//获取任务总的完成度
int TaskClass::Get_TaskSumUpComp()
{
	return taskSumUpComp;
}



//任务列表类
CTaskListClass::CTaskListClass()
{
	taskc = new TaskClass;
}

CTaskListClass::~CTaskListClass()
{
}

//增加任务
void CTaskListClass::Add_Task(TaskClass * addtask)
{
	vectc.push_back(addtask);

}

//删除任务
void CTaskListClass::Erase_Task(TaskClass * addtask)
{
	std::vector<TaskClass*>::iterator ittask = std::find(vectc.begin(), vectc.end(), addtask);
	if (ittask == vectc.end())
	{
		return;
	}
	else
	{
		vectc.erase(ittask);
	}

}


//遍历任务
TaskClass * CTaskListClass::ErgodicTask(uint32 index)
{
	return vectc[index];
}

