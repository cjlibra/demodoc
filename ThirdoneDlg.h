#pragma once


// CThirdoneDlg �Ի���

class CThirdoneDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CThirdoneDlg)

public:
	CThirdoneDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CThirdoneDlg();

// �Ի�������
	enum { IDD = IDD_THIRD_1_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
