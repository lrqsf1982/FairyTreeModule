#include "XmlConfigManager.h"



XmlConfigManager::XmlConfigManager()
{
	ParseXmlToItem();//��Ʒ
	ParseXmlToElfin();//С����
	ParseXmlToSkill();//����
	ParseXmlToSunshine();//����
	ParseXmlToTask();//����
	ParseXmlToTree();//������
	ParseXmlToTreeEnchantment();//�����
}


bool XmlConfigManager::ParseXmlToItem()
{
	const char* pItemXmlFileName = "Item.xml"; //��Ʒxml�ļ���
	ItemInfo iteminfo; //��Ʒ�ṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument();//�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pItemXmlFileName);//�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		iteminfo.articleID = atoi(pchild->ToElement()->GetText());//������ƷID

		pchild = pnode->IterateChildren(pchild);
		iteminfo.articlename = pchild->ToElement()->GetText();//������Ʒ����

		pchild = pnode->IterateChildren(pchild);
		iteminfo.articledescribe = pchild->ToElement()->GetText(); //��Ʒ����

		pchild = pnode->IterateChildren(pchild);
		iteminfo.goldprice = atoi(pchild->ToElement()->GetText());//��Ʒ��Ҽ۸�

		pchild = pnode->IterateChildren(pchild);
		iteminfo.diamondprice = atoi(pchild->ToElement()->GetText());//��Ʒ��ʯ�۸�

		pchild = pnode->IterateChildren(pchild);
		iteminfo.discountrate = atof(pchild->ToElement()->GetText());//��Ʒ�ۿ���	

		pchild = pnode->IterateChildren(pchild);
		iteminfo.consStr = atoi(pchild->ToElement()->GetText());//��������

		pchild = pnode->IterateChildren(pchild); 
		iteminfo.timeCon = atoi(pchild->ToElement()->GetText());//��ʱ

		pchild = pnode->IterateChildren(pchild); 
		iteminfo.height = atoi(pchild->ToElement()->GetText());//�߶�

		pchild = pnode->IterateChildren(pchild);
		iteminfo.mtype = pchild->ToElement()->GetText(); //��Ʒ����		

		pchild = pnode->IterateChildren(pchild);
		iteminfo.photoname = atoi(pchild->ToElement()->GetText()); //��ƷͼƬ��

		ItemInfos[iteminfo.articleID] = &iteminfo;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToElfin()
{
	const char* pElfinXmlFileName = "Elfin.xml"; //С����xml�ļ���
	ElfinInfo elifninfo; //С����ṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument();//�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pElfinXmlFileName);//�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		elifninfo.grade = atoi(pchild->ToElement()->GetText());//��ȡ�ȼ�

		pchild = pnode->IterateChildren(pchild);
		elifninfo.physicalilmit = atoi(pchild->ToElement()->GetText());//��ȡ��������

		pchild = pnode->IterateChildren(pchild);
		elifninfo.cowaternumber = atoi(pchild->ToElement()->GetText());//��ȡ����ˮ������

		pchild = pnode->IterateChildren(pchild);
		elifninfo.cosunnum = atoi(pchild->ToElement()->GetText());//��ȡ������������

		pchild = pnode->IterateChildren(pchild);
		elifninfo.cogoldnum = atoi(pchild->ToElement()->GetText());//��ȡ�����������

		pchild = pnode->IterateChildren(pchild);
		elifninfo.codiamondnum = atoi(pchild->ToElement()->GetText());//��ȡ��ʯ��������

		pchild = pnode->IterateChildren(pchild);
		elifninfo.cultEffic = atoi(pchild->ToElement()->GetText());//��ȡ����Ч��

		pchild = pnode->IterateChildren(pchild);
		elifninfo.uwatering = atoi(pchild->ToElement()->GetText());//��ȡ��ˮ

		pchild = pnode->IterateChildren(pchild);
		elifninfo.abiPlun = atoi(pchild->ToElement()->GetText());//��ȡ�Ӷ�����

		ElfinInfos[elifninfo.grade] = &elifninfo;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToSkill()
{
	const char* pSkillXmlFileName = "Skill.xml"; //����xml�ļ���
	SkillInfo skillinfo; //���ܽṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument();//�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pSkillXmlFileName);//�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		skillinfo.Level = atoi(pchild->ToElement()->GetText());//��ȡ�ȼ�

		pchild = pnode->IterateChildren(pchild);
		skillinfo.plunder = atoi(pchild->ToElement()->GetText());//��ȡ�Ӷ�Ч��

		pchild = pnode->IterateChildren(pchild);
		skillinfo.watering = atoi(pchild->ToElement()->GetText());//��ȡ��ˮЧ��

		pchild = pnode->IterateChildren(pchild);
		skillinfo.storage = atoi(pchild->ToElement()->GetText());//��ȡ������

		pchild = pnode->IterateChildren(pchild);
		skillinfo.cultivation = atoi(pchild->ToElement()->GetText());//��ȡ����Ч��

		pchild = pnode->IterateChildren(pchild);
		skillinfo.elude = atoi(pchild->ToElement()->GetText());//��ȡ�������

		pchild = pnode->IterateChildren(pchild);
		skillinfo.plunderAddition = atoi(pchild->ToElement()->GetText());//��ȡ���ټӳ�

		pchild = pnode->IterateChildren(pchild);
		skillinfo.cogoldnum = atoi(pchild->ToElement()->GetText()); //��ȡ���Ľ������

		pchild = pnode->IterateChildren(pchild);
		skillinfo.codiamondnum = atoi(pchild->ToElement()->GetText()); //��ȡ������ʯ����

		SkillInfos[skillinfo.Level] = &skillinfo;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToSunshine()
{
	const char* pSunXmlFileName = "Sun.xml"; //����xml�ļ���
	SunshineInfo sunshine; //�ṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument();//�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pSunXmlFileName);//�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�

	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		sunshine.grade = atoi(pchild->ToElement()->GetText());//��ȡ�ȼ�

		pchild = pnode->IterateChildren(pchild);
		sunshine.cowaternumber = atoi(pchild->ToElement()->GetText());//��ȡ����ˮ������

		pchild = pnode->IterateChildren(pchild);
		sunshine.cosunnum = atoi(pchild->ToElement()->GetText());//��ȡ������������

		pchild = pnode->IterateChildren(pchild);
		sunshine.cogoldnum = atoi(pchild->ToElement()->GetText());//��ȡ�����������

		pchild = pnode->IterateChildren(pchild);
		sunshine.codiamondnum = atoi(pchild->ToElement()->GetText());//��ȡ��ʯ��������

		pchild = pnode->IterateChildren(pchild);
		sunshine.producompet = atoi(pchild->ToElement()->GetText());//��ȡ��������

		pchild = pnode->IterateChildren(pchild);
		sunshine.produtime = atoi(pchild->ToElement()->GetText());//��ȡ����ʱ��

		SunInfos[sunshine.grade] = &sunshine;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToTask()
{
	const char* pTaskXmlFileName = "Task.xml"; //����xml�ļ���
	TaskInfo taskclass; //����ṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument(); //�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pTaskXmlFileName); //�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		taskclass.taskId = atoi(pchild->ToElement()->GetText());//��ȡ������

		pchild = pnode->IterateChildren(pchild);
		taskclass.headline = pchild->ToElement()->GetText();//��ȡ�������

		pchild = pnode->IterateChildren(pchild);
		taskclass.content = pchild->ToElement()->GetText();//��ȡ��������

		pchild = pnode->IterateChildren(pchild);
		taskclass.totalcomptimes = atoi(pchild->ToElement()->GetText());//��ȡ���������ɶ�

		pchild = pnode->IterateChildren(pchild);
		taskclass.bonusitemnumOne = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ��� 1

		pchild = pnode->IterateChildren(pchild);
		taskclass.numberOne = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ1������

		pchild = pnode->IterateChildren(pchild);
		taskclass.bonusitemnumTwo = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ��� 2

		pchild = pnode->IterateChildren(pchild);
		taskclass.numberTwo = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ2������

		pchild = pnode->IterateChildren(pchild);
		taskclass.bonusitemnumThree = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ��� 3

		pchild = pnode->IterateChildren(pchild);
		taskclass.numberThree = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ3������

		TaskInfos[taskclass.taskId] = &taskclass;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToTree()
{
	const char* pTreeXmlFileName = "Tree.xml"; //������Xml�ļ���
	TreeInfo fairytree; //�������Ľṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument(); //�����ĵ�����
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pTreeXmlFileName);//����Xml�ļ�
	TiXmlElement* proot = ptixml->RootElement();//ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		fairytree.gread = atoi(pchild->ToElement()->GetText());//��ȡ�ȼ�

		pchild = pnode->IterateChildren(pchild);
		fairytree.cowaternum = atoi(pchild->ToElement()->GetText());//��ȡ����ˮ������

		pchild = pnode->IterateChildren(pchild);
		fairytree.cosunnum = atoi(pchild->ToElement()->GetText());//��ȡ�������������

		pchild = pnode->IterateChildren(pchild);
		fairytree.cogoldnum = atoi(pchild->ToElement()->GetText());//��ȡ���Ľ�ҵ�����

		pchild = pnode->IterateChildren(pchild);
		fairytree.codiamondnum = atoi(pchild->ToElement()->GetText());//��ȡ��ʯ��������

		pchild = pnode->IterateChildren(pchild);
		fairytree.elfinprodco = atoi(pchild->ToElement()->GetText());//��ȡ����С��������������

		pchild = pnode->IterateChildren(pchild);
		fairytree.productivity = atoi(pchild->ToElement()->GetText());//��ȡ����������

		pchild = pnode->IterateChildren(pchild);
		fairytree.treehigh = atof(pchild->ToElement()->GetText());//��ȡ����

		pchild = pnode->IterateChildren(pchild);
		fairytree.breakthReq = atoi(pchild->ToElement()->GetText());//��ȡ����

		pchild = pnode->IterateChildren(pchild);
		fairytree.photoname = pchild->ToElement()->GetText(); //ͼƬ��

		TreeInfos[fairytree.gread] = &fairytree;
	}
	return true;
}

bool XmlConfigManager::ParseXmlToTreeEnchantment()
{
	const char* pTreeEnchantmentXmlFileName = "TreeEnchantment.xml"; //������xml�ļ�
	TreeEnchantmentInfo treeench; //�����ṹ�����
								  //�����ĵ�����ָ��
	TiXmlDocument* tixml = new TiXmlDocument();
	if (NULL == tixml)
	{
		return false;
	}
	tixml->LoadFile(pTreeEnchantmentXmlFileName);//�����ļ�
	TiXmlElement* proot = tixml->RootElement();//�����ĵ�����ָ���ҵ����ڵ�

											   //�ӵ�һ����Ϊ(Table)�Ľڵ� ѭ�� �����ݷ����������
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		treeench.gread = atoi(pchild->ToElement()->GetText());//���������ĵȼ�		

		pchild = pnode->IterateChildren(pchild);
		treeench.enchantdefense = atoi(pchild->ToElement()->GetText());//������������

		pchild = pnode->IterateChildren(pchild);
		treeench.fairyDoor = pchild->ToElement()->GetText(); //������

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
