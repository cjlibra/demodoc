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
};
