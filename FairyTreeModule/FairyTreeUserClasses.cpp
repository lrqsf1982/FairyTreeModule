#include "FairyTreeUserClasses.h"



FairyTreeUserClasses::FairyTreeUserClasses()
{
	udiamond = 0; //钻石
}


FairyTreeUserClasses::~FairyTreeUserClasses()
{
}

//获取小精灵
Elfin* FairyTreeUserClasses::Get_Elfin(uint32 id)
{ 
	for (std::list<Elfin*>::iterator it = slistElfin.begin(); it != slistElfin.end(); it++)
	{
		if (id == (*it)->Get_ID())
		{
			return *it;
		}
	}
	return nullptr;
}

//获取神仙树
FairyTree FairyTreeUserClasses::Get_FairyTree()
{
	return fairytree;
}

//获取太阳
CSunshine FairyTreeUserClasses::Get_SunShine()
{
	return sunshine;
}

//获取树结界
TreeEnchantment FairyTreeUserClasses::Get_TreeEnchantment()
{
	return treeenchantment;
}

//获取仓库
Warehouse FairyTreeUserClasses::Get_Warehouse()
{
	return warehouse;
}

//获取商店
Shop FairyTreeUserClasses::Get_Shop()
{
	return shop;
}

//获取邮箱
CMailbox FairyTreeUserClasses::Get_CMailbox()
{
	return mailbox;
}

//获取任务列表
CTaskListClass FairyTreeUserClasses::Get_CTaskListClass()
{
	return tasklist;
}

//获取关系
Relation FairyTreeUserClasses::Get_Relation()
{
	return relation;
}

//获取排行榜
RankingList FairyTreeUserClasses::Get_RankingList()
{
	return rankinglist;
}

//获取技能
CSkill FairyTreeUserClasses::Get_CSkill()
{
	return skill;
}

//获取资源水
Water FairyTreeUserClasses::Get_Water()
{
	return water;
}

//获取资源金币
Gold FairyTreeUserClasses::Get_Gold()
{
	return gold;
}

//设置增加钻石
void FairyTreeUserClasses::Set_UserAddDiamond(uint32 sd)
{
	udiamond += sd;
}

//设置减少钻石
void FairyTreeUserClasses::Set_UserRedDiamond(uint32 surd)
{
	udiamond -= surd;
}

//获取钻石
int FairyTreeUserClasses::Get_UserDiamond()
{
	return udiamond;
}





//加载Xml文件
//bool bPaintXml(const char* pfilepath)
//{
//	//const char* filepath = ".Test.Xml";
//	//定义一个文件节点TiXmlDocument指针, 加载的将是整个XML文档,构建文档对象
//	TiXmlDocument* tixml = new TiXmlDocument(pfilepath);
//	if (NULL == tixml)
//	{
//		return false;
//	}
//	// 加载文件 文件名,就是将文件信息载入到文档对象中
//	tixml->LoadFile();
//
//	//Element元素是一个容器类
//	//根据文档对象找到跟元素或跟节点,就是指向节点的指针
//	TiXmlElement* proot = tixml->RootElement();
//
//	////从第一个名字为("Table")的节点循环 到它的下一个节点 
//	////NextSibling("Table")下一个名为"Table"的子节点
//	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
//	{
//		TiXmlNode* pchild = pnode->FirstChild();
//		const char* pgrade = pchild->ToElement()->GetText(); //获得这个节点的值(等级)
//
//		if (pgrade)
//		{
//			OUR_DEBUG((LM_INFO, "pgrade = %s\n", pgrade));
//		}
//		else
//		{
//			OUR_DEBUG((LM_INFO, "error pgrade = %s\n"));
//		}
//
//		pchild = pnode->IterateChildren(pchild);//IterateChildren()返回下一个子节点
//		const char* ptiLi = pchild->ToElement()->GetText(); //获得这个节点的值(当前等级下的最大体力)
//
//		if (ptiLi)
//		{
//			OUR_DEBUG((LM_INFO, "ptiLi = %s\n", ptiLi));
//		}
//		else
//		{
//			OUR_DEBUG((LM_INFO, "error ptiLi = %s\n"));
//		}
//	}
//	return true;
//}
