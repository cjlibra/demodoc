#pragma once
#include "afxwin.h"


// CMainDlg �Ի���

class CMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMainDlg();

// �Ի�������
	enum { IDD = IDD_MAIN_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();

	bool Show_picture(CString imgPath);
	afx_msg void OnPaint();
	bool isPointInRect(CPoint point ,CRect rect);

	float xScale;
	float yScale;
	CEdit m_editsearchctrl;
	CString m_editsearchtxt;
	CString imgfile;
};
