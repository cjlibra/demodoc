// FirstDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demodoc.h"
#include "FirstDlg.h"
#include "afxdialogex.h"

#include "SecondDlg.h"


// CFirstDlg �Ի���

IMPLEMENT_DYNAMIC(CFirstDlg, CDialogEx)

CFirstDlg::CFirstDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFirstDlg::IDD, pParent)
{

}

CFirstDlg::~CFirstDlg()
{
}

void CFirstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CFirstDlg::OnInitDialog()
{
	ShowWindow(SW_MAXIMIZE);
	CRect rect(576,172, 1134,235);
	
	
	imgfile = _T("res\\1.jpg");
	Show_picture(imgfile);

	CEdit *editp =(CEdit *) GetDlgItem(IDC_EDIT1);
	editp->MoveWindow( rect.left*xScale,rect.top*yScale, (rect.right-rect.left)*xScale,(rect.bottom-rect.top)*yScale );
	
	LOGFONT lf;     
      
	memset(&lf,0,sizeof(lf));   
	lf.lfHeight = 35;  //�ı��С  
	lf.lfCharSet = GB2312_CHARSET;
	font.CreateFontIndirect(&lf) ;	
	editp->SetFont(&font,TRUE);
	
	
	CDialogEx::OnInitDialog();
	return TRUE; 
}

BEGIN_MESSAGE_MAP(CFirstDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CFirstDlg ��Ϣ�������


void CFirstDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CRect rect1(263,591,546,828);//gongsi
	CRect rect2(634,602,930,839);//gerenduziqiye
	CRect rect3(1032,618,1308,840);//hehuoqiye
	CRect rect4(1393,621,1650,850);//feigongsifarenqiye
	CRect rect5(1460,461,1677,517);//tui shang
	CRect rect6(1699,466,1890,517);//fan shouye

	CRect rect7(1139,173,1320,238);//sousuoanniu
	if (true == isPointInRect( point ,  rect1)){
		CSecondDlg dlg;
		mynum = 1000;
		dlg.fromwherenum = mynum+fromwherenum;
		dlg.DoModal();

	}
	if (true == isPointInRect( point ,  rect2)){
		CSecondDlg dlg;
		mynum = 2000;
		dlg.fromwherenum = mynum+fromwherenum;
		dlg.DoModal();

	}
	if (true == isPointInRect( point ,  rect3)){
		CSecondDlg dlg;
		mynum = 3000;
		dlg.fromwherenum = mynum+fromwherenum;
		dlg.DoModal();

	}
	if (true == isPointInRect( point ,  rect4)){
		CSecondDlg dlg;
		mynum = 4000;
		dlg.fromwherenum = mynum+fromwherenum;
		dlg.DoModal();

	}


	if (true == isPointInRect( point ,  rect5)){
		CDialogEx::OnCancel();

	}
	if (true == isPointInRect( point ,  rect6)){
		CDialogEx::OnCancel();

	}
	CDialogEx::OnLButtonDown(nFlags, point);
}



bool CFirstDlg::Show_picture(CString imgPath)
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

void CFirstDlg::OnPaint()
{
	CPaintDC dc(this); 
	// device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	Show_picture(imgfile);
}


bool CFirstDlg::isPointInRect(CPoint point ,CRect rect)
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