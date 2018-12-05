
// DllTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DllTest.h"
#include "DllTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDllTestDlg �Ի���



CDllTestDlg::CDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDllTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAlipay = NULL;
}

void CDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDllTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_TEST, &CDllTestDlg::OnBnClickedBtnTest)
	ON_BN_CLICKED(IDOK, &CDllTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDllTestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BTN_PAY_TEST, &CDllTestDlg::OnBnClickedBtnPayTest)
	ON_BN_CLICKED(ID_BTN_RESET, &CDllTestDlg::OnBnClickedBtnReset)
END_MESSAGE_MAP()


// CDllTestDlg ��Ϣ�������

BOOL CDllTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	InitData();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDllTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDllTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDllTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDllTestDlg::OnBnClickedBtnTest()
{
	if (!m_pAlipay)
	{
		m_pAlipay = new CAlipay;

		CString m_strAppID, m_strPKey, m_strPubKey;
		GetDlgItemText(IDC_EDIT_APPID, m_strAppID);
		if (m_strAppID.IsEmpty())
		{
			AfxMessageBox("AppiD is NULL!");
			m_pAlipay = NULL;
			return;
		}
		m_pAlipay->SetAppID(m_strAppID.GetBuffer());

		GetDlgItemText(IDC_EDIT_PKEY, m_strPKey);
		if (m_strPKey.IsEmpty())
		{
			AfxMessageBox("PKey is NULL!");
			m_pAlipay = NULL;
			return;
		}
		else
		{
			if (m_strPKey.Find("-----BEGIN RSA PRIVATE KEY-----") <0)
			{
				m_strPKey = "-----BEGIN RSA PRIVATE KEY-----\n" + m_strPKey;
			}
			if (m_strPKey.Find("-----END RSA PRIVATE KEY-----") <0)
			{
				m_strPKey = m_strPKey + "\n-----END RSA PRIVATE KEY-----";
			}
			SetDlgItemText(IDC_EDIT_PKEY, m_strPKey);
		}
		m_pAlipay->SetPrivateKey(m_strPKey.GetBuffer());

		GetDlgItemText(IDC_EDIT_PUBKEY, m_strPubKey);
		if (m_strPubKey.IsEmpty())
		{
			AfxMessageBox("PubKey is NULL!");
			m_pAlipay = NULL;
			return;
		}
		else
		{
			if (m_strPubKey.Find("-----BEGIN PUBLIC KEY-----") < 0)
			{
				m_strPubKey = "-----BEGIN PUBLIC KEY-----\n" + m_strPubKey;
			}
			if (m_strPubKey.Find("-----END PUBLIC KEY-----") < 0)
			{
				m_strPubKey = m_strPubKey + "\n-----END PUBLIC KEY-----";
			}
			SetDlgItemText(IDC_EDIT_PUBKEY, m_strPubKey);
		}
		m_pAlipay->SetPublicAliKey(m_strPubKey.GetBuffer());

		UpdateData(FALSE);
	}



	CString m_strPayNO, m_strPayTitle, m_strPayTotal, m_strPayCard;
	GetDlgItemText(IDC_EDIT_NO,m_strPayNO);
	GetDlgItemText(IDC_EDIT_TITLE, m_strPayTitle);
	GetDlgItemText(IDC_EDIT_TOTAL, m_strPayTotal);
	GetDlgItemText(IDC_EDIT_PAYCODE, m_strPayCard);

	double dPayTotal = 0.0f;
	dPayTotal = atof(m_strPayTotal);

	if (dPayTotal > 5.0f)
	{
		AfxMessageBox("���޴�!");
		return;
	}

	CString m_strRet;
	std::string strRetMsg;
	int nRet = m_pAlipay->BarcodePay(m_strPayNO.GetBuffer(),m_strPayCard.GetBuffer(),dPayTotal,m_strPayTitle.GetBuffer());
	m_pAlipay->GetRetMsg(strRetMsg);
	if (nRet == -1)
	{
		m_strRet.Format("Error---%s", strRetMsg.c_str());
		AfxMessageBox(m_strRet);
	}
	else
	{
		m_strRet.Format("Success---%s", strRetMsg.c_str());
		AfxMessageBox(m_strRet);
		SetDlgItemText(IDC_EDIT_PAYCODE, "");
		UpdateData(FALSE);
	}
	InitData();
}

void CDllTestDlg::InitData()
{
	CString m_strPayNo;
	SYSTEMTIME systime;
	GetLocalTime(&systime);
	m_strPayNo.Format(_T("%04d%02d%02d%02d%02d%02d%02d"), systime.wYear, systime.wMonth, systime.wDay, systime.wHour, systime.wHour, systime.wSecond, systime.wMilliseconds);

	SetDlgItemText(IDC_EDIT_NO, m_strPayNo);

	CString m_strTotal = "0.01";
	SetDlgItemText(IDC_EDIT_TOTAL, m_strTotal);

	CString m_strTitle = "���渶-����֧��-Test";
	SetDlgItemText(IDC_EDIT_TITLE, m_strTitle);

	SetDlgItemText(IDC_EDIT_PAYCODE, "");

	UpdateData(FALSE);
}


void CDllTestDlg::OnBnClickedOk()
{
	//InitData();
	//CDialogEx::OnOK();
}


void CDllTestDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CDllTestDlg::OnBnClickedBtnPayTest()
{
	if (!m_pAlipay)
	{
		m_pAlipay = new CAlipay;
	}

	CString m_strRet;
	std::string strRetMsg;
	int nRet = m_pAlipay->TestPay();
	m_pAlipay->GetRetMsg(strRetMsg);
	if (nRet == -1)
	{
		m_strRet.Format("Error---%s", strRetMsg.c_str());
		AfxMessageBox(m_strRet);
	}
	else
	{
		m_strRet.Format("Success---%s", strRetMsg.c_str());
		AfxMessageBox(m_strRet);
	}
	if (m_pAlipay)
	{
		m_pAlipay = NULL;
	}
}


void CDllTestDlg::OnBnClickedBtnReset()
{
	// Reset
	InitData();
	SetDlgItemText(IDC_EDIT_APPID, "");
	SetDlgItemText(IDC_EDIT_PKEY, "");
	SetDlgItemText(IDC_EDIT_PUBKEY, "");

	if (m_pAlipay)
	{
		m_pAlipay = NULL;
	}

	UpdateData(FALSE);

}
