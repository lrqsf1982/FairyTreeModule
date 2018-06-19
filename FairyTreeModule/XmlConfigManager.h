#pragma once

#include "define.h"
#include <map>
#include "./TinyXML/tinyxml.h"



//��Ʒ
struct ItemInfo
{
	uint32 articleID; //��ƷID
	std::string articlename; //��Ʒ��
	std::string articledescribe; //��Ʒ����
	uint32 goldprice; //��Ҽ۸�
	uint32 diamondprice; //��ʯ�۸�
	double discountrate; //�ۿ���
	uint32 consStr; //��������
	uint32 timeCon; //��ʱ
	uint32 height;  //�߶�
	std::string mtype; //����
	std::string photoname; //��Ӧ��ͼƬ��
};

//С����
struct ElfinInfo
{
	uint32 grade; //�ȼ�
	uint32 physicalilmit; //��������
	uint32 cowaternumber; //����ˮ������
	uint32 cosunnum; //������������
	uint32 cogoldnum; //�����������
	uint32 codiamondnum; //��ʯ��������
	uint32 cultEffic;//����Ч��
	uint32 uwatering;//��ˮ
	uint32 abiPlun;//�Ӷ�����
};

//����
struct SkillInfo
{
	uint32 Level; //�ȼ�
	uint32 plunder; //�Ӷ�Ч��
	uint32 watering; //��ˮЧ��
	uint32 storage; //������
	uint32 cultivation; //����Ч��
	uint32 elude; //�������
	uint32 plunderAddition; //���ټӳ�
	uint32 cogoldnum; //���Ľ������
	uint32 codiamondnum; //������ʯ����
};

//����
struct SunshineInfo
{
	uint32 grade; //�ȼ�
	uint32 cowaternumber; //����ˮ������
	uint32 cosunnum; //������������
	uint32 cogoldnum; //�����������
	uint32 codiamondnum; //��ʯ��������
	uint32 producompet; //��������
	uint32 produtime; //����ʱ��
};

//����
struct TaskInfo
{
	uint32 taskId; //���
	std::string headline; //����
	std::string content; //����
	uint32 totalcomptimes; //����ɴ���
	uint32 bonusitemnumOne; //������Ʒ���1
	uint32 numberOne; //����1
	uint32 bonusitemnumTwo; //������Ʒ���2
	uint32 numberTwo; //����2
	uint32 bonusitemnumThree; //������Ʒ���3
	uint32 numberThree; //����3
};

//������
struct TreeInfo
{
	uint32 gread; //�ȼ�
	uint32 cowaternum; //����ˮ������
	uint32 cosunnum; //������������
	uint32 cogoldnum; //�����������
	uint32 codiamondnum; //��ʯ��������
	uint32 elfinprodco; //С������������
	uint32 productivity; //������
	double treehigh; //���ĸ߶�
	uint32 breakthReq; //ͻ������
	std::string photoname; //ͼƬ��
};

//�����
struct TreeEnchantmentInfo
{
	uint32 gread; //�ȼ�
	uint32 enchantdefense; //������
	std::string fairyDoor; //������
};


class XmlConfigManager
{
public:
	std::map<uint32, ItemInfo*> ItemInfos;
	std::map<uint32, ElfinInfo*> ElfinInfos;
	std::map<uint32, SkillInfo*> SkillInfos;
	std::map<uint32, SunshineInfo*> SunInfos;
	std::map<uint32, TaskInfo*> TaskInfos;
	std::map<uint32, TreeInfo*> TreeInfos;
	std::map<uint32, TreeEnchantmentInfo*> TreeEnchantInfos;
	static XmlConfigManager* GetInstance();
	~XmlConfigManager();

private:
	XmlConfigManager();
	bool ParseXmlToItem();//��ȡ��ƷXml�ļ�����
	bool ParseXmlToElfin();//��ȡС����Xml�ļ�����
	bool ParseXmlToSkill();//��ȡ����Xml�ļ�����
	bool ParseXmlToSunshine();//��ȡ����Xml�ļ�����
	bool ParseXmlToTask();//��ȡ����Xml�ļ�����
	bool ParseXmlToTree();//��ȡ������Xml�ļ�����
	bool ParseXmlToTreeEnchantment();//��ȡ�����Xml�ļ�����
	static XmlConfigManager* Instance;
};


