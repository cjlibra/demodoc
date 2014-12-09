// StartServer.cpp : ʵ���ļ�
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
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	LPVOID p=NULL;
	StartServer(p);
	return TRUE;
}

int CStartServer::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CStartServer, CWinThread)
END_MESSAGE_MAP()


// CStartServer ��Ϣ�������


int CStartServer::Run()
{
	// TODO: �ڴ����ר�ô����/����û���
	
	return CWinThread::Run();
}



unsigned int CStartServer::StartServer(LPVOID lParam)
{
        //��ʼ��Winscok
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
    //��ò�Ҫʹ��aSocket.Create��������Ϊ���׻����10048����
    if (!aSocket.Socket())
    {
        char szError[256] = {0};
        
        sprintf(szError, "Create Faild: %d", GetLastError());
        
        AfxMessageBox(szError);
        
        return 1; 
    }

    BOOL bOptVal = TRUE;
    int bOptLen = sizeof(BOOL);

     //����Socket��ѡ��, ���10048�������Ĳ���
    aSocket.SetSockOpt(SO_REUSEADDR, (void *)&bOptVal, bOptLen, SOL_SOCKET);

	 if (!aSocket.Bind(nPort))
    {
        char szError[256] = {0};
            
        sprintf(szError, "Bind Faild: %d", GetLastError());
            
        AfxMessageBox(szError);
            
        return 1; 
    }
        //����
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
        //�����ⲿ����
        if(!aSocket.Accept(serverSocket))
        {
            continue;
        }
        else
        {
            char szRecvMsg[256] = {0};
            char szOutMsg[256] = {0};    
            
                //���տͻ�������:����
            serverSocket.Receive(szRecvMsg, 256);

            sprintf(szOutMsg, "Receive Msg: %s  ", szRecvMsg);
			TRACE("this is %s",szOutMsg);
            
                     
            strText += szOutMsg;
     
                //�������ݸ��ͻ���
           // serverSocket.Send("Have Receive The Msg", 50);

                //�ر�
            serverSocket.Close();
        }
        
    }
    
        //�ر�
    aSocket.Close();
    serverSocket.Close();
    return 0;
}