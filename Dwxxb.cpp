// Dwxxb.cpp: implementation of the CDwxxb class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WordGLXT.h"
#include "Dwxxb.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDwxxb::CDwxxb()
{

}

CDwxxb::~CDwxxb()
{

}

int CDwxxb::GetDWbh()
{
	return DWbh;
}

void CDwxxb::SetDWbh(int iDWbh)
{
	DWbh=iDWbh;
}

CString CDwxxb::GetDWmc()
{
	return DWmc;
}

void CDwxxb::SetDWmc(CString cDWmc)
{
	DWmc=cDWmc;
}

CString CDwxxb::GetLxr()
{
	return Lxr;
}

void CDwxxb::SetLxr(CString cLxr)
{
	Lxr=cLxr;
}

CString CDwxxb::GetLxdh()
{
	return Lxdh;
}

void CDwxxb::SetLxdh(CString cLxdh)
{
	Lxdh=cLxdh;
}

CString CDwxxb::GetLxdz()
{
	return Lxdz;
}

void CDwxxb::SetLxdz(CString cLxdz)
{
	Lxdz=cLxdz;
}

CString CDwxxb::GetMemo()
{
	
	return Memo;
}

void CDwxxb::SetMemo(CString cMemo)
{
	Memo=cMemo;
}

void CDwxxb::sql_insert()
{
    ADOConn m_AdoConn;
	CString vSQL;
	vSQL.Format("INSERT INTO Dwxxb(DWbh,DWmc,Lxr,Lxdh,Lxdz,Memo)VALUES(%d,'"
		+DWmc+"','"+Lxr+"','"+Lxdh+"','"+Lxdz+"','"+Memo+"')",DWbh);
    m_AdoConn.ExecuteSQL(_bstr_t(vSQL));
    m_AdoConn.ExitConnect();
}

void CDwxxb::sql_update(int iDWbh)
{
    ADOConn m_AdoConn;	 
	 CString vSQL;
	 vSQL.Format("UPDATE Dwxxb SET DWmc='"+DWmc+"',Lxr='"+Lxr+"',Lxdh='"
		+Lxdh+"',Lxdz='"+Lxdz+"',Memo='"+Memo+"' WHERE DWbh=%d",iDWbh);
    m_AdoConn.ExecuteSQL(_bstr_t(vSQL));
	m_AdoConn.ExitConnect();
}

void CDwxxb::sql_delete(int iDWbh)
{
    ADOConn m_AdoConn;
    m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from Dwxxb where DWbh='%i'",iDWbh);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
}

void CDwxxb::Load_dep()
{
	//�������ݿ�
    ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();

    //����SQL���
	_bstr_t vSQL="SELECT*FROM Dwxxb ORDER BY DWbh";
    _RecordsetPtr m_pRecordset=m_AdoConn.GetRecordSet(vSQL);
   
	//��ʼ������
	a_DWbh.RemoveAll();       //��λ���;
	a_DWmc.RemoveAll();       //��λ����
	while(m_pRecordset->adoEOF==0)
	{
		a_DWbh.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("DWbh"));
		a_DWmc.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("DWmc"));
		m_pRecordset->MoveNext();//��һ����¼��
	}
	m_AdoConn.ExitConnect();    //�Ͽ����ݿ������
}

int CDwxxb::HaveId(int iDWbh)   //�������ݿ⣬����û��ָ�������ļ�¼
{
	ADOConn m_AdoConn;
    m_AdoConn.OnInitADOConn();
	CString strDWbh;
	_RecordsetPtr m_pRecordset;
		
	strDWbh.Format("SELECT*FROM Dwxxb WHERE DWbh=%d",iDWbh);
	m_pRecordset=m_AdoConn.GetRecordSet(_bstr_t(strDWbh));
	return (m_pRecordset->adoEOF)?-1:1;
	m_AdoConn.ExitConnect();
}
