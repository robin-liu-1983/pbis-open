// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���A
//            �܂��͎Q�Ɖ񐔂������A�����܂�ύX����Ȃ�
//            �v���W�F�N�g��p�̃C���N���[�h �t�@�C�����L�q���܂��B

#if !defined(AFX_STDAFX_H__F1B27DC3_C4B6_4033_B4D8_1498EFD02550__INCLUDED_)
#define AFX_STDAFX_H__F1B27DC3_C4B6_4033_B4D8_1498EFD02550__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
// CComModule �N���X����h�������N���X���g�p���āA�I�[�o�[���C�h����ꍇ
// _Module �̖��O�͕ύX���Ȃ��ł��������B
class CExeModule : public CComModule
{
public:
	LONG Unlock();
	DWORD dwThreadID;
	HANDLE hEventShutdown;
	void MonitorShutdown();
	bool StartMonitor();
	bool bActivity;
};
extern CExeModule _Module;
#include <atlcom.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_STDAFX_H__F1B27DC3_C4B6_4033_B4D8_1498EFD02550__INCLUDED)