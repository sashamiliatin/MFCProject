
// MFCprojectDlg.h : header file
//

#pragma once

#include "Figure.h"
//!! 17 b
#include "RectangleF.h"
#include "EllipseF.h"
#include "DavidStar.h"
#include "SquareF.h"
//!! 17 e

// CMFCprojectDlg dialog
class CMFCprojectDlg : public CDialogEx
{
// Construction
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);	// standard constructor
	COLORREF _PenColor = RGB(0, 0, 0);
	COLORREF _BgColor = RGB(255, 255, 255);
	int _PenSize = 1;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	CPoint start, end;
	bool isPressed=false;
	 CTypedPtrArray< CObArray, Figure*> figs;
     //!! 17 b
	 int futureFigureKind = 1; //Rectangle (2 - Ellipse)
	 //TODO add menu draw default selecte 
	 //!! 17 e
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedOk();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDrawRectangle();
	afx_msg void OnDrawElipce();
	afx_msg void OnDrawDavidstar();
	afx_msg void OnPensize1();
	afx_msg void OnFileSave32771();
	afx_msg void OnFileLoad();
	afx_msg void OnPensize2();
	afx_msg void OnPensize3();
	afx_msg void OnPencolor();
	afx_msg void OnBrushcolor();
	afx_msg void OnDrawSquare();
};
