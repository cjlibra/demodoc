#pragma once
#include "afxcmn.h"


// CManageDlg �Ի���

class CManageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManageDlg)

public:
	CManageDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CManageDlg();

// �Ի�������
	enum { IDD = IDD_MANAGE_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL  OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListCtrl m_contentlistctrl;
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	CString id;
	CString title;
	CString content;
	CString filename;
	CString typenum;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	void  refreshlist();
};
