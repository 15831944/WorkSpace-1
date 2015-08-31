// SaveToXsl.cpp: implementation of the CSaveToXsl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SaveToXsl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSaveToXsl::CSaveToXsl()
{
	m_strH = "";
	m_strFileName = "";
}

CSaveToXsl::~CSaveToXsl()
{
	if(m_database.IsOpen())
	m_database.Close();
}

void CSaveToXsl::GetFileName(CString strFileName)
{
	///Ĭ���ļ���
	if(strFileName == "")
		GetDefaultXlsFileName(m_strFileName);
	else 
		m_strFileName = strFileName ;
			
}

void CSaveToXsl::Initialize(CString strTitle/*����*/,CString strCreateName/*�ֶ���*/,CString strName)
{	//strNames = "���� TEXT,���� TEXT,ʱ�� TEXT" ��
		CString warningStr;
		CString sDriver;
		CString sSql = ""; //SQL ���
		m_tableName = strTitle;
		m_strH = strName;  //�����ֶ���	

		// �����Ƿ�װ��Excel���� "Microsoft Excel Driver (*.xls)" 
		sDriver = GetExcelDriver();
		if (sDriver.IsEmpty())
		{
			// û�з���Excel����
			AfxMessageBox("û�а�װExcel!\n���Ȱ�װExcel�������ʹ�õ�������!");
			return;
		}

		if(m_strFileName == "")
		{
			GetFileName() ;
		}
	// �������д�ȡ���ַ���
		sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, m_strFileName, m_strFileName);
		
		// �������ݿ� (��Excel����ļ�)
		if( m_database.OpenEx(sSql,CDatabase::noOdbcDialog) )
		{
			// ������ṹ
			sSql = "CREATE TABLE " + m_tableName + " ( " + strCreateName +  " ) ";
			m_database.ExecuteSQL(sSql);
		}      
}

BOOL CSaveToXsl::InsertToTable(CString strV/*�ֶ�ֵ*/)
{
	// strV = " '10' ,'0', '2006:10:15' " ;
	if(!m_database.IsOpen()) 
	{
		AfxMessageBox("���ݿ�δ��");
		return FALSE ;
	}

	CString sSql = "";
	sSql = "INSERT INTO " + m_tableName + "(" + m_strH + ")" + "VALUES(" + strV + ")";
	m_database.ExecuteSQL(sSql);
	return TRUE ;
}


CString CSaveToXsl::GetExcelDriver()
{
    char szBuf[2001];
    WORD cbBufMax = 2000;
    WORD cbBufOut;
    char *pszBuf = szBuf;
    CString sDriver;
	
    // ��ȡ�Ѱ�װ����������(������odbcinst.h��)
    if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))
        return "";
    
    // �����Ѱ�װ�������Ƿ���Excel...
    do
    {
        if (strstr(pszBuf, "Excel") != 0)
        {
            //���� !
            sDriver = CString(pszBuf);
            break;
        }
        pszBuf = strchr(pszBuf, '\0') + 1;
    }
    while (pszBuf[1] != '\0');
	
    return sDriver;
}

BOOL CSaveToXsl::MakeSurePathExists( CString &Path,bool FilenameIncluded)
{
	int Pos=0;
	while((Pos=Path.Find('\\',Pos+1))!=-1)
		CreateDirectory(Path.Left(Pos),NULL);
	if(!FilenameIncluded)
		CreateDirectory(Path,NULL);
	//	return ((!FilenameIncluded)?!_access(Path,0):
	//	!_access(Path.Left(Path.ReverseFind('\\')),0));
	
	return !_access(Path,0);
}

//���Ĭ�ϵ��ļ���
BOOL CSaveToXsl::GetDefaultXlsFileName(CString& sExcelFile)
{
	///Ĭ���ļ�����yyyymmddhhmmss.xls
	CString timeStr;
	CTime day;
	day=CTime::GetCurrentTime();
	int filenameday,filenamemonth,filenameyear,filehour,filemin,filesec;
	filenameday=day.GetDay();//dd
	filenamemonth=day.GetMonth();//mm�·�
	filenameyear=day.GetYear();//yyyy
	filehour=day.GetHour();//hh
	filemin=day.GetMinute();//mm����
	filesec=day.GetSecond();//ss
	timeStr.Format("%04d%02d%02d%02d%02d%02d",filenameyear,filenamemonth,filenameday,filehour,filemin,filesec);
	
	sExcelFile =  timeStr + ".xls";
	// prompt the user (with all document templates)
	CFileDialog dlgFile(FALSE,".xls",sExcelFile);
	CString title;
	CString strFilter;
	
	title = "����";
	strFilter = "Excel�ļ�(*.xls)";
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.xls");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;
	dlgFile.m_ofn.nFilterIndex = 1;
	// append the "*.*" all files filter
	CString allFilter;
	VERIFY(allFilter.LoadString(AFX_IDS_ALLFILTER));
	strFilter += allFilter;
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.*");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;
	
	dlgFile.m_ofn.lpstrFilter = strFilter;
	dlgFile.m_ofn.lpstrTitle = title;
	
	if (dlgFile.DoModal()==IDCANCEL)
		return FALSE; // open cancelled
	sExcelFile.ReleaseBuffer();
	if (MakeSurePathExists(sExcelFile,true)) {
		if(!DeleteFile(sExcelFile)) {    // delete the file
			AfxMessageBox("�����ļ�ʱ����");
			return FALSE;
		}
	}
	CString str = dlgFile.GetFileTitle();
	sExcelFile = str + _T(".xls");
	return TRUE;
}