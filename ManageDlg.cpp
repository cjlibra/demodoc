// ManageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "ManageDlg.h"
#include "afxdialogex.h"

#include "sqlite3.h"
#include "LoginDlg.h"

// CManageDlg 对话框
static int  _sql_init_callback(void * notused, int argc, char ** argv, char ** szColName);
CManageDlg *thisp;
static int jj=0;

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
	DDX_Control(pDX, IDC_LIST2, m_contentlistctrl);
}

BOOL CManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	DWORD dwStyle;
 	dwStyle =m_contentlistctrl.GetStyle();
	dwStyle |= LVS_EX_FULLROWSELECT| LVS_SHOWSELALWAYS;
	m_contentlistctrl.SetExtendedStyle(dwStyle);
	m_contentlistctrl.InsertColumn(0,"序号",LVCFMT_CENTER,50);
	m_contentlistctrl.InsertColumn(1,"标题",LVCFMT_CENTER,100);
	m_contentlistctrl.InsertColumn(2,"内容",LVCFMT_CENTER,100);
	m_contentlistctrl.InsertColumn(3,"文件名",LVCFMT_CENTER,200);
	m_contentlistctrl.InsertColumn(4,"所属编码",LVCFMT_CENTER,100);
	thisp= this;
	CLoginDlg *pDlg = (CLoginDlg *)this->GetParent();
	const char * sSQL3 = "select * from contents;";
	char * pErrMsg = 0;
	sqlite3_exec(pDlg->db, sSQL3, _sql_init_callback, 0, &pErrMsg);

	 
	
	
	return TRUE; 

}

static int  _sql_init_callback(void * notused, int argc, char ** argv, char ** szColName)
{
	thisp->m_contentlistctrl.InsertItem(jj,argv[0]);
	thisp->m_contentlistctrl.SetItemText(jj,1,argv[1]);
	thisp->m_contentlistctrl.SetItemText(jj,2,argv[2] );
	thisp->m_contentlistctrl.SetItemText(jj,3,argv[3]);
	thisp->m_contentlistctrl.SetItemText(jj,4,argv[4]);
	 
	jj++;

	return 0;
}
BEGIN_MESSAGE_MAP(CManageDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CManageDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CManageDlg 消息处理程序


void CManageDlg::OnBnClickedButton1()
{
	AfxMessageBox(_T("添加"),MB_OK);
}
