#pragma once


// CFirstDlg 对话框

class CFirstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFirstDlg)

public:
	CFirstDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFirstDlg();

// 对话框数据
	enum { IDD = IDD_FIRST_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL  OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	bool Show_picture(CString imgPath);
	CString imgfile;
	afx_msg void OnPaint();
	bool isPointInRect(CPoint point ,CRect rect);
	CFont   font; 
	float xScale;
	float yScale;
	int mynum;
	int fromwherenum;
};
