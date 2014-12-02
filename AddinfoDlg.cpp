// AddinfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "AddinfoDlg.h"
#include "afxdialogex.h"

#include "sqlite3.h"
#include "LoginDlg.h"
#include "ManageDlg.h"
// CAddinfoDlg 对话框

IMPLEMENT_DYNAMIC(CAddinfoDlg, CDialogEx)

CAddinfoDlg::CAddinfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddinfoDlg::IDD, pParent)
	, m_title(_T(""))
	, m_content(_T(""))
	, m_filename(_T(""))
	, m_type0(_T(""))
	, m_type1(_T(""))
	, m_type2(_T(""))
	, m_type3(_T(""))
	, m_type4(_T(""))
{
	::AfxInitRichEdit2();
	A1="名称登记";
	A2="内资登记";
	A3="外资登记";

	B4="非公司企业法人";
	B3="合伙企业";
	B2="个人独资企业";
	B1="公司";

	C5="注销";
	C4="类型互变";
	C3="备案";
	C2="变更";
	C1="开业";

	D4="范本下载";
	D3="样张下载";
	D2="表格下载";
	D1="办事指南";

	E2="合资有限公司";
	E1="一人有限公司";
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
	DDX_CBString(pDX, IDC_COMBO1, m_type0);
	DDX_CBString(pDX, IDC_COMBO2, m_type1);
	DDX_CBString(pDX, IDC_COMBO3, m_type2);
	DDX_CBString(pDX, IDC_COMBO4, m_type3);
	DDX_CBString(pDX, IDC_COMBO5, m_type4);
}
BOOL CAddinfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	this->m_mainpagectrl.AddString(A1);
	this->m_mainpagectrl.AddString(A2);
	this->m_mainpagectrl.AddString(A3);
	 

	this->m_1pagectrl.AddString(B1);
	this->m_1pagectrl.AddString(B2);
	this->m_1pagectrl.AddString(B3);
	this->m_1pagectrl.AddString(B4);
	 

	this->m_2pagectrl.AddString(C1);
	this->m_2pagectrl.AddString(C2);
	this->m_2pagectrl.AddString(C3);
	this->m_2pagectrl.AddString(C4);
	this->m_2pagectrl.AddString(C5);
 

	this->m_3pagectrl.AddString(D1);
	this->m_3pagectrl.AddString(D2);
	this->m_3pagectrl.AddString(D3);
	this->m_3pagectrl.AddString(D4);
	 

	this->m_5pagectrl.AddString(E1);
	this->m_5pagectrl.AddString(E2);

	if (editflag == 1){
		m_title= title;
		m_content=content;
		m_filename =filename;
		this->typenum2str(_ttoi(this->typenum));
		m_type0=valuestr[0];
		m_type1=valuestr[1];
		m_type2=valuestr[2];
		m_type3=valuestr[3];
		m_type4=valuestr[4];
		UpdateData(FALSE);
		CButton *bt=(CButton *)this->GetDlgItem(IDC_BUTTON2);
		bt->SetWindowText("编辑");



		return TRUE;
	}
	
	
	
	 
	return TRUE;
}

BEGIN_MESSAGE_MAP(CAddinfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddinfoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddinfoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddinfoDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CAddinfoDlg 消息处理程序


void CAddinfoDlg::OnBnClickedButton2()
{
	

	int typenum=0;
	CString a1;
	CString a2;
	CString a3;
    CString a4;
	CString a5;
	this->m_mainpagectrl.GetWindowText(a1);
	this->m_1pagectrl.GetWindowText(a2);
	this->m_2pagectrl.GetWindowText(a3);
	this->m_3pagectrl.GetWindowText(a4);
	this->m_5pagectrl.GetWindowText(a5);
		
	typenum = maketypenum(a1)+maketypenum(a2)+maketypenum(a3)+maketypenum(a4)+maketypenum(a5);
	char *tmpstr;
	if (this->editflag == 1){
		char sSQL4[255] = "update  contents set title='%s',content='%s',filename='%s',typenum=%d where id = %s;";
	    tmpstr = sSQL4;
	}else{
	    char sSQL4[255] = "insert into contents(title,content,filename,typenum) values('%s','%s','%s',%d);";
	    tmpstr = sSQL4;
	}
	char sSQL3[255];
	UpdateData(TRUE); 
	if (this->editflag == 1){
	   sprintf(sSQL3,tmpstr,this->m_title,this->m_content,this->m_filename,typenum,id);
	}else{
	   
	   sprintf(sSQL3,tmpstr,this->m_title,this->m_content,this->m_filename,typenum);
	}
	char * pErrMsg = 0;
	CLoginDlg *pDlg = (CLoginDlg *)this->GetParent()->GetParent();
	int ret =1;
	ret = sqlite3_exec(pDlg->db, sSQL3, NULL, 0, &pErrMsg);
	if (ret == 0){
		AfxMessageBox("成功");
	}else{
        AfxMessageBox("不成功");
	}
	CManageDlg *pMandlg=(CManageDlg *)this->GetParent();
	pMandlg->refreshlist();
}


void CAddinfoDlg::OnBnClickedButton1()
{
	CFileDialog dlg(TRUE,//TRUE是创建打开文件对话框，FALSE则创建的是保存文件对话框 
                    ".*",//默认的打开文件的类型 
                     NULL,//默认打开的文件名 
                     OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,//打开只读文件 
                     "文件(*.*)|*.*|所有文件 (*.*)|*.*||");//所有可以打开的文件类型 
   if(dlg.DoModal()==IDOK)   
   {
	   UpdateData(TRUE); 
	   CString m_FilePath = dlg.GetPathName();////////取出文件路径 
       CString  m_path; 
       m_filename=m_FilePath;//将文件的路径放入m_path 
       UpdateData(FALSE); 
   } 
}
void CAddinfoDlg::typenum2str(int typenum)
{
	
	char typenumstr[10]="";
	sprintf(typenumstr,"%d",typenum);
	switch (typenumstr[0])
	{
	case '1' :
      valuestr[0]=A1;
	  break;
	case '2':
	   valuestr[0]=A2;
	   break;
	case '3':
		valuestr[0]=A3;
		break;
	default:
		valuestr[0]="";
		break;
	}

	switch (typenumstr[1])
	{
	case '1' :
      valuestr[1]=B1;
	  break;
	case '2':
	   valuestr[1]=B2;
	   break;
	case '3':
		valuestr[1]=B3;
		break;
    case '4':
		valuestr[1]=B4;
		break;
	default:
		valuestr[1]="";
		break;
	}

	switch (typenumstr[2])
	{
	case '1' :
      valuestr[2]=C1;
	  break;
	case '2':
	   valuestr[2]=C2;
	   break;
	case '3':
		valuestr[2]=C3;
		break;
    case '4':
		valuestr[2]=C4;
		break;
    case '5':
		valuestr[2]=C5;
		break;
	default:
		valuestr[2]="";
		break;
	}

	switch (typenumstr[3])
	{
	case '1' :
      valuestr[3]=D1;
	  break;
	case '2':
	   valuestr[3]=D2;
	   break;
	case '3':
		valuestr[3]=D3;
		break;
    case '4':
		valuestr[3]=D4;
		break;
   	default:
		valuestr[3]="";
		break;
	}

	switch (typenumstr[4])
	{
	case '1' :
      valuestr[4]=E1;
	  break;
	case '2':
	   valuestr[4]=E2;
	   break;
	
   	default:
		valuestr[4]="";
		break;
	}

	return  ;
}
int  CAddinfoDlg::maketypenum(CString str)
{
	if (str == A1)  return 10000;
	if (str == A2)  return 20000;
	if (str == A3)  return 30000;

	if (str == B1)  return 1000;
	if (str == B2)  return 2000;
	if (str == B3)  return 3000;
	if (str == B4)  return 4000;

	if (str == C1)  return 100;
	if (str == C2)  return 200;
	if (str == C3)  return 300;
	if (str == C4)  return 400;
	if (str == C5)  return 500;

	if (str == D1)  return 10;
	if (str == D2)  return 20;
	if (str == D3)  return 30;
	if (str == D4)  return 40;

	if (str == E1)  return 1;
	if (str == E2)  return 2;


	return 0;

}

void CAddinfoDlg::OnBnClickedButton3()
{
	CDialogEx::OnCancel();
}
