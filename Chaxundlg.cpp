#include "stdafx.h"
#include "WordGLXT.h"
#include "Chaxundlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
	
	)DDX_Control(pDX, IDC_COMBO1, m_cxfs);
	DDX_Text(pDX, IDC_EDIT1, m_cxz);
	
}


BEGIN_MESSAGE_MAP(CChaxundlg, CDialog)

END_MESSAGE_MAP()

BOOL CChaxundlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	

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
	return TRUE;  

void CChaxundlg::OnOK() 
{
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
