#include "XmlConfigManager.h"



XmlConfigManager::XmlConfigManager()
{
	ParseXmlToArticle();//物品
	ParseXmlToElfin();//小精灵
	ParseXmlToSkill();//技能
	ParseXmlToSunshine();//阳光
	ParseXmlToTask();//任务
	ParseXmlToTree();//神仙树
	ParseXmlToTreeEnchantment();//树结界
}

bool XmlConfigManager::ParseXmlToArticle()
{
	return false;
}

bool XmlConfigManager::ParseXmlToElfin()
{
	const char* pxmlFileName = "Elfin.xml"; //小精灵xml文件名
	ElfinInfo elifninfo; //
	return false;
}

bool XmlConfigManager::ParseXmlToSkill()
{
	const char* pxmlFileName = "Skill.xml"; //技能xml文件名
	SkillInfo skillinfo; //结构体对象
	TiXmlDocument* ptixml = new TiXmlDocument();//构建文档对象指针
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pxmlFileName);//加载文件
	TiXmlElement* proot = ptixml->RootElement(); //指向根节点
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		const char* pgread = pchild->ToElement()->GetText(); //读取等级
		uint32 ugreadLen = strlen(pgread);
		if (NULL != pgread)
		{
			//设置等级
			uint32 setgread;
			memcpy_safe((char*)&pgread, ugreadLen, (char*)&setgread, ugreadLen);
			skillinfo.Level = setgread;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pplun = pchild->ToElement()->GetText(); //读取掠夺效果
		uint32 uplunLen = strlen(pplun);
		if (NULL != pplun)
		{
			//设置掠夺效果
			uint32 setplun;
			memcpy_safe((char*)&pplun, uplunLen, (char*)&setplun, uplunLen);
			skillinfo.plunder = setplun;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pwater = pchild->ToElement()->GetText(); //读取浇水效果
		uint32 uwaterLen = strlen(pwater);
		if (NULL != pwater)
		{
			//设置浇水效果
			uint32 setwater;
			memcpy_safe((char*)&pwater, uwaterLen, (char*)&setwater, uwaterLen);
			skillinfo.watering = setwater;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pstorage = pchild->ToElement()->GetText(); //读取储存金币
		uint32 ustorLen = strlen(pstorage);
		if (NULL != pstorage)
		{
			//设置储存金币
			uint32 setstor;
			memcpy_safe((char*)&pstorage, ustorLen, (char*)&setstor, ustorLen);
			skillinfo.storage = setstor;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pculti = pchild->ToElement()->GetText(); //读取栽培效果
		uint32 ucultiLen = strlen(pculti);
		if (NULL != pculti)
		{
			//设置栽培效果
			uint32 setculti;
			memcpy_safe((char*)&pculti, ucultiLen, (char*)&setculti, ucultiLen);
			skillinfo.cultivation = setculti;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pelude = pchild->ToElement()->GetText(); //读取躲避能力
		uint32 ueludeiLen = strlen(pelude);
		if (NULL != pelude)
		{
			//设置躲避能力
			uint32 setelude;
			memcpy_safe((char*)&pelude, ueludeiLen, (char*)&setelude, ueludeiLen);
			skillinfo.elude = setelude;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pplAdd = pchild->ToElement()->GetText(); //读取抢劫加成
		uint32 uplAddLen = strlen(pplAdd);
		if (NULL != pplAdd)
		{
			//设置抢劫加成
			uint32 setplAdd;
			memcpy_safe((char*)&pplAdd, uplAddLen, (char*)&setplAdd, uplAddLen);
			skillinfo.plunderAddition = setplAdd;
		}

	}
	return true;
}

bool XmlConfigManager::ParseXmlToSunshine()
{
	const char* pxmlFileName = "Sunshine.xml"; //阳光xml文件名
	SunshineInfo sunshine; //结构体对象
	TiXmlDocument* ptixml = new TiXmlDocument();//构建文档对象指针
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pxmlFileName);//加载文件
	TiXmlElement* proot = ptixml->RootElement(); //指向根节点

	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		const char* pgrad = pchild->ToElement()->GetText(); //读取等级
		uint32 uglen = strlen(pgrad);
		if (NULL != pgrad)
		{
			//设置等级
			uint32 ugrad = 0;
			memcpy_safe((char*)&pgrad, uglen, (char*)&ugrad, uglen);
			sunshine.grade = ugrad;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pcowat = pchild->ToElement()->GetText(); //读取消耗水的数量
		uint32 ucolen = strlen(pcowat);
		if (NULL != pcowat)
		{
			//设置消耗水的数量
			uint32 unum = 0;
			memcpy_safe((char*)&pcowat, ucolen, (char*)&unum, ucolen);
			sunshine.cowaternumber = unum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pcosun = pchild->ToElement()->GetText(); //读取阳光数量消耗
		uint32 uslen = strlen(pcosun);
		if (NULL != pcosun)
		{
			//设置阳光数量消耗
			uint32 usunNum = 0;
			memcpy_safe((char*)&pcosun, uslen, (char*)&usunNum, uslen);
			sunshine.cosunnum = usunNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pgold = pchild->ToElement()->GetText(); //读取金币数量消耗
		uint32 ugolen = strlen(pgold);
		if (NULL != pgold)
		{
			//设置金币数量消耗
			uint32 ugoldnum = 0;
			memcpy_safe((char*)&pgold, ugolen, (char*)&ugoldnum, ugolen);
			sunshine.cogoldnum = ugoldnum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pprocap = pchild->ToElement()->GetText(); //读取产出能力
		uint32 uprolen = strlen(pprocap);
		if (NULL != pprocap)
		{
			//设置产出能力
			uint32 uproCap = 0;
			memcpy_safe((char*)&pprocap, uprolen, (char*)&uproCap, uprolen);
			sunshine.producompet = uproCap;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pprotime = pchild->ToElement()->GetText(); //读取生产时间
		uint32 uptlen = strlen(pprotime);
		if (NULL != pprotime)
		{
			//设置生产时间
			uint32 uprot = 0;
			memcpy_safe((char*)&pprotime, uptlen, (char*)&uprot, uptlen);
			sunshine.produtime = uprot;
		}
	}

	return true;
}

bool XmlConfigManager::ParseXmlToTask()
{
	const char* ptaskXmlF = "Task.xml"; //任务xml文件名
	TaskInfo taskclass; //任务结构体对象
	TiXmlDocument* ptixml = new TiXmlDocument(); //构建文档对象指针
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(ptaskXmlF); //加载文件
	TiXmlElement* proot = ptixml->RootElement(); //指向根节点

	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		const char* pid = pchild->ToElement()->GetText(); //读取任务编号
		uint32 uidlen = strlen(pid);
		if (NULL != pid)
		{
			//设置任务编号
			uint32 uid = 0;
			memcpy_safe((char*)&pid, uidlen, (char*)&uid, uidlen);
			taskclass.taskId = uid;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pheadline = pchild->ToElement()->GetText(); //读取任务标题
		uint32 uheadlen = strlen(pheadline);
		if (NULL != pheadline)
		{
			//设置任务标题
			std::string shead = "";
			memcpy_safe((char*)&pheadline, uheadlen, (char*)&shead, uheadlen);
			taskclass.headline = shead;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pcontent = pchild->ToElement()->GetText(); //读取任务内容
		uint32 ucontlen = strlen(pcontent);
		if (NULL != pcontent)
		{
			//设置任务内容
			std::string scont = "";
			memcpy_safe((char*)&pcontent, ucontlen, (char*)&scont, ucontlen);
			taskclass.content = scont;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pSunUC = pchild->ToElement()->GetText(); //读取任务的总完成度
		uint32 usunuclen = strlen(pSunUC);
		if (NULL != pSunUC)
		{
			//设置任务的总完成度
			uint32 uSunUC = 0;
			memcpy_safe((char*)&pSunUC, usunuclen, (char*)&uSunUC, usunuclen);
			taskclass.totalcomptimes = uSunUC;
		}

		//奖励物品编号1 和 数量1
		pchild = pnode->IterateChildren(pchild);
		const char* pbonIteNuOne = pchild->ToElement()->GetText(); //读取奖励物品编号 1
		uint32 ublen = strlen(pbonIteNuOne); //编号1的长度
		pchild = pnode->IterateChildren(pchild);
		const char* pnumb1 = pchild->ToElement()->GetText(); //读取奖励物品1的数量
		uint32 ublen1 = strlen(pnumb1);//数量1的长度
		if (NULL != pbonIteNuOne && NULL != pnumb1)
		{
			//设置奖励物品编号1 和 数量1
			uint32 ubINID = 0;
			uint32 ubiNNum = 0;
			memcpy_safe((char*)&pbonIteNuOne, ublen, (char*)&ubINID, ublen);
			memcpy_safe((char*)&pnumb1, ublen1, (char*)&ubiNNum, ublen1);
			taskclass.bonusitemnumOne = ubINID;
			taskclass.numberOne = ubiNNum;
		}

		//奖励物品编号2 和 数量2
		pchild = pnode->IterateChildren(pchild);
		const char* pbonIteNuTwo = pchild->ToElement()->GetText(); //读取奖励物品编号 2
		uint32 ublen2 = strlen(pbonIteNuTwo); //编号2的长度
		pchild = pnode->IterateChildren(pchild);
		const char* pnumbtwo = pchild->ToElement()->GetText(); //读取奖励物品2的数量
		uint32 ublentwo = strlen(pnumbtwo);//数量2的长度
		if (NULL != pbonIteNuTwo && NULL != pnumbtwo)
		{
			//设置奖励物品编号2 和 数量2
			uint32 ubINID2 = 0;
			uint32 ubiNNum2 = 0;
			memcpy_safe((char*)&pbonIteNuTwo, ublen2, (char*)&ubINID2, ublen2);
			memcpy_safe((char*)&pnumbtwo, ublentwo, (char*)&ubiNNum2, ublentwo);
			taskclass.bonusitemnumTwo = ubINID2;
			taskclass.numberTwo = ubiNNum2;
		}

		//奖励物品编号3 和 数量3
		pchild = pnode->IterateChildren(pchild);
		const char* pbonIteNuThree = pchild->ToElement()->GetText(); //读取奖励物品编号 3
		uint32 ublen3 = strlen(pbonIteNuThree); //编号3的长度
		pchild = pnode->IterateChildren(pchild);
		const char* pnumbthree = pchild->ToElement()->GetText(); //读取奖励物品3的数量
		uint32 ublenthree = strlen(pnumbthree);//数量3的长度
		if (NULL != pbonIteNuThree && NULL != pnumbthree)
		{
			//设置奖励物品编号2 和 数量2
			uint32 ubINID3 = 0;
			uint32 ubiNNum3 = 0;
			memcpy_safe((char*)&pbonIteNuThree, ublen3, (char*)&ubINID3, ublen3);
			memcpy_safe((char*)&pnumbthree, ublenthree, (char*)&ubiNNum3, ublenthree);
			taskclass.bonusitemnumThree = ubINID3;
			taskclass.numberThree = ubiNNum3;
		}
	}

	return true;
}

bool XmlConfigManager::ParseXmlToTree()
{
	const char* pftxf = "Tree.xml";
	TreeInfo fairytree; //神仙树的结构体对象
	TiXmlDocument* ptixml = new TiXmlDocument(); //构建文档对象
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pftxf);//加载Xml文件
	TiXmlElement* proot = ptixml->RootElement();//指向根节点
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		const char* pgrad = pchild->ToElement()->GetText(); //读取等级
		uint32 uglen = strlen(pgrad);
		if (NULL != pgrad)
		{
			//设置神仙树的等级
			uint32 ugrad = 0;
			memcpy_safe((char*)&pgrad, uglen, (char*)&ugrad, uglen);
			fairytree.gread = ugrad;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pwater = pchild->ToElement()->GetText(); //读取消耗水的数量
		uint32 uwlen = strlen(pwater);
		if (NULL != pwater)
		{
			//设置神仙树消耗水的数量
			uint32 uwNum = 0;
			memcpy_safe((char*)&pwater, uwlen, (char*)&uwNum, uwlen);
			fairytree.cowaternum = uwNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* psunshine = pchild->ToElement()->GetText(); //读取消耗阳光的数量
		uint32 uslen = strlen(psunshine);
		if (NULL != psunshine)
		{
			//设置神仙树消耗阳光的数量
			uint32 uwNum = 0;
			memcpy_safe((char*)&psunshine, uslen, (char*)&uwNum, uslen);
			fairytree.cosunnum = uwNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pgold = pchild->ToElement()->GetText(); //读取消耗金币的数量
		uint32 ugoldlen = strlen(pgold);
		if (NULL != pgold)
		{
			//设置神仙树的消耗金币的数量
			uint32 ugoldNum = 0;
			memcpy_safe((char*)&pgold, ugoldlen, (char*)&ugoldNum, ugoldlen);
			fairytree.cogoldnum = ugoldNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pelfin = pchild->ToElement()->GetText(); //读取消耗小精灵体力的数量
		uint32 uelen = strlen(pelfin);
		if (NULL != pelfin)
		{
			//设置神仙树的消耗小精灵体力的数量
			uint32 ueNum = 0;
			memcpy_safe((char*)&pelfin, uelen, (char*)&ueNum, uelen);
			fairytree.elfinprodco = ueNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pprod = pchild->ToElement()->GetText(); //读取生产的数量
		uint32 uplen = strlen(pprod);
		if (NULL != pprod)
		{
			//设置神仙树的生产的数量
			uint32 upNum = 0;
			memcpy_safe((char*)&pprod, uplen, (char*)&upNum, uplen);
			fairytree.productivity = upNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pheitree = pchild->ToElement()->GetText(); //读取树高
		uint32 uheilen = strlen(pheitree);
		if (NULL != pheitree)
		{
			//设置神仙树的树高
			uint32 uheiNum = 0;
			memcpy_safe((char*)&pheitree, uheilen, (char*)&uheiNum, uheilen);
			fairytree.treehigh = uheiNum;
		}
	}
	return true;
}

bool XmlConfigManager::ParseXmlToTreeEnchantment()
{
	const char* XmlName = "TreeEnchantment.xml"; //树结界的xml文件
	TreeEnchantmentInfo treeench; //树结界结构体对象
							  //构建文档对象指针
	TiXmlDocument* tixml = new TiXmlDocument();
	if (NULL == tixml)
	{
		return false;
	}
	//加载文件
	tixml->LoadFile(XmlName);

	//根据文档对象指针找到根节点
	TiXmlElement* proot = tixml->RootElement();

	//从第一个名为(Table)的节点 循环 将数据放入树结界里
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		const char* pgrade = pchild->ToElement()->GetText();
		uint32 uglen = strlen(pgrade);
		if (NULL != pgrade)
		{
			//设置树结界的等级
			uint32 ugrad = 0;
			memcpy_safe((char*)&pgrade, uglen, (char*)&ugrad, uglen);
			treeench.gread = ugrad;
		}
		pchild = pnode->IterateChildren(pchild);
		const char* pdef = pchild->ToElement()->GetText();
		uint32 udlen = strlen(pdef);
		if (NULL != pdef)
		{
			//设置树结界防御
			uint32 udefe = 0;
			memcpy_safe((char*)&pdef, udlen, (char*)&udefe, udlen);
			treeench.enchantdefense = udefe;
		}
	}
}


XmlConfigManager::~XmlConfigManager()
{
}
