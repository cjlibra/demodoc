#pragma once



// CStartServer

class CStartServer : public CWinThread
{
	DECLARE_DYNCREATE(CStartServer)

public:
	          // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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


