// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "MainDlg.h"
#include "afxdialogex.h"


#include "FirstDlg.h"


// CMainDlg 对话框

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


// CMainDlg 消息处理程序


void CMainDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	AfxMessageBox(_T("up"));
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox(_T("clcikbutton"));
}


bool CMainDlg::Show_picture(CString imgPath)
{
	int height, width;
	CRect rect;//定义矩形类
	CRect rect1;
	CImage image; //创建图片类
	image.Load(imgPath);
	
	height = image.GetHeight();
	width = image.GetWidth();
	
	this->GetClientRect(&rect); //获得pictrue控件所在的矩形区域
	CDC *pDc = this->GetDC();//获得pictrue控件的Dc
	SetStretchBltMode(pDc->m_hDC,STRETCH_HALFTONE); 
	xScale=(float)rect.Width()/(float)width;
	yScale=(float)rect.Height()/(float)height;
	if(width<=rect.Width() && height<=rect.Width()) //小图片，不缩放
	{
	rect1 = CRect(rect.TopLeft(), CSize(width,height));
	image.StretchBlt(pDc->m_hDC,rect,SRCCOPY); //将图片画到Picture控件表示的矩形区域
	return TRUE;
	}
	else
	{
	xScale=(float)rect.Width()/(float)width;
	yScale=(float)rect.Height()/(float)height;
	float ScaleIndex=(xScale<=yScale?xScale:yScale);
	rect1 = CRect(rect.TopLeft(), CSize((int)width*ScaleIndex,(int)height*ScaleIndex));
	image.StretchBlt(pDc->m_hDC,rect,SRCCOPY); //将图片画到Picture控件表示的矩形区域
	}
	ReleaseDC(pDc);//释放picture控件的Dc
	return TRUE;
}

void CMainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	Show_picture(imgfile);
}
