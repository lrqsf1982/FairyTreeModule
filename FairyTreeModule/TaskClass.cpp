#include "TaskClass.h"


//std::map<uint32, uint32> vecwareone;
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

//设置任务奖励(物品类的表,(编号,数量))1
void TaskClass::Set_TTaskAwardOne(uint32 stta, uint32 unum)
{
	vecwareone.insert(pair<uint32, uint32>(stta,unum));
}

//获取任务奖励(物品类的表,(编号,数量))1
std::map<uint32, uint32> TaskClass::Get_TTaskAwardOne()
{
	return vecwareone;
}

//设置任务奖励(物品类的表,(编号,数量))2
void TaskClass::Set_TTaskAwardTwo(uint32 stta, uint32 unum)
{
	vecwaretwo.insert(pair<uint32, uint32>(stta, unum));
}

//获取任务奖励(物品类的表,(编号,数量))2
std::map<uint32, uint32> TaskClass::Get_TTaskAwardTwo()
{
	return vecwaretwo;
}

//设置任务奖励(物品类的表,(编号,数量))3
void TaskClass::Set_TTaskAwardThree(uint32 stta, uint32 unum)
{
	vecwarethree.insert(pair<uint32, uint32>(stta, unum));
}

//获取任务奖励(物品类的表,(编号,数量))3
std::map<uint32, uint32> TaskClass::Get_TTaskAwardThree()
{
	return vecwarethree;
}

//任务状态(result结果)
TaskState TaskClass::TaskStateResult(uint32 utsr)
{
	//设置任务状态
	switch (utsr)
	{
	case 0: {taskstate = NotYet; break; }
	case 1: {taskstate = Already; break; }
	case 2: {taskstate = Done; break; }
	case 3: {taskstate = Received; break; }
	}
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

