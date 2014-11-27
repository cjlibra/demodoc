// ChooseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "ChooseDlg.h"
#include "afxdialogex.h"


#include "LoginDlg.h"
#include "MainDlg.h"


// CChooseDlg 对话框

IMPLEMENT_DYNAMIC(CChooseDlg, CDialogEx)

CChooseDlg::CChooseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChooseDlg::IDD, pParent)
{

}

CChooseDlg::~CChooseDlg()
{
}

void CChooseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChooseDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CChooseDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CChooseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CChooseDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CChooseDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CChooseDlg 消息处理程序


void CChooseDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
	
}


void CChooseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDialogEx::OnOK();
}


void CChooseDlg::OnBnClickedButton1()
{
	CMainDlg dlg;
	
	dlg.DoModal();
}


void CChooseDlg::OnBnClickedButton2()
{
	CLoginDlg dlg;
	dlg.DoModal();
}
