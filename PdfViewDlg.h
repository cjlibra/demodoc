#pragma once
#include "pdf1.h"


// CPdfViewDlg �Ի���

class CPdfViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPdfViewDlg)

public:
	CPdfViewDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPdfViewDlg();

// �Ի�������
	enum { IDD = IDD_PDFVIEW_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual  BOOL  OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	 CPdf1 m_pdfviewctrl;
	afx_msg void OnBnClickedButton1();
	 CString m_pdfname;
	 CBitmapButton m_exitbutton;
};
