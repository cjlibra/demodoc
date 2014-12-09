#pragma once



// CStartServer

class CStartServer : public CWinThread
{
	DECLARE_DYNCREATE(CStartServer)

public:
	          // 动态创建所使用的受保护的构造函数
	virtual ~CStartServer();
	CStartServer(); 

public:
	
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual int Run();
	unsigned int StartServer(LPVOID lParam);
};


