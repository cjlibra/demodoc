#pragma once


// CThirdoneDlg 对话框

class CThirdoneDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CThirdoneDlg)

public:
	CThirdoneDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CThirdoneDlg();

// 对话框数据
	enum { IDD = IDD_THIRD_1_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL  OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	bool  Show_picture(CString imgPath);

	bool isPointInRect(CPoint point ,CRect rect);
	float xScale;
	float yScale;
	CString imgfile;
	int mynum;
	int fromwherenum;
	CFont   font; 
};
