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
		iteminfo.photoname = atoi(pchild->ToElement()->GetText()); //物品图片名

		ItemInfos[iteminfo.articleID] = &iteminfo;
		StoreItemsInStores(iteminfo.articleID);
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
		InitElfinData(elifninfo.grade);
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
		InitSkillData(skillinfo.Level);
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
		InitSunData(sunshine.grade);
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
		InitTaskData(taskclass.taskId);
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

		pchild = pnode->IterateChildren(pchild);
		fairytree.breakthReq = atoi(pchild->ToElement()->GetText());//读取树高

		TreeInfos[fairytree.gread] = &fairytree;
		InitTreeData(fairytree.gread);
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
		InitTreeEnchantData(treeench.gread);
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
	delete xmlshop;
	xmlshop = nullptr;
	delete xmlelfin;
	xmlelfin = nullptr;
	delete xmlskill;
	xmlskill = nullptr;
	delete xmlsunshine;
	xmlsunshine = nullptr;
	delete xmlfairytree;
	xmlfairytree = nullptr;
	delete xmltreeenchantment;
	xmltreeenchantment = nullptr;

	delete Instance;
	Instance = nullptr;
}

//存储物品到商店类
void XmlConfigManager::StoreItemsInStores(uint32 uid)
{
	xmlshop = new Shop;
	xmlshop->pwareArt->Set_CArticleSerialNumber(uid);
	xmlshop->pwareArt->Set_CArticleGoldPrice(ItemInfos[uid]->goldprice);
	xmlshop->pwareArt->Set_CArticleJewelPrice(ItemInfos[uid]->diamondprice);
	xmlshop->pwareArt->Set_CArticleDiscount(ItemInfos[uid]->discountrate);
	xmlshop->pwareArt->Set_WareName(ItemInfos[uid]->articlename);
	xmlshop->pwareArt->Set_CArticleDescribe(ItemInfos[uid]->articledescribe);
	xmlshop->storeItemInfo[uid] = xmlshop->pwareArt;

}

//初始化小精灵数据到小精灵类
void XmlConfigManager::InitElfinData(uint32 uid)
{
	xmlelfin = new Elfin;
	xmlelfin->Set_EGrade(ElfinInfos[uid]->grade);
	xmlelfin->Set_EMaxPhysicalPower(ElfinInfos[uid]->physicalilmit);
	xmlelfin->Set_uCoWaterNum(ElfinInfos[uid]->cowaternumber);
	xmlelfin->Set_uCoSunNum(ElfinInfos[uid]->cosunnum);
	xmlelfin->Set_uCoGoldNum(ElfinInfos[uid]->cogoldnum);
	xmlelfin->Set_uCoJewelNum(ElfinInfos[uid]->codiamondnum);
	xmlelfin->map_elfin[uid] = xmlelfin;
}

//初始化技能数据到技能类
void XmlConfigManager::InitSkillData(uint32 id)
{
	xmlskill = new CSkill;
	xmlskill->Set_Skill_Level(SkillInfos[id]->Level);
	xmlskill->Set_uPillageEffect(SkillInfos[id]->plunder);
	xmlskill->Set_uWateringEffect(SkillInfos[id]->watering);
	xmlskill->Set_uReserveGold(SkillInfos[id]->storage);
	xmlskill->Set_uPlantEffect(SkillInfos[id]->cultivation);
	xmlskill->Set_uDodgeAbility(SkillInfos[id]->elude);
	xmlskill->Set_uRobAddition(SkillInfos[id]->plunderAddition);
	xmlskill->map_skill[id] = xmlskill;
}

//初始化太阳数据到太阳类
void XmlConfigManager::InitSunData(uint32 id)
{
	xmlsunshine = new CSunshine;
	xmlsunshine->Set_FGrade(SunInfos[id]->grade);
	xmlsunshine->Set_SunCoWaterNum(SunInfos[id]->cowaternumber);
	xmlsunshine->Set_SunCoSunNum(SunInfos[id]->cosunnum);
	xmlsunshine->Set_SunCoGoldNum(SunInfos[id]->cogoldnum);
	xmlsunshine->Set_SunCoJewelNum(SunInfos[id]->codiamondnum);
	xmlsunshine->Set_FSunProCap(SunInfos[id]->producompet);
	xmlsunshine->Set_FSunProTime(SunInfos[id]->produtime);
	xmlsunshine->map_sunshine[id] = xmlsunshine;
}

//初始化任务数据到任务类
void XmlConfigManager::InitTaskData(uint32 id)
{
	xmltasklistclass.taskc->Set_TSerialNumber(TaskInfos[id]->taskId);
	xmltasklistclass.taskc->Set_TTaskheadline(TaskInfos[id]->headline);
	xmltasklistclass.taskc->Set_TTaskContent(TaskInfos[id]->content);
	xmltasklistclass.taskc->Set_TaskSumUpComp(TaskInfos[id]->totalcomptimes);
	xmltasklistclass.taskc->Set_TTaskAward(TaskInfos[id]->bonusitemnumOne, TaskInfos[id]->numberOne);
	xmltasklistclass.taskc->Set_TTaskAward(TaskInfos[id]->bonusitemnumTwo, TaskInfos[id]->numberTwo);
	xmltasklistclass.taskc->Set_TTaskAward(TaskInfos[id]->bonusitemnumThree, TaskInfos[id]->numberThree);
	xmltasklistclass.map_task[id] = xmltasklistclass.taskc;
}

//初始化神仙树数据到神仙树类
void XmlConfigManager::InitTreeData(uint32 id)
{
	xmlfairytree = new FairyTree;
	xmlfairytree->Set_FGrade(TreeInfos[id]->gread);
	xmlfairytree->Set_FCoWaterNum(TreeInfos[id]->cowaternum);
	xmlfairytree->Set_FCoSunNum(TreeInfos[id]->cosunnum);
	xmlfairytree->Set_FCoGoldNum(TreeInfos[id]->cogoldnum);
	xmlfairytree->Set_FCoJewelNum(TreeInfos[id]->codiamondnum);
	xmlfairytree->Set_FCoeflinNum(TreeInfos[id]->elfinprodco);
	xmlfairytree->Set_FGold(TreeInfos[id]->productivity);
	xmlfairytree->Set_TreeHeight(TreeInfos[id]->treehigh);
	xmlfairytree->Set_FCoBreakthNum(TreeInfos[id]->breakthReq);
	xmlfairytree->map_fairytree[id] = xmlfairytree;
}

//初始化树结界数据到树结界类
void XmlConfigManager::InitTreeEnchantData(uint32 id)
{
	xmltreeenchantment = new TreeEnchantment;
	xmltreeenchantment->Set_TEGrade(TreeEnchantInfos[id]->gread);
	xmltreeenchantment->Set_TEDefense(TreeEnchantInfos[id]->enchantdefense);
	xmltreeenchantment->map_treeEn[id] = xmltreeenchantment;
}

