
// AppMFCView.cpp : CAppMFCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CAppMFCView ����/����

CAppMFCView::CAppMFCView()
{
	// TODO: �ڴ˴���ӹ������

}

CAppMFCView::~CAppMFCView()
{
}

BOOL CAppMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CAppMFCView ����

void CAppMFCView::OnDraw(CDC* /*pDC*/)
{
	CAppMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CAppMFCView ��ӡ

BOOL CAppMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CAppMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CAppMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CAppMFCView ���

#ifdef _DEBUG
void CAppMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CAppMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAppMFCDoc* CAppMFCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAppMFCDoc)));
	return (CAppMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CAppMFCView ��Ϣ�������
