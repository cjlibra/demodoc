// StartServer.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "StartServer.h"

#include <afxsock.h>


// CStartServer

IMPLEMENT_DYNCREATE(CStartServer, CWinThread)

CStartServer::CStartServer()
{
}

CStartServer::~CStartServer()
{
}

BOOL CStartServer::InitInstance()
{
	// TODO: 在此执行任意逐线程初始化
	LPVOID p=NULL;
	StartServer(p);
	return TRUE;
}

int CStartServer::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CStartServer, CWinThread)
END_MESSAGE_MAP()


// CStartServer 消息处理程序


int CStartServer::Run()
{
	// TODO: 在此添加专用代码和/或调用基类
	
	return CWinThread::Run();
}



unsigned int CStartServer::StartServer(LPVOID lParam)
{
        //初始化Winscok
    if (!AfxSocketInit())
    {
        AfxMessageBox("IDP_SOCKETS_INIT_FAILED");
        return 1;
    }

    bool m_exit = false;

    

    CString strPort="8764";
    
     
    
    UINT nPort = atoi(strPort);
    
    //socket------------------------------------------------
    
    CSocket aSocket, serverSocket;
    //最好不要使用aSocket.Create创建，因为容易会出现10048错误
    if (!aSocket.Socket())
    {
        char szError[256] = {0};
        
        sprintf(szError, "Create Faild: %d", GetLastError());
        
        AfxMessageBox(szError);
        
        return 1; 
    }

    BOOL bOptVal = TRUE;
    int bOptLen = sizeof(BOOL);

     //设置Socket的选项, 解决10048错误必须的步骤
    aSocket.SetSockOpt(SO_REUSEADDR, (void *)&bOptVal, bOptLen, SOL_SOCKET);

	 if (!aSocket.Bind(nPort))
    {
        char szError[256] = {0};
            
        sprintf(szError, "Bind Faild: %d", GetLastError());
            
        AfxMessageBox(szError);
            
        return 1; 
    }
        //监听
    if(!aSocket.Listen(10))
    {    
        char szError[256] = {0};
        
        sprintf(szError, "Listen Faild: %d", GetLastError());
        
        AfxMessageBox(szError);
        
        return 1;
    }
    
    CString strText;    
         
    strText += "Server Start!  ";    

    while(!m_exit)
    {
        //接收外部连接
        if(!aSocket.Accept(serverSocket))
        {
            continue;
        }
        else
        {
            char szRecvMsg[256] = {0};
            char szOutMsg[256] = {0};    
            
                //接收客户端内容:阻塞
            serverSocket.Receive(szRecvMsg, 256);

            sprintf(szOutMsg, "Receive Msg: %s  ", szRecvMsg);
			TRACE("this is %s",szOutMsg);
            
                     
            strText += szOutMsg;
     
                //发送内容给客户端
           // serverSocket.Send("Have Receive The Msg", 50);

                //关闭
            serverSocket.Close();
        }
        
    }
    
        //关闭
    aSocket.Close();
    serverSocket.Close();
    return 0;
}