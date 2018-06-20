#pragma once

#ifndef _WARE_HOUSE_ARTICLE_H_
#define _WARE_HOUSE_ARTICLE_H_

#include "mysql_encap.h"

//物品类数据
class CDB_WarehouseArticle :public MysqlEncap
{
public:
	bool Select_tb_WarehouseArticle_id(UINT32 id);
	bool Insert_tb_WarehouseArticle_id(UINT32 id);
	bool Delete_tb_WarehouseArticle_id(UINT32 id);
	bool loadtable(void * dbcon);
	std::map<UINT32, CDB_WarehouseArticle*>m_mapWarehouseArticleInfo;
private:
	uint32_t m_iArticleID;				//物品编号
	uint32_t m_iGoldPrice;				//物品金币价格
	uint32_t m_iJewelPrice;				//钻石价格
	FLOAT    m_fArticleDescribe;		//物品折扣
	std::string   m_strDescribe;				//物品描述
	MYSQL	 m_sql;
};

#endif // 
