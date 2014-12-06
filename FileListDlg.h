#pragma once
#include "afxwin.h"


// CFileListDlg 对话框

class CFileListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFileListDlg)

public:
	CFileListDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFileListDlg();

// 对话框数据
	enum { IDD = IDD_FILELIST_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL  OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_filelistctrl;
	afx_msg void OnBnClickedButton2();
	CBitmap  bitmap;
	CButton m_copybton;
	CButton m_viewbton;
	afx_msg void OnPaint();
	bool  Show_picture(CString imgPath);
	float xScale;
	float yScale;
	CString imgfile;
	int filecount;
	CString filelistname[200];
	CString nowdir;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	bool  isPointInRect(CPoint point ,CRect rect);
	afx_msg void OnLbnSetfocusList1();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	CFont font;
	int dontflag;
	CEdit m_edittitlectrl;
	CString currdir;
	CString m_stitle;
	CEdit m_stitlectrl;
	CEdit m_txtsctrl;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLvnItemchangingList2(NMHDR *pNMHDR, LRESULT *pResult);
	CButton *pbt1[200];
	CButton *pbt2[200];
	int nCount ;
};
