// WDgldlg.cpp : implementation file
//

#include "stdafx.h"
#include "WordGLXT.h"
#include "WDgldlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWDgldlg dialog



CWDgldlg::CWDgldlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWDgldlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWDgldlg)
	m_wdmc = _T("");
	m_gjz = _T("");
	m_memo = _T("");
	m_wdbh = 0;
	tabindex = 0;
	//}}AFX_DATA_INIT

}


void CWDgldlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWDgldlg)
	DDX_Control(pDX, IDC_COMBO4, m_combo4);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_COMBO3, m_combo3);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT6, m_wjlj);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Text(pDX, IDC_EDIT4, m_wdmc);
	DDX_Text(pDX, IDC_EDIT5, m_gjz);
	DDX_Text(pDX, IDC_EDIT7, m_memo);
	DDX_Text(pDX, IDC_EDIT3, m_wdbh);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWDgldlg, CDialog)
	//{{AFX_MSG_MAP(CWDgldlg)
	ON_BN_CLICKED(IDC_WJLJXZ, OnWjljxz)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_NOTIFY(TCN_SELCHANGING, IDC_TAB1, OnSelchangingTab1)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON_DelWD, OnBUTTONDelWD)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWDgldlg message handlers

BOOL CWDgldlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_hIcon = AfxGetApp()->LoadIcon(IDI_CHILDICON4);
	// TODO: Add extra initialization here
	SetIcon(m_hIcon, TRUE);	
	TC_ITEM tci;
	tci.mask=TCIF_TEXT;
	tci.pszText="������Ϣ";
	m_tab.InsertItem(0,&tci);
	tci.pszText="��Ϣɾ��";
	m_tab.InsertItem(1,&tci);

	dwb.Load_dep();
	mlb.Load_dep();
	xxb.Load_dep();

	t=CTime::GetCurrentTime();

	UpdateData(true);
	for(int i=0;i<xxb.a_WDbh.GetSize();i++) //�����ĵ�������ĵ����������ĵ�����
	
		m_combo1.AddString(xxb.a_WDmc.GetAt(i));//����ǩҳ2�µ���Ͽ�����ĵ�����
	
	for( i=0;i<dwb.a_DWbh.GetSize();i++) //���ݵ�λ����ڵ�λ����������λ����
	
		m_combo3.AddString(dwb.a_DWmc.GetAt(i));//����ǩҳ1�µ���Ͽ���ӵ�λ����
	    
	
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list.InsertColumn(0,"��λ����",LVCFMT_LEFT,100,0);
	m_list.InsertColumn(1,"�ĵ����",LVCFMT_LEFT,100,1);
	m_list.InsertColumn(2,"�ĵ����",LVCFMT_LEFT,100,2);
	m_list.InsertColumn(3,"�ĵ�����",LVCFMT_LEFT,100,3);
	m_list.InsertColumn(4,"�ؼ���",LVCFMT_LEFT,100,4);
	m_list.InsertColumn(5,"�ĵ�·��",LVCFMT_LEFT,100,5);
	m_list.InsertColumn(6,"��ע",LVCFMT_LEFT,100,6);
	CString dwmc[100],wdlb[100],pp;
	//���ݵ�λ��ŷ��ص�λ����
	for(i=0;i<xxb.a_WDmc.GetSize();i++)
	{
		for(int j=0;j<dwb.a_DWbh.GetSize();j++)
		{
			if(atoi(xxb.a_DWbh.GetAt(i))==atoi(dwb.a_DWbh.GetAt(j)))
			{
				dwmc[i]=dwb.a_DWmc.GetAt(j);
			}
		}
		//��������ŷ����������
		for(j=0;j<mlb.a_DWbh.GetSize();j++)
		{
			if(atoi(xxb.a_DWbh.GetAt(i))==atoi(mlb.a_DWbh.GetAt(j)) && atoi(xxb.a_LBbh.GetAt(i))==atoi(mlb.a_LBbh.GetAt(j)))
			{
				wdlb[i]=mlb.a_LBmc.GetAt(j);
			}
		}
		
	}
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select* from Zdxxb order by wdbh desc");
	m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		m_list.InsertItem(0,"");
		m_list.SetItemText(0,0,dwmc[i-1]);
		m_list.SetItemText(0,1,wdlb[i-1]);
		m_list.SetItemText(0,2,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("wdbh"));
		m_list.SetItemText(0,3,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("wdmc"));
		m_list.SetItemText(0,4,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("gjz"));
		m_list.SetItemText(0,5,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("wjlj"));
		m_list.SetItemText(0,6,(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("memo"));
		i--;
		m_AdoConn.m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	//���ݲ˵�ѡ��ʹ��ͬ�ĵ�ѡ��ť����ѡ��״̬
	if(str==0)
	{
		CButton* tempbutton = (CButton*)GetDlgItem(IDC_RADIO1);
		tempbutton->SetCheck(1);
	}
	else
	{
		CButton* tempbutton = (CButton*)GetDlgItem(IDC_RADIO2);
		tempbutton->SetCheck(1);
	}
	//����SetCurTab()
	SetCurTab(tabindex);

	m_wdbh = xxb.a_WDmc.GetSize()+1;  //��Ĭ�ϱ��Ϊ1�ĸ�Ū���Զ������

	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWDgldlg::OnWjljxz()     //�ļ�·��ѡ��
{
	// TODO: Add your control notification handler code here
	CFileDialog file(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"All Files(*.*)|*.*| |",AfxGetMainWnd());
		if(file.DoModal()==IDOK)
		{
			
			strText= file.GetPathName();
		    m_wjlj.SetWindowText(strText);
			
			m_wdmc = file.GetFileName();   //�Զ�����ĵ�����
			int index=m_wdmc.ReverseFind('.');
			CString tem = m_wdmc;
			if(index!=-1) tem.Delete(index,m_wdmc.GetLength()-index);
			m_gjz  = tem;
			UpdateData(false); //������m_wdmc������������༭����
		}
}



void CWDgldlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	switch(m_tab.GetCurSel())
	{
	case 0: 
		//��ǩ0�Ŀؼ���ʾ
		//GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO3)->ShowWindow(SW_SHOW);
		//GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_WJLJXZ)->ShowWindow(SW_SHOW);
		GetDlgItem(IDOK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDCANCEL)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIO1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIO2)->ShowWindow(SW_SHOW);
		break;
	case 1: 
		//��ǩ1�Ŀؼ���ʾ
		GetDlgItem(IDC_LIST1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTONDEL)->ShowWindow(SW_SHOW);
		break;
	}
	*pResult = 0;
}

void CWDgldlg::OnSelchangingTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	switch(m_tab.GetCurSel())
	{
	case 0: 
		//��ǩ0�Ŀؼ�����
		//GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO3)->ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_WJLJXZ)->ShowWindow(SW_HIDE);
		GetDlgItem(IDOK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDCANCEL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIO1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIO2)->ShowWindow(SW_HIDE);
		break;
	case 1: 
		//��ǩ1�Ŀؼ�����
		GetDlgItem(IDC_LIST1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTONDEL)->ShowWindow(SW_HIDE);
		break;
	}
	*pResult = 0;
}

void CWDgldlg::OnOK() //���水ť�Ĵ���
{
	// TODO: Add extra validation here
	UpdateData(true);
	CString strdwmc,strwdlb;
    
	if(m_combo3.GetCurSel()==CB_ERR) 
	{
		MessageBox("��λ���Ʋ���Ϊ��,��ѡ��λ!","�ĵ�����ϵͳ");
	    return;
	}
	else 
		m_combo3.GetLBText(m_combo3.GetCurSel(),strdwmc);
	
	
	if(m_combo4.GetCurSel()==CB_ERR)
	{
		MessageBox("�ĵ������Ϊ��,��ѡ���ĵ����!","�ĵ�����ϵͳ");
		return;
	}
	else 
		m_combo4.GetLBText(m_combo4.GetCurSel(),strwdlb);

	if(m_wdmc=="")
	{
		MessageBox("�ĵ����Ʋ���Ϊ��","�ĵ�����ϵͳ");
		return;
	}
	CString strwjlj;
	m_wjlj.GetWindowText(strwjlj);
	if(strwjlj=="")
	{
		MessageBox("�ĵ�·������Ϊ��","�ĵ�����ϵͳ");
		return;
	}

	int dw=0,lb=0;
	for(int i=0;i<dwb.a_DWbh.GetSize();i++)//���ݵ�λ���������λ����
	{
		if(strdwmc==dwb.a_DWmc.GetAt(i))
		{
			dwbh=atoi(dwb.a_DWbh.GetAt(i));
			dw++; 
		}
	}
	if(dw==0)
	{
		MessageBox("��λ���Ʋ�����","�ĵ�����ϵͳ");
		return;
	}
	for(i=0;i<mlb.a_DWbh.GetSize();i++)//���ݵ�λ���������λ���
	{
		if(dwbh==atoi(mlb.a_DWbh.GetAt(i)) && strwdlb==mlb.a_LBmc.GetAt(i))
		{
			lbbh=atoi(mlb.a_LBbh.GetAt(i));//�����
			lb++;
		}
	}
	if(lb==0)
	{
		MessageBox("�ĵ���𲻴���","�ĵ�����ϵͳ");
		return;
	}

	xxb.SetDWbh(dwbh);
	xxb.SetLBbh(lbbh);
	xxb.SetWDbh(m_wdbh);
	xxb.SetWDmc(m_wdmc);
	xxb.SetGJz(m_gjz);
	    
	xxb.SetWJlj(strwjlj);
	xxb.SetMemo(m_memo);
	xxb.SetTjrxm(user.GetUsername());
	switch(str)
	{
		case 0: //���
			if(xxb.HaveId(dwbh,lbbh,m_wdbh)==1)
			{
				MessageBox("�ĵ��Ѵ���","�ĵ�����ϵͳ");
				return;
			}
			xxb.sql_insert();
			zhi.SetDLsj(t.Format("%y-%m-%d"));
			zhi.SetName(user.GetUsername());
			zhi.SetDZ("����ĵ�");
			zhi.sql_insert();
           
			break;
		case 1:  //�޸�
			xxb.sql_update(m_wdbh);
			zhi.SetDLsj(t.Format("%y-%m-%d"));
			zhi.SetName(user.GetUsername());
			zhi.SetDZ("�޸��ĵ�");
			zhi.sql_insert();
			break;
	}
	dw=0;
	lb=0;
	CDialog::OnOK();
}

void CWDgldlg::OnRadio1() //ѡ�����
{
	// TODO: Add your control notification handler code here
	str=0;
	
}
void CWDgldlg::OnRadio2() //ѡ���޸�
{
	// TODO: Add your control notification handler code here
	str=1;		
}

void CWDgldlg::SetCurTab(UINT m_index)
{
	m_tab.SetCurSel(m_index);
	if(m_index==0)
	{
		//��ǩ1�Ŀؼ�����
		GetDlgItem(IDC_LIST1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTONDEL)->ShowWindow(SW_HIDE);
		//��ǩ0�Ŀؼ���ʾ
		//GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO3)->ShowWindow(SW_SHOW);
		//GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_WJLJXZ)->ShowWindow(SW_SHOW);
		GetDlgItem(IDOK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDCANCEL)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIO1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIO2)->ShowWindow(SW_SHOW);
	}
	else
	{   //��ǩ0�Ŀؼ�����
		//GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO3)->ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_WJLJXZ)->ShowWindow(SW_HIDE);
		GetDlgItem(IDOK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDCANCEL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIO1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIO2)->ShowWindow(SW_HIDE);
        //��ǩ1�Ŀؼ���ʾ
		GetDlgItem(IDC_LIST1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTONDEL)->ShowWindow(SW_SHOW);
	}
}
void CWDgldlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int pos;
	pos=m_list.GetSelectionMark();
	m_combo1.SelectString(-1,m_list.GetItemText(pos,3));

	*pResult = 0;
}

void CWDgldlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	int pos;
	pos=m_list.GetSelectionMark();
	SetCurTab(0); //�л�����ǩ0��
	//���б���������ӵ���ǩ0�ĸ����ؼ���
	CString strdwmc,strwdlb;

	strdwmc=m_list.GetItemText(pos,0);	
    m_combo3.SelectString(-1,strdwmc);

    OnSelchangeCombo3(); //�ȵ���ִ�иú���,������ȷִ����������

    strwdlb=m_list.GetItemText(pos,1);	
	m_combo4.SelectString(-1,strwdlb);

	m_wdbh=atoi(m_list.GetItemText(pos,2));
	m_wdmc=m_list.GetItemText(pos,3);
	m_gjz=m_list.GetItemText(pos,4);
	m_wjlj.SetWindowText(m_list.GetItemText(pos,5));
	m_memo=m_list.GetItemText(pos,6);


	*pResult = 0;
}


void CWDgldlg::OnSelchangeCombo3() //�Լ���ӵĺ���
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString strdwmc;
	m_combo3.GetLBText(m_combo3.GetCurSel(),strdwmc);//��õ�ǰѡ�еĵ�λ����
			
	dwb.Load_dep();
	mlb.Load_dep();
	xxb.Load_dep();
	m_combo4.ResetContent();//ɾ������
	for(int i=0;i<dwb.a_DWbh.GetSize();i++) //���ݵ�λ����ڵ�λ����������λ����
	{
		if(strdwmc == dwb.a_DWmc.GetAt(i))
		{
			for(int j=0;j<mlb.a_LBbh.GetSize();j++) //����������������������������
				if(atoi(dwb.a_DWbh.GetAt(i))==atoi(mlb.a_DWbh.GetAt(j)))
					//�Զ�����ǩҳ1�µ������Ͽ�����ĵ���� 		   
					m_combo4.AddString(mlb.a_LBmc.GetAt(j));
		}
	}
}
void CWDgldlg::OnBUTTONDelWD() //ɾ���ĵ��İ�ť��Ӧ����
{
	// TODO: Add your control notification handler code here
		
	CString wdmc;

	if(m_combo1.GetCurSel()==CB_ERR) 
	{
		MessageBox("�ĵ����Ʋ���Ϊ��,��ѡ���ĵ�!","�ĵ�����ϵͳ");
	    return;
	}
	else 
		m_combo1.GetLBText(m_combo1.GetCurSel(),wdmc);
	
	for(int i=0;i<xxb.a_WDbh.GetSize();i++)
	{
		if(wdmc==xxb.a_WDmc.GetAt(i))
		{
			wdbh=atoi(xxb.a_WDbh.GetAt(i));
		}
	}
	xxb.sql_delete(wdbh);
	zhi.SetDLsj(t.Format("%y-%m-%d"));
	zhi.SetName(user.GetUsername());
	zhi.SetDZ("�ĵ�ɾ��");
	zhi.sql_insert();	
	CDialog::OnOK();

}


BOOL CWDgldlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==13)
	{	pMsg->wParam=9;	
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}


