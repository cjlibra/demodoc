#pragma once


// CThirdDlg �Ի���

class CThirdDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CThirdDlg)

public:
	CThirdDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CThirdDlg();

// �Ի�������
	enum { IDD = IDD_THIRD_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL  OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	bool isPointInRect(CPoint point ,CRect rect);
	bool  Show_picture(CString imgPath);
	float xScale;
	float yScale;
	CString imgfile;
	int mynum;
	int fromwherenum;
	bool isFromGongsi(int typenum);
	CFont   font;  
};
