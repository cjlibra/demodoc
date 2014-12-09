// MainDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demodoc.h"
#include "MainDlg.h"
#include "afxdialogex.h"


#include "FirstDlg.h"
#include "ContentListDlg.h"
#include "DirListCtrlDlg.h"
#include "FileListDlg.h"
 
#include "StartServer.h"

// CMainDlg �Ի���

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDlg::IDD, pParent)
	, m_editsearchtxt(_T(""))
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editsearchctrl);
	DDX_Text(pDX, IDC_EDIT1, m_editsearchtxt);
	//DDX_Control(pDX, IDC_EDIT2, m_edittitlectrl);
}
BOOL CMainDlg::OnInitDialog()
{
	//SipShowIM(SIPF_ON);
	CStartServer *pThread = new CStartServer();
	 
	if ( pThread == NULL )
		return FALSE;
	if (!pThread->CreateThread(CREATE_SUSPENDED))
	{
		delete pThread;
		return FALSE;
	}
	pThread->ResumeThread();

	ShowWindow(SW_MAXIMIZE);
	//CRect rect6(1110,168, 1671,228);//old huai�� pic
	CRect rect6(604,185,1161,254);
	
	
	imgfile = _T("res\\0.jpg");
	Show_picture(imgfile);

	CEdit *editp =(CEdit *) GetDlgItem(IDC_EDIT1);
	editp->MoveWindow(rect6.left*xScale , rect6.top*yScale, (rect6.right-rect6.left)*xScale,(rect6.bottom-rect6.top)*yScale );
	LOGFONT lf;     
       
	memset(&lf,0,sizeof(lf));   
	lf.lfHeight = 35;  //�ı��С  
	font.CreateFontIndirect(&lf) ;	
	editp->SetFont(&font,TRUE);
	
	CDialogEx::OnInitDialog();
	return TRUE; 
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CMainDlg::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMainDlg ��Ϣ�������


void CMainDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//AfxMessageBox(_T("up"));
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	//CRect rect1(1018, 478 ,  1112 ,507);
	CRect rect1(0 , 0,  100 ,100); //jieshu
	CRect rect2(485 , 604,  752 ,852); //mingchengdengji
	CRect rect3(869,625,1123,8490); //neizhidengji
	CRect rect4(1246,606, 1472,842); //waizhidengji
	CRect rect5(1166,186, 1346,254); //shousuoanniu
	CRect rect6(1110,168, 1671,228);//shurukuang

	if (true == isPointInRect(point,rect1)){
		CDialogEx::OnCancel();
	}
	if (true == isPointInRect(point,rect2)){
		/*
		CFirstDlg dlg;
		mynum = 10000;
		dlg.fromwherenum = mynum;
		dlg.DoModal();		
		*/
		CDirListCtrlDlg dlg;
		dlg.currdir = "�г��ල�����\\���ƵǼ�";
		dlg.DoModal();	
	}
	if (true == isPointInRect(point,rect3)){
		/*
		CFirstDlg dlg;
		mynum = 20000;
		dlg.fromwherenum = mynum;
		dlg.DoModal();		
		*/
		CDirListCtrlDlg dlg;
		dlg.currdir = "�г��ල�����\\���ʵǼ�";
		dlg.DoModal();	
	}
	if (true == isPointInRect(point,rect4)){
		/*
		CFirstDlg dlg;
		mynum = 30000;
		dlg.fromwherenum = mynum;
		dlg.DoModal();		
		*/
		CDirListCtrlDlg dlg;
		dlg.currdir = "�г��ල�����\\���ʵǼ�";
		dlg.DoModal();	
	}
	if (true == isPointInRect(point,rect5)){
		//CContentListDlg dlg;
		//mynum = 10000;
		//dlg.fromwherenum = mynum;
		//dlg.DoModal();		
	//	AfxMessageBox("û��������������ļ�");
		return;
		UpdateData(TRUE);
		CString str;
		CEdit *editp =(CEdit *) GetDlgItem(IDC_EDIT1);
		str = this->m_editsearchtxt;
		this->m_editsearchctrl.GetWindowText(this->m_editsearchtxt);
		SearchDir("�г��ල�����\\",&str);
	//	AfxMessageBox( searchdir+str);;
		CFileListDlg dlg;
		dlg.nowdir = searchdir;
	    dlg.filecount = 0;
		CFileFind finder;
		BOOL bWorking=finder.FindFile(searchdir+"*.*");
	    while(bWorking)
        {

			bWorking=finder.FindNextFile();
			if (finder.IsDots()){
				continue;
			}
			if (finder.IsDirectory()){
				 continue;

		  
			}else{
				dlg.filelistname[dlg.filecount]=finder.GetFileName();
				dlg.filecount++;
				 
			
			}
		
	   }
		dlg.dontflag = 99;
		dlg.DoModal();
	}
	
	CDialogEx::OnLButtonDown(nFlags, point);
}
int  CMainDlg:: SearchDir(char *path,CString *pstr)//ע�⣺���path������'\'��β
{
	HANDLE hFind;
	WIN32_FIND_DATA wfData;
	char FullPath[MAX_PATH];
	char subdir[MAX_PATH];

	//fprintf(fp,"Directory of %s\n", path);

	strcpy(FullPath,path);
	strcat(FullPath,"*.*");

	hFind = FindFirstFile(FullPath,&wfData);
	if(hFind == INVALID_HANDLE_VALUE)
	{
	   //fprintf(fp,"No file is found.\n");

	   return  1;
	}
	static int flag =0 ;
	
	do
	{
	   switch(wfData.dwFileAttributes)
	   {
	   case FILE_ATTRIBUTE_DIRECTORY://Ŀ¼
			if(strcmp(wfData.cFileName,".") && strcmp(wfData.cFileName,".."))//�ų���ǰĿ¼���ϼ�Ŀ¼
			{
			// fprintf(fp,"%s\t\t\t\t\tdirectory\n",wfData.cFileName);
			 sprintf(subdir,"%s%s\\",path,wfData.cFileName);
			 searchdir = subdir;
			 SearchDir(subdir,pstr);//�ݹ���ã����Ǳ����Ļ���
			}
			break;
	   default:
			//fprintf(fp,"\t%s\t\t\t\tfile\n",wfData.cFileName);
		    *pstr = wfData.cFileName;
			
			if ((*pstr).Find(this->m_editsearchtxt)> 0){
				flag = 1;
			}
		    break;
	   }
	}while(FindNextFile(hFind,&wfData)&&flag == 0);

	return 0;
}
bool CMainDlg::isPointInRect(CPoint point ,CRect rect)
{
	float a = xScale*rect.left;
	float b = yScale*rect.top;
	float c = xScale*rect.right;
	float d = yScale*rect.bottom;
	if (point.x > a &&  point.y> b  && point.x < c  && point.y< d){

		return true;
	}
	return false;
}

void CMainDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxMessageBox(_T("clcikbutton"));
}


bool CMainDlg::Show_picture(CString imgPath)
{
	int height, width;
	CRect rect;//���������
	CRect rect1;
	CImage image; //����ͼƬ��
	image.Load(imgPath);
	
	height = image.GetHeight();
	width = image.GetWidth();
	
	this->GetClientRect(&rect); //���pictrue�ؼ����ڵľ�������
	CDC *pDc = this->GetDC();//���pictrue�ؼ���Dc
	SetStretchBltMode(pDc->m_hDC,STRETCH_HALFTONE); 
	xScale=(float)rect.Width()/(float)width;
	yScale=(float)rect.Height()/(float)height;
	if(width<=rect.Width() && height<=rect.Width()) //СͼƬ��������
	{
	rect1 = CRect(rect.TopLeft(), CSize(width,height));
	image.StretchBlt(pDc->m_hDC,rect,SRCCOPY); //��ͼƬ����Picture�ؼ���ʾ�ľ�������
	return TRUE;
	}
	else
	{
	xScale=(float)rect.Width()/(float)width;
	yScale=(float)rect.Height()/(float)height;
	float ScaleIndex=(xScale<=yScale?xScale:yScale);
	rect1 = CRect(rect.TopLeft(), CSize((int)width*ScaleIndex,(int)height*ScaleIndex));
	image.StretchBlt(pDc->m_hDC,rect,SRCCOPY); //��ͼƬ����Picture�ؼ���ʾ�ľ�������
	}
	ReleaseDC(pDc);//�ͷ�picture�ؼ���Dc
	return TRUE;
}

void CMainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	Show_picture(imgfile);
}


HBRUSH CMainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	
	return hbr;
}
