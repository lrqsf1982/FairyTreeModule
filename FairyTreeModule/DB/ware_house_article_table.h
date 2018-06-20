#pragma once

#ifndef _WARE_HOUSE_ARTICLE_H_
#define _WARE_HOUSE_ARTICLE_H_

#include "mysql_encap.h"

//��Ʒ������
class CDB_WarehouseArticle :public MysqlEncap
{
public:
	bool Select_tb_WarehouseArticle_id(UINT32 id);
	bool Insert_tb_WarehouseArticle_id(UINT32 id);
	bool Delete_tb_WarehouseArticle_id(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_WarehouseArticle*>m_mapWarehouseArticleInfo;
private:
	uint32_t m_iArticleID;				//��Ʒ���
	uint32_t m_iGoldPrice;				//��Ʒ��Ҽ۸�
	uint32_t m_iJewelPrice;				//��ʯ�۸�
	FLOAT    m_fArticleDescribe;		//��Ʒ�ۿ�
	std::string   m_strDescribe;				//��Ʒ����
	MYSQL	 m_sql;
};

#endif // 
