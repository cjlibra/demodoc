// ManageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "ManageDlg.h"
#include "afxdialogex.h"


// CManageDlg 对话框

IMPLEMENT_DYNAMIC(CManageDlg, CDialogEx)

CManageDlg::CManageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManageDlg::IDD, pParent)
{

}

CManageDlg::~CManageDlg()
{
}

void CManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CManageDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CManageDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CManageDlg 消息处理程序


void CManageDlg::OnBnClickedButton1()
{
	AfxMessageBox(_T("添加"),MB_OK);
}
