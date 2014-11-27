#pragma once
#include "afxwin.h"


// CAddinfoDlg 对话框

class CAddinfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddinfoDlg)

public:
	CAddinfoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddinfoDlg();

// 对话框数据
	enum { IDD = IDD_ADDINFO_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CString m_title;
	CString m_content;
	CString m_filename;
	CComboBox m_mainpagectrl;
	CComboBox m_2pagectrl;
	CComboBox m_1pagectrl;
	CComboBox m_3pagectrl;
	CComboBox m_5pagectrl;
};
