// WordGLXTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WordGLXT.h"
#include "WordGLXTDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
CToolBar m_ToolBar;
CString strShow;        //��ʾ�ı���ʾ
CImageList m_ImageList; //ͼƬ�б�
char buf[512];           //��ʾ��ǰĿ¼

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordGLXTDlg dialog

CWordGLXTDlg::CWordGLXTDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWordGLXTDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWordGLXTDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_CHILDICON4);
}

void CWordGLXTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWordGLXTDlg)
	DDX_Control(pDX, IDC_RICHEDIT1, m_richedit);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWordGLXTDlg, CDialog)
	//{{AFX_MSG_MAP(CWordGLXTDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, OnDblclkTree1)
	ON_NOTIFY_EX(TTN_NEEDTEXT,0, OnToolTipNotify)
	ON_COMMAND(ID_MENUDWDAN, OnMenudwdan)
	ON_COMMAND(ID_MENUWDLB, OnMenuwdlb)	
	ON_COMMAND(ID_MENULIULWD, OnMenuliulwd)
	ON_COMMAND(ID_MENUYHGL, OnMenuyhgl)
	ON_COMMAND(ID_MENUMODPWD, OnMenumodpwd)
	ON_COMMAND(ID_MENUADDWD, OnMenuaddwd)
	ON_COMMAND(ID_MENUDELWD, OnMenudelwd)
	ON_COMMAND(ID_MENUMODWD, OnMenumodwd)
	ON_COMMAND(ID_MENURZGL, OnMenurzgl)
    ON_COMMAND(IDD_MENULookFileAttri, OnMENULookFileAttri)
    ON_COMMAND(ID_EXIT, OnExit)
	ON_COMMAND(ID_Button_Add, OnButtonAdd)
	ON_COMMAND(ID_Button_DwDA, OnButtonDwDA)
	ON_COMMAND(ID_Button_WDLB, OnButtonWDLB)
	ON_COMMAND(ID_Button_Modify, OnButtonModify)
	ON_COMMAND(ID_Button_Del, OnButtonDel)
	ON_COMMAND(ID_Button_Scan, OnButtonScan)
	ON_COMMAND(ID_Button_Attri, OnButtonAttri)
	ON_COMMAND(ID_Button_UserManage, OnButtonUserManage)
	ON_COMMAND(ID_Button_mimaModify, OnButtonmimaModify)
	ON_COMMAND(ID_Button_LogManage, OnButtonLogManage)
	ON_COMMAND(ID_Button_Exit, OnButtonExit)
	ON_COMMAND(ID_Menu_DBBackUp, OnMenuDBBackUp)
	ON_COMMAND(ID_Menu_DBRestore, OnMenuDBRestore)
	ON_COMMAND(ID_Button_BackUp, OnButtonBackUp)
	ON_COMMAND(ID_Button_Restore, OnButtonRestore)
	ON_COMMAND(ID_System_Exit, OnSystemExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordGLXTDlg message handlers

BOOL CWordGLXTDlg::OnInitDialog()
{

     CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CDialogin gin;
	
	if(gin.DoModal()!=IDOK)//������¼�Ի���
		                  OnOK();
	dwb.Load_dep();//�������ص�λ���еļ�¼����
	mlb.Load_dep();//�������������еļ�¼����
	xxb.Load_dep();//���������ĵ����еļ�¼����
	m_treeImageList.Create(16,16,ILC_MASK,4,1);
	m_treeImageList.Add(theApp.LoadIcon(IDI_ROOTICON)); //��ʾ��Ŀ¼ͼ��
	m_treeImageList.Add(theApp.LoadIcon(IDI_CHILDICON1));//��ʾһ��Ŀ¼��ͼ��
	m_treeImageList.Add(theApp.LoadIcon(IDI_CHILDICON2));//��ʾ����Ŀ¼��ͼ��
	m_treeImageList.Add(theApp.LoadIcon(IDI_CHILDICON4));//��ʾ����Ŀ¼��ͼ�꣬�����Ǹ�word��ͼ��
	m_tree.SetImageList(&m_treeImageList,LVSIL_NORMAL);
	m_root=m_tree.InsertItem("������Ϣ����",0,0);
	AddtoTree(m_root);
	m_tree.Expand(m_root,TVE_EXPAND);
    //״̬����ʾ���ݵ�����
	m_StatusBar.EnableAutomation();
	m_StatusBar.Create(WS_CHILD|WS_VISIBLE,CRect(0,0,0,0),this,0);
	
	int width[]={200,400};
	m_StatusBar.SetParts(4, &width[0]);
	m_StatusBar.SetText("����ʡ���տƼ����޹�˾",0,0);//��ʾ��λ����
    
	CString StatusText;
	StatusText.Format("��ǰ�û���%s",user.GetUsername());//��ʾ��ǰ�û�
	m_StatusBar.SetText(StatusText,0,1);
    
	t=CTime::GetCurrentTime();
	CString strdate;
	strdate.Format("��ǰ����:%s",t.Format("%y-%m-%d"));//��ʾ��ǰʱ��
	m_StatusBar.SetText(strdate,0,2);
    //��������ʾ���ݵ�����
	m_ImageList.Create(32,32,ILC_COLOR|ILC_MASK,1,1);  //����ͼ���б�
	
    m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONDWDA));  //��λ����
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONWDLB));    //�ĵ����
	
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONAdd));   //����ĵ�
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONMod));  //�޸��ĵ�
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONDel));   //ɾ���ĵ�
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONScan));   //����ĵ�
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONFileAttri));//�鿴����
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONUser));    //�û�����
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONMIMA));    //�����޸�
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONLog));       //��־����
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONSJKBF));      //����
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONSJKHF));      //�ָ�
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONExit));    //�˳�ϵͳ


	UINT array[16];
	for(int i=0;i<16;i++)
	{
		if(i==2||i==8||i==12)
		{
			array[i]=ID_SEPARATOR;//�������͵ھŸ���ťΪ�ָ���
		}
		else  array[i]=i+1101;
	}
	
	m_ToolBar.Create(this);
	m_ToolBar.SetButtons(array,16);
	m_ToolBar.SetButtonText(0,"��λ����");
	m_ToolBar.SetButtonText(1,"�ĵ����");
	m_ToolBar.SetButtonText(3,"����ĵ�");
	m_ToolBar.SetButtonText(4,"�޸��ĵ�");
	m_ToolBar.SetButtonText(5,"ɾ���ĵ�");
	m_ToolBar.SetButtonText(6,"����ĵ�");
	m_ToolBar.SetButtonText(7,"�鿴����");
	m_ToolBar.SetButtonText(9,"�û�����");
	m_ToolBar.SetButtonText(10,"�����޸�");
	m_ToolBar.SetButtonText(11,"��־����");
    m_ToolBar.SetButtonText(13,"��������");
    m_ToolBar.SetButtonText(14,"�ָ�����");
	m_ToolBar.SetButtonText(15,"�˳�ϵͳ");
    m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList);//����ͼ���б�
	
    m_ToolBar.SetSizes(CSize(60,60),CSize(32,32));//���ð�ť�Ͱ�ťλͼ��С
	m_ToolBar.EnableToolTips(true);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);//��ʾ������
    ::GetCurrentDirectory(512,buf);//��õ�ǰ·��,�������ݿ�ʱ�õ� 
	return TRUE; 
	// return TRUE  unless you set the focus to a control
}


void CWordGLXTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWordGLXTDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWordGLXTDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWordGLXTDlg::AddtoTree(HTREEITEM m_node) //����AddtoTree()�������������е�
                                               //���ݰ���νṹ��ӵ�Tree�ؼ���
{
	int i,j;
	for(i=0;i<dwb.a_DWbh.GetSize();i++)
	{
		arrays[i]=m_tree.InsertItem(dwb.a_DWmc.GetAt(i),1,1,m_node);
		for(j=0;j<mlb.a_DWbh.GetSize();j++)
		{
			if(atoi(dwb.a_DWbh.GetAt(i))==atoi(mlb.a_DWbh.GetAt(j)))
			{
				brrays[j]=m_tree.InsertItem(mlb.a_LBmc.GetAt(j),2,2,arrays[i]);
			}
		}
	}
	for(i=0;i<xxb.a_WDbh.GetSize();i++)
	{
		for(j=0;j<mlb.a_DWbh.GetSize();j++)
		{
			if(atoi(xxb.a_DWbh.GetAt(i))==atoi(mlb.a_DWbh.GetAt(j))&&atoi(xxb.a_LBbh.GetAt(i))==atoi(mlb.a_LBbh.GetAt(j)))
			{
				CString str = xxb.a_WDmc.GetAt(i);
				hitem[i]=m_tree.InsertItem(xxb.a_WDmc.GetAt(i),3,3,brrays[j]);
			}
		}
	}
	m_tree.SetRedraw();//�ػ����Ϳؼ�
}

void CWordGLXTDlg::OnMenudwdan() //������Ϣ-����λ����
{
	// TODO: Add your command handler code here
	CDwdandlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_tree.DeleteAllItems();
		dwb.Load_dep();//�������ص�λ���еļ�¼����
		mlb.Load_dep();//�������������еļ�¼����
		xxb.Load_dep();//���������ĵ����еļ�¼����
		m_root=m_tree.InsertItem("������Ϣ����",0,0);
		AddtoTree(m_root);
	}
}

void CWordGLXTDlg::OnMenuwdlb() //������Ϣ-���ĵ����
{
	// TODO: Add your command handler code here
	CWdlbiedlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_tree.DeleteAllItems();
		dwb.Load_dep();//�������ص�λ���еļ�¼����
		mlb.Load_dep();//�������������еļ�¼����
		xxb.Load_dep();//���������ĵ����еļ�¼����
		m_root=m_tree.InsertItem("������Ϣ����",0,0);
		AddtoTree(m_root);
	}
}

void CWordGLXTDlg::OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult) //���ؼ���˫���¼�
{
	// TODO: Add your control notification handler code here
	CString strWjian="";

	//��ȡ��ǰ�ڵ�
	temp = m_tree.GetSelectedItem();//��õ�ǰѡ�����ؼ�����Ŀ
	//����ǰ�ڵ��ӽڵ㸶��temp
	temp = m_tree.GetChildItem(temp);//��ȡָ�����ؼ�������Ŀ
	if (temp != NULL)
	{
		while (temp!= NULL)
		{
			//ȡ��temp�е��ı�
			CString strTemp = m_tree.GetItemText(temp);  // 
			strWjian += strTemp + "\n";			
			m_richedit.SetWindowText(strWjian);       //RichEdit�ؼ���ʾ����
			temp = m_tree.GetNextItem(temp,TVGN_NEXT);//��temp���ֵܽڵ㸶��temp
		}
	}
	else
	{
		temp = m_tree.GetSelectedItem(); //���»�õ�ǰѡ�����ؼ�����Ŀ
		for(int i=0;i<xxb.a_WDbh.GetSize();i++)
		{
			if(temp==hitem[i])
			{
				//ȡ��temp��Ӧ���ĵ�·��
				strWordpath = xxb.a_WJlj.GetAt(i);
				CFileFind file;
				if(!file.FindFile(strWordpath))
				{//�����ļ��Ƿ���ڣ���������������ݿ��еļ�¼
					MessageBox("�ļ������ڣ�","�ĵ�����ϵͳ");
					
					int	wdbh=0;
					wdbh = atoi(xxb.a_WDbh.GetAt(i));
					//ɾ�����ĵ�
					UpdateData(true);
					xxb.sql_delete(wdbh); //ɾ�����ĵ�
					MessageBox("���ݿ��и��ļ��ļ�¼��ɾ����","�ĵ�����ϵͳ");
					UpdateData(false);
					return ;
				}

			}
		}
		//wordӦ�ó���ĵ��� 
		_Application app;
		//��ʼ������
		//***�����ʼ������ʱ�Ľ��̳�ͻ����*****************
        LPDISPATCH  pDisp;
		LPUNKNOWN  pUnk;
		CLSID clsid;
		CLSIDFromProgID(L"word.Application",&clsid);
        if(GetActiveObject(clsid,NULL,&pUnk)==S_OK)
		{
			pUnk->QueryInterface(IID_IDispatch,(void**)&pDisp);
			app.AttachDispatch(pDisp);
			
		}
		else
		if(!app.CreateDispatch("word.Application"))   // ����word
		{ 
			MessageBox("Word����ʧ�ܣ�","�ĵ�����ϵͳ"); 
			return ;
		}
		//***�����ʼ������ʱ�Ľ��̳�ͻ����*****************

		Documents doc;
		CComVariant a (_T(strWordpath)),b(false),c(0),d(true),aa(0),bb(1);
		_Document doc1;
	     
		doc.AttachDispatch( app.GetDocuments());
		doc1.AttachDispatch(doc.Add(&a,&b,&c,&d));
		Range range;
		
		//ȡ���ĵ�����ѡ����
		range = doc1.GetContent();
		//ȡ���ļ�����
		strText = range.GetText();
		m_richedit.SetWindowText(strText);
		//�ر�
		app.Quit(&b,&c,&c);	
		//�ͷŻ���
		range.ReleaseDispatch();
		doc.ReleaseDispatch();
		doc1.ReleaseDispatch();
		app.ReleaseDispatch();

	}
	*pResult = 0;
}

void CWordGLXTDlg::OnMenuliulwd() //�ĵ�����-���ĵ����
{
	// TODO: Add your command handler code here
	CString strd,strs;
	xxb.Load_dep();
	for(int i=0;i<xxb.a_WDbh.GetSize();i++)
	{
		strd=xxb.a_WDmc.GetAt(i);
		strs+=strd+"\n";
		m_richedit.SetWindowText(strs);
	}
}

void CWordGLXTDlg::OnMenuyhgl() //�û�������
{
	// TODO: Add your command handler code here
	if(user.GetJB()=="1")
	{
		CYHgldlg dlg;
		dlg.DoModal();
	}
	else
	{
		MessageBox("û��Ȩ��","�ĵ�����ϵͳ");
		return;
	}	
}

void CWordGLXTDlg::OnMenumodpwd() //�����޸Ĺ���
{
	// TODO: Add your command handler code here
	CKLxgdlg dlg;
	dlg.DoModal();
}

void CWordGLXTDlg::OnMenuaddwd() //ʵ������ĵ�����
{
	// TODO: Add your command handler code here
	CWDgldlg dlg;
	dlg.str = 0;
	if(dlg.DoModal()==IDOK)
	{
		m_tree.DeleteAllItems();
		dwb.Load_dep();
		mlb.Load_dep();
		xxb.Load_dep();
		m_root=m_tree.InsertItem("������Ϣ����",0,0);
		AddtoTree(m_root);
	}
}

void CWordGLXTDlg::OnMenudelwd() //ʵ��ɾ���ĵ�����
{
	// TODO: Add your command handler code here
	CWDgldlg dlg;
	dlg.tabindex = 1;
	if(dlg.DoModal()==IDOK)
	{
		m_tree.DeleteAllItems();
		dwb.Load_dep();
		mlb.Load_dep();
		xxb.Load_dep();
		m_root=m_tree.InsertItem("������Ϣ����",0,0);
		AddtoTree(m_root);
	}
}

void CWordGLXTDlg::OnMenumodwd() //ʵ���޸��ĵ�����
{
	// TODO: Add your command handler code here
	CWDgldlg dlg;
	dlg.str = 1;
	if(dlg.DoModal()==IDOK)
	{
		m_tree.DeleteAllItems();
		dwb.Load_dep();
		mlb.Load_dep();
		xxb.Load_dep();
		m_root=m_tree.InsertItem("������Ϣ����",0,0);
		AddtoTree(m_root);
	}
}

void CWordGLXTDlg::OnMenurzgl() //ʵ����־������
{
	// TODO: Add your command handler code here
	ADOConn m_AdoConn;
    m_AdoConn.OnInitADOConn();
	CString sql,sqlzd="�û���\t��¼ʱ��\t����\n";
	sql.Format("select* from Rizhib");
	m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(m_AdoConn.m_pRecordset->adoEOF==0)
	{
		sqlzd+=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("name");
		sqlzd+="  \t";
		sqlzd+=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("DLsj");
		sqlzd+="\t";
		sqlzd+=(char*)(_bstr_t)m_AdoConn.m_pRecordset->GetCollect("dz");
		sqlzd+="\n";
		m_AdoConn.m_pRecordset->MoveNext();
		m_richedit.SetWindowText(sqlzd);
	}
	m_AdoConn.ExitConnect();
}

void CWordGLXTDlg::OnExit() 
{
	// TODO: Add your command handler code here
	OnOK();
}



BOOL CWordGLXTDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==13)
		pMsg->wParam=9;		
	return CDialog::PreTranslateMessage(pMsg);
}

void CWordGLXTDlg::OnMENULookFileAttri() //�쿴�ļ����Թ���
{
	// TODO: Add your command handler code here
	FileAttri dlg;
	if(strWordpath!="") 
	{
		dlg.pathname = strWordpath;	
		
		if(dlg.DoModal()==IDCANCEL) return ;
	}
	else dlg.DoModal();   
}

//��������ť��Ӧ����
void CWordGLXTDlg::OnButtonDwDA() 
{
	OnMenudwdan();
	// TODO: Add your command handler code here
	
}
void CWordGLXTDlg::OnButtonWDLB() 
{
	// TODO: Add your command handler code here
	OnMenuwdlb();
}

void CWordGLXTDlg::OnButtonAdd() 
{
	// TODO: Add your command handler code here
	OnMenuaddwd();
}

 

void CWordGLXTDlg::OnButtonModify() 
{
	// TODO: Add your command handler code here
	OnMenumodwd();
}

void CWordGLXTDlg::OnButtonDel() 
{
	// TODO: Add your command handler code here
	
	OnMenudelwd();
}

void CWordGLXTDlg::OnButtonScan() 
{
	// TODO: Add your command handler code here
	OnMenuliulwd();
}

void CWordGLXTDlg::OnButtonAttri() 
{
	// TODO: Add your command handler code here
	OnMENULookFileAttri();
}


void CWordGLXTDlg::OnButtonUserManage() 
{
	// TODO: Add your command handler code here
	OnMenuyhgl();
}


void CWordGLXTDlg::OnButtonmimaModify() 
{
	// TODO: Add your command handler code here
	OnMenumodpwd();
	
}

void CWordGLXTDlg::OnButtonLogManage() 
{
	// TODO: Add your command handler code here
	OnMenurzgl();
}



void CWordGLXTDlg::OnButtonExit() 
{
	// TODO: Add your command handler code here
  
	OnOK();
}



void CWordGLXTDlg::OnMenuDBBackUp() 
{
	// TODO: Add your command handler code here
	ADOConn m_AdoConn;

	CString sql,strpath,m_filename;
	strcat(buf,"\\DataBase\\WDGL_Data.DAT");
	strpath.Format("%s",buf);
	m_filename="WDGL_Data";
	sql = "use master exec sp_addumpdevice 'disk','"+m_filename+"','"+strpath+"' backup database WenDGL to "+m_filename+" ";
	if(AfxMessageBox("��ȷ��Ҫ�������ݿ���?",MB_OKCANCEL)==IDCANCEL)  	return; 
	   	
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	MessageBox("���ݿⱸ�ݳɹ���","ϵͳ��ʾ",MB_OK|MB_ICONEXCLAMATION);
		
}

void CWordGLXTDlg::OnMenuDBRestore() 
{
	// TODO: Add your command handler code here
	ADOConn m_AdoConn;
	CString sql,m_filename;
	m_filename="WDGL_Data";
	sql = "use master  restore database WenDGL from "+m_filename+" ";
	if(AfxMessageBox("��ԭ���ݿ⽫����ԭ�������ݿ⡣��ȷ��Ҫ��ԭ��?",MB_OKCANCEL)==IDCANCEL) 
	return; 
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	MessageBox("���ݿ�ָ���ɣ�","ϵͳ��ʾ",MB_OK|MB_ICONEXCLAMATION); 
}

void CWordGLXTDlg::OnButtonBackUp() 
{
	// TODO: Add your command handler code here
	OnMenuDBBackUp();
}

void CWordGLXTDlg::OnButtonRestore() 
{
	// TODO: Add your command handler code here
	OnMenuDBRestore();
}

void CWordGLXTDlg::OnSystemExit() 
{
	// TODO: Add your command handler code here
	OnOK();
}

bool CWordGLXTDlg::OnToolTipNotify(UINT id, NMHDR *pNMHDR, LRESULT *pResult)
{
	

	TOOLTIPTEXT *pTTT=(TOOLTIPTEXT*)pNMHDR;	 
	UINT nID=pNMHDR->idFrom; //��ȡ��������ťID
	 
	 if(nID)
	 {
		 nID = m_ToolBar.CommandToIndex(nID);//����ID��ȡ��ť����
		 if(nID!=-1)
		 {
			 
			 m_ToolBar.GetButtonText(nID,strShow); //��ȡ�������ı�
		     pTTT->lpszText=strShow.GetBuffer(strShow.GetLength());//������ʾ��Ϣ�ı�
             pTTT->hinst = AfxGetResourceHandle();
			 return(true);
		 }
	 }
	 return(false);


}
