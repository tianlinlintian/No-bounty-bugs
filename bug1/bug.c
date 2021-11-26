

/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
 /* Compiler settings for idl.idl:
     Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622
     protocol : all , ms_ext, c_ext, robust
     error checks: allocation ref bounds_check enum stub_data
     VC __declspec() decoration level:
          __declspec(uuid()), __declspec(selectany), __declspec(novtable)
          DECLSPEC_UUID(), MIDL_INTERFACE()
 */
 /* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/

#include <string.h>

#include "idl_h.h"

#define TYPE_FORMAT_STRING_SIZE   85                                
#define PROC_FORMAT_STRING_SIZE   67                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _idl_MIDL_TYPE_FORMAT_STRING
{
    short          Pad;
    unsigned char  Format[TYPE_FORMAT_STRING_SIZE];
} idl_MIDL_TYPE_FORMAT_STRING;

typedef struct _idl_MIDL_PROC_FORMAT_STRING
{
    short          Pad;
    unsigned char  Format[PROC_FORMAT_STRING_SIZE];
} idl_MIDL_PROC_FORMAT_STRING;

typedef struct _idl_MIDL_EXPR_FORMAT_STRING
{
    long          Pad;
    unsigned char  Format[EXPR_FORMAT_STRING_SIZE];
} idl_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax =
{ {0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0} };

static const RPC_SYNTAX_IDENTIFIER  _NDR64_RpcTransferSyntax =
{ {0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0} };



extern const idl_MIDL_TYPE_FORMAT_STRING idl__MIDL_TypeFormatString;
extern const idl_MIDL_PROC_FORMAT_STRING idl__MIDL_ProcFormatString;
extern const idl_MIDL_EXPR_FORMAT_STRING idl__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: DefaultIfName, ver. 1.0,
   GUID={0x58b19028,0xb9a0,0x4c25,{0x88,0x7f,0xac,0xa5,0x8b,0x58,0x4d,0x1b}} */

extern const MIDL_STUBLESS_PROXY_INFO DefaultIfName_ProxyInfo;


static const RPC_CLIENT_INTERFACE DefaultIfName___RpcClientInterface =
{
sizeof(RPC_CLIENT_INTERFACE),
{{0x58b19028,0xb9a0,0x4c25,{0x88,0x7f,0xac,0xa5,0x8b,0x58,0x4d,0x1b}},{1,0}},
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
0,
0,
0,
0,
&DefaultIfName_ProxyInfo,
0x02000000
};
RPC_IF_HANDLE DefaultIfName_v1_0_c_ifspec = (RPC_IF_HANDLE)&DefaultIfName___RpcClientInterface;

extern const MIDL_STUB_DESC DefaultIfName_StubDesc;

static RPC_BINDING_HANDLE DefaultIfName__MIDL_AutoBindHandle;


long Proc0(
    /* [in] */ handle_t IDL_handle,
    /* [size_is][in] */ byte* arg_1,
    /* [in] */ long arg_2,
    /* [length_is][size_is][out] */ byte* arg_3,
    /* [range][in] */ long arg_4,
    /* [out] */ long* arg_5)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall3(
        (PMIDL_STUBLESS_PROXY_INFO)&DefaultIfName_ProxyInfo,
        0,
        0,
        IDL_handle,
        arg_1,
        arg_2,
        arg_3,
        arg_4,
        arg_5);
    return (long)_RetVal.Simple;

}


#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const idl_MIDL_PROC_FORMAT_STRING idl__MIDL_ProcFormatString =
{
    0,
    {

        /* Procedure Proc0 */

                0x0,		/* 0 */
                0x48,		/* Old Flags:  */
                /*  2 */	NdrFcLong(0x0),	/* 0 */
                /*  6 */	NdrFcShort(0x0),	/* 0 */
                /*  8 */	NdrFcShort(0x38),	/* X64 Stack size/offset = 56 */
                /* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
                            0x0,		/* 0 */
                            /* 12 */	NdrFcShort(0x0),	/* X64 Stack size/offset = 0 */
                            /* 14 */	NdrFcShort(0x10),	/* 16 */
                            /* 16 */	NdrFcShort(0x24),	/* 36 */
                            /* 18 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
                                        0x6,		/* 6 */
                                        /* 20 */	0xa,		/* 10 */
                                                    0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
                                                    /* 22 */	NdrFcShort(0x1),	/* 1 */
                                                    /* 24 */	NdrFcShort(0x1),	/* 1 */
                                                    /* 26 */	NdrFcShort(0x0),	/* 0 */
                                                    /* 28 */	NdrFcShort(0x0),	/* 0 */

                                                        /* Parameter arg_1 */

                                                        /* 30 */	NdrFcShort(0x10b),	/* Flags:  must size, must free, in, simple ref, */
                                                        /* 32 */	NdrFcShort(0x8),	/* X64 Stack size/offset = 8 */
                                                        /* 34 */	NdrFcShort(0x6),	/* Type Offset=6 */

                                                            /* Parameter arg_2 */

                                                            /* 36 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                            /* 38 */	NdrFcShort(0x10),	/* X64 Stack size/offset = 16 */
                                                            /* 40 */	0x8,		/* FC_LONG */
                                                                        0x0,		/* 0 */

                                                                /* Parameter arg_3 */

                                                                /* 42 */	NdrFcShort(0x113),	/* Flags:  must size, must free, out, simple ref, */
                                                                /* 44 */	NdrFcShort(0x18),	/* X64 Stack size/offset = 24 */
                                                                /* 46 */	NdrFcShort(0x20),	/* Type Offset=32 */

                                                                    /* Parameter arg_4 */

                                                                    /* 48 */	NdrFcShort(0x88),	/* Flags:  in, by val, */
                                                                    /* 50 */	NdrFcShort(0x20),	/* X64 Stack size/offset = 32 */
                                                                    /* 52 */	NdrFcShort(0x46),	/* 70 */

                                                                        /* Parameter arg_5 */

                                                                        /* 54 */	NdrFcShort(0x2150),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
                                                                        /* 56 */	NdrFcShort(0x28),	/* X64 Stack size/offset = 40 */
                                                                        /* 58 */	0x8,		/* FC_LONG */
                                                                                    0x0,		/* 0 */

                                                                            /* Return value */

                                                                            /* 60 */	NdrFcShort(0x70),	/* Flags:  out, return, base type, */
                                                                            /* 62 */	NdrFcShort(0x30),	/* X64 Stack size/offset = 48 */
                                                                            /* 64 */	0x8,		/* FC_LONG */
                                                                                        0x0,		/* 0 */

                                                                                        0x0
                                                                                    }
};

static const idl_MIDL_TYPE_FORMAT_STRING idl__MIDL_TypeFormatString =
{
    0,
    {
        NdrFcShort(0x0),	/* 0 */
/*  2 */
            0x11, 0x0,	/* FC_RP */
            /*  4 */	NdrFcShort(0x2),	/* Offset= 2 (6) */
            /*  6 */
                        0x1b,		/* FC_CARRAY */
                        0x0,		/* 0 */
                        /*  8 */	NdrFcShort(0x1),	/* 1 */
                        /* 10 */	0x28,		/* Corr desc:  parameter, FC_LONG */
                                    0x0,		/*  */
                                    /* 12 */	NdrFcShort(0x10),	/* X64 Stack size/offset = 16 */
                                    /* 14 */	NdrFcShort(0x0),	/* Corr flags:  */
                                    /* 16 */	0x0 ,
                                                0x0,		/* 0 */
                                                /* 18 */	NdrFcLong(0x0),	/* 0 */
                                                /* 22 */	NdrFcLong(0x0),	/* 0 */
                                                /* 26 */	0x1,		/* FC_BYTE */
                                                            0x5b,		/* FC_END */
                                                /* 28 */
                                                            0x11, 0x0,	/* FC_RP */
                                                            /* 30 */	NdrFcShort(0x2),	/* Offset= 2 (32) */
                                                            /* 32 */
                                                                        0x1c,		/* FC_CVARRAY */
                                                                        0x0,		/* 0 */
                                                                        /* 34 */	NdrFcShort(0x1),	/* 1 */
                                                                        /* 36 */	0x28,		/* Corr desc:  parameter, FC_LONG */
                                                                                    0x0,		/*  */
                                                                                    /* 38 */	NdrFcShort(0x20),	/* X64 Stack size/offset = 32 */
                                                                                    /* 40 */	NdrFcShort(0x10),	/* Corr flags:  */
                                                                                    /* 42 */	0x1 , /* correlation range */
                                                                                                0x0,		/* 0 */
                                                                                                /* 44 */	NdrFcLong(0x0),	/* 0 */
                                                                                                /* 48 */	NdrFcLong(0x1000000),	/* 16777216 */
                                                                                                /* 52 */	0x28,		/* Corr desc:  parameter, FC_LONG */
                                                                                                            0x54,		/* FC_DEREFERENCE */
                                                                                                            /* 54 */	NdrFcShort(0x28),	/* X64 Stack size/offset = 40 */
                                                                                                            /* 56 */	NdrFcShort(0x0),	/* Corr flags:  */
                                                                                                            /* 58 */	0x0 ,
                                                                                                                        0x0,		/* 0 */
                                                                                                                        /* 60 */	NdrFcLong(0x0),	/* 0 */
                                                                                                                        /* 64 */	NdrFcLong(0x0),	/* 0 */
                                                                                                                        /* 68 */	0x1,		/* FC_BYTE */
                                                                                                                                    0x5b,		/* FC_END */
                                                                                                                                    /* 70 */	0xb7,		/* FC_RANGE */
                                                                                                                                                0x8,		/* 8 */
                                                                                                                                                /* 72 */	NdrFcLong(0x0),	/* 0 */
                                                                                                                                                /* 76 */	NdrFcLong(0x1000000),	/* 16777216 */
                                                                                                                                                /* 80 */
                                                                                                                                                            0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
                                                                                                                                                            /* 82 */	0x8,		/* FC_LONG */
                                                                                                                                                                        0x5c,		/* FC_PAD */

                                                                                                                                                                        0x0
                                                                                                                                                                    }
};

static const unsigned short DefaultIfName_FormatStringOffsetTable[] =
{
0
};



#endif /* defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
 /* Compiler settings for idl.idl:
     Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622
     protocol : all , ms_ext, c_ext, robust
     error checks: allocation ref bounds_check enum stub_data
     VC __declspec() decoration level:
          __declspec(uuid()), __declspec(selectany), __declspec(novtable)
          DECLSPEC_UUID(), MIDL_INTERFACE()
 */
 /* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)




#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif


#include "ndr64types.h"
#include "pshpack8.h"


typedef
NDR64_FORMAT_CHAR
__midl_frag16_t;
extern const __midl_frag16_t __midl_frag16;

typedef
struct _NDR64_POINTER_FORMAT
    __midl_frag14_t;
extern const __midl_frag14_t __midl_frag14;

typedef
struct _NDR64_RANGE_FORMAT
    __midl_frag13_t;
extern const __midl_frag13_t __midl_frag13;

typedef
struct
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_NOOP frag2;
    struct _NDR64_EXPR_CONST64 frag3;
}
__midl_frag12_t;
extern const __midl_frag12_t __midl_frag12;

typedef
struct
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_OPERATOR frag2;
    struct _NDR64_EXPR_VAR frag3;
}
__midl_frag11_t;
extern const __midl_frag11_t __midl_frag11;

typedef
struct
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_RANGE_FORMAT frag2;
    struct _NDR64_EXPR_VAR frag3;
}
__midl_frag10_t;
extern const __midl_frag10_t __midl_frag10;

typedef
struct
{
    struct _NDR64_CONF_VAR_ARRAY_HEADER_FORMAT frag1;
}
__midl_frag9_t;
extern const __midl_frag9_t __midl_frag9;

typedef
struct _NDR64_POINTER_FORMAT
    __midl_frag8_t;
extern const __midl_frag8_t __midl_frag8;

typedef
NDR64_FORMAT_CHAR
__midl_frag6_t;
extern const __midl_frag6_t __midl_frag6;

typedef
struct
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_VAR frag2;
}
__midl_frag5_t;
extern const __midl_frag5_t __midl_frag5;

typedef
struct
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag4_t;
extern const __midl_frag4_t __midl_frag4;

typedef
struct _NDR64_POINTER_FORMAT
    __midl_frag3_t;
extern const __midl_frag3_t __midl_frag3;

typedef
struct
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
    struct _NDR64_PARAM_FORMAT frag7;
    struct _NDR64_PARAM_FORMAT frag8;
}
__midl_frag2_t;
extern const __midl_frag2_t __midl_frag2;

typedef
NDR64_FORMAT_UINT32
__midl_frag1_t;
extern const __midl_frag1_t __midl_frag1;

static const __midl_frag16_t __midl_frag16 =
0x5    /* FC64_INT32 */;

static const __midl_frag14_t __midl_frag14 =
{
    /* *long */
        0x20,    /* FC64_RP */
        (NDR64_UINT8)12 /* 0xc */,
        (NDR64_UINT16)0 /* 0x0 */,
        &__midl_frag16
};

static const __midl_frag13_t __midl_frag13 =
{
    /* long */
        0xa4,    /* FC64_RANGE */
        0x5,    /* FC64_INT32 */
        (NDR64_UINT16)0 /* 0x0 */,
        (NDR64_INT64)0 /* 0x0 */,
        (NDR64_INT64)16777216 /* 0x1000000 */
};

static const __midl_frag12_t __midl_frag12 =
{
    /*  */
        (NDR64_UINT32)1 /* 0x1 */,
        {
        /* struct _NDR64_EXPR_NOOP */
            0x5,    /* FC_EXPR_PAD */
            (NDR64_UINT8)4 /* 0x4 */,
            (NDR64_UINT16)0 /* 0x0 */
        },
        {
            /* struct _NDR64_EXPR_CONST64 */
                0x2,    /* FC_EXPR_CONST64 */
                0x7,    /* FC64_INT64 */
                (NDR64_UINT16)0 /* 0x0 */,
                (NDR64_UINT64)0 /* 0x0 */
            }
};

static const __midl_frag11_t __midl_frag11 =
{
    /*  */
        (NDR64_UINT32)0 /* 0x0 */,
        {
        /* struct _NDR64_EXPR_OPERATOR */
            0x4,    /* FC_EXPR_OPER */
            0x5,    /* OP_UNARY_INDIRECTION */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT8)0 /* 0x0 */
        },
        {
            /* struct _NDR64_EXPR_VAR */
                0x3,    /* FC_EXPR_VAR */
                0x7,    /* FC64_INT64 */
                (NDR64_UINT16)0 /* 0x0 */,
                (NDR64_UINT32)40 /* 0x28 */  /* Offset */
            }
};

static const __midl_frag10_t __midl_frag10 =
{
    /*  */
        (NDR64_UINT32)4 /* 0x4 */,
        {
        /* struct _NDR64_RANGE_FORMAT */
            0xa4,    /* FC64_RANGE */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_INT64)0 /* 0x0 */,
            (NDR64_INT64)16777216 /* 0x1000000 */
        },
        {
            /* struct _NDR64_EXPR_VAR */
                0x3,    /* FC_EXPR_VAR */
                0x5,    /* FC64_INT32 */
                (NDR64_UINT16)0 /* 0x0 */,
                (NDR64_UINT32)32 /* 0x20 */  /* Offset */
            }
};

static const __midl_frag9_t __midl_frag9 =
{
    /* *byte */
        {
        /* *byte */
            0x43,    /* FC64_CONFVAR_ARRAY */
            (NDR64_UINT8)0 /* 0x0 */,
            {
        /* *byte */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8)0 /* 0x0 */,
        (NDR64_UINT32)1 /* 0x1 */,
        &__midl_frag10,
        &__midl_frag11
    }
};

static const __midl_frag8_t __midl_frag8 =
{
    /* *byte */
        0x20,    /* FC64_RP */
        (NDR64_UINT8)0 /* 0x0 */,
        (NDR64_UINT16)0 /* 0x0 */,
        &__midl_frag9
};

static const __midl_frag6_t __midl_frag6 =
0x2    /* FC64_INT8 */;

static const __midl_frag5_t __midl_frag5 =
{
    /*  */
        (NDR64_UINT32)0 /* 0x0 */,
        {
        /* struct _NDR64_EXPR_VAR */
            0x3,    /* FC_EXPR_VAR */
            0x5,    /* FC64_INT32 */
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT32)16 /* 0x10 */  /* Offset */
        }
};

static const __midl_frag4_t __midl_frag4 =
{
    /* *byte */
        {
        /* *byte */
            0x41,    /* FC64_CONF_ARRAY */
            (NDR64_UINT8)0 /* 0x0 */,
            {
        /* *byte */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8)0 /* 0x0 */,
        (NDR64_UINT32)1 /* 0x1 */,
        &__midl_frag5
    },
    {
        /* struct _NDR64_ARRAY_ELEMENT_INFO */
            (NDR64_UINT32)1 /* 0x1 */,
            &__midl_frag6
        }
};

static const __midl_frag3_t __midl_frag3 =
{
    /* *byte */
        0x20,    /* FC64_RP */
        (NDR64_UINT8)0 /* 0x0 */,
        (NDR64_UINT16)0 /* 0x0 */,
        &__midl_frag4
};

static const __midl_frag2_t __midl_frag2 =
{
    /* Proc0 */
        {
        /* Proc0 */      /* procedure Proc0 */
            (NDR64_UINT32)23986240 /* 0x16e0040 */,    /* explicit handle */ /* IsIntrepreted, ServerMustSize, ClientMustSize, HasReturn, ServerCorrelation, ClientCorrelation, HasExtensions */
            (NDR64_UINT32)56 /* 0x38 */ ,  /* Stack size */
            (NDR64_UINT32)16 /* 0x10 */,
            (NDR64_UINT32)40 /* 0x28 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)6 /* 0x6 */,
            (NDR64_UINT16)8 /* 0x8 */
        },
        {
            /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                {
                /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                    0x72,    /* FC64_BIND_PRIMITIVE */
                    (NDR64_UINT8)0 /* 0x0 */,
                    0 /* 0x0 */,   /* Stack offset */
                    (NDR64_UINT8)0 /* 0x0 */,
                    (NDR64_UINT8)0 /* 0x0 */
                },
                (NDR64_UINT16)0 /* 0x0 */      /* Notify index */
            },
            {
                /* arg_1 */      /* parameter arg_1 */
                    &__midl_frag4,
                    {
        /* arg_1 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    {
        /* arg_2 */      /* parameter arg_2 */
            &__midl_frag16,
            {
        /* arg_2 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    {
        /* arg_3 */      /* parameter arg_3 */
            &__midl_frag9,
            {
        /* arg_3 */
            1,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [out], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    {
        /* arg_4 */      /* parameter arg_4 */
            &__midl_frag13,
            {
        /* arg_4 */
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    },
    {
        /* arg_5 */      /* parameter arg_5 */
            &__midl_frag16,
            {
        /* arg_5 */
            0,
            0,
            0,
            0,
            1,
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            1
        },    /* [out], Basetype, SimpleRef, UseCache */
        (NDR64_UINT16)0 /* 0x0 */,
        40 /* 0x28 */,   /* Stack offset */
    },
    {
        /* long */      /* parameter long */
            &__midl_frag16,
            {
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        48 /* 0x30 */,   /* Stack offset */
    }
};

static const __midl_frag1_t __midl_frag1 =
(NDR64_UINT32)0 /* 0x0 */;


#include "poppack.h"


static const FormatInfoRef DefaultIfName_Ndr64ProcTable[] =
{
&__midl_frag2
};


static const MIDL_STUB_DESC DefaultIfName_StubDesc =
{
(void*)&DefaultIfName___RpcClientInterface,
MIDL_user_allocate,
MIDL_user_free,
&DefaultIfName__MIDL_AutoBindHandle,
0,
0,
0,
0,
idl__MIDL_TypeFormatString.Format,
1, /* -error bounds_check flag */
0x60001, /* Ndr library version */
0,
0x801026e, /* MIDL Version 8.1.622 */
0,
0,
0,  /* notify & notify_flag routine table */
0x2000001, /* MIDL flag */
0, /* cs routines */
(void*)&DefaultIfName_ProxyInfo,   /* proxy/server info */
0
};

static const MIDL_SYNTAX_INFO DefaultIfName_SyntaxInfo[2] =
{
{
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
0,
idl__MIDL_ProcFormatString.Format,
DefaultIfName_FormatStringOffsetTable,
idl__MIDL_TypeFormatString.Format,
0,
0,
0
}
,{
{{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}},
0,
0 ,
(unsigned short*)DefaultIfName_Ndr64ProcTable,
0,
0,
0,
0
}
};

static const MIDL_STUBLESS_PROXY_INFO DefaultIfName_ProxyInfo =
{
&DefaultIfName_StubDesc,
idl__MIDL_ProcFormatString.Format,
DefaultIfName_FormatStringOffsetTable,
(RPC_SYNTAX_IDENTIFIER*)&_RpcTransferSyntax,
2,
(MIDL_SYNTAX_INFO*)DefaultIfName_SyntaxInfo

};

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

