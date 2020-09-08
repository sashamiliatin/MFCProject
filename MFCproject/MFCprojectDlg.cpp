
// MFCprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"

#include <wingdi.h>

#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#define WM_CTLCOLOR
#endif

// CMFCprojectDlg dialog



CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDOK, &CMFCprojectDlg::OnBnClickedOk)
	ON_WM_RBUTTONDBLCLK()
	ON_COMMAND(ID_DRAW_RECTANGLE, &CMFCprojectDlg::OnDrawRectangle)
	ON_COMMAND(ID_DRAW_ELIPCE, &CMFCprojectDlg::OnDrawElipce)
	ON_COMMAND(ID_DRAW_DAVIDSTAR, &CMFCprojectDlg::OnDrawDavidstar)
	ON_COMMAND(ID_PENSIZE_1, &CMFCprojectDlg::OnPensize1)
	ON_COMMAND(ID_FILE_SAVE32771, &CMFCprojectDlg::OnFileSave32771)
	ON_COMMAND(ID_FILE_LOAD, &CMFCprojectDlg::OnFileLoad)
	ON_COMMAND(ID_PENSIZE_2, &CMFCprojectDlg::OnPensize2)
	ON_COMMAND(ID_PENSIZE_3, &CMFCprojectDlg::OnPensize3)
	ON_COMMAND(ID_PENCOLOR, &CMFCprojectDlg::OnPencolor)
	ON_COMMAND(ID_BRUSHCOLOR, &CMFCprojectDlg::OnBrushcolor)
	ON_COMMAND(ID_DRAW_SQUARE, &CMFCprojectDlg::OnDrawSquare)
END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//m_window_background.CreateSolidBrush(RGB(0x00, 0x00, 0xff));

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	// TODO: Add extra initialization here
	CMenu *pMenu = GetMenu();
	if (pMenu != NULL)
	{
		pMenu->CheckMenuItem(ID_DRAW_RECTANGLE, MF_CHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_ELIPCE, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_DAVIDSTAR, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_SQUARE, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_PENSIZE_1, MF_CHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_PENSIZE_2, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_PENSIZE_3, MF_UNCHECKED | MF_BYCOMMAND);
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < figs.GetSize(); i++)
			figs[i]->Draw(&dc);
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	start = point;
	isPressed = true;
	CPaintDC dc(this);
    //!! 20 b
	//figs.Add(new Figure(start, start));
	switch (futureFigureKind)
	{
	case 1:
		figs.Add(new RectangleF(start, start));
		break;
	case 2:
  	    figs.Add(new EllipseF(start, start));
		break;
	case 3:
		figs.Add(new DavidStar(start, start));
		break;
	case 4:
		figs.Add(new SquareF(start, start));
		break;
	}
	//!! 20 e
	figs[figs.GetSize() - 1]->SetBgColor(_BgColor);
	figs[figs.GetSize() - 1]->SetPenColor(_PenColor);
	figs[figs.GetSize() - 1]->SetPenSize(_PenSize);
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	if (isPressed)
	{
		end = point;
		isPressed = false;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		end = point;
		figs[figs.GetSize()-1]->Redefine(start,end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CMFCprojectDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CMFCprojectDlg::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	//RESIE
	// TODO: Add your message handler code here and/or call default
	CPaintDC dc(this); // device context for painting
	for (int i = 0; i < figs.GetSize(); i++)
	{
		if (figs[i]->isInside(point))
		{
			AfxMessageBox(L"You ara in the area!!!");
		}
	}


	CDialogEx::OnRButtonDblClk(nFlags, point);
}


void CMFCprojectDlg::OnDrawRectangle()
{
	futureFigureKind = 1;
	CMenu *pMenu = GetMenu();
	if (pMenu != NULL )
	{
		pMenu->CheckMenuItem(ID_DRAW_RECTANGLE, MF_CHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_ELIPCE, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_DAVIDSTAR, MF_UNCHECKED | MF_BYCOMMAND);
	}
}


void CMFCprojectDlg::OnDrawElipce()
{
	futureFigureKind = 2;
	CMenu *pMenu = GetMenu();
	if (pMenu != NULL)
	{
		pMenu->CheckMenuItem(ID_DRAW_RECTANGLE, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_ELIPCE, MF_CHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_DAVIDSTAR, MF_UNCHECKED | MF_BYCOMMAND);
	}
}


void CMFCprojectDlg::OnDrawDavidstar()
{
	futureFigureKind = 3;
	CMenu *pMenu = GetMenu();
	if (pMenu != NULL)
	{
		pMenu->CheckMenuItem(ID_DRAW_RECTANGLE, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_ELIPCE, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_DAVIDSTAR, MF_CHECKED | MF_BYCOMMAND);
	}
}

void CMFCprojectDlg::OnFileSave32771()
{
	// TODO: Add your control notification handler code here
//!! 23 b
			 // FALSE to SAVE
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}

	//!! 23 e
}


void CMFCprojectDlg::OnFileLoad()
{
//!! 24 b
			 // TRUE to LOAD
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
	//!! 24 e
}

void CMFCprojectDlg::OnPensize1()
{
	_PenSize = 1;
	CMenu *pMenu = GetMenu();
	if (pMenu != NULL)
	{
		pMenu->CheckMenuItem(ID_PENSIZE_1, MF_CHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_PENSIZE_2, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_PENSIZE_3, MF_UNCHECKED | MF_BYCOMMAND);
	}
}

void CMFCprojectDlg::OnPensize2()
{
	_PenSize = 2;
	CMenu *pMenu = GetMenu();
	if (pMenu != NULL)
	{
		pMenu->CheckMenuItem(ID_PENSIZE_1, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_PENSIZE_2, MF_CHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_PENSIZE_3, MF_UNCHECKED | MF_BYCOMMAND);
	}
}


void CMFCprojectDlg::OnPensize3()
{
	_PenSize = 3;
	CMenu *pMenu = GetMenu();
	if (pMenu != NULL)
	{
		pMenu->CheckMenuItem(ID_PENSIZE_1, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_PENSIZE_2, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_PENSIZE_3, MF_CHECKED | MF_BYCOMMAND);
	}
}


void CMFCprojectDlg::OnPencolor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		COLORREF color = dlg.GetColor();
		 _PenColor= color;
	}
}


void CMFCprojectDlg::OnBrushcolor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		COLORREF color = dlg.GetColor();
		_BgColor = color;
	}
}


void CMFCprojectDlg::OnDrawSquare()
{
	futureFigureKind = 4;
	CMenu *pMenu = GetMenu();
	if (pMenu != NULL)
	{
		pMenu->CheckMenuItem(ID_DRAW_RECTANGLE, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_ELIPCE, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_DAVIDSTAR, MF_UNCHECKED | MF_BYCOMMAND);
		pMenu->CheckMenuItem(ID_DRAW_SQUARE, MF_CHECKED | MF_BYCOMMAND);
	}
}
