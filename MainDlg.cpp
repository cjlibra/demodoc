// MainDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demodoc.h"
#include "MainDlg.h"
#include "afxdialogex.h"


#include "FirstDlg.h"


// CMainDlg �Ի���

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDlg::IDD, pParent)
	, m_editsearchtxt(_T(""))
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editsearchctrl);
	DDX_Text(pDX, IDC_EDIT1, m_editsearchtxt);
}
BOOL CMainDlg::OnInitDialog()
{
	ShowWindow(SW_MAXIMIZE);
	CRect rect6(1110,168, 1671,228);
	
	
	imgfile = _T("res\\0.jpg");
	Show_picture(imgfile);

	CEdit *editp =(CEdit *) GetDlgItem(IDC_EDIT1);
	editp->MoveWindow( 1110*xScale,168*yScale, (1671-1110)*xScale,(228-168)*yScale );
	CDialogEx::OnInitDialog();
	return TRUE; 
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CMainDlg::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CMainDlg ��Ϣ�������


void CMainDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	AfxMessageBox(_T("up"));
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rect1(1018, 478 ,  1112 ,507);
	CRect rect2(485 , 604,  752 ,852); //mingchengdengji
	CRect rect3(869,625,1123,8490); //neizhidengji
	CRect rect4(1246,606, 1149,842); //waizhidengji
	CRect rect5(1673,162, 1856,226); //shousuoanniu
	CRect rect6(1110,168, 1671,228);//shurukuang
	if (true == isPointInRect(point,rect2)){
		//AfxMessageBox(_T("bingo"));
		CFirstDlg dlg;
		dlg.DoModal();
		
	}
	TCHAR tmpstr[255];
	wsprintf(tmpstr,_T("x is %d  y is %d"),point.x,point.y);
	//AfxMessageBox(_T("down"));
	//AfxMessageBox(tmpstr);
	CDialogEx::OnLButtonDown(nFlags, point);
}

bool CMainDlg::isPointInRect(CPoint point ,CRect rect)
{
	float a = xScale*rect.left;
	float b = yScale*rect.top;
	float c = xScale*rect.right;
	float d = yScale*rect.bottom;
	if (point.x > a &&  point.y> b  && point.x < c  && point.y< d){

		return true;
	}
	return false;
}

void CMainDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxMessageBox(_T("clcikbutton"));
}


bool CMainDlg::Show_picture(CString imgPath)
{
	int height, width;
	CRect rect;//���������
	CRect rect1;
	CImage image; //����ͼƬ��
	image.Load(imgPath);
	
	height = image.GetHeight();
	width = image.GetWidth();
	
	this->GetClientRect(&rect); //���pictrue�ؼ����ڵľ�������
	CDC *pDc = this->GetDC();//���pictrue�ؼ���Dc
	SetStretchBltMode(pDc->m_hDC,STRETCH_HALFTONE); 
	xScale=(float)rect.Width()/(float)width;
	yScale=(float)rect.Height()/(float)height;
	if(width<=rect.Width() && height<=rect.Width()) //СͼƬ��������
	{
	rect1 = CRect(rect.TopLeft(), CSize(width,height));
	image.StretchBlt(pDc->m_hDC,rect,SRCCOPY); //��ͼƬ����Picture�ؼ���ʾ�ľ�������
	return TRUE;
	}
	else
	{
	xScale=(float)rect.Width()/(float)width;
	yScale=(float)rect.Height()/(float)height;
	float ScaleIndex=(xScale<=yScale?xScale:yScale);
	rect1 = CRect(rect.TopLeft(), CSize((int)width*ScaleIndex,(int)height*ScaleIndex));
	image.StretchBlt(pDc->m_hDC,rect,SRCCOPY); //��ͼƬ����Picture�ؼ���ʾ�ľ�������
	}
	ReleaseDC(pDc);//�ͷ�picture�ؼ���Dc
	return TRUE;
}

void CMainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	Show_picture(imgfile);
}
