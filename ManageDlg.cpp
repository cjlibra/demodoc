// ManageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "ManageDlg.h"
#include "afxdialogex.h"

#include "sqlite3.h"
#include "LoginDlg.h"
#include "AddinfoDlg.h"

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
	jj=0;
	DWORD dwStyle;
 	dwStyle =m_contentlistctrl.GetStyle();
	dwStyle |= LVS_EX_FULLROWSELECT| LVS_SHOWSELALWAYS;
	m_contentlistctrl.SetExtendedStyle(dwStyle);
	m_contentlistctrl.InsertColumn(0,_T("序号"),LVCFMT_CENTER,50);
	m_contentlistctrl.InsertColumn(1,_T("标题"),LVCFMT_CENTER,100);
	m_contentlistctrl.InsertColumn(2,_T("内容"),LVCFMT_CENTER,100);
	m_contentlistctrl.InsertColumn(3,_T("文件名"),LVCFMT_CENTER,200);
	m_contentlistctrl.InsertColumn(4,_T("所属编码"),LVCFMT_CENTER,100);
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
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CManageDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON2, &CManageDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CManageDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CManageDlg 消息处理程序


void CManageDlg::OnBnClickedButton1()
{
	CAddinfoDlg dlg;
	dlg.DoModal();
}


void CManageDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if(pNMListView->uChanged == LVIF_STATE)
    {
        if(pNMListView->uNewState)
        {
             int nIndex = pNMListView->iItem;
            //要进行的操作
			 id = this->m_contentlistctrl.GetItemText(nIndex,0);
			 title = m_contentlistctrl.GetItemText(nIndex,1);
			 content = m_contentlistctrl.GetItemText(nIndex,2);
			 filename = m_contentlistctrl.GetItemText(nIndex,3);
			 typenum = m_contentlistctrl.GetItemText(nIndex,4);
			  
        }
    }
	*pResult = 0;
}


void CManageDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CAddinfoDlg dlg;
	dlg.id = id;
	dlg.title = title;
	dlg.content = content;
	dlg.filename = filename;
	dlg.typenum = typenum;
	dlg.editflag = 1;
	
	dlg.DoModal();
}


void CManageDlg::OnBnClickedButton3()
{
	char sSQL3[255];
	char format[255]="delete  from contents where id = %s;";
	sprintf(sSQL3,format,id);
	CLoginDlg *pDlg = (CLoginDlg *)this->GetParent() ;
	int ret =1;
	char * pErrMsg = 0;
	ret = sqlite3_exec(pDlg->db, sSQL3, NULL, 0, &pErrMsg);
	if (ret == 0){
		AfxMessageBox("成功删除");
	}else{
        AfxMessageBox("不成功删除");
	}
	refreshlist();
}

void CManageDlg::refreshlist()
{
	jj = 0;
	this->m_contentlistctrl.DeleteAllItems();

	CLoginDlg *pDlg = (CLoginDlg *)this->GetParent();
	const char * sSQL3 = "select * from contents;";
	char * pErrMsg = 0;
	sqlite3_exec(pDlg->db, sSQL3, _sql_init_callback, 0, &pErrMsg);



}