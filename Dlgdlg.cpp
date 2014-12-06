// Dlgdlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "Dlgdlg.h"
#include "afxdialogex.h"


// CDlgdlg 对话框

IMPLEMENT_DYNAMIC(CDlgdlg, CDialogEx)

CDlgdlg::CDlgdlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgdlg::IDD, pParent)
{

}

CDlgdlg::~CDlgdlg()
{
}

void CDlgdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgdlg, CDialogEx)
END_MESSAGE_MAP()


// CDlgdlg 消息处理程序
