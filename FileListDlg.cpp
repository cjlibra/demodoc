// FileListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demodoc.h"
#include "FileListDlg.h"
#include "afxdialogex.h"

#include "DirListCtrlDlg.h"
#include "PdfViewDlg.h"

#include "Dlgdlg.h"
// CFileListDlg �Ի���

IMPLEMENT_DYNAMIC(CFileListDlg, CDialogEx)

CFileListDlg::CFileListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileListDlg::IDD, pParent)
	, m_stitle(_T(""))
{

}

CFileListDlg::~CFileListDlg()
{

	for (int i=0;i<nCount;i++){
//		delete pbt1[i];
//		delete pbt2[i];
	}
}

void CFileListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_filelistctrl);
	DDX_Control(pDX, IDC_BUTTON1, m_copybton);
	DDX_Control(pDX, IDC_BUTTON2, m_viewbton);
	DDX_Control(pDX, IDC_EDIT1, m_edittitlectrl);
	DDX_Text(pDX, IDC_STATICTITLE, m_stitle);
	DDX_Control(pDX, IDC_STATICTITLE, m_stitlectrl);
	DDX_Control(pDX, IDC_EDIT3, m_txtsctrl);
}
BOOL CFileListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ShowWindow(SW_MAXIMIZE);
	
	imgfile = _T("res\\6.jpg");
	Show_picture(imgfile);
	
	//CRect rect1(50,246,1804,699);//file list
	//CRect rect2(rect1.left*xScale,rect1.top*yScale,rect1.right*xScale,rect1.bottom*yScale);

	//CRect rect3(807,736,910,834); //xia zai anniu
	//CRect rect3_1(rect3.left*xScale,rect3.top*yScale,rect3.right*xScale,rect3.bottom*yScale);
	//CRect rect3_2(rect3_1.left+150,rect3_1.top,rect3_1.right+150,rect3_1.bottom);
	//this->m_filelistctrl.MoveWindow(rect2);


	CRect rect4(530,338,1398,399); //��tiitle
	CRect rect4_1(rect4.left*xScale,rect4.top*yScale,rect4.right*xScale,rect4.bottom*yScale);
	m_stitle = this->nowdir+"�����嵥";
	int n = m_stitle.ReverseFind('\\');
	this->m_stitlectrl.MoveWindow(rect4_1);
	this->m_stitlectrl.SetWindowText(m_stitle.Right(m_stitle.GetLength()-n-1));

	CRect rect5(111,445,1799,1317);//�ļ��б��
	CRect rect5_1(rect5.left*xScale,rect5.top*yScale,rect5.right*xScale,rect5.bottom*yScale);
	m_filelistctrl.MoveWindow(rect5_1);
	m_filelistctrl.InsertColumn(0,"���",LVCFMT_CENTER,100);
	m_filelistctrl.InsertColumn(1,"�ύ�ļ�",LVCFMT_CENTER,700);
	m_filelistctrl.InsertColumn(2,"˵��",LVCFMT_CENTER,200);
	m_filelistctrl.InsertColumn(2,"����",LVCFMT_CENTER,200);

	CRect rect6(109,1356,1824,2127);
	CRect rect6_1(rect6.left*xScale,rect6.top*yScale,rect6.right*xScale,rect6.bottom*yScale);
	this->m_txtsctrl.MoveWindow(rect6_1);
	CFile file;
	if(file.Open( this->nowdir+"\\"+"�ύ����˵��.txt",CFile::modeRead ,NULL)) {
		char *readbuf;
		int nNum = file.GetLength()+1;
		readbuf = new char [nNum ];
		memset(readbuf,0,nNum);
		file.Read(readbuf,nNum);
		this->m_txtsctrl.SetWindowText(readbuf);
		file.Close();
		delete readbuf;

	}
	//bbt.SubclassDlgItem(IDC_BUTTON1,this);
		//bbt.AutoLoad(IDR_IDB_AAA_UP1,this);
		//bt->LoadBitmaps(IDR_IDB_AAA_UP1,IDR_IDB_AAA_UP1,IDR_IDB_AAA_UP1,IDR_IDB_AAA_UP1);
		//bbt.ShowWindow(1);
 	//	bt->SizeToContent();
	//if (this->m_copybton.GetBitmap() == NULL)
    // this->m_copybton.SetBitmap(::LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_IDB_AAA_UP1)));
	//this->m_copybton.LoadBitmaps(IDR_IDB_AAA_UP1);//,IDR_IDB_AAA_UP1,IDR_IDB_AAA_UP1,IDR_IDB_AAA_UP1);
//	this->m_copybton.SubclassDlgItem(IDC_BUTTON1,this);
	//this->m_copybton.SizeToContent();
	//bool ret = bitmap.LoadBitmap(MAKEINTRESOURCE(IDR_IDB_AAA_UP1));
    //this->m_copybton.SetBitmap((HBITMAP)bitmap);
	//CRect rect_b;
	//m_filelistctrl.GetSubItemRect(1,3,LVIR_BOUNDS,rect_b);
	////m_filelistctrl.ClientToScreen(rect_b);
	//this->m_copybton.SetParent(&m_filelistctrl);
	//CRect rect_b1(rect_b.left,rect_b.top,rect_b.right-(rect_b.right-rect_b.left)/2-5, rect_b.bottom);
	//this->m_copybton.MoveWindow(rect_b1);

	//this->m_viewbton.SetParent(&m_filelistctrl);
	//CRect rect_b2(rect_b.left+(rect_b.right-rect_b.left)/2+5,rect_b.top,rect_b.right, rect_b.bottom);
	//this->m_viewbton.MoveWindow(rect_b2);

	this->m_viewbton.SetParent(&m_filelistctrl);
	this->m_copybton.SetParent(&m_filelistctrl);

	//HBITMAP hBitmap1 = ::LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_DOWNLOAD1));
//	this->m_copybton.LoadBitmaps( MAKEINTRESOURCE(IDB_DOWNLOAD1));
//	this->m_copybton.SizeToContent();
	//this->m_copybton.SetBitmap(hBitmap1);
	//HBITMAP hBitmap2 = ::LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_VIEWPDF1));
	//this->m_viewbton.SetBitmap(hBitmap2);
//	this->m_viewbton.LoadBitmaps( MAKEINTRESOURCE(IDB_VIEWPDF1));
	//this->m_viewbton.SizeToContent();

	LOGFONT lf;     
       
	memset(&lf,0,sizeof(lf));   
	
	//font.CreateFontIndirect(&lf) ;	

	CFont* font2 = this->GetFont();  
    if (font2){
		font2->GetLogFont(&lf);   // ����ȡ��LOGFONT�ṹ
		 // ��������  lf2.lfFaceName  �
     }
	lf.lfHeight = 20;  //�ı��С  
	font.CreateFontIndirect(&lf) ;	
	CString subfilename[4];
	this->m_filelistctrl.SetFont(&font,TRUE);
	this->m_filelistctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT );
//	int n = this->m_filelistctrl.GetItemHeight(0);
	
	for (int i=0;i<this->filecount;i++){
		CString tmpstr=	this->filelistname[i];
		if (tmpstr.Right(4) == ".set"){
			tmpstr.Replace("."," ");
			AfxExtractSubString(subfilename[0], (LPCTSTR)tmpstr, 0, ' ');
			AfxExtractSubString(subfilename[1], (LPCTSTR)tmpstr, 1, ' ');
			AfxExtractSubString(subfilename[2], (LPCTSTR)tmpstr, 2, ' ');
			AfxExtractSubString(subfilename[3], (LPCTSTR)tmpstr, 3, ' ');
	//		this->m_filelistctrl.SetItemHeight(i,n+11);
			this->m_filelistctrl.InsertItem(i,subfilename[0]);
			this->m_filelistctrl.SetItemText(i,1,subfilename[1]);
			this->m_filelistctrl.SetItemText(i,2,subfilename[2]);
			//this->m_filelistctrl.SetItemText(i,3,subfilename[3]);
		}
		
	}
	CButton *bt1 ;
	CButton *bt2 ;
	
	//bt->Create(titlebutton[i],WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,rect1,this,IDC_BUTTON1);
	int nhang = this->m_filelistctrl.GetItemCount();
	CRect rect_b;
	for (int i=0;i<nhang;i++){
		m_filelistctrl.GetSubItemRect(i,3,LVIR_BOUNDS,rect_b);
		bt1 = new CButton;
		bt2 = new CButton;
		bt1 ->Create("����",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,rect_b,&m_filelistctrl,IDC_BUTTON1);
		bt2 ->Create("Ԥ��",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,rect_b,&m_filelistctrl,IDC_BUTTON2);
		pbt1[i]=bt1;
		pbt2[i]=bt2;
		nCount = i;
		  
        CString str;
	    str = m_filelistctrl.GetItemText(i,1);
						 
    
		CFile file;
		CString currentdir = this->nowdir;
		if(file.Open(currentdir+"\\"+str+".pdf",CFile::modeRead)){
			bt2->EnableWindow(1);
			file.Close();
		}else{ 
			bt2->EnableWindow(0);
		}
	 
		if(file.Open(currentdir+"\\"+str+".doc",CFile::modeRead)){
			bt1->EnableWindow(1);
			file.Close();
		}else{ 
			bt1->EnableWindow(0);
		}

		CRect rect_b;
		m_filelistctrl.GetSubItemRect(i,3,LVIR_BOUNDS,rect_b);
		//m_filelistctrl.ClientToScreen(rect_b);
		//this->m_copybton.SetParent(&m_filelistctrl);
		CRect rect_b1(rect_b.left,rect_b.top+1,rect_b.right-(rect_b.right-rect_b.left)/2-5, rect_b.bottom-1);
		bt1->MoveWindow(rect_b1);
		bt1->ShowWindow(1);

		//this->m_viewbton.SetParent(&m_filelistctrl);
		CRect rect_b2(rect_b.left+(rect_b.right-rect_b.left)/2+5,rect_b.top+1,rect_b.right, rect_b.bottom-1);
		bt2->MoveWindow(rect_b2);
		bt2->ShowWindow(1);

	}
	
	CRect rect_1(34,140,1255,160); //̧ͷ����ʾĿ¼�ṹ
	this->m_edittitlectrl.MoveWindow(rect_1.left*xScale,rect_1.top*yScale,rect_1.right*xScale,rect_1.bottom*yScale-20);;
	 
	//this->m_edittitlectrl.SetWindowTextA(this->nowdir);
	CString tmp1 = this->nowdir;
	tmp1.Replace("\\"," >>> ");
	//this->m_edittitlectrl.SetFont(&font);
	//this->m_edittitlectrl.SetReadOnly();
    this->SetDlgItemText(IDC_EDIT1,tmp1);


	 

	return TRUE; 

}

BEGIN_MESSAGE_MAP(CFileListDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CFileListDlg::OnBnClickedButton2)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_LBN_SETFOCUS(IDC_LIST1, &CFileListDlg::OnLbnSetfocusList1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CFileListDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CFileListDlg::OnBnClickedButton1)
	
	ON_NOTIFY(LVN_ITEMCHANGING, IDC_LIST2, &CFileListDlg::OnLvnItemchangingList2)
END_MESSAGE_MAP()


// CFileListDlg ��Ϣ�������


void CFileListDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int isel;
	isel = this->m_filelistctrl.GetSelectedCount();;
 
	 
	if (isel <= 0) {
		AfxMessageBox("��ѡ���ļ�");
		return;
	}

	POSITION pos = this->m_filelistctrl.GetFirstSelectedItemPosition();
	CString str;
	if (pos == NULL){
	   TRACE0("No items were selected!\n");
	    AfxMessageBox("��ѡ���ļ�");
		return;
	}
	else
	{
	   while (pos)
	   {
		  int nItem = this->m_filelistctrl.GetNextSelectedItem(pos);
		  str =  this->m_filelistctrl.GetItemText(nItem,1);
		   
		  
	   }
	}
	
	 
	CString pdffile = nowdir+"\\"+str+".pdf";
	//::ShellExecute(this->m_hWnd,"open",pdffile,"","",SW_SHOW);
	CPdfViewDlg dlg1;
	//CDlgdlg dlg1;
 	dlg1.m_pdfname = pdffile;
	dlg1.DoModal();
	
}


bool CFileListDlg::Show_picture(CString imgPath)
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

void CFileListDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	Show_picture(imgfile);
	m_filelistctrl.ShowWindow(1);
	CDialogEx::OnPaint();
}


void CFileListDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CRect rect1(1426,137,1649,263); //tuiqianye
	CRect rect2(1663,143,1860,200);//fanshouye
	if (true == isPointInRect(point,rect1)){
		 
		this->OnCancel();

	}
	if (true == isPointInRect(point,rect2)){
		CDirListCtrlDlg *p;
		p = (CDirListCtrlDlg *)this->GetParent();
		if (this->dontflag != 99){
		  p->OnMyCancel();
		}
		this->OnCancel();
		//p->CloseWindow();

	}

	CDialogEx::OnLButtonDown(nFlags, point);
}



bool CFileListDlg::isPointInRect(CPoint point ,CRect rect)
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

void CFileListDlg::OnLbnSetfocusList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}


void CFileListDlg::OnLbnSelchangeList1()
{
	 
	



}


void CFileListDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString currentdir = this->nowdir;
	CString selfilename;
	CString uDisk;
	int isel;
	isel = this->m_filelistctrl.GetSelectedCount();
	if (isel <= 0) {
		AfxMessageBox("��ѡ���ļ�");
		return;
	}
    POSITION pos = this->m_filelistctrl.GetFirstSelectedItemPosition();
	CString str;
	if (pos == NULL){
	   TRACE0("No items were selected!\n");
	    AfxMessageBox("��ѡ���ļ�");
		return;
	}
	else
	{
	   while (pos)
	   {
		  int nItem = this->m_filelistctrl.GetNextSelectedItem(pos);
		  selfilename =  this->m_filelistctrl.GetItemText(nItem,1);
		   
		  
	   }
	}
	 AfxMessageBox("�����U�̺��ȷ����ť");
	 UINT DiskType;  
	size_t   szAllDriveStrings   =   GetLogicalDriveStrings(0,NULL);     
	char   *pDriveStrings   =   new   char[szAllDriveStrings   +   sizeof(_T( " "))];     
	GetLogicalDriveStrings(szAllDriveStrings,pDriveStrings);     
	size_t   szDriveString   =   strlen(pDriveStrings);  
	int flagudisk = 0;
	while(szDriveString   >   0)     
	{     
		//AfxMessageBox(pDriveStrings);     
		DiskType=GetDriveType(pDriveStrings);     
		switch(DiskType)       
		{     
			case   DRIVE_NO_ROOT_DIR:     
			return;     
			case   DRIVE_REMOVABLE:     
			//::AfxMessageBox( "�ƶ��洢�豸 ");     
			uDisk = pDriveStrings;
			flagudisk = 1;
			break;     
			case   DRIVE_FIXED:     
			//::AfxMessageBox( "�̶�Ӳ�������� ");     
			break;     
			case   DRIVE_REMOTE:     
			//::AfxMessageBox( "�������������� ");     
			break;    
			case   DRIVE_CDROM:     
			//::AfxMessageBox( "���ǹ��������� ");     
			break;  
     
		}  
    
		pDriveStrings   +=   szDriveString   +   1;     
		szDriveString   =   strlen(pDriveStrings);     
	}   
//	delete pDriveStrings; 

	if  ( flagudisk != 1){
        AfxMessageBox("û���ҵ�u��");
		return;
	}
	if (true == ::CopyFile(currentdir+"\\"+selfilename+".doc",uDisk+selfilename+".doc",false)){
		AfxMessageBox("���سɹ�");
	}else{
		AfxMessageBox("���س���");
	}


}


BOOL CFileListDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_LBUTTONUP && GetWindowLong(pMsg->hwnd,GWL_ID)==IDC_BUTTON1) 
	{
	//�Լ�����ť����¼���Ӧ
		OnBnClickedButton1();
	}

	if(pMsg->message==WM_LBUTTONUP && GetWindowLong(pMsg->hwnd,GWL_ID)==IDC_BUTTON2) 
	{
	//�Լ�����ť����¼���Ӧ
		OnBnClickedButton2();
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CFileListDlg::OnLvnItemchangingList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	*pResult = 0;
	return;
	 
	 NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	 if(pNMListView->uChanged == LVIF_STATE)
     {
        if(pNMListView->uNewState)
        {
               int nIndex = pNMListView->iItem;
               CString str;
			   str = m_filelistctrl.GetItemText(nIndex,1);
						 
    
				CFile file;
				CString currentdir = this->nowdir;
				if(file.Open(currentdir+"\\"+str+".pdf",CFile::modeRead)){
					this->m_viewbton.EnableWindow(1);
					file.Close();
				}else{ 
					this->m_viewbton.EnableWindow(0);
				}
	 
				if(file.Open(currentdir+"\\"+str+".doc",CFile::modeRead)){
					this->m_copybton.EnableWindow(1);
					file.Close();
				}else{ 
					this->m_copybton.EnableWindow(0);
				}

				CRect rect_b;
				m_filelistctrl.GetSubItemRect(nIndex,3,LVIR_BOUNDS,rect_b);
				//m_filelistctrl.ClientToScreen(rect_b);
				//this->m_copybton.SetParent(&m_filelistctrl);
				CRect rect_b1(rect_b.left,rect_b.top+1,rect_b.right-(rect_b.right-rect_b.left)/2-5, rect_b.bottom-1);
				this->m_copybton.MoveWindow(rect_b1);
				this->m_copybton.ShowWindow(1);

				//this->m_viewbton.SetParent(&m_filelistctrl);
				CRect rect_b2(rect_b.left+(rect_b.right-rect_b.left)/2+5,rect_b.top+1,rect_b.right, rect_b.bottom-1);
				this->m_viewbton.MoveWindow(rect_b2);
				this->m_viewbton.ShowWindow(1);
		}
     }
	*pResult = 0;
}
