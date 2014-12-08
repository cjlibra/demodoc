// DirListCtrlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "DirListCtrlDlg.h"
#include "afxdialogex.h"


#include "FileListDlg.h"


// CDirListCtrlDlg 对话框

IMPLEMENT_DYNAMIC(CDirListCtrlDlg, CDialogEx)

CDirListCtrlDlg::CDirListCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDirListCtrlDlg::IDD, pParent)
{

}

CDirListCtrlDlg::~CDirListCtrlDlg()
{
}


BOOL CDirListCtrlDlg::OnInitDialog()
{

    CDialogEx::OnInitDialog();

	ShowWindow(SW_MAXIMIZE);
	//CRect rect6(1110,168, 1671,228);
	
	 
	imgfile = _T("res\\4.jpg");
	Show_picture(imgfile);
	CRect rect(43*xScale,622*yScale,1807*xScale,835*yScale);
	//CRect rect(43*xScale,622*yScale,193*xScale,772*yScale);
	CFileFind finder;
	CString totoaldir = currdir+"\\*.*";
    BOOL bWorking=finder.FindFile(totoaldir);
	howmuchbutton=0;
	CString titlebutton[200];
	CFileListDlg dlg;
	dlg.nowdir = currdir;
	dlg.filecount = 0;
	int flagfile = 0;
    while(bWorking)
    {

		bWorking=finder.FindNextFile();
		if (finder.IsDots()){
			continue;
		}
		if (finder.IsDirectory()){
			titlebutton[howmuchbutton]=finder.GetFileName();
			howmuchbutton++;

		  
		}else{
			dlg.filelistname[dlg.filecount]=finder.GetFileName();
			dlg.filecount++;
			flagfile = 1;
			
		}
	}
	if (flagfile == 1){ 
		dlg.DoModal();
		CDialogEx::OnCancel();
		return TRUE;

	}
	int width = rect.right-rect.left;
	int seperate = width/(howmuchbutton+1);
	CRect rect1(rect.left+seperate-150,rect.top,rect.left+seperate,rect.top+150);
	LOGFONT lf;      /*
	lf.lfCharSet = GB2312_CHARSET;
	lf.lfQuality = PROOF_QUALITY ;
	lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
	lf.lfWeight = 1000;
	memset(&lf,0,sizeof(lf));
	CFont *font1;
	font1 = this->GetFont();
	font1->*/
	lf=*(LOGFONT*)this->GetFont();
	lf.lfHeight = 20;//改变大小  
	
	font.CreateFontIndirect(&lf) ;	
	
	for (int i=0;i<howmuchbutton;i++){
		bt=new CBitmapButton;
		if (howmuchbutton >3 ){
			    rect1.left = rect.left+seperate*(i+1)-150;
			}else{
				rect1.left = rect.left+seperate*(i+1)-250;
			}
		rect1.top = rect.top;
		rect1.right = rect.left+seperate*(i+1);
		rect1.bottom = rect.top+150;
		 
		//bt->Create(titlebutton[i],WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,rect1,this,IDC_BUTTON1);
		bt->Create(titlebutton[i],WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect1,this,IDC_BUTTON1);
		//bt->LoadBitmaps(IDB_BEIAN);
		SwitchBmp(titlebutton[i],bt);
		//bbt.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect1,this,IDC_BUTTON1);
//		bbt.SubclassDlgItem(IDC_BUTTON1,this);
		//bbt.AutoLoad(IDR_IDB_AAA_UP1,this);
		//bt->LoadBitmaps(IDR_IDB_AAA_UP1,IDR_IDB_AAA_UP1,IDR_IDB_AAA_UP1,IDR_IDB_AAA_UP1);
		//bbt.ShowWindow(1);
 		bt->SizeToContent();
		//bbt.MoveWindow(rect1);
		
		//bbt.ShowWindow(1);
		//break;
// 		bbt.SizeToContent();
		/*
		CDC* pDC=bt->GetDC();
		CRect rc;
		bt->GetClientRect(&rc);

		CBrush brush;
		brush.CreateSolidBrush(RGB(0,250,250));
		pDC->FillRect(&rc,&brush);

		pDC->SetBkColor(RGB(0,0,255));
		pDC->SetTextColor(RGB(0,120,0));
		*/
		bt->SetFont(this->GetFont(),TRUE);
		p[i]=bt;
	}

	CRect rect_1(34,159,1255,202);
	this->m_edittitlectrl.MoveWindow(rect_1.left*xScale,rect_1.top*yScale,rect_1.right*xScale,rect_1.bottom*yScale);;
	//this->m_edittitlectrl.SetWindowTextA(this->nowdir);
	CString tmp1 = this->currdir;
	tmp1.Replace("\\"," >>> ");
	this->SetDlgItemText(IDC_EDIT1,tmp1);

	return TRUE;

}

void CDirListCtrlDlg::SwitchBmp(CString str  ,CBitmapButton *pBton)
{
	if (str == "备案") 
	{
		pBton->LoadBitmaps(IDB_BEIAN);
		return;
	}
	if (str == "变更") 
	{
		pBton->LoadBitmaps(IDB_BIANGENG);
		return;
	}
	if (str == "合资有限公司") 
	{
		pBton->LoadBitmaps(IDB_BITMAP13);
		return;
	}
	if (str == "经理") 
	{
		pBton->LoadBitmaps(IDB_BITMAP14);
		return;
	}
	if (str == "监事") 
	{
		pBton->LoadBitmaps(IDB_BITMAP15);
		return;
	}
	if (str == "减资") 
	{
		pBton->LoadBitmaps(IDB_BITMAP16);
		return;
	}
	if (str == "类型互变") 
	{
		pBton->LoadBitmaps(IDB_BITMAP17);
		return;
	}
	if (str == "其他") 
	{
		pBton->LoadBitmaps(IDB_BITMAP25);
		return;
	}
	if (str == "清算组") 
	{
		pBton->LoadBitmaps(IDB_BITMAP19);
		return;
	}
	if (str == "表格") 
	{
		pBton->LoadBitmaps(IDB_BITMAP2);
		return;
	}
	if (str == "开业") 
	{
		pBton->LoadBitmaps(IDB_BITMAP20);
		return;
	}
	if (str == "公司") 
	{
		pBton->LoadBitmaps(IDB_BITMAP21);
		return;
	}
	if (str == "个人独资企业") 
	{
		pBton->LoadBitmaps(IDB_BITMAP22);
		return;
	}
	if (str == "合伙企业") 
	{
		pBton->LoadBitmaps(IDB_BITMAP23);
		return;
	}
	if (str == "非公司企业法人") 
	{
		pBton->LoadBitmaps(IDB_BITMAP24);
		return;
	}
	if (str == "其他") 
	{
		pBton->LoadBitmaps(IDB_BITMAP18);
		return;
	}
	if (str == "样张") 
	{
		pBton->LoadBitmaps(IDB_BITMAP26);
		return;
	}
	if (str == "一人") 
	{
		pBton->LoadBitmaps(IDB_BITMAP27);
		return;
	}
	if (str == "一人有限公司") 
	{
		pBton->LoadBitmaps(IDB_BITMAP28);
		return;
	}
	if (str == "章程") 
	{
		pBton->LoadBitmaps(IDB_BITMAP29);
		return;
	}
	if (str == "董事") 
	{
		pBton->LoadBitmaps(IDB_BITMAP3);
		return;
	}
	if (str == "注销") 
	{
		pBton->LoadBitmaps(IDB_BITMAP30);
		return;
	}
	if (str == "增资") 
	{
		pBton->LoadBitmaps(IDB_BITMAP31);
		return;
	}
	if (str == "法定代表") 
	{
		pBton->LoadBitmaps(IDB_BITMAP4);
		return;
	}
	if (str == "股东") 
	{
		pBton->LoadBitmaps(IDB_BITMAP5);
		return;
	}
	if (str == "个人独资企业") 
	{
		pBton->LoadBitmaps(IDB_BITMAP6);
		return;
	}
	if (str == "个人独资企业") 
	{
		pBton->LoadBitmaps(IDB_BITMAP7);
		return;
	}
	if (str == "公司") 
	{
		pBton->LoadBitmaps(IDB_BITMAP8);
		return;
	}
	if (str == "公司范本") 
	{
		pBton->LoadBitmaps(IDB_BITMAP9);
		return;
	}
		if (str == "范本") 
	{
		pBton->LoadBitmaps(IDB_BITMAP9);
		return;
	}
	if (str == "材料") 
	{
		pBton->LoadBitmaps(IDB_BITMAP10);
		return;
	}
	
	if (str == "合伙企业") 
	{
		pBton->LoadBitmaps(IDB_HEHUOQIYE);
		return;
	}
	if (str == "合资") 
	{
		pBton->LoadBitmaps(IDB_HEYIGONGSI);
		return;
	}
	if (str == "合伙企业") 
	{
		pBton->LoadBitmaps(IDB_NEIHEHUOQIYE);
		return;
	}
	pBton->LoadBitmaps(IDB_DEFAULT1);


}
void CDirListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edittitlectrl);
}


BEGIN_MESSAGE_MAP(CDirListCtrlDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDirListCtrlDlg::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDirListCtrlDlg 消息处理程序


void CDirListCtrlDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	GetDlgItem(IDC_BUTTON1)->GetWindowText(str);
	
	const MSG* pMsg= GetCurrentMessage();
	int i=0;
	int oldbuttonnum = howmuchbutton;
	for (i;i<this->howmuchbutton;i++){
		if (HWND(pMsg->lParam) == p[i]->m_hWnd){
			p[i]->GetWindowText(str);
			break;
			 

		}

	}

	CRect rect(43*xScale,622*yScale,1807*xScale,835*yScale);
	CFileFind finder;
	
	totoaldir =currdir+"\\"+str;
	
	
    BOOL bWorking=finder.FindFile(totoaldir+"\\*.*");
    howmuchbutton=0;
	CString titlebutton[200];
	CFileListDlg dlg;
	dlg.nowdir = totoaldir;
	dlg.filecount = 0;
	int flagfile = 0;
    while(bWorking)
    {

		bWorking=finder.FindNextFile();
		if (finder.IsDots()){
			continue;
		}
		if (finder.IsDirectory()){
			titlebutton[howmuchbutton]=finder.GetFileName();
			howmuchbutton++;

		  
		}else{
			dlg.filelistname[dlg.filecount]=finder.GetFileName();
			dlg.filecount++;
			flagfile = 1;
			
		}
		
	}
	if (flagfile == 1) {
		this->howmuchbutton = oldbuttonnum;
		dlg.DoModal();
		return;
	}
	for (i=0;i< oldbuttonnum;i++){
	 
			p[i]->ShowWindow(0);
			p[i]->EnableWindow(0);
			p[i]->CloseWindow();
			//delete  p[i];
		 
	}
	prevdir =currdir;
	this->currdir = totoaldir;
	
	int width = rect.right-rect.left;
	int seperate = width/(howmuchbutton+1);
	CRect rect1(rect.left+seperate-150,rect.top,rect.left+seperate,rect.top+150);
	 
	
	for (int i=0;i<howmuchbutton;i++){
		bt=new CBitmapButton;
		if (howmuchbutton >3 ){
			    rect1.left = rect.left+seperate*(i+1)-150;
			}else{
				rect1.left = rect.left+seperate*(i+1)-250;
			}
		rect1.top = rect.top;
		rect1.right = rect.left+seperate*(i+1);
		rect1.bottom = rect.top+150;
		//bt->Create(titlebutton[i],WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,rect1,this,IDC_BUTTON1);
		bt->Create(titlebutton[i],WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect1,this,IDC_BUTTON1);
		
		this->SwitchBmp(titlebutton[i],bt);
		bt->SizeToContent();
		bt->SetFont(this->GetFont(),TRUE);
		p[i]=bt;
	}
	//CRect rect_1(34,159,855,202);
	//this->m_edittitlectrl.MoveWindow(rect_1.left*xScale,rect_1.top*yScale,rect_1.right*xScale,rect_1.bottom*yScale);;
	//this->m_edittitlectrl.SetWindowTextA(this->nowdir);
	CString tmp1 = this->currdir;
	tmp1.Replace("\\"," >>> ");
	this->SetDlgItemText(IDC_EDIT1,tmp1);
}



bool CDirListCtrlDlg::Show_picture(CString imgPath)
{
	int height, width;
	CRect rect;//定义矩形类
	CRect rect1;
	CImage image; //创建图片类
	image.Load(imgPath);
	
	height = image.GetHeight();
	width = image.GetWidth();
	
	this->GetClientRect(&rect); //获得pictrue控件所在的矩形区域
	CDC *pDc = this->GetDC();//获得pictrue控件的Dc
	SetStretchBltMode(pDc->m_hDC,STRETCH_HALFTONE); 
	xScale=(float)rect.Width()/(float)width;
	yScale=(float)rect.Height()/(float)height;
	if(width<=rect.Width() && height<=rect.Width()) //小图片，不缩放
	{
	rect1 = CRect(rect.TopLeft(), CSize(width,height));
	image.StretchBlt(pDc->m_hDC,rect,SRCCOPY); //将图片画到Picture控件表示的矩形区域
	return TRUE;
	}
	else
	{
	xScale=(float)rect.Width()/(float)width;
	yScale=(float)rect.Height()/(float)height;
	float ScaleIndex=(xScale<=yScale?xScale:yScale);
	rect1 = CRect(rect.TopLeft(), CSize((int)width*ScaleIndex,(int)height*ScaleIndex));
	image.StretchBlt(pDc->m_hDC,rect,SRCCOPY); //将图片画到Picture控件表示的矩形区域
	}
	ReleaseDC(pDc);//释放picture控件的Dc
	return TRUE;
}

void CDirListCtrlDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	Show_picture(imgfile);

	 
	 
	
}
void CDirListCtrlDlg::OnMyCancel()
{
	CDialogEx::OnCancel();

}

void CDirListCtrlDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	 
	CRect rect5(1422,134,1650,201);//fanshangye
	CRect rect6(1666,139,1860,201);//jieshu
	if (true == isPointInRect(point,rect6)){
		
		this->OnCancel();
	}
	if (true == isPointInRect(point,rect5)){

		
		for (int i=0;i<this->howmuchbutton;i++){
	 
				p[i]->ShowWindow(0);
				p[i]->EnableWindow(0);
				p[i]->CloseWindow();
				//delete  p[i];
		 
		}
		CRect rect(43*xScale,622*yScale,1807*xScale,835*yScale);
		CFileFind finder;
		CString totoaldir = prevdir+"\\*.*";
		this->currdir = prevdir;
		if  (-1 == prevdir.Find("\\")){
			this->OnCancel();
			return;

		}
		int nindex2 = currdir.ReverseFind('\\') ;
		prevdir =currdir.Left(nindex2);

		
		BOOL bWorking=finder.FindFile(totoaldir);
		howmuchbutton=0;
		CString titlebutton[200];
		while(bWorking)
		{

			bWorking=finder.FindNextFile();
			if (finder.IsDots()){
				continue;
			}
			if (finder.IsDirectory()){
				titlebutton[howmuchbutton]=finder.GetFileName();
				howmuchbutton++;

		  
			}
		}
		int width = rect.right-rect.left;
		int seperate = width/(howmuchbutton+1);
		CRect rect1(rect.left+seperate-150,rect.top,rect.left+seperate,rect.top+150);
	 
	
		for (int i=0;i<howmuchbutton;i++){
			bt=new CBitmapButton;
			if (howmuchbutton >3 ){
			    rect1.left = rect.left+seperate*(i+1)-150;
			}else{
				rect1.left = rect.left+seperate*(i+1)-250;
			}
			rect1.top = rect.top;
			rect1.right = rect.left+seperate*(i+1);
			rect1.bottom = rect.top+150;

			//bt->Create(titlebutton[i],WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,rect1,this,IDC_BUTTON1);
			bt->Create(titlebutton[i],WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,rect1,this,IDC_BUTTON1);
			SwitchBmp(titlebutton[i],bt);
			bt->SizeToContent();
			bt->SetFont(this->GetFont(),TRUE);
			 
			p[i]=bt;
		}
		CRect rect_1(34,159,855,202);
		this->m_edittitlectrl.MoveWindow(rect_1.left*xScale,rect_1.top*yScale,rect_1.right*xScale,rect_1.bottom*yScale);;
		//this->m_edittitlectrl.SetWindowTextA(this->nowdir);
		CString tmp1 = this->currdir;
		tmp1.Replace("\\"," >>> ");
		this->SetDlgItemText(IDC_EDIT1,tmp1);
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}
bool CDirListCtrlDlg::isPointInRect(CPoint point ,CRect rect)
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

HBRUSH CDirListCtrlDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔

	

   // Are we painting the IDC_MYSTATIC control? We can use
   // CWnd::GetDlgCtrlID() to perform the most efficient test.
   if (pWnd->GetDlgCtrlID() == IDC_BUTTON1)//请注意：只有IDC_MYSTATIC才可能受影响
   {
      // Set the text color to red
      pDC->SetTextColor(RGB(255, 0, 0));
	  pDC->SetTextColor(RGB(255,22,3));//前景文本色
      pDC->SetBkColor(RGB(255,255,0));//背景色

      // Set the background mode for text to transparent 
      // so background will show thru.
      pDC->SetBkMode(TRANSPARENT);

      // Return handle to our CBrush object
     // hbr = pDC->m_bm_brush;
   }
	return hbr;
}
