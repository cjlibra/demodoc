#pragma once
#include "afxshelltreectrl.h"
#include "afxwin.h"


// CContentListDlg 对话框

class CContentListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CContentListDlg)

public:
	CContentListDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CContentListDlg();

// 对话框数据
	enum { IDD = IDD_CONTENTLIST_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL  OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	bool  Show_picture(CString imgPath);
	CString imgfile;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	bool  isPointInRect(CPoint point ,CRect rect);

	float xScale;
	float yScale;
	afx_msg void OnPaint();
	int totaltypenum;
	afx_msg void OnEnSetfocusEdit1();
	CString m_line1;
	CString m_line2;
	CString m_line3;
	CMFCShellTreeCtrl m_dirtree;
	CListBox m_listctrl;
};
