// ContentListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demodoc.h"
#include "ContentListDlg.h"
#include "afxdialogex.h"


// CContentListDlg �Ի���

IMPLEMENT_DYNAMIC(CContentListDlg, CDialogEx)

CContentListDlg::CContentListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CContentListDlg::IDD, pParent)
	, m_line1(_T(""))
	, m_line2(_T(""))
	, m_line3(_T(""))
{

}

CContentListDlg::~CContentListDlg()
{
}

void CContentListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	 
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}

BOOL  CContentListDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	ShowWindow(SW_MAXIMIZE);

	imgfile = _T("res\\4.jpg");
	Show_picture(imgfile);
	//CRect rect(49,260,1800,316);
//	m_dirtree.SelectPath("c:\\go");
	CRect rect(63,160,1164,842);
	this->m_listctrl.SetWindowPos(NULL,50,160,700,500,NULL);
	//this->m_listctrl.MoveWindow(rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top);
	LOGFONT lf;     
    static CFont font;   
	memset(&lf,0,sizeof(lf));   
	lf.lfHeight = 35;  //�ı��С  
	font.CreateFontIndirect(&lf) ;	
	this->m_listctrl.SetFont(&font,TRUE);
	this->m_listctrl.AddString("lllllll");
	this->m_listctrl.AddString("22222222");

	Show_picture(imgfile);

	
	//S1->MoveWindow(rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top);
	//S1->MoveWindow(0,0,10,10);
	//S1->move

	return TRUE; 

}

BEGIN_MESSAGE_MAP(CContentListDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CContentListDlg::OnBnClickedOk)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_EN_SETFOCUS(IDC_EDIT1, &CContentListDlg::OnEnSetfocusEdit1)
END_MESSAGE_MAP()


// CContentListDlg ��Ϣ�������


void CContentListDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}



bool CContentListDlg::Show_picture(CString imgPath)
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

void CContentListDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CRect rect1(588,872,748,913);//diyiye
	CRect rect2(800,872,960,912);//shangyiye
	CRect rect3(1012,872,1173,913);//xiayiye
	CRect rect4(1222,875,1384,914);//weiye
	CRect rect5(1424,136,1654,203);//tuishangye
	CRect rect6(1663,137,1866,204);//fanshouye

	if (true == isPointInRect( point ,  rect5)){
		CString tmp;
		tmp.Format("%d",this->totaltypenum);
		AfxMessageBox(tmp);

	}
	if (true == isPointInRect( point ,  rect5)){
		CDialogEx::OnCancel();

	}
	if (true == isPointInRect( point ,  rect6)){
		CDialogEx::OnCancel();

	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


bool CContentListDlg::isPointInRect(CPoint point ,CRect rect)
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

void CContentListDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}


void CContentListDlg::OnEnSetfocusEdit1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
