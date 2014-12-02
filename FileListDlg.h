#pragma once
#include "afxwin.h"


// CFileListDlg �Ի���

class CFileListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFileListDlg)

public:
	CFileListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFileListDlg();

// �Ի�������
	enum { IDD = IDD_FILELIST_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL  OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_filelistctrl;
	afx_msg void OnBnClickedButton2();
	CBitmap  bitmap;
	CBitmapButton m_copybton;
	CBitmapButton m_viewbton;
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
};
