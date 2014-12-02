#pragma once


// CSecondDlg 对话框

class CSecondDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSecondDlg)

public:
	CSecondDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSecondDlg();

// 对话框数据
	enum { IDD = IDD_SECOND_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL  OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	bool Show_picture(CString imgPath);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();

	bool isPointInRect(CPoint point ,CRect rect);
	float xScale;
	float yScale;
	CString imgfile;
	int mynum;
	int fromwherenum;
	CFont   font; 
	
};
