// saveAsCv.h : saveAsCv DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CsaveAsCvApp
// �йش���ʵ�ֵ���Ϣ������� saveAsCv.cpp
//

class CsaveAsCvApp : public CWinApp
{
public:
	CsaveAsCvApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
