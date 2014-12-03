#pragma once
#include "pdf1.h"


// CPdfViewDlg 对话框

class CPdfViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPdfViewDlg)

public:
	CPdfViewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPdfViewDlg();

// 对话框数据
	enum { IDD = IDD_PDFVIEW_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual  BOOL  OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	 CPdf1 m_pdfviewctrl;
	afx_msg void OnBnClickedButton1();
	 CString m_pdfname;
	 CBitmapButton m_exitbutton;
};
