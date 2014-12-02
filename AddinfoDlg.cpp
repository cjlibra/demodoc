// AddinfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demodoc.h"
#include "AddinfoDlg.h"
#include "afxdialogex.h"

#include "sqlite3.h"
#include "LoginDlg.h"
#include "ManageDlg.h"
// CAddinfoDlg �Ի���

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
	A1="���ƵǼ�";
	A2="���ʵǼ�";
	A3="���ʵǼ�";

	B4="�ǹ�˾��ҵ����";
	B3="�ϻ���ҵ";
	B2="���˶�����ҵ";
	B1="��˾";

	C5="ע��";
	C4="���ͻ���";
	C3="����";
	C2="���";
	C1="��ҵ";

	D4="��������";
	D3="��������";
	D2="�������";
	D1="����ָ��";

	E2="�������޹�˾";
	E1="һ�����޹�˾";
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
		bt->SetWindowText("�༭");



		return TRUE;
	}
	
	
	
	 
	return TRUE;
}

BEGIN_MESSAGE_MAP(CAddinfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddinfoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddinfoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddinfoDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CAddinfoDlg ��Ϣ�������


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
		AfxMessageBox("�ɹ�");
	}else{
        AfxMessageBox("���ɹ�");
	}
	CManageDlg *pMandlg=(CManageDlg *)this->GetParent();
	pMandlg->refreshlist();
}


void CAddinfoDlg::OnBnClickedButton1()
{
	CFileDialog dlg(TRUE,//TRUE�Ǵ������ļ��Ի���FALSE�򴴽����Ǳ����ļ��Ի��� 
                    ".*",//Ĭ�ϵĴ��ļ������� 
                     NULL,//Ĭ�ϴ򿪵��ļ��� 
                     OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,//��ֻ���ļ� 
                     "�ļ�(*.*)|*.*|�����ļ� (*.*)|*.*||");//���п��Դ򿪵��ļ����� 
   if(dlg.DoModal()==IDOK)   
   {
	   UpdateData(TRUE); 
	   CString m_FilePath = dlg.GetPathName();////////ȡ���ļ�·�� 
       CString  m_path; 
       m_filename=m_FilePath;//���ļ���·������m_path 
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
