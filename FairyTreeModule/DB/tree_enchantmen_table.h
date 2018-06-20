#pragma once
#ifndef _TREE_ENCHANTMENT_H_
#define _TREE_ENCHANTMENT_H_
#include "mysql_encap.h"
//�����������
class CDB_TreeEnchantment :public MysqlEncap
{
public:
	bool Select_tb_TreeEnchantment_id(UINT32 id);
	bool Insert_tb_TreeEnchantment_id(UINT32 id);
	bool Delete_tb_TreeEnchantment_id(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_TreeEnchantment*>m_mapTreeEnchantmentInfo;
private:
	UINT32		m_UerID;					//�û�ID
	UINT32		m_iLevel;					//�����ȼ�
	UINT32		m_defenseRating;			//�������������ȼ�
	MYSQL		m_sql;
};
#endif // !_TREE_ENCHANTMENT_H_

