// Dwdandlg.cpp : implementation file
//

#include "stdafx.h"
#include "WordGLXT.h"
#include "Dwdandlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDwdandlg dialog


CDwdandlg::CDwdandlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDwdandlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDwdandlg)
	m_lxdz = _T("");
	m_lxr = _T("");
	m_memo = _T("");
	m_dwbh = 0;
	RadioFlag = 0;
	m_lxdh = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICONDANWEI);
}


void CDwdandlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDwdandlg)
	DDX_Control(pDX, IDC_COMBO2, m_combo_dwmc);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Text(pDX, IDC_EDIT5, m_lxdz);
	DDX_Text(pDX, IDC_EDIT3, m_lxr);
	DDX_Text(pDX, IDC_EDIT6, m_memo);
	DDX_Text(pDX, IDC_EDIT1, m_dwbh);
	DDX_Text(pDX, IDC_EDIT4, m_lxdh);
	DDV_MaxChars(pDX, m_lxdh, 13);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDwdandlg, CDialog)
	//{{AFX_MSG_MAP(CDwdandlg)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_NOTIFY(TCN_SELCHANGING, IDC_TAB1, OnSelchangingTab1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_BN_CLICKED(IDC_RADIO_Modify, OnRADIOModify)
	ON_BN_CLICKED(IDC_RADIO_ADD, OnRadioAdd)
	ON_BN_CLICKED(IDC_RADIO_Del, OnRADIODel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDwdandlg message handlers

void CDwdandlg::OnOK()  //��Ӱ�ť
{
	// TODO: Add extra validation here
	switch(RadioFlag)
	{
	case 1:
		   ModifyDW();
		   break;
	case 2:
		   AddDW();
		   break;
	case 3: 
			DelDW();
		    break;
	default:
			AfxMessageBox("��ѡ�����!");
		    return ;
	}

	CDialog::OnOK();
}
BOOL CDwdandlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetIcon(m_hIcon, TRUE);	
	t=CTime::GetCurrentTime();//��ȡ��ǰʱ��
	TC_ITEM tci; //һ����ǩ���ܺ����ı�/ͼƬ�����ԣ�
	             //TC_ITEM�ṹ��maskָ���˱�ǩ��������������Ч�ġ�
	             //mask=TCIF_IMAGE��ͼƬ��Ч
	tci.mask=TCIF_TEXT;    //�ı���Ч
	tci.pszText="��λ����";
	m_tab.InsertItem(0,&tci);
	tci.pszText="��λ�б�";
	m_tab.InsertItem(1,&tci);
	
	GetDlgItem(IDC_LIST1)->ShowWindow(SW_HIDE);//ʹListContro�ؼ����ɼ�

	UpdateData(true);

	//ΪListContro�ؼ�������
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list.InsertColumn(0,"��λ���",LVCFMT_LEFT,100,0);
	m_list.InsertColumn(1,"��λ����",LVCFMT_LEFT,100,1);
	m_list.InsertColumn(2,"��ϵ��",LVCFMT_LEFT,100,2);
	m_list.InsertColumn(3,"��ϵ�绰",LVCFMT_LEFT,100,3);
	m_list.InsertColumn(4,"��ϵ��ַ",LVCFMT_LEFT,100,4);
	m_list.InsertColumn(6,"��ע",LVCFMT_LEFT,100,5);

	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();//�������ݿ�

	CString sql;
	sql.Format("select* from Dwxxb order by dwbh desc");

	m_AdoConn.GetRecordSet((_bstr_t)sql);

	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		m_list.InsertItem(0,"");
		m_list.SetItemText(0,0,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("dwbh"));
		m_list.SetItemText(0,1,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("dwmc"));
		m_combo_dwmc.AddString((char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("dwmc"));
		m_list.SetItemText(0,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("lxr"));
		m_list.SetItemText(0,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("lxdh"));
		m_list.SetItemText(0,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("lxdz"));
		m_list.SetItemText(0,5,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("memo"));
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();//�Ͽ�����

	CDwxxb dwb;
	dwb.Load_dep();
    m_dwbh=	dwb.a_DWbh.GetSize()+1;;//���õ�λ������Ĭ�ϵ�λ���

	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDwdandlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) //���û��ı��ǩʱ����
{
	// TODO: Add your control notification handler code here
	switch(m_tab.GetCurSel())//ʵ�ֱ�ǩ���л�����
	{
	case 0: 
		GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_COMBO2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDOK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDCANCEL)->ShowWindow(SW_SHOW);

		break;
	case 1: 
		GetDlgItem(IDC_LIST1)->ShowWindow(SW_SHOW);
		break;
	}
	*pResult = 0;
}

void CDwdandlg::OnSelchangingTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	switch(m_tab.GetCurSel())
	{
	case 0: 
		GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_COMBO2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
		GetDlgItem(IDOK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDCANCEL)->ShowWindow(SW_HIDE);

		break;
	case 1: 
		GetDlgItem(IDC_LIST1)->ShowWindow(SW_HIDE);
		
		break;

	}
	*pResult = 0;
}
void CDwdandlg::SetCurTab(UINT m_index)
{
	m_tab.SetCurSel(m_index);
	if(m_index==0)
	{
		GetDlgItem(IDC_LIST1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
		
        GetDlgItem(IDC_COMBO2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDOK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDCANCEL)->ShowWindow(SW_SHOW);

	}
	else 
	{
		GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
		
		GetDlgItem(IDC_COMBO2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
		GetDlgItem(IDOK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDCANCEL)->ShowWindow(SW_HIDE);
		
		GetDlgItem(IDC_LIST1)->ShowWindow(SW_SHOW);
	}
	
}

void CDwdandlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) //˫���б����Ӧ����
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int pos;
	pos=m_list.GetSelectionMark();
	SetCurTab(0);
	m_dwbh=atoi(m_list.GetItemText(pos,0));

	CString Dbldwmc = m_list.GetItemText(pos,1);

	m_combo_dwmc.SelectString(-1,Dbldwmc);

	m_lxr=m_list.GetItemText(pos,2);
	m_lxdh=m_list.GetItemText(pos,3);
	m_lxdz=m_list.GetItemText(pos,4);
	m_memo=m_list.GetItemText(pos,5);
	UpdateData(false);
	*pResult = 0;
}

BOOL CDwdandlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==13)
		pMsg->wParam=9;	
	return CDialog::PreTranslateMessage(pMsg);
}

void CDwdandlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	 GetDlgItem(IDC_EDIT1)->EnableWindow(false);
	 CDwxxb dwb;	
	CString strdwmc;

	m_combo_dwmc.GetLBText(m_combo_dwmc.GetCurSel(),strdwmc);    
   
	dwb.Load_dep();
    int m =dwb.a_DWbh.GetSize();
	for(int i=0;i<m;i++)//���ݵ�λ���������λ����
	{
		
		if(strdwmc==dwb.a_DWmc.GetAt(i))
		{
			m_dwbh = atoi(dwb.a_DWbh.GetAt(i));
		}
	}
	UpdateData(false);
}

void CDwdandlg::OnRADIOModify() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	RadioFlag = 1;
}

void CDwdandlg::OnRadioAdd() 
{
	// TODO: Add your control notification handler code here
    CDwxxb dwb;
	dwb.Load_dep();
    m_dwbh=	dwb.a_DWbh.GetSize()+1;;//������ʾĬ�ϵĵ�λ���
    GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	RadioFlag = 2;
	UpdateData(false);
}

void CDwdandlg::OnRADIODel() 
{
	// TODO: Add your control notification handler code here   	
	RadioFlag = 3;
}

void CDwdandlg::AddDW()  //��ӵ�λ��Ϣ
{
	UpdateData(true);
	CString strdwmc; 	
    m_combo_dwmc.GetWindowText(strdwmc);
	CDwxxb dwb;	
	if(strdwmc=="")
		::AfxMessageBox("��λ���Ʋ���Ϊ��");
	
	else if(dwb.HaveId(m_dwbh)==1)	
		MessageBox("��λ����Ѵ���","�ĵ�����ϵͳ");			
	else if(m_lxdh.GetLength()>12)	
		MessageBox("�绰���벻��ȷ","�ĵ�����ϵͳ");
	else
	{		
		dwb.SetDWbh(m_dwbh);
		dwb.SetDWmc(strdwmc);
		dwb.SetLxr(m_lxr);
		dwb.SetLxdh(m_lxdh);
		dwb.SetLxdz(m_lxdz);
		dwb.SetMemo(m_memo);
		dwb.sql_insert();
		zhi.SetDLsj(t.Format("%y-%m-%d"));
		zhi.SetName(user.GetUsername());
		zhi.SetDZ("��λ���");
		zhi.sql_insert();
	}
}

void CDwdandlg::ModifyDW() //�޸ĵ�λ��Ϣ
{
	UpdateData(true);
	CString strdwmc;	
	if(m_combo_dwmc.GetCurSel()!=CB_ERR)//���������б���ѡ�� 
	    	m_combo_dwmc.GetLBText(m_combo_dwmc.GetCurSel(),strdwmc);
	else	 //��û�д������б���ѡ��
	{
		m_combo_dwmc.GetWindowText(strdwmc); 
        int a =m_combo_dwmc.SelectString(-1,strdwmc);
		if(a == CB_ERR) strdwmc="";  //�����ݿ���û�иõ�λ,�����strdwmc		
	}

	if(strdwmc=="")
		MessageBox("��λ���Ʋ���Ϊ��","�ĵ�����ϵͳ");	
	else if(m_lxdh.GetLength()>12)
		MessageBox("�绰���벻��ȷ","�ĵ�����ϵͳ");
	else
	{
		CDwxxb dwb;
		dwb.SetDWmc(strdwmc);
		dwb.SetLxr(m_lxr);
		dwb.SetLxdh(m_lxdh);
		dwb.SetLxdz(m_lxdz);
		dwb.SetMemo(m_memo);
		dwb.sql_update(m_dwbh);
		zhi.SetDLsj(t.Format("%y-%m-%d"));
		zhi.SetName(user.GetUsername());
		zhi.SetDZ("��λ�޸�");
		zhi.sql_insert();
	}

}

void CDwdandlg::DelDW() //ɾ����λ��Ϣ
{
	CDwxxb dwb;
	if(dwb.HaveId(m_dwbh)==-1)
		MessageBox("��λ��Ų�����,�޷�ִ��ɾ������!","�ĵ�����ϵͳ");
	else
	{
		
		dwb.sql_delete(m_dwbh); //ɾ����λ���иõ�λ��Ϣ
		CZdmlb mlb;
		mlb.sql_deletedw(m_dwbh); //ɾ�������иõ�λ��Ϣ
		CZdxxb xxb;
		xxb.sql_deletedw(m_dwbh); //ɾ���ĵ����иõ�λ��Ϣ
		zhi.SetDLsj(t.Format("%y-%m-%d"));
		zhi.SetName(user.GetUsername());
		zhi.SetDZ("��λɾ��");
		zhi.sql_insert();
	}	

}


