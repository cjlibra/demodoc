// SecondDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demodoc.h"
#include "SecondDlg.h"
#include "afxdialogex.h"

#include "ThirdDlg.h"


// CSecondDlg �Ի���

IMPLEMENT_DYNAMIC(CSecondDlg, CDialogEx)

CSecondDlg::CSecondDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSecondDlg::IDD, pParent)
{

}

CSecondDlg::~CSecondDlg()
{
}

void CSecondDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BOOL CSecondDlg::OnInitDialog()
{
	ShowWindow(SW_MAXIMIZE);
	CRect rect(564,171, 1122,234);
	
	
	imgfile = _T("res\\2.jpg");
	Show_picture(imgfile);

	CEdit *editp =(CEdit *) GetDlgItem(IDC_EDIT1);
	editp->MoveWindow( rect.left*xScale,rect.top*yScale, (rect.right-rect.left)*xScale,(rect.bottom-rect.top)*yScale );
	LOGFONT lf;     
     
	memset(&lf,0,sizeof(lf));   
	lf.lfHeight = 35;  //�ı��С  
	font.CreateFontIndirect(&lf) ;	
	editp->SetFont(&font,TRUE);

	
	CDialogEx::OnInitDialog();
	return TRUE; 
}

BEGIN_MESSAGE_MAP(CSecondDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CSecondDlg::OnEnChangeEdit1)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CSecondDlg ��Ϣ�������


void CSecondDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}




bool CSecondDlg::Show_picture(CString imgPath)
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

void CSecondDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CRect rect1(342,624,549,798); //kaiye
	CRect rect2(615,638,828,793);//biangeng
	CRect rect3(879,634,1082,793);//beian
	CRect rect4(1151,632,1363,789); //leixinghubian
	CRect rect5(1424,640,1630,797); //zhuxiao
	CRect rect6(1459,459,1683,522);//tuiqianye
	CRect rect7(1695,462,1892,519);//fanshouye
	CRect rect8(1124,172,1309,236);//shousuoanniu
	if (true == isPointInRect( point ,  rect1)){
		CThirdDlg dlg;
		mynum = 100;
		dlg.fromwherenum=mynum+fromwherenum;
		dlg.DoModal();
	}
	if (true == isPointInRect( point ,  rect2)){
		CThirdDlg dlg;
		mynum = 200;
		dlg.fromwherenum=mynum+fromwherenum;
		dlg.DoModal();
	}
	if (true == isPointInRect( point ,  rect3)){
		CThirdDlg dlg;
		mynum = 300;
		dlg.fromwherenum=mynum+fromwherenum;
		dlg.DoModal();
	}
	if (true == isPointInRect( point ,  rect4)){
		CThirdDlg dlg;
		mynum = 400;
		dlg.fromwherenum=mynum+fromwherenum;
		dlg.DoModal();
	}
	if (true == isPointInRect( point ,  rect5)){
		CThirdDlg dlg;
		mynum = 500;
		dlg.fromwherenum=mynum+fromwherenum;
		dlg.DoModal();
	}



	if (true == isPointInRect( point ,  rect6)){
		CDialogEx::OnCancel();

	}
	if (true == isPointInRect( point ,  rect7)){
		CDialogEx::OnCancel();

	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CSecondDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	Show_picture(imgfile);
}


bool CSecondDlg::isPointInRect(CPoint point ,CRect rect)
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