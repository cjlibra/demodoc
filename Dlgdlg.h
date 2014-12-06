#pragma once


// CDlgdlg 对话框

class CDlgdlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgdlg)

public:
	CDlgdlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgdlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
