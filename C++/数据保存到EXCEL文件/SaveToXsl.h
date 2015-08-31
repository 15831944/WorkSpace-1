// SaveToXsl.h: interface for the CSaveToXsl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAVETOXSL_H__EFE0B670_09CE_403C_BD10_000AD8243EAA__INCLUDED_)
#define AFX_SAVETOXSL_H__EFE0B670_09CE_403C_BD10_000AD8243EAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxdb.h>
#include <odbcinst.h>
#include <io.h>

class CSaveToXsl  
{
public:
	CSaveToXsl();
	virtual ~CSaveToXsl();
public:
	CDatabase m_database;
	void Initialize(CString strTitle/*����*/,CString strCreateName/*�ֶ���*/,CString strName);
	BOOL InsertToTable(CString strV);
	void GetFileName(CString strFileName = ""); //�����ļ���

private :
	CString m_strH ;  //�����ֶ���
	CString m_tableName ;//�������
	CString m_strFileName ;//Excel�ļ���
private:
	CString GetExcelDriver();
	BOOL GetDefaultXlsFileName(CString& sExcelFile);
	BOOL MakeSurePathExists( CString &Path,bool FilenameIncluded);
};

#endif // !defined(AFX_SAVETOXSL_H__EFE0B670_09CE_403C_BD10_000AD8243EAA__INCLUDED_)
