#pragma once


// CChooseDlg �Ի���

class CChooseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChooseDlg)

public:
	CChooseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChooseDlg();

// �Ի�������
	enum { IDD = IDD_CHOOSE_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
