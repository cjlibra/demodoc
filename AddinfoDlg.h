#pragma once
#include "afxwin.h"


// CAddinfoDlg �Ի���

class CAddinfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddinfoDlg)

public:
	CAddinfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddinfoDlg();

// �Ի�������
	enum { IDD = IDD_ADDINFO_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
