// YHgldlg.cpp : implementation file
//

#include "stdafx.h"
#include "WordGLXT.h"
#include "YHgldlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CYHgldlg dialog


CYHgldlg::CYHgldlg(CWnd* pParent /*=NULL*/)
	: CDialog(CYHgldlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CYHgldlg)
	m_name = _T("");
	m_pwd = _T("");
	m_pwd1 = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICONYHGL);
}


void CYHgldlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CYHgldlg)
	DDX_Control(pDX, IDC_COMBO1, m_jb);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
	DDX_Text(pDX, IDC_EDIT3, m_pwd1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CYHgldlg, CDialog)
	//{{AFX_MSG_MAP(CYHgldlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYHgldlg message handlers

BOOL CYHgldlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetIcon(m_hIcon, TRUE);	
	m_jb.AddString("ϵͳ����Ա");
	m_jb.AddString("��ͨ����Ա");
	t=CTime::GetCurrentTime();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CYHgldlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	if(m_name=="")
	{
		MessageBox("�������û���","�ĵ�����ϵͳ");
		return;
	}
	CString jb;
	m_jb.GetWindowText(jb);
	if(jb=="")
	{
		MessageBox("������Ϊ��","�ĵ�����ϵͳ");
		return;
	}
    if(m_pwd=="")
	{
		MessageBox("����������","�ĵ�����ϵͳ");
		return;
	}
	if(m_pwd1=="")
	{
		MessageBox("��ȷ������","�ĵ�����ϵͳ");
		return;
	}
	if(m_pwd!=m_pwd1)
	{
		MessageBox("�������벻ͬ","�ĵ�����ϵͳ");
		return;
	}
	CUsers ser;
	if(ser.Havename(m_name)==1)
	{
		MessageBox("�û��Դ��ڣ�����������","�ĵ�����ϵͳ");
		return;
	}
	
	ser.SetUsername(m_name);
	ser.SetPwd(m_pwd);
	m_jb.GetLBText(m_jb.GetCurSel(),strjb);
	if(strjb=="ϵͳ����Ա")
		strjb="1";
	else
		strjb="0";
	ser.SetJB(strjb);
	ser.sql_insert();
	zhi.SetDLsj(t.Format("%y-%m-%d"));
	zhi.SetName(user.GetUsername());
	zhi.SetDZ("����û�");
	zhi.sql_insert();
	CDialog::OnOK();
}

void CYHgldlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(MessageBox("�Ƿ�ɾ����ǰ��¼","��ȷ��",MB_YESNO)==IDYES)
	{
		CUsers ser;
		ser.sql_delete(m_name);
		zhi.SetDLsj(t.Format("%y-%m-%d"));
		zhi.SetName(user.GetUsername());
		zhi.SetDZ("�û�ɾ��");
		zhi.sql_insert();
	}
	CDialog::OnOK();
}

BOOL CYHgldlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==13)
		pMsg->wParam=9;	
	return CDialog::PreTranslateMessage(pMsg);
}
