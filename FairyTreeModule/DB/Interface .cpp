#include "mysql_encap.h"
#include <functional>
#include <thread>

using namespace std;

#define MAX_SESSION_NUM 9999999999
#define MAX_NAME_SIZE	16

int DB_Register_Account(const std::string & strAccountName, const std::string & strPassword);
int DB_Login_Account(const std::string & strAccountName, const std::string & strPassword);

//客户端
struct Session
{
	char m_szName[MAX_NAME_SIZE];
	int m_iID;
	Session()
	{
		static int s_iCurSession = 0;
		if (s_iCurSession > MAX_SESSION_NUM)
		{
			s_iCurSession = 1;
		}
		else
		{
			s_iCurSession++;
		}
		m_iID = s_iCurSession;
	}
};

//等待处理数据库
class DBWait
{
public:
	function<void(int, int)> m_pCompleteDBLogic;
	virtual void DoDB()
	{}
	virtual void Run()
	{}
};

class DBWaitRegister :public DBWait
{
public:
	int iSessionID;				//加入的客户端ID
	string m_strAccount;		//账号
	string m_strPassword;		//密码
	int iIp;
	int m_iRet;					//完成数据库读取
	void DoDB()					//数据库线程调用
	{
		m_iRet = DB_Register_Account(m_strAccount, m_strPassword);
	}
	void Run()					//主线程调用
	{
		m_pCompleteDBLogic(iSessionID, m_iRet);
	}
};

class DBWaitLogin :public DBWait
{
public:
	int iSessionID;				//加入的客户端ID
	string m_strAccount;		//账号
	string m_strPassword;		//密码
	int iIp;
	int m_iRet;					//完成数据库读取
	void DoDB()					//数据库线程调用
	{
		m_iRet = DB_Login_Account(m_strAccount, m_strPassword);
	}
	void Run()					//主线程调用
	{
		m_pCompleteDBLogic(iSessionID, m_iRet);
	}
};

//bool f(int a, int b);
//auto newf = bind(f, _2, _1);