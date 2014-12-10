// WebFilelistDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demodoc.h"
#include "WebFilelistDlg.h"
#include "afxdialogex.h"

#include "PdfViewDlg.h"
#include "DirListCtrlDlg.h"

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
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CWebFilelistDlg 消息处理程序


BOOL CWebFilelistDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetTimer(1,1000,NULL);
	this->ShowWindow (SW_MAXIMIZE);
	CRect rect;
	this->GetClientRect(&rect);
	this->m_webctrl.MoveWindow(&rect);
	CString tablehtml = "  \
		 <tr class=\"whf.css\"  >\
		 <td bgcolor=\"#FFFFFF\" class=\"whf\" >{{*num*}}</td>\
		 <td align=\"center\" bgcolor=\"#FFFFFF\" class=\"whf\">{{*doc*}}</td>\
		 <td align=\"center\" bgcolor=\"#FFFFFF\">{{*shuoming*}}</td>\
         <td align=\"center\" bgcolor=\"#FFFFFF\">\
	     <table width=\"100%\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\
         <tbody>\
         <tr>\
		 <td height=\"120\" align=\"center\">{{*downimg*}}</td>\
		 <td align=\"center\">{{*viewimg*}}</td>\
         </tr>\
         </tbody>\
         </table>\
		 </td>\
         </tr>";
	CString downhtml = "<a href=\"http://127.0.0.1:9001/default.html?file={{*fname*}}&act=0\" ><img src=\"images/xiaz.jpg\" width=\"100\" height=\"100\" alt=\"\"/> </a>";
	CString viewhtml = " <a href=\"http://127.0.0.1:9001/default.html?file={{*fname*}}&act=1\" ><img src=\"images/chak.jpg\" width=\"100\" height=\"100\" alt=\"\"/> </a>";
		
	CString tableshtml;
	CFile filedoc;
	CString subfilename[4];
	for (int i=0;i<this->filecount;i++){
		CString tablehtml1 = tablehtml;
		CString tmpstr=	this->filelistname[i];
		if (tmpstr.Right(4) == ".set"){
			tmpstr.Replace("."," ");
			AfxExtractSubString(subfilename[0], (LPCTSTR)tmpstr, 0, ' ');
			AfxExtractSubString(subfilename[1], (LPCTSTR)tmpstr, 1, ' ');
			AfxExtractSubString(subfilename[2], (LPCTSTR)tmpstr, 2, ' ');
			AfxExtractSubString(subfilename[3], (LPCTSTR)tmpstr, 3, ' ');
	//		this->m_filelistctrl.SetItemHeight(i,n+11);
			tablehtml1.Replace("{{*num*}}",subfilename[0]);
			tablehtml1.Replace("{{*doc*}}",subfilename[1]);
			tablehtml1.Replace("{{*shuoming*}}",subfilename[2]);
			
			if(filedoc.Open(nowdir+"\\"+subfilename[1]+".pdf",CFile::modeRead)){
                  tablehtml1.Replace("{{*viewimg*}}",viewhtml);
				  tablehtml1.Replace("{{*fname*}}",subfilename[1]+".pdf");
				  filedoc.Close();

		    }else{

				 tablehtml1.Replace("{{*viewimg*}}","");
			}
			
			if(filedoc.Open(nowdir+"\\"+subfilename[1]+".doc",CFile::modeRead)){
                  tablehtml1.Replace("{{*downimg*}}",downhtml);
				  tablehtml1.Replace("{{*fname*}}",subfilename[1]+".doc");
				  filedoc.Close();

		    }else{

				 tablehtml1.Replace("{{*downimg*}}","");
			}
			 
			tableshtml += tablehtml1;

			 
			
			


	    }
	}
	CString tailhtml="<tr>   <td class=\"h2\">";
	if(filedoc.Open(nowdir+"\\提交材料说明.txt",CFile::modeRead)){
		char *readbuf;
		int ncount = filedoc.GetLength();
		readbuf = new char [ncount+1];
		memset(readbuf,0,ncount+1);
		filedoc.Read(readbuf,ncount);
		tailhtml += readbuf ;
		filedoc.Close();
		delete readbuf;
	}
	tailhtml.Replace("\n","<br/>");
	tailhtml += "</td> </tr>";

	CString totaltmphtml;
	if(filedoc.Open("res\\biaogweb\\tmp.html",CFile::modeRead)){
				char *readbuf;
				int ncount = filedoc.GetLength();
				readbuf = new char [ncount+1];
				memset(readbuf,0,ncount+1);
			    filedoc.Read(readbuf,ncount);
				totaltmphtml= readbuf;
				filedoc.Close();
				delete readbuf;
						
	}
	CString cailiaoqingdan;
	int nnindex = nowdir.ReverseFind('\\');
	cailiaoqingdan=nowdir.Right(nowdir.GetLength()-nnindex-1);
	totaltmphtml.Replace("{{*title*}}",cailiaoqingdan+"材料清单");
	totaltmphtml.Replace("{{*content*}}",tableshtml);
	totaltmphtml.Replace("{{*tail*}}",tailhtml);

	if(filedoc.Open("res\\biaogweb\\default.html",CFile::modeCreate| CFile::modeWrite)){
		 
		//char BOM[3]={0xEF, 0xBB, 0xBF};
		//filedoc.Write(BOM,3);
		int nLength = totaltmphtml.GetLength();  
        CString tt ;
		char *strOut = new char[nLength*2];  
		memset(strOut,0,nLength*2);
  
		Convert(totaltmphtml.GetBuffer(0),strOut, CP_ACP, CP_UTF8); 
		//TCHAR* TestLine = new TCHAR[1000];
		//TCHAR TestLine;
		//Convert the line to UTF-8 multibyte.
		//WideCharToMultiByte (CP_UTF8,0,totaltmphtml,totaltmphtml.GetLength(),TestLine,strlen(TestLine)+1,NULL,NULL);
		//Add the line to file.
		tt = strOut;
		int nstr = tt.GetLength();
		filedoc.Write(strOut,nstr);
		//filedoc.Write(totaltmphtml,totaltmphtml.GetLength());
		 tt = strOut;
		 CString fdf=tt.Right(5);
		filedoc.Close();
		//delete []strOut;
		//strOut = NULL;
		 
	}
	//Sleep(3000);
	m_webctrl.Navigate("http://127.0.0.1:9001/default.html", NULL, NULL, NULL, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CWebFilelistDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFile file;
	KillTimer(1);
	if(file.Open( "set.set",CFile::modeReadWrite ,NULL)) {
		char *readbuf;
		int nNum = file.GetLength()+1;
		if (nNum <= 3) {
			file.Close();
			SetTimer(1,1000,NULL);
			return;
		}
		readbuf = new char [nNum ];
		memset(readbuf,0,nNum);
		file.Read(readbuf,nNum-1);
		CString sstr(readbuf);
		file.Close();
		delete readbuf;
		if (remove("set.set") != 0){
			//SetTimer(1,1000,NULL);
			return;
		}
		if (sstr.Find("99999") > 0){
			CDialogEx::OnCancel();
			return;
		}
		if (sstr.Find("77777") > 0){
			((CDirListCtrlDlg *)GetParent())->OnMyCancel();
			CDialogEx::OnCancel();
			return;
		}
		int n = sstr.ReverseFind(' ');
		if (n <= 2){
			file.Close();
			delete readbuf;
			SetTimer(1,1000,NULL);
			return ;
		}
		CString strfile = sstr.Left(n).Trim();
		CString stract = sstr.Right(nNum-1-n).Trim();
		if (stract == "1"){
			//pdf view
			CPdfViewDlg dlg;
			int nlen = strfile.GetLength();
			char *szGbk = new char [nlen+1];
			memset(szGbk,0,nlen+1);
			UTF82GBK(strfile.GetBuffer(0),szGbk,nlen )  ;
			dlg.m_pdfname = this->nowdir+"\\"+szGbk;
			dlg.DoModal();


		}else{
            //download
			CopyToUdisk(this->nowdir,strfile);

		}
		 
		
		

	}
	SetTimer(1,1000,NULL);
	CDialogEx::OnTimer(nIDEvent);
}

void CWebFilelistDlg::CopyToUdisk(CString path,CString filename)
{

	
	AfxMessageBox("请插入U盘后点确定按钮");
	UINT DiskType;  
	CString uDisk;
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
			//::AfxMessageBox( "移动存储设备 ");     
			uDisk = pDriveStrings;
			flagudisk = 1;
			break;     
			case   DRIVE_FIXED:     
			//::AfxMessageBox( "固定硬盘驱动器 ");     
			break;     
			case   DRIVE_REMOTE:     
			//::AfxMessageBox( "这是网络驱动器 ");     
			break;    
			case   DRIVE_CDROM:     
			//::AfxMessageBox( "这是光盘驱动器 ");     
			break;  
     
		}  
    
		pDriveStrings   +=   szDriveString   +   1;     
		szDriveString   =   strlen(pDriveStrings);     
	}   
//	delete pDriveStrings; 

	if  ( flagudisk != 1){
        AfxMessageBox("没有找到u盘");
		return;
	}
	int nlen = filename.GetLength();
	char *szGbk = new char [nlen+1];
	memset(szGbk,0,nlen+1);
	UTF82GBK(filename.GetBuffer(0),szGbk,nlen )  ;
	if (true == ::CopyFile(path+"\\"+szGbk,uDisk+szGbk,false)){
		AfxMessageBox("下载成功");
	}else{
		AfxMessageBox("下载出错");
	}




}

void CWebFilelistDlg::Convert(const char* strIn, char* strOut, int sourceCodepage, int targetCodepage)  
{  
    int len=lstrlen(strIn);     
    int unicodeLen=MultiByteToWideChar(sourceCodepage,0,strIn,-1,NULL,0);     
    wchar_t* pUnicode;     
    pUnicode=new wchar_t[unicodeLen+1];     
    memset(pUnicode,0,(unicodeLen+1)*sizeof(wchar_t));     
    MultiByteToWideChar(sourceCodepage,0,strIn,-1,(LPWSTR)pUnicode,unicodeLen);     
    BYTE * pTargetData = NULL;     
    int targetLen=WideCharToMultiByte(targetCodepage,0,(LPWSTR)pUnicode,-1,(char *)pTargetData,0,NULL,NULL);     
    pTargetData=new BYTE[targetLen+1];     
    memset(pTargetData,0,targetLen+1);     
    WideCharToMultiByte(targetCodepage,0,(LPWSTR)pUnicode,-1,(char *)pTargetData,targetLen,NULL,NULL);     
    lstrcpy(strOut,(char*)pTargetData);     
    delete pUnicode;  
    pUnicode = NULL;  
    delete pTargetData;  
    pTargetData = NULL;  
}


int  CWebFilelistDlg::UTF82GBK(char *szUtf8,char *szGbk,int Len)  
{  
    int n = MultiByteToWideChar(CP_UTF8, 0, szUtf8, -1, NULL, 0);  
    WCHAR * wszGBK = new WCHAR[sizeof(WCHAR) * n];  
    memset(wszGBK, 0, sizeof(WCHAR) * n);  
    MultiByteToWideChar(CP_UTF8, 0,szUtf8,-1, wszGBK, n);  
  
    n = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);  
    if (n > Len)  
    {  
        delete[]wszGBK;  
        return -1;  
    }  
  
    WideCharToMultiByte(CP_ACP,0, wszGBK, -1, szGbk, n, NULL, NULL);  
  
    delete[]wszGBK;  
    wszGBK = NULL;  
  
    return 0;  
} 