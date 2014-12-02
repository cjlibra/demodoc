#pragma once
#include "afxwin.h"


// CDirListCtrlDlg �Ի���

class CDirListCtrlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDirListCtrlDlg)

public:
	CDirListCtrlDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDirListCtrlDlg();

// �Ի�������
	enum { IDD = IDD_DIRLISTCTRL_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	bool Show_picture(CString imgPath);
	CString imgfile;
	float xScale;
	float yScale;
	CString currdir;
	CBitmapButton *bt;
	CBitmapButton bbt;
	CFont font;
	CButton *p[200];
	int howmuchbutton;
 
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	bool  isPointInRect(CPoint point ,CRect rect);
	CString totoaldir;
	CString prevdir;
	void  OnMyCancel();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CEdit m_edittitlectrl;
	void SwitchBmp(CString str, CBitmapButton *pBton);
};
