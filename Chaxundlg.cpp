// Chaxundlg.cpp : implementation file
//

#include "stdafx.h"
#include "WordGLXT.h"
#include "Chaxundlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChaxundlg dialog


CChaxundlg::CChaxundlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChaxundlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChaxundlg)
	m_cxz = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICONFIND);
}


void CChaxundlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChaxundlg)
	DDX_Control(pDX, IDC_COMBO1, m_cxfs);
	DDX_Text(pDX, IDC_EDIT1, m_cxz);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChaxundlg, CDialog)
	//{{AFX_MSG_MAP(CChaxundlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChaxundlg message handlers

BOOL CChaxundlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetIcon(m_hIcon, TRUE);	
	switch(cx)
	{
		case 0:
			m_cxfs.AddString("关键字");
			break;
		case 1:
			m_cxfs.AddString("文档名称");
			break;
	}
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CChaxundlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	CString str,strzd;
	m_cxfs.GetLBText(m_cxfs.GetCurSel(),str);
	if(str=="关键字")
	{
		zdxxb.SetGJz(m_cxz);
	}
	else if(str=="文档名称")
	{
		if(xxb.sql_selectwdmc(m_cxz)>=1)
		{
			zdxxb.SetWDmc(m_cxz);
		}
		else
		{
			MessageBox("文档不存在!");
			return;
		}
	}
	
	CDialog::OnOK();
}
