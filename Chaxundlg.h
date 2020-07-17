#if !defined(AFX_CHAXUNDLG_H__47D1A1A4_7D4D_4A71_AE77_5FB0FDD17D2D__INCLUDED_)
#define AFX_CHAXUNDLG_H__47D1A1A4_7D4D_4A71_AE77_5FB0FDD17D2D__INCLUDED_
#include "Zdxxb.h"
#include "Dwxxb.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Chaxundlg.h : header file
//
extern CZdxxb zdxxb;
/////////////////////////////////////////////////////////////////////////////
// CChaxundlg dialog

class CChaxundlg : public CDialog
{
// Construction
public:
	int cx;
	CChaxundlg(CWnd* pParent = NULL);   // standard constructor
	CDwxxb dwb;
	CZdxxb xxb;

// Dialog Data
	//{{AFX_DATA(CChaxundlg)
	CComboBox	m_cxfs;
	CString	m_cxz;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChaxundlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CChaxundlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAXUNDLG_H__47D1A1A4_7D4D_4A71_AE77_5FB0FDD17D2D__INCLUDED_)
