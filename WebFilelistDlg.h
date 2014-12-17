#pragma once
#include "explorer1.h"


// CWebFilelistDlg �Ի���

class CWebFilelistDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWebFilelistDlg)

public:
	CWebFilelistDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWebFilelistDlg();

// �Ի�������
	enum { IDD = IDD_WEBDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 m_webctrl;
	CString nowdir;
	int filecount;
	CString filelistname[200];
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void  Convert(const char* strIn, char* strOut, int sourceCodepage, int targetCodepage) ; 
	void CopyToUdisk(CString path, CString filename);
	int   UTF82GBK(char *szUtf8,char *szGbk,int Len) ;
	int IntFromStr(CString str);
};
