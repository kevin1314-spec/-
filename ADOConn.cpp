#include "stdafx.h"
#include "WordGLXT.h"
#include "ADOConn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



ADOConn::ADOConn()
{

}

ADOConn::~ADOConn()
{

}

void ADOConn::OnInitADOConn()
{
	
    ::CoInitialize(NULL);
	try
	{
		
		m_pConnection.CreateInstance(__uuidof(Connection));
	   
	  
	   _bstr_t strConnect="Provider=SQLOLEDB.1;Integrated Security=SSPI;\
		   Persist Security Info=False;Initial Catalog=WenDGL;Data Source=.\\";
	  
	   m_pConnection->Open(strConnect,"","",adModeUnknown);
	}
	
	catch(_com_error e)
	{
		
		AfxMessageBox(e.Description());
	}
}

_RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
    try
	{
	
		if(m_pConnection==NULL)
              OnInitADOConn();
        m_pRecordset.CreateInstance("ADODB.Recordset");
        m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
    catch(_com_error e)
	{
		e.Description();
	    return m_pRecordset;
	}

		
}

BOOL ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	_variant_t RecordsAffected;
	try
	{
        if(m_pConnection==NULL)
	     	OnInitADOConn();

        m_pConnection->Execute(bstrSQL,NULL,adCmdText); 
		return true;
	}
	catch(_com_error e)
	{
		e.Description();
		return false;
	}
}

void ADOConn::ExitConnect()
{
    if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
	::CoUninitialize();
}
