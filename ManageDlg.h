#pragma once
#include "afxcmn.h"


// CManageDlg 对话框

class CManageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManageDlg)

public:
	CManageDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CManageDlg();

// 对话框数据
	enum { IDD = IDD_MANAGE_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL  OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListCtrl m_contentlistctrl;
};
