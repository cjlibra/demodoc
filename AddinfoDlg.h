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
	virtual BOOL CAddinfoDlg::OnInitDialog();

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
	afx_msg void OnBnClickedButton1();
	int  maketypenum(CString str);
	CString A1;
	CString A2;
	CString A3;

	CString B4;
	CString B3;
	CString B2;
	CString B1;

	CString C5;
	CString C4;
	CString C3;
	CString C2;
	CString C1;

	CString D4;
	CString D3;
	CString D2;
	CString D1;

	CString E2;
	CString E1;

	CString id;
	CString title;
	CString content;
	CString filename;
	CString typenum;
	int editflag;
	void typenum2str(int typenum);
	afx_msg void OnBnClickedButton3();
	CString m_type0;
	CString m_type1;
	CString m_type2;
	CString m_type3;
	CString m_type4;
	CString valuestr[5];
};
