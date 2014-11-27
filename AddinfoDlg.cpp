// AddinfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "AddinfoDlg.h"
#include "afxdialogex.h"


// CAddinfoDlg 对话框

IMPLEMENT_DYNAMIC(CAddinfoDlg, CDialogEx)

CAddinfoDlg::CAddinfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddinfoDlg::IDD, pParent)
	, m_title(_T(""))
	, m_content(_T(""))
	, m_filename(_T(""))
{

}

CAddinfoDlg::~CAddinfoDlg()
{
}

void CAddinfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_title);
	DDX_Text(pDX, IDC_RICHEDIT21, m_content);
	DDX_Text(pDX, IDC_EDIT3, m_filename);
	DDX_Control(pDX, IDC_COMBO1, m_mainpagectrl);
	DDX_Control(pDX, IDC_COMBO3, m_2pagectrl);
	DDX_Control(pDX, IDC_COMBO2, m_1pagectrl);
	DDX_Control(pDX, IDC_COMBO4, m_3pagectrl);
	DDX_Control(pDX, IDC_COMBO5, m_5pagectrl);
}


BEGIN_MESSAGE_MAP(CAddinfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddinfoDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CAddinfoDlg 消息处理程序


void CAddinfoDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}
