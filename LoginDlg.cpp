// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "LoginDlg.h"
#include "afxdialogex.h"

#include "ManageDlg.h"

// CLoginDlg 对话框
static CString username_db;
static CString	password_db;

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
	, m_username(_T(""))
	, m_password(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_password);
}
BOOL CLoginDlg::OnInitDialog()
{
	int ret = 1;
	db = 0;
	ret = sqlite3_open("demodoc.s3db", &db);
      
    if ( ret != SQLITE_OK )
    {
      fprintf(stderr, "无法打开数据库: %s", sqlite3_errmsg(db));
      return(FALSE);
    }
      
    printf("数据库连接成功!\n");
	CDialogEx::OnInitDialog();
	return TRUE; 

}

BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	//CDialogEx::OnOK();

	  const char * sSQL3 = "select * from login;";
	  UpdateData(TRUE);
	  CString username, password;
	 // m_username.GetWindowText(username );
	 // m_password.GetWindowText( password);

	   char * pErrMsg = 0;
	   sqlite3_exec( db, sSQL3, _sql_callback, 0, &pErrMsg);

	   CManageDlg dlg;
	   if (m_password == password_db && m_username == username_db){
		   dlg.DoModal();
		   return;
	   }
	   AfxMessageBox(_T("密码不对"));
}
int CLoginDlg::_sql_callback(void * notused, int argc, char ** argv, char ** szColName)
{
  int i;
  for ( i=0; i < argc; i++ )
  {
      printf( "%s = %s\n", szColName[i], argv[i] == 0 ? "NUL" : argv[i] );
  }

  username_db = CString(argv[1]);
  password_db = CString(argv[2]);
  return 0;
 }