#pragma once


// CDlgdlg �Ի���

class CDlgdlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgdlg)

public:
	CDlgdlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgdlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
