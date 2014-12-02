// ThirdDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "ThirdDlg.h"
#include "afxdialogex.h"


#include "ThirdoneDlg.h"
#include "ContentListDlg.h"


// CThirdDlg 对话框

IMPLEMENT_DYNAMIC(CThirdDlg, CDialogEx)

CThirdDlg::CThirdDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThirdDlg::IDD, pParent)
{

}

CThirdDlg::~CThirdDlg()
{
}

void CThirdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CThirdDlg::OnInitDialog()
{
	ShowWindow(SW_MAXIMIZE);
	CRect rect(566,169,1122,236);
	
	
	imgfile = _T("res\\3.jpg");
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

BEGIN_MESSAGE_MAP(CThirdDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CThirdDlg 消息处理程序


void CThirdDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect1(373,649,545,802); //banshizhinan
	CRect rect2(696,647,853,806);//biaogexiazai
	CRect rect3(1013,645,1187,809);//yangzhangxiazai
	CRect rect4(1333,650,1493,811);//fanbenxiazai
	CRect rect5(1455,458,1680,518);//fantuichu
	CRect rect6(1693,460,1892,521);//tuishouye
	CRect rect7(1130,170,1311,233);//sousuoanniu
	if (true == isPointInRect( point ,  rect1)){
		if (true == this->isFromGongsi(fromwherenum)){
			CThirdoneDlg dlg;
			mynum = 10;
			dlg.fromwherenum = mynum+fromwherenum;
			dlg.DoModal();
		}else{
			 CContentListDlg dlg;
		     mynum=10;
		     dlg.totaltypenum=mynum+fromwherenum;
		     dlg.DoModal();
		}
	}
	if (true == isPointInRect( point ,  rect2)){
		if (true == this->isFromGongsi(fromwherenum)){
			CThirdoneDlg dlg;
			mynum = 20;
			dlg.fromwherenum = mynum+fromwherenum;
			dlg.DoModal();
		}else{
			 CContentListDlg dlg;
		     mynum=20;
		     dlg.totaltypenum=mynum+fromwherenum;
		     dlg.DoModal();
		}
	}
	if (true == isPointInRect( point ,  rect3)){
		if (true == this->isFromGongsi(fromwherenum)){
			CThirdoneDlg dlg;
			mynum = 30;
			dlg.fromwherenum = mynum+fromwherenum;
			dlg.DoModal();
		}else{
			 CContentListDlg dlg;
		     mynum=30;
		     dlg.totaltypenum=mynum+fromwherenum;
		     dlg.DoModal();
		}
	}
	if (true == isPointInRect( point ,  rect4)){
		if (true == this->isFromGongsi(fromwherenum)){
			CThirdoneDlg dlg;
			mynum = 40;
			dlg.fromwherenum = mynum+fromwherenum;
			dlg.DoModal();
		}else{
			 CContentListDlg dlg;
		     mynum=40;
		     dlg.totaltypenum=mynum+fromwherenum;
		     dlg.DoModal();
		}
	}
	

	if (true == isPointInRect( point ,  rect5)){
		CDialogEx::OnCancel();

	}
	if (true == isPointInRect( point ,  rect6)){
		CDialogEx::OnCancel();

	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CThirdDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	Show_picture(imgfile);
}

bool CThirdDlg::Show_picture(CString imgPath)
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

bool CThirdDlg::isPointInRect(CPoint point ,CRect rect)
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


bool CThirdDlg::isFromGongsi(int typenum)
{
	int tmp1;
	tmp1=typenum/1000;
	int tmp2;
	tmp2 = tmp1 % 10;
	if (tmp2 == 1) return true;

	return false;



}