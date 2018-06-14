#pragma once
#ifndef _CHARACTER_TABLE_H_
#define _CHARACTER_TABLE_H_
#include <string>
#include "mysql_encap.h"


//角色类数据   
class CDB_Character :public MysqlEncap
{
public:
	bool loadtable(void * dbcon);

	//只能支持对角色ID的操作
	bool Select_tb_userid(UINT32 id);
	bool Insert_tb_userid(UINT32 id, const std::string& name);
	bool Delete_tb_userid(UINT32 id);

	//获取相关属性
	UINT32 GetId();
	const std::string& GetName();
	UINT32 GetLevel();
	UINT32 GetGrowValue();
	char GetunlineTime(char*temp);
	std::map<UINT32, CDB_Character*>m_mapcharacterInfo;

	UINT32	m_uroleID;					//角色ID
	std::string	m_sroleName;				//角色名字
	UINT32	m_urolelevel;				//角色等级
	UINT32	m_urolegrowthvalue;			//角色成长值
	char*	m_unlineTime=NULL;			//离线时间
	MYSQL   m_sql;
};

#endif 

