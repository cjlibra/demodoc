// WebFilelistDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demodoc.h"
#include "WebFilelistDlg.h"
#include "afxdialogex.h"


// CWebFilelistDlg �Ի���

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
END_MESSAGE_MAP()


// CWebFilelistDlg ��Ϣ�������


BOOL CWebFilelistDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	this->ShowWindow (SW_MAXIMIZE);
	CRect rect;
	this->GetClientRect(&rect);
	this->m_webctrl.MoveWindow(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
