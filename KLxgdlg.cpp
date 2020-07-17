// KLxgdlg.cpp : implementation file
//

#include "stdafx.h"
#include "WordGLXT.h"
#include "KLxgdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKLxgdlg dialog


CKLxgdlg::CKLxgdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKLxgdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKLxgdlg)
	m_opwd = _T("");
	m_npwd2 = _T("");
	m_npwd1 = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICONMIMA);
}


void CKLxgdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKLxgdlg)
	DDX_Control(pDX, IDC_STATICyh, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_opwd);
	DDX_Text(pDX, IDC_EDIT4, m_npwd2);
	DDX_Text(pDX, IDC_EDIT3, m_npwd1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKLxgdlg, CDialog)
	//{{AFX_MSG_MAP(CKLxgdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKLxgdlg message handlers

void CKLxgdlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	CString name;
	m_name.GetWindowText(name);
	if(m_opwd=="")
	{
		MessageBox("�����������","�ĵ�����ϵͳ");
		return;
	}
	if(m_npwd1=="")
	{
		MessageBox("������������","�ĵ�����ϵͳ");
		return;
	}
	if(m_npwd2=="")
	{
		MessageBox("��ȷ��������","�ĵ�����ϵͳ");
		return;
	}
	if(m_npwd1!=m_npwd2)
	{
		MessageBox("�����������벻ͬ","�ĵ�����ϵͳ");
		return;
	}
	CUsers ser;
	if(ser.HaveCzy(name,m_opwd)!=1)
	{
		MessageBox("�û����������","�ĵ�����ϵͳ");
		return;
	}
	else
	{
	    ser.SetPwd(m_npwd1);
	    ser.sql_updatepwd(name);
		MessageBox("�����޸ĳɹ����´ε�¼����������","�ĵ�����ϵͳ");
	}
	zhi.SetDLsj(t.Format("%y-%m-%d"));
	zhi.SetName(user.GetUsername());
	zhi.SetDZ("�޸�����");
	zhi.sql_insert();
	UpdateData(false);
	CDialog::OnOK();
}

BOOL CKLxgdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetIcon(m_hIcon, TRUE);	
	t=CTime::GetCurrentTime();
	m_name.SetWindowText(user.GetUsername());
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CKLxgdlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==13)
		pMsg->wParam=9;	
	return CDialog::PreTranslateMessage(pMsg);
}
