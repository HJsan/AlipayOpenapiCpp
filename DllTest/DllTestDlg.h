
// DllTestDlg.h : ͷ�ļ�
//

#pragma once

#include "..\AliPayWin32\Alipay.h"

class CAlipay;

// CDllTestDlg �Ի���
class CDllTestDlg : public CDialogEx
{
// ����
public:
	CDllTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DLLTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnTest();
public:
	void InitData();
public:
	CAlipay *m_pAlipay;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBtnPayTest();
	afx_msg void OnBnClickedBtnReset();
};
