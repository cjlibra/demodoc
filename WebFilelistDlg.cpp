// WebFilelistDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "WebFilelistDlg.h"
#include "afxdialogex.h"


// CWebFilelistDlg 对话框

IMPLEMENT_DYNAMIC(CWebFilelistDlg, CDialogEx)

CWebFilelistDlg::CWebFilelistDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWebFilelistDlg::IDD, pParent)
{

}

CWebFilelistDlg::~CWebFilelistDlg()
{
}

void CWebFilelistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_webctrl);
}


BEGIN_MESSAGE_MAP(CWebFilelistDlg, CDialogEx)
END_MESSAGE_MAP()


// CWebFilelistDlg 消息处理程序


BOOL CWebFilelistDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	this->ShowWindow (SW_MAXIMIZE);
	CRect rect;
	this->GetClientRect(&rect);
	this->m_webctrl.MoveWindow(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
