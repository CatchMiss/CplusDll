
// AppMFCView.cpp : CAppMFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "AppMFC.h"
#endif

#include "AppMFCDoc.h"
#include "AppMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAppMFCView

IMPLEMENT_DYNCREATE(CAppMFCView, CView)

BEGIN_MESSAGE_MAP(CAppMFCView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CAppMFCView 构造/析构

CAppMFCView::CAppMFCView()
{
	// TODO: 在此处添加构造代码

}

CAppMFCView::~CAppMFCView()
{
}

BOOL CAppMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CAppMFCView 绘制

void CAppMFCView::OnDraw(CDC* /*pDC*/)
{
	CAppMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CAppMFCView 打印

BOOL CAppMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CAppMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CAppMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CAppMFCView 诊断

#ifdef _DEBUG
void CAppMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CAppMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAppMFCDoc* CAppMFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAppMFCDoc)));
	return (CAppMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CAppMFCView 消息处理程序
