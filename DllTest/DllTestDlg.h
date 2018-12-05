
// DllTestDlg.h : 头文件
//

#pragma once

#include "..\AliPayWin32\Alipay.h"

class CAlipay;

// CDllTestDlg 对话框
class CDllTestDlg : public CDialogEx
{
// 构造
public:
	CDllTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DLLTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
