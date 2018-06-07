#include "XmlConfigManager.h"



XmlConfigManager::XmlConfigManager()
{
	ParseXmlToItem();//物品
	ParseXmlToElfin();//小精灵
	ParseXmlToSkill();//技能
	ParseXmlToSunshine();//阳光
	ParseXmlToTask();//任务
	ParseXmlToTree();//神仙树
	ParseXmlToTreeEnchantment();//树结界
}


bool XmlConfigManager::ParseXmlToItem()
{
	const char* pItemXmlFileName = "Item.xml"; //物品xml文件名
	ItemInfo iteminfo; //物品结构体对象
	TiXmlDocument* ptixml = new TiXmlDocument();//构建文档对象指针
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pItemXmlFileName);//加载文件
	TiXmlElement* proot = ptixml->RootElement(); //指向根节点
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		iteminfo.articleID = atoi(pchild->ToElement()->GetText());//设置物品ID

		pchild = pnode->IterateChildren(pchild);
		iteminfo.articlename = pchild->ToElement()->GetText();//设置物品名字

		pchild = pnode->IterateChildren(pchild);
		iteminfo.articledescribe = pchild->ToElement()->GetText(); //物品描述

		pchild = pnode->IterateChildren(pchild);
		iteminfo.goldprice = atoi(pchild->ToElement()->GetText());//物品金币价格

		pchild = pnode->IterateChildren(pchild);
		iteminfo.diamondprice = atoi(pchild->ToElement()->GetText());//物品钻石价格

		pchild = pnode->IterateChildren(pchild);
		iteminfo.discountrate = atof(pchild->ToElement()->GetText());//物品折扣率	

		pchild = pnode->IterateChildren(pchild);
		iteminfo.type = pchild->ToElement()->GetText(); //物品类型		

		pchild = pnode->IterateChildren(pchild);
		iteminfo.photoname = pchild->ToElement()->GetText(); //物品图片名

		ItemInfos[iteminfo.articleID] = &iteminfo;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToElfin()
{
	const char* pElfinXmlFileName = "Elfin.xml"; //小精灵xml文件名
	ElfinInfo elifninfo; //小精灵结构体对象
	TiXmlDocument* ptixml = new TiXmlDocument();//构建文档对象指针
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pElfinXmlFileName);//加载文件
	TiXmlElement* proot = ptixml->RootElement(); //指向根节点
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		elifninfo.grade = atoi(pchild->ToElement()->GetText());//读取等级

		pchild = pnode->IterateChildren(pchild);
		elifninfo.physicalilmit = atoi(pchild->ToElement()->GetText());//读取体力上限

		pchild = pnode->IterateChildren(pchild);
		elifninfo.cowaternumber = atoi(pchild->ToElement()->GetText());//读取消耗水的数量

		pchild = pnode->IterateChildren(pchild);
		elifninfo.cosunnum = atoi(pchild->ToElement()->GetText());//读取阳光数量消耗

		pchild = pnode->IterateChildren(pchild);
		elifninfo.cogoldnum = atoi(pchild->ToElement()->GetText());//读取金币数量消耗

		pchild = pnode->IterateChildren(pchild);
		elifninfo.codiamondnum = atoi(pchild->ToElement()->GetText());//读取钻石消耗数量

		ElfinInfos[elifninfo.grade] = &elifninfo;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToSkill()
{
	const char* pSkillXmlFileName = "Skill.xml"; //技能xml文件名
	SkillInfo skillinfo; //技能结构体对象
	TiXmlDocument* ptixml = new TiXmlDocument();//构建文档对象指针
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pSkillXmlFileName);//加载文件
	TiXmlElement* proot = ptixml->RootElement(); //指向根节点
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		skillinfo.Level = atoi(pchild->ToElement()->GetText());//读取等级

		pchild = pnode->IterateChildren(pchild);
		skillinfo.plunder = atoi(pchild->ToElement()->GetText());//读取掠夺效果

		pchild = pnode->IterateChildren(pchild);
		skillinfo.watering = atoi(pchild->ToElement()->GetText());//读取浇水效果

		pchild = pnode->IterateChildren(pchild);
		skillinfo.storage = atoi(pchild->ToElement()->GetText());//读取储存金币

		pchild = pnode->IterateChildren(pchild);
		skillinfo.cultivation = atoi(pchild->ToElement()->GetText());//读取栽培效果

		pchild = pnode->IterateChildren(pchild);
		skillinfo.elude = atoi(pchild->ToElement()->GetText());//读取躲避能力

		pchild = pnode->IterateChildren(pchild);
		skillinfo.plunderAddition = atoi(pchild->ToElement()->GetText());//读取抢劫加成

		SkillInfos[skillinfo.Level] = &skillinfo;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToSunshine()
{
	const char* pSunXmlFileName = "Sun.xml"; //阳光xml文件名
	SunshineInfo sunshine; //结构体对象
	TiXmlDocument* ptixml = new TiXmlDocument();//构建文档对象指针
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pSunXmlFileName);//加载文件
	TiXmlElement* proot = ptixml->RootElement(); //指向根节点

	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		sunshine.grade = atoi(pchild->ToElement()->GetText());//读取等级

		pchild = pnode->IterateChildren(pchild);
		sunshine.cowaternumber = atoi(pchild->ToElement()->GetText());//读取消耗水的数量

		pchild = pnode->IterateChildren(pchild);
		sunshine.cosunnum = atoi(pchild->ToElement()->GetText());//读取阳光数量消耗

		pchild = pnode->IterateChildren(pchild);
		sunshine.cogoldnum = atoi(pchild->ToElement()->GetText());//读取金币数量消耗

		pchild = pnode->IterateChildren(pchild);
		sunshine.codiamondnum = atoi(pchild->ToElement()->GetText());//读取钻石消耗数量

		pchild = pnode->IterateChildren(pchild);
		sunshine.producompet = atoi(pchild->ToElement()->GetText());//读取产出能力

		pchild = pnode->IterateChildren(pchild);
		sunshine.produtime = atoi(pchild->ToElement()->GetText());//读取生产时间

		SunInfos[sunshine.grade] = &sunshine;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToTask()
{
	const char* pTaskXmlFileName = "Task.xml"; //任务xml文件名
	TaskInfo taskclass; //任务结构体对象
	TiXmlDocument* ptixml = new TiXmlDocument(); //构建文档对象指针
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pTaskXmlFileName); //加载文件
	TiXmlElement* proot = ptixml->RootElement(); //指向根节点
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		taskclass.taskId = atoi(pchild->ToElement()->GetText());//读取任务编号

		pchild = pnode->IterateChildren(pchild);
		taskclass.headline = pchild->ToElement()->GetText();//读取任务标题

		pchild = pnode->IterateChildren(pchild);
		taskclass.content = pchild->ToElement()->GetText();//读取任务内容

		pchild = pnode->IterateChildren(pchild);
		taskclass.totalcomptimes = atoi(pchild->ToElement()->GetText());//读取任务的总完成度

		pchild = pnode->IterateChildren(pchild);
		taskclass.bonusitemnumOne = atoi(pchild->ToElement()->GetText());//读取奖励物品编号 1

		pchild = pnode->IterateChildren(pchild);
		taskclass.numberOne = atoi(pchild->ToElement()->GetText());//读取奖励物品1的数量

		pchild = pnode->IterateChildren(pchild);
		taskclass.bonusitemnumTwo = atoi(pchild->ToElement()->GetText());//读取奖励物品编号 2

		pchild = pnode->IterateChildren(pchild);
		taskclass.numberTwo = atoi(pchild->ToElement()->GetText());//读取奖励物品2的数量

		pchild = pnode->IterateChildren(pchild);
		taskclass.bonusitemnumThree = atoi(pchild->ToElement()->GetText());//读取奖励物品编号 3

		pchild = pnode->IterateChildren(pchild);
		taskclass.numberThree = atoi(pchild->ToElement()->GetText());//读取奖励物品3的数量

		TaskInfos[taskclass.taskId] = &taskclass;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToTree()
{
	const char* pTreeXmlFileName = "Tree.xml"; //神仙树Xml文件名
	TreeInfo fairytree; //神仙树的结构体对象
	TiXmlDocument* ptixml = new TiXmlDocument(); //构建文档对象
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pTreeXmlFileName);//加载Xml文件
	TiXmlElement* proot = ptixml->RootElement();//指向根节点
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		fairytree.gread = atoi(pchild->ToElement()->GetText());//读取等级

		pchild = pnode->IterateChildren(pchild);
		fairytree.cowaternum = atoi(pchild->ToElement()->GetText());//读取消耗水的数量

		pchild = pnode->IterateChildren(pchild);
		fairytree.cosunnum = atoi(pchild->ToElement()->GetText());//读取消耗阳光的数量

		pchild = pnode->IterateChildren(pchild);
		fairytree.cogoldnum = atoi(pchild->ToElement()->GetText());//读取消耗金币的数量

		pchild = pnode->IterateChildren(pchild);
		fairytree.codiamondnum = atoi(pchild->ToElement()->GetText());//读取钻石消耗数量

		pchild = pnode->IterateChildren(pchild);
		fairytree.elfinprodco = atoi(pchild->ToElement()->GetText());//读取消耗小精灵体力的数量

		pchild = pnode->IterateChildren(pchild);
		fairytree.productivity = atoi(pchild->ToElement()->GetText());//读取生产的数量

		pchild = pnode->IterateChildren(pchild);
		fairytree.treehigh = atof(pchild->ToElement()->GetText());//读取树高

		TreeInfos[fairytree.gread] = &fairytree;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToTreeEnchantment()
{
	const char* pTreeEnchantmentXmlFileName = "TreeEnchantment.xml"; //树结界的xml文件
	TreeEnchantmentInfo treeench; //树结界结构体对象
								  //构建文档对象指针
	TiXmlDocument* tixml = new TiXmlDocument();
	if (NULL == tixml)
	{
		return false;
	}
	tixml->LoadFile(pTreeEnchantmentXmlFileName);//加载文件
	TiXmlElement* proot = tixml->RootElement();//根据文档对象指针找到根节点

											   //从第一个名为(Table)的节点 循环 将数据放入树结界里
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		treeench.gread = atoi(pchild->ToElement()->GetText());//设置树结界的等级		

		pchild = pnode->IterateChildren(pchild);
		treeench.enchantdefense = atoi(pchild->ToElement()->GetText());//设置树结界防御

		TreeEnchantInfos[treeench.gread] = &treeench;
	}
	return true;
}


template<typename T>
void ReleaseMapFun(std::map<uint32, T*> it)
{
	for (std::map<uint32, T*>::iterator iter = it.begin(); iter != it.end(); iter++)
	{
		it.erase(iter);
	}
}

XmlConfigManager * XmlConfigManager::Instance = new XmlConfigManager();
XmlConfigManager * XmlConfigManager::GetInstance()
{
	return Instance;
}

XmlConfigManager::~XmlConfigManager()
{
	ReleaseMapFun(ItemInfos);
	ReleaseMapFun(ElfinInfos);
	ReleaseMapFun(SkillInfos);
	ReleaseMapFun(SunInfos);
	ReleaseMapFun(TaskInfos);
	ReleaseMapFun(TreeInfos);
	ReleaseMapFun(TreeEnchantInfos);
}

