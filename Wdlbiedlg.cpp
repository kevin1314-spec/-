// Wdlbiedlg.cpp : implementation file
//

#include "stdafx.h"
#include "WordGLXT.h"
#include "Wdlbiedlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWdlbiedlg dialog


CWdlbiedlg::CWdlbiedlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWdlbiedlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWdlbiedlg)
	m_dwbh = 0;
	m_lbbh = 0;
	m_lbmc = _T("");
    RadioFlag = 0;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICONWDLB);
}


void CWdlbiedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWdlbiedlg)
	DDX_Control(pDX, IDC_COMBO5, m_combo5);
	DDX_Text(pDX, IDC_EDIT1, m_dwbh);
	DDX_Text(pDX, IDC_EDIT2, m_lbbh);
	DDX_Text(pDX, IDC_EDIT3, m_lbmc);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWdlbiedlg, CDialog)
	//{{AFX_MSG_MAP(CWdlbiedlg)
	ON_CBN_SELCHANGE(IDC_COMBO5, OnSelchangeCombo5)
	ON_BN_CLICKED(IDC_RADIO_Modify, OnRADIOModify)
	ON_BN_CLICKED(IDC_RADIO_ADD, OnRadioAdd)
	ON_BN_CLICKED(IDC_RADIO_Del, OnRADIODel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWdlbiedlg message handlers

void CWdlbiedlg::OnOK() //��Ӱ�ť
{
	// TODO: Add extra validation here
    switch(RadioFlag)
	{	
	case 1: LBModify(); break;
	case 2: LBAdd(); break;
	case 3: LBDel(); break ;
    default :
		::AfxMessageBox("��ѡ�����ѡ��!");
		return ;
	}
	
	CDialog::OnOK();
}

BOOL CWdlbiedlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	SetIcon(m_hIcon, TRUE);	
	
	t=CTime::GetCurrentTime();
	CZdmlb mlb;
	CDwxxb dwb;
	dwb.Load_dep();
	mlb.Load_dep();
	
	for(int i=0;i<dwb.a_DWbh.GetSize();i++)
	{
		m_combo5.AddString(dwb.a_DWmc.GetAt(i));
	}
	m_lbbh = mlb.a_LBbh.GetSize()+1; //�����Ĭ��ֵ
  	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CWdlbiedlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==13)
		pMsg->wParam=9;	
	return CDialog::PreTranslateMessage(pMsg);
}

void CWdlbiedlg::OnSelchangeCombo5() //�����Ͽ�5����Ӧ����
{
	// TODO: Add your control notification handler code here
	CString strdwmc;
	m_combo5.GetLBText(m_combo5.GetCurSel(), strdwmc);
    CZdmlb mlb;
	CDwxxb dwb;
	dwb.Load_dep();
	mlb.Load_dep();
	//m_dwbh = dwb.a_DWbh.GetSize()+1;
	for(int i=0;i<dwb.a_DWbh.GetSize();i++)
	{
		if(strdwmc==dwb.a_DWmc.GetAt(i))
			m_dwbh=atoi(dwb.a_DWbh.GetAt(i));
	}
	int n = 0;
	for( i=0;i<mlb.a_DWbh.GetSize();i++)
	{   
		
		if(m_dwbh==atoi(mlb.a_DWbh.GetAt(i))) n++;
			
	}
	m_lbbh=++n;
	UpdateData(false);
}

void CWdlbiedlg::OnRADIOModify() 
{
	// TODO: Add your control notification handler code here
	RadioFlag=1;
}

void CWdlbiedlg::OnRadioAdd() 
{
	// TODO: Add your control notification handler code here
	RadioFlag=2;
}

void CWdlbiedlg::OnRADIODel() 
{
	// TODO: Add your control notification handler code here
	RadioFlag=3;
}

void CWdlbiedlg::LBAdd()
{
	UpdateData(true);
	if(m_lbmc=="")
	{
		MessageBox("������Ʋ���Ϊ��","�ĵ�����ϵͳ");
		return;
	}
	CZdmlb mlb;
	CDwxxb dwb;
	mlb.Load_dep();
	dwb.Load_dep();
	int dw=0;
	for(int i=0;i<dwb.a_DWbh.GetSize();i++)
	{
		int p=atoi(dwb.a_DWbh.GetAt(i));
		if(m_dwbh==atoi(dwb.a_DWbh.GetAt(i)))
		{
			dw++;
		}
	}
	if(dw==0)
	{
		MessageBox("��λ��Ų�����","�ĵ�����ϵͳ");
		return;
	}
	dw=0;
	if(mlb.HaveId(m_dwbh,m_lbbh)==1)
	{
		MessageBox("����Ѵ���","�ĵ�����ϵͳ");
		return;
	}
	mlb.SetDwbh(m_dwbh);
	mlb.SetLBbh(m_lbbh);
	mlb.SetLBmc(m_lbmc);
	mlb.sql_insert();
	zhi.SetDLsj(t.Format("%y-%m-%d"));
	zhi.SetName(user.GetUsername());
	zhi.SetDZ("������");
	zhi.sql_insert();

}

void CWdlbiedlg::LBModify()
{
	UpdateData(true);
	if(m_lbmc=="")
	{
		MessageBox("������Ʋ���Ϊ��","�ĵ�����ϵͳ");
		return;
	}
	CZdmlb mlb;
	CDwxxb dwb;
	dwb.Load_dep();
	mlb.Load_dep();
	int dw=0;
	for(int i=0;i<dwb.a_DWbh.GetSize();i++)
	{
		if(m_dwbh==atoi(dwb.a_DWbh.GetAt(i)))
		{
			dw++;
		}
	}
	if(dw==0)
	{
		MessageBox("��λ��Ų�����","�ĵ�����ϵͳ");
		return;
	}
	dw=0;
	mlb.SetDwbh(m_dwbh);
	mlb.SetLBmc(m_lbmc);
	mlb.sql_update(m_dwbh,m_lbbh);
	zhi.SetDLsj(t.Format("%y-%m-%d"));
	zhi.SetName(user.GetUsername());
	zhi.SetDZ("����޸�");
	zhi.sql_insert();
}

void CWdlbiedlg::LBDel()
{
	UpdateData(true);
	CZdmlb mlb;
	mlb.sql_delete(m_dwbh,m_lbbh);  //ɾ�������е���ؼ�¼
	CZdxxb xxb;
	xxb.sql_deletelb(m_dwbh,m_lbbh);//ɾ���ĵ�������صļ�¼
	zhi.SetDLsj(t.Format("%y-%m-%d"));  //��־
	zhi.SetName(user.GetUsername());
	zhi.SetDZ("���ɾ��");
	zhi.sql_insert();

}
