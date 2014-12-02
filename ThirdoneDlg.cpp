// ThirdoneDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "ThirdoneDlg.h"
#include "afxdialogex.h"


#include "ContentListDlg.h"


// CThirdoneDlg 对话框

IMPLEMENT_DYNAMIC(CThirdoneDlg, CDialogEx)

CThirdoneDlg::CThirdoneDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThirdoneDlg::IDD, pParent)
{

}

CThirdoneDlg::~CThirdoneDlg()
{
}

void CThirdoneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CThirdoneDlg::OnInitDialog()
{
	ShowWindow(SW_MAXIMIZE);
	CRect rect(574,173,1130,236);
	
	
	imgfile = _T("res\\3-1.jpg");
	Show_picture(imgfile);

	CEdit *editp =(CEdit *) GetDlgItem(IDC_EDIT1);
	editp->MoveWindow( rect.left*xScale,rect.top*yScale, (rect.right-rect.left)*xScale,(rect.bottom-rect.top)*yScale );
	LOGFONT lf;     
      
	memset(&lf,0,sizeof(lf));   
	lf.lfHeight = 35;  //改变大小  
	font.CreateFontIndirect(&lf) ;	
	editp->SetFont(&font,TRUE);
	
	
	CDialogEx::OnInitDialog();
	return TRUE; 
}

BEGIN_MESSAGE_MAP(CThirdoneDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CThirdoneDlg 消息处理程序


void CThirdoneDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect1(614,634,835,805); //yirengongsi
	CRect rect2(1046,631,1257,808); //heziyouxiangongsi
	CRect rect3(1453,460,1680,520);//tuishangye
	CRect rect4(1694,460,1893,520);//tuisouye
	CRect rect5(1135,171,1318,239);//sousuoanniu

	if (true == isPointInRect( point ,  rect1)){
		 CContentListDlg dlg;
		 mynum=1;
		 dlg.totaltypenum=mynum+fromwherenum;
		 dlg.DoModal();
	}
	if (true == isPointInRect( point ,  rect2)){
		 CContentListDlg dlg;
		 mynum=2;
		 dlg.totaltypenum=mynum+fromwherenum;
		 dlg.DoModal();
	}
	if (true == isPointInRect( point ,  rect3)){
		CDialogEx::OnCancel();

	}
	if (true == isPointInRect( point ,  rect4)){
		CDialogEx::OnCancel();

	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CThirdoneDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	Show_picture(imgfile);
}


bool CThirdoneDlg::Show_picture(CString imgPath)
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
bool CThirdoneDlg::isPointInRect(CPoint point ,CRect rect)
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