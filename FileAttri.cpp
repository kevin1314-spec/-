// FileAttri.cpp : implementation file
//

#include "stdafx.h"
#include "WordGLXT.h"
#include "FileAttri.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// FileAttri dialog


FileAttri::FileAttri(CWnd* pParent /*=NULL*/)
	: CDialog(FileAttri::IDD, pParent)
{
	//{{AFX_DATA_INIT(FileAttri)
	//}}AFX_DATA_INIT
	    
	
}


void FileAttri::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(FileAttri)
	DDX_Control(pDX, IDC_Pigeonhole, m_ar);
	DDX_Control(pDX, IDC_Catalog, m_dir);
	DDX_Control(pDX, IDC_VolumeLabel, m_vol);
	DDX_Control(pDX, IDC_ReadOnly, m_readonly);
	DDX_Control(pDX, IDC_System, m_system);
	DDX_Control(pDX, IDC_Normal, m_normal);
	DDX_Control(pDX, IDC_Hide, m_hide);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(FileAttri, CDialog)
	//{{AFX_MSG_MAP(FileAttri)
	ON_BN_CLICKED(ID_BNAddFile, OnBNAddFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// FileAttri message handlers



void FileAttri::OnBNAddFile()  //����ļ���Ӧ�¼�
{
	// TODO: Add your control notification handler code here
	CFileDialog log(TRUE,"�ļ�","*.*",OFN_HIDEREADONLY,"FILE(*.*)|*.*||",NULL);
	if(log.DoModal()==IDCANCEL)return;
	pathname=log.GetPathName();	
    ShowFileAttri();
}

void FileAttri::ShowFileAttri()
{
	   
		GetDlgItem(IDC_STATIC_FilePath)->SetWindowText(pathname);//��ʾ�ļ�·��
	    CFileStatus status;
		CFile::GetStatus(pathname,status);
		CString strsize; //
		if(status.m_size<1024)  //��ʾ�ļ���С�ķ�ʽ
		{
		   strsize.Format("%d",status.m_size);
		   strsize.Insert(strsize.GetLength(),'B');
		}
		else if(status.m_size<1024*1024)
		{
		   strsize.Format("%d",status.m_size/1024);
		   strsize.Insert(strsize.GetLength(),'K');
		}
		else
		{
		   strsize.Format("%d",status.m_size/(1024*1024));
		   strsize.Insert(strsize.GetLength(),'M');
		}
		
		CString str;
		str.Format("�ļ���С:%s",strsize);
        GetDlgItem(IDC_STATIC_FSize)->SetWindowText(str);

		CTime createtime = status.m_ctime;//�ļ��Ĵ���ʱ��
		CTime modifytime = status.m_mtime;//�ļ����޸�ʱ��
		CTime readtime = status.m_atime;  //�ļ��ķ���ʱ��
		GetDlgItem(IDC_STATIC_CTime)->SetWindowText(createtime.Format("����ʱ��:%Y��%m��%d��%H:%M:%S"));
		GetDlgItem(IDC_STATIC_MTime)->SetWindowText(modifytime.Format("�޸�ʱ��:%Y��%m��%d��%H:%M:%S"));
		GetDlgItem(IDC_STATIC_RTime)->SetWindowText(readtime.Format("����ʱ��:%Y��%m��%d��%H:%M:%S"));
		
		if(status.m_attribute&0x00)	m_ar.SetCheck(1);
		if(status.m_attribute&0x10)	m_dir.SetCheck(1);
		if(status.m_attribute&0x02)	m_hide.SetCheck(1);
		if(status.m_attribute&0x20)	m_normal.SetCheck(1);
		if(status.m_attribute&0x01)	m_readonly.SetCheck(1);
		if(status.m_attribute&0x04)	m_system.SetCheck(1);
		if(status.m_attribute&0x08)	m_vol.SetCheck(1);
		
}



BOOL FileAttri::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(pathname=="") ::AfxMessageBox("����ѡ�����ĵ���",MB_OK,0);
	else
	{   
		GetDlgItem(ID_BNAddFile)->EnableWindow(false);
		ShowFileAttri();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void FileAttri::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
	GetDlgItem(ID_BNAddFile)->EnableWindow(true);
}
