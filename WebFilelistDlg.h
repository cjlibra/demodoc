#pragma once
#include "explorer1.h"


// CWebFilelistDlg 对话框

class CWebFilelistDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWebFilelistDlg)

public:
	CWebFilelistDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CWebFilelistDlg();

// 对话框数据
	enum { IDD = IDD_WEBDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 m_webctrl;
	CString nowdir;
	int filecount;
	CString filelistname[200];
	virtual BOOL OnInitDialog();
};
