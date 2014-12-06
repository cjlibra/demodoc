// PdfViewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "PdfViewDlg.h"
#include "afxdialogex.h"


// CPdfViewDlg 对话框

IMPLEMENT_DYNAMIC(CPdfViewDlg, CDialogEx)

CPdfViewDlg::CPdfViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPdfViewDlg::IDD, pParent)
{

}

CPdfViewDlg::~CPdfViewDlg()
{
}

void CPdfViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
 	DDX_Control(pDX, IDC_PDF1, m_pdfviewctrl);
 	DDX_Control(pDX, IDC_BUTTON1, m_exitbutton);
}

BOOL CPdfViewDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	 
	 
	this->ShowWindow(SW_MAXIMIZE);
	CRect rect;
	this->GetClientRect(&rect);
	m_pdfviewctrl.MoveWindow(rect);
	this->m_pdfviewctrl.LoadFile(m_pdfname);
	this->m_pdfviewctrl.ShowWindow(1);
	//SetTimer(1,1000,NULL);
	
	this->m_exitbutton.LoadBitmaps(IDB_EXIT1);
	this->m_exitbutton.MoveWindow(0,0,50,50); 
	this->m_exitbutton.SizeToContent();
	
	return TRUE;


}
BEGIN_MESSAGE_MAP(CPdfViewDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPdfViewDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPdfViewDlg 消息处理程序


void CPdfViewDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
//	this->m_pdfviewctrl.Detach();
	this->m_pdfviewctrl.CloseWindow();
	CDialogEx::OnCancel();
}
