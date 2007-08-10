/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _CORREG_H_
#define _CORREG_H_

#include <ole2.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <pshpack1.h>

#ifndef NODLLIMPORT
#define DLLIMPORT __declspec(dllimport)
#else
#define DLLIMPORT
#endif

#if !defined(_META_DATA_NO_SCOPE_) || defined(_META_DATA_SCOPE_WRAPPER_)

  STDAPI CoGetCor(REFIID riid,void **ppv);
#endif

  STDAPI CoInitializeCor(DWORD fFlags);
  STDAPI_(void) CoUninitializeCor(void);

  typedef INT_PTR mdScope;
#define mdScopeNil ((mdScope)0)

  typedef INT_PTR mdToken;
  typedef INT_PTR mdModule;
  typedef INT_PTR mdTypeDef;
  typedef INT_PTR mdInterfaceImpl;
  typedef INT_PTR mdTypeRef;
  typedef INT_PTR mdNamespace;
  typedef INT_PTR mdCustomValue;
  typedef INT_PTR mdResource;
  typedef INT_PTR mdCocatdef;
  typedef INT_PTR mdCocatImpl;
  typedef INT_PTR mdMimeTypeImpl;
  typedef INT_PTR mdFormatImpl;
  typedef INT_PTR mdProgID;
  typedef INT_PTR mdRoleCheck;
  typedef unsigned long RID;

  enum CorRegTokenType {
    mdtTypeDef = 0x00000000,mdtInterfaceImpl = 0x01000000,mdtTypeRef = 0x03000000,mdtNamespace = 0x06000000,mdtCustomValue = 0x07000000,
    mdtResource = 0x0B000000,mdtCocatImpl = 0x0D000000,mdtMimeTypeImpl = 0x0E000000,mdtFormatImpl = 0x0F000000,mdtProgID = 0x10000000,
    mdtRoleCheck = 0x11000000,mdtModule = 0x14000000
  };

#define RidToToken(rid,tktype) ((rid) |= (tktype))
#define TokenFromRid(rid,tktype) ((rid) | (tktype))
#define RidFromToken(tk) ((RID) ((tk) & 0x00ffffff))
#define TypeFromToken(tk) ((tk) & 0xff000000)

#define mdTokenNil ((mdToken)0)
#define mdModuleNil ((mdModule)mdtModule)
#define mdTypeDefNil ((mdTypeDef)mdtTypeDef)
#define mdInterfaceImplNil ((mdInterfaceImpl)mdtInterfaceImpl)
#define mdTypeRefNil ((mdTypeRef)mdtTypeRef)
#define mdNamespaceNil ((mdNamespace)mdtNamespace)
#define mdCustomValueNil ((mdCustomValue)mdtCustomValue)
#define mdResourceNil ((mdResource)mdtResource)
#define mdCocatImplNil ((mdCocatImpl)mdtCocatImpl)
#define mdMimeTypeImplNil ((mdMimeTypeImpl)mdtMimeTypeImpl)
#define mdFormatImplNil ((mdFormatImpl)mdtFormatImpl)
#define mdProgIDNil ((mdProgID)mdtProgID)
#define mdRoleCheckNil ((mdRoleCheck)mdtRoleCheck)

  enum CorRegTypeAttr {
    tdPublic = 0x0001,tdLayoutMask = 0x0006,tdAutoLayout = 0x0000,tdLayoutSequential = 0x0002,tdExplicitLayout = 0x0004,tdWrapperClass = 0x0008,
    tdFinal = 0x0010,tdISSCompat = 0x0020,tdStringFormatMask = 0x00c0,tdAnsiClass = 0x0000,tdUnicodeClass = 0x0040,tdAutoClass = 0x0080,
    tdValueClass = 0x0100,tdInterface = 0x0200,tdAbstract = 0x0400,tdImport = 0x1000,tdRecord = 0x2000,tdEnum = 0x4000,tdReserved1 = 0x0800
  };

  enum CorImplementType {
    itImplements = 0x0000,itEvents = 0x0001,itRequires = 0x0002,itInherits = 0x0004
  };

  enum CorClassActivateAttr {
    caaDeferCreate = 0x0001,caaAppObject = 0x0002,caaFixedIfaceSet = 0x0004,caaIndependentlyCreateable = 0x0100,caaPredefined = 0x0200,
    caaLoadBalancing = 0x0c00,caaLBNotSupported = 0x0400,caaLBSupported = 0x0800,caaLBNotSpecified = 0x0000,caaObjectPooling = 0x3000,
    caaOPNotSupported = 0x1000,caaOPSupported = 0x2000,caaOPNotSpecified = 0x0000,caaJITActivation = 0xc000,caaJANotSupported = 0x4000,
    caaJASupported = 0x8000,caaJANotSpecified = 0x0000
  };

  enum CorIfaceSvcAttr {
    mlNone = 0x0001,mlAutomation = 0x0002,mlProxyStub = 0x0004,mlDeferrable = 0x0018,mlDeferNotSupported = 0x0008,mlDeferSupported = 0x0010,
    mlDeferNotSpecified = 0x0000
  };

  enum CocatImplAttr {
    catiaImplements = 0x0001,catiaRequires = 0x0002
  };

  enum CorModuleExportAttr {
    moUsesGetLastError = 0x0001
  };

  enum CorModuleRegAttr {
    rmaCustomReg = 0x0001
  };

  enum CorRegFormatAttr {
    rfaSupportsFormat = 0x0001,rfaConvertsFromFormat = 0x0002,rfaConvertsToFormat = 0x0003,rfaDefaultFormat = 0x0004,rfaIsFileExt = 0x0005,
    rfaIsFileType = 0x0006,rfaIsDataFormat = 0x0007
  };

  enum CorSynchAttr {
    sySupported = 0x0001,syRequired = 0x0002,syRequiresNew = 0x0004,syNotSupported = 0x0008,syThreadAffinity = 0x0010
  };

  enum CorThreadingAttr {
    taMain = 0x0001,taSTA = 0x0002,taMTA = 0x0004,taNeutral = 0x0008,taBoth = 0x0010
  };

  enum CorXactionAttr {
    xaSupported = 0x0001,xaRequired = 0x0002,xaRequiresNew = 0x0004,xaNotSupported = 0x0008,xaNoVote = 0x0010
  };

  enum CorRoleCheckAttr {
    rcChecksFor = 0x0001
  };

  typedef void *HCORENUM;

#ifndef _CORSAVESIZE_DEFINED_
#define _CORSAVESIZE_DEFINED_
  enum CorSaveSize {
    cssAccurate = 0x0000,cssQuick = 0x0001
  };
#endif

#define MAX_CLASS_NAME 255
#define MAX_PACKAGE_NAME 255

  typedef unsigned __int64 CLASSVERSION;

#ifndef DECLSPEC_SELECT_ANY
#define DECLSPEC_SELECT_ANY __declspec(selectany)
#endif

  extern const GUID DECLSPEC_SELECT_ANY CLSID_Cor = { 0xbee00010,0xee77,0x11d0,{0xa0,0x15,0x00,0xc0,0x4f,0xbb,0xb8,0x84 } };
  extern const GUID DECLSPEC_SELECT_ANY CLSID_CorMetaDataDispenser = { 0xe5cb7a31,0x7512,0x11d2,{ 0x89,0xce,0x0,0x80,0xc7,0x92,0xe5,0xd8 } };
  extern const GUID DECLSPEC_SELECT_ANY CLSID_CorMetaDataDispenserReg = { 0x435755ff,0x7397,0x11d2,{ 0x97,0x71,0x0,0xa0,0xc9,0xb4,0xd5,0xc } };
  extern const GUID DECLSPEC_SELECT_ANY CLSID_CorMetaDataReg = { 0x87f3a1f5,0x7397,0x11d2,{ 0x97,0x71,0x0,0xa0,0xc9,0xb4,0xd5,0xc } };
  extern const GUID DECLSPEC_SELECT_ANY IID_IMetaDataInternal = { 0x2d601bb,0xc5b9,0x11d1,{0x93,0xf9,0x0,0x0,0xf8,0x8,0x34,0x60 } };
  extern const GUID DECLSPEC_SELECT_ANY IID_IMetaDataEmitTemp = { 0xad93d71d,0xe1f2,0x11d1,{0x94,0x9,0x0,0x0,0xf8,0x8,0x34,0x60 } };

  interface IMetaDataRegEmit;
  interface IMetaDataRegImport;
  interface IMetaDataDispenser;

  extern const GUID DECLSPEC_SELECT_ANY IID_IMemory = { 0x6a3ea8a,0x225,0x11d1,{0xbf,0x72,0x0,0xc0,0x4f,0xc3,0x1e,0x12 } };

#undef INTERFACE
#define INTERFACE IMemory
  DECLARE_INTERFACE_(IMemory,IUnknown) {
    STDMETHOD(QueryInterface)(THIS_ REFIID riid,LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(GetMemory)(void **pMem,ULONG *iSize) PURE;
    STDMETHOD(SetMemory)(void *pMem,ULONG iSize) PURE;
  };

  extern const GUID DECLSPEC_SELECT_ANY IID_IMetaDataError = { 0xb81ff171,0x20f3,0x11d2,{ 0x8d,0xcc,0x0,0xa0,0xc9,0xb0,0x9c,0x19 } };

#undef INTERFACE
#define INTERFACE IMetaDataError
  DECLARE_INTERFACE_(IMetaDataError,IUnknown) {
    STDMETHOD(OnError)(HRESULT hrError,mdToken token) PURE;
  };

  extern const GUID DECLSPEC_SELECT_ANY IID_IMapToken = { 0x6a3ea8b,0x225,0x11d1,{0xbf,0x72,0x0,0xc0,0x4f,0xc3,0x1e,0x12 } };

#undef INTERFACE
#define INTERFACE IMapToken
  DECLARE_INTERFACE_(IMapToken,IUnknown) {
    STDMETHOD(Map)(ULONG tkImp,ULONG tkEmit) PURE;
  };

  extern const GUID DECLSPEC_SELECT_ANY IID_IMetaDataDispenser = { 0x809c652e,0x7396,0x11d2,{ 0x97,0x71,0x0,0xa0,0xc9,0xb4,0xd5,0xc } };

#undef INTERFACE
#define INTERFACE IMetaDataDispenser
  DECLARE_INTERFACE_(IMetaDataDispenser,IUnknown) {
    STDMETHOD(DefineScope)(REFCLSID rclsid,DWORD dwCreateFlags,REFIID riid,IUnknown **ppIUnk) PURE;
    STDMETHOD(OpenScope)(LPCWSTR szScope,DWORD dwOpenFlags,REFIID riid,IUnknown **ppIUnk) PURE;
    STDMETHOD(OpenScopeOnStream)(IStream *pIStream,DWORD dwOpenFlags,REFIID riid,IUnknown **ppIUnk) PURE;
    STDMETHOD(OpenScopeOnMemory)(LPCVOID pData,ULONG cbData,DWORD dwOpenFlags,REFIID riid,IUnknown **ppIUnk) PURE;
  };

#if defined(_META_DATA_NO_SCOPE_) || defined(_META_DATA_SCOPE_WRAPPER_)
  extern const GUID DECLSPEC_SELECT_ANY IID_IMetaDataRegEmit = { 0x601c95b9,0x7398,0x11d2,{ 0x97,0x71,0x0,0xa0,0xc9,0xb4,0xd5,0xc } };
  extern const GUID DECLSPEC_SELECT_ANY IID_IMetaDataRegEmitOld = { 0xf28f419b,0x62ca,0x11d2,{ 0x8f,0x2c,0x0,0xa0,0xc9,0xa6,0x18,0x6d } };

#undef INTERFACE
#define INTERFACE IMetaDataRegEmit
  DECLARE_INTERFACE_(IMetaDataRegEmit,IUnknown) {
    STDMETHOD(SetModuleProps)(LPCWSTR szName,const GUID *ppid,LCID lcid) PURE;
    STDMETHOD(Save)(LPCWSTR szFile,DWORD dwSaveFlags) PURE;
    STDMETHOD(SaveToStream)(IStream *pIStream,DWORD dwSaveFlags) PURE;
    STDMETHOD(GetSaveSize)(CorSaveSize fSave,DWORD *pdwSaveSize) PURE;
    STDMETHOD(Merge)(IMetaDataRegImport *pImport,IMapToken *pIMap) PURE;
    STDMETHOD(DefineCustomValueAsBlob)(mdToken tkObj,LPCWSTR szName,void const *pCustomValue,ULONG cbCustomValue,mdCustomValue *pcv) PURE;
    STDMETHOD(DefineTypeDef)(LPCWSTR szNamespace,LPCWSTR szTypeDef,const GUID *pguid,CLASSVERSION *pVer,DWORD dwTypeDefFlags,mdToken tkExtends,DWORD dwExtendsFlags,mdToken rtkImplements[],mdToken rtkEvents[],mdTypeDef *ptd) PURE;
    STDMETHOD(SetTypeDefProps)(mdTypeDef td,CLASSVERSION *pVer,DWORD dwTypeDefFlags,mdToken tkExtends,DWORD dwExtendsFlags,mdToken rtkImplements[],mdToken rtkEvents[]) PURE;
    STDMETHOD(SetClassSvcsContext)(mdTypeDef td,DWORD dwClassActivateAttr,DWORD dwClassThreadAttr,DWORD dwXactionAttr,DWORD dwSynchAttr) PURE;
    STDMETHOD(DefineTypeRefByGUID)(GUID *pguid,mdTypeRef *ptr) PURE;
    STDMETHOD(SetModuleReg)(DWORD dwModuleRegAttr,const GUID *pguid) PURE;
    STDMETHOD(SetClassReg)(mdTypeDef td,LPCWSTR szProgID,LPCWSTR szVIProgID,LPCWSTR szIconURL,ULONG ulIconResource,LPCWSTR szSmallIconURL,ULONG ulSmallIconResource,LPCWSTR szDefaultDispName) PURE;
    STDMETHOD(SetIfaceReg)(mdTypeDef td,DWORD dwIfaceSvcs,const GUID *proxyStub) PURE;
    STDMETHOD(SetCategoryImpl)(mdTypeDef td,GUID rGuidCoCatImpl[],GUID rGuidCoCatReqd[]) PURE;
    STDMETHOD(SetRedirectProgID)(mdTypeDef td,LPCWSTR rszRedirectProgID[]) PURE;
    STDMETHOD(SetMimeTypeImpl)(mdTypeDef td,LPCWSTR rszMimeType[]) PURE;
    STDMETHOD(SetFormatImpl)(mdTypeDef td,LPCWSTR rszFormatSupported[],LPCWSTR rszFormatConvertsFrom[],LPCWSTR rszFormatConvertsTo[],LPCWSTR rszFormatDefault[],LPCWSTR rszFileExt[],LPCWSTR rszFileType[]) PURE;
    STDMETHOD(SetRoleCheck)(mdToken tk,LPCWSTR rszName[],DWORD rdwRoleFlags[]) PURE;
    STDMETHOD(SetHandler)(IUnknown *pUnk) PURE;
  };
#endif

#if !defined(_META_DATA_NO_SCOPE_)
#if !defined(_META_DATA_SCOPE_WRAPPER_)
  extern const GUID DECLSPEC_SELECT_ANY IID_IMetaDataRegEmit = { 0xf28f419b,0x62ca,0x11d2,{ 0x8f,0x2c,0x0,0xa0,0xc9,0xa6,0x18,0x6d } };
#endif

#undef INTERFACE
#if defined(_META_DATA_SCOPE_WRAPPER_)
#define INTERFACE IMetaDataRegEmitOld
#else
#define INTERFACE IMetaDataRegEmit
#endif
  DECLARE_INTERFACE_(INTERFACE,IUnknown) {
    STDMETHOD(DefineScope)(DWORD dwCreateFlags,mdScope *pscope) PURE;
    STDMETHOD(SetModuleProps)(mdScope scope,LPCWSTR szName,const GUID *ppid,LCID lcid) PURE;
    STDMETHOD(Save)(mdScope es,LPCWSTR szFile,DWORD dwSaveFlags) PURE;
    STDMETHOD(SaveToStream)(mdScope es,IStream *pIStream,DWORD dwSaveFlags) PURE;
    STDMETHOD(GetSaveSize)(mdScope es,CorSaveSize fSave,DWORD *pdwSaveSize) PURE;
    STDMETHOD_(void,Close)(mdScope scope) PURE;
    STDMETHOD(Merge)(mdScope scEmit,mdScope scImport,IMapToken *pIMap) PURE;
    STDMETHOD(DefineCustomValueAsBlob)(mdScope es,mdToken tkObj,LPCWSTR szName,void const *pCustomValue,ULONG cbCustomValue,mdCustomValue *pcv) PURE;
    STDMETHOD(DefineTypeDef)(mdScope es,LPCWSTR szNamespace,LPCWSTR szTypeDef,const GUID *pguid,CLASSVERSION *pVer,DWORD dwTypeDefFlags,mdToken tkExtends,DWORD dwExtendsFlags,mdToken rtkImplements[],mdToken rtkEvents[],mdTypeDef *ptd) PURE;
    STDMETHOD(SetTypeDefProps)(mdScope es,mdTypeDef td,CLASSVERSION *pVer,DWORD dwTypeDefFlags,mdToken tkExtends,DWORD dwExtendsFlags,mdToken rtkImplements[],mdToken rtkEvents[]) PURE;
    STDMETHOD(SetClassSvcsContext)(mdScope es,mdTypeDef td,DWORD dwClassActivateAttr,DWORD dwClassThreadAttr,DWORD dwXactionAttr,DWORD dwSynchAttr) PURE;
    STDMETHOD(DefineTypeRefByGUID)(mdScope sc,GUID *pguid,mdTypeRef *ptr) PURE;
    STDMETHOD(SetModuleReg)(mdScope es,DWORD dwModuleRegAttr,const GUID *pguid) PURE;
    STDMETHOD(SetClassReg)(mdScope es,mdTypeDef td,LPCWSTR szProgID,LPCWSTR szVIProgID,LPCWSTR szIconURL,ULONG ulIconResource,LPCWSTR szSmallIconURL,ULONG ulSmallIconResource,LPCWSTR szDefaultDispName) PURE;
    STDMETHOD(SetIfaceReg)(mdScope es,mdTypeDef td,DWORD dwIfaceSvcs,const GUID *proxyStub) PURE;
    STDMETHOD(SetCategoryImpl)(mdScope es,mdTypeDef td,GUID rGuidCoCatImpl[],GUID rGuidCoCatReqd[]) PURE;
    STDMETHOD(SetRedirectProgID)(mdScope es,mdTypeDef td,LPCWSTR rszRedirectProgID[]) PURE;
    STDMETHOD(SetMimeTypeImpl)(mdScope es,mdTypeDef td,LPCWSTR rszMimeType[]) PURE;
    STDMETHOD(SetFormatImpl)(mdScope es,mdTypeDef td,LPCWSTR rszFormatSupported[],LPCWSTR rszFormatConvertsFrom[],LPCWSTR rszFormatConvertsTo[],LPCWSTR rszFormatDefault[],LPCWSTR rszFileExt[],LPCWSTR rszFileType[]) PURE;
    STDMETHOD(SetRoleCheck)(mdScope es,mdToken tk,LPCWSTR rszName[],DWORD rdwRoleFlags[]) PURE;
    STDMETHOD(SetHandler)(mdScope sc,IUnknown *pUnk) PURE;
  };
#endif

#if defined(_META_DATA_NO_SCOPE_) || defined(_META_DATA_SCOPE_WRAPPER_)
  extern const GUID DECLSPEC_SELECT_ANY IID_IMetaDataRegImport = { 0x4398b4fd,0x7399,0x11d2,{ 0x97,0x71,0x0,0xa0,0xc9,0xb4,0xd5,0xc } };
  extern const GUID DECLSPEC_SELECT_ANY IID_IMetaDataRegImportOld = { 0xf28f419a,0x62ca,0x11d2,{ 0x8f,0x2c,0x0,0xa0,0xc9,0xa6,0x18,0x6d } };

#undef INTERFACE
#define INTERFACE IMetaDataRegImport
  DECLARE_INTERFACE_(IMetaDataRegImport,IUnknown) {
    STDMETHOD_(void,CloseEnum)(HCORENUM hEnum) PURE;
    STDMETHOD(CountEnum)(HCORENUM hEnum,ULONG *pulCount) PURE;
    STDMETHOD(ResetEnum)(HCORENUM hEnum,ULONG ulPos) PURE;
    STDMETHOD(EnumTypeDefs)(HCORENUM *phEnum,mdTypeDef rTypeDefs[],ULONG cMax,ULONG *pcTypeDefs) PURE;
    STDMETHOD(EnumInterfaceImpls)(HCORENUM *phEnum,mdTypeDef td,mdInterfaceImpl rImpls[],ULONG cMax,ULONG *pcImpls) PURE;
    STDMETHOD(EnumTypeRefs)(HCORENUM *phEnum,mdTypeRef rTypeRefs[],ULONG cMax,ULONG *pcTypeRefs) PURE;
    STDMETHOD(EnumCustomValues)(HCORENUM *phEnum,mdToken tk,mdCustomValue rCustomValues[],ULONG cMax,ULONG *pcCustomValues) PURE;
    STDMETHOD(EnumResources)(HCORENUM *phEnum,mdResource rResources[],ULONG cMax,ULONG *pcResources) PURE;
    STDMETHOD(EnumCategoryImpls)(HCORENUM *phEnum,mdTypeDef td,mdCocatImpl rCocatImpls[],ULONG cMax,ULONG *pcCocatImpls) PURE;
    STDMETHOD(EnumRedirectProgIDs)(HCORENUM *phEnum,mdTypeDef td,mdProgID rRedirectProgIDs[],ULONG cMax,ULONG *pcRedirectProgIDs) PURE;
    STDMETHOD(EnumMimeTypeImpls)(HCORENUM *phEnum,mdTypeDef td,mdMimeTypeImpl rMimeTypeImpls[],ULONG cMax,ULONG *pcMimeTypeImpls) PURE;
    STDMETHOD(EnumFormatImpls)(HCORENUM *phEnum,mdTypeDef td,mdFormatImpl rFormatImpls[],ULONG cMax,ULONG *pcFormatImpls) PURE;
    STDMETHOD(EnumRoleChecks)(HCORENUM *phEnum,mdToken tk,mdRoleCheck rRoleChecks[],ULONG cMax,ULONG *pcRoleChecks) PURE;
    STDMETHOD(FindTypeDefByName)(LPCWSTR szNamespace,LPCWSTR szTypeDef,mdTypeDef *ptd) PURE;
    STDMETHOD(FindTypeDefByGUID)(const GUID *pguid,mdTypeDef *ptd) PURE;
    STDMETHOD(FindCustomValue)(mdToken tk,LPCWSTR szName,mdCustomValue *pcv,DWORD *pdwValueType) PURE;
    STDMETHOD(GetScopeProps)(LPWSTR szName,ULONG cchName,ULONG *pchName,GUID *ppid,GUID *pmvid,LCID *pLcid) PURE;
    STDMETHOD(GetModuleFromScope)(mdModule *pmd) PURE;
    STDMETHOD(GetTypeDefProps)(mdTypeDef td,LPWSTR szNamespace,ULONG cchNamespace,ULONG *pchNamespace,LPWSTR szTypeDef,ULONG cchTypeDef,ULONG *pchTypeDef,GUID *pguid,CLASSVERSION *pver,DWORD *pdwTypeDefFlags,mdToken *ptkExtends,DWORD *pdwExtendsFlags) PURE;
    STDMETHOD(GetClassSvcsContext)(mdTypeDef td,DWORD *pdwClassActivateAttr,DWORD *pdwThreadAttr,DWORD *pdwXactonAttr,DWORD *pdwSynchAttr) PURE;
    STDMETHOD(GetInterfaceImplProps)(mdInterfaceImpl iiImpl,mdTypeDef *pClass,mdToken *ptkIface,DWORD *pdwFlags) PURE;
    STDMETHOD(GetCustomValueProps)(mdCustomValue cv,LPWSTR szName,ULONG cchName,ULONG *pchName,DWORD *pdwValueType) PURE;
    STDMETHOD(GetCustomValueAsBlob)(mdCustomValue cv,void const **ppBlob,ULONG *pcbSize) PURE;
    STDMETHOD(GetTypeRefProps)(mdTypeRef tr,LPWSTR szTypeRef,ULONG cchTypeRef,ULONG *pchTypeRef,GUID *pGuid,DWORD *pdwBind) PURE;
    STDMETHOD(GetModuleRegProps)(DWORD *pModuleRegAttr,GUID *pguid) PURE;
    STDMETHOD(GetClassRegProps)(mdTypeDef td,LPWSTR szProgid,ULONG cchProgid,ULONG *pchProgid,LPWSTR szVIProgid,ULONG cchVIProgid,ULONG *pchVIProgid,LPWSTR szIconURL,ULONG cchIconURL,ULONG *pchIconURL,ULONG *pIconResource,LPWSTR szSmallIconURL,ULONG cchSmallIconURL,ULONG *pchSmallIconURL,ULONG *pSmallIconResource,LPWSTR szDefaultDispname,ULONG cchDefaultDispname,ULONG *pchDefaultDispname) PURE;
    STDMETHOD(GetIfaceRegProps)(mdTypeDef td,DWORD *pdwIfaceSvcs,GUID *pProxyStub) PURE;
    STDMETHOD(GetResourceProps)(mdResource rs,LPWSTR szURL,ULONG cchURL,ULONG *pchURL) PURE;
    STDMETHOD(GetCategoryImplProps)(mdCocatImpl cocat,GUID *pguid,DWORD *pdwCocatImplAttr) PURE;
    STDMETHOD(GetRedirectProgIDProps)(mdProgID progid,LPWSTR szProgID,ULONG cchProgID,ULONG *pchProgID) PURE;
    STDMETHOD(GetMimeTypeImplProps)(mdMimeTypeImpl mime,LPWSTR szMime,ULONG cchMime,ULONG *pchMime) PURE;
    STDMETHOD(GetFormatImplProps)(mdFormatImpl format,LPWSTR szFormat,ULONG cchFormat,ULONG *pchFormat,DWORD *pdwRegFormatAttr) PURE;
    STDMETHOD(GetRoleCheckProps)(mdRoleCheck rc,LPWSTR szName,ULONG cchName,ULONG *pchName,DWORD *pdwRoleFlags) PURE;
    STDMETHOD(ResolveTypeRef)(mdTypeRef tr,REFIID riid,IUnknown **ppIScope,mdTypeDef *ptd) PURE;
  };
#endif

#if !defined(_META_DATA_NO_SCOPE_)
#if !defined(_META_DATA_SCOPE_WRAPPER_)
  extern const GUID DECLSPEC_SELECT_ANY IID_IMetaDataRegImport = { 0xf28f419a,0x62ca,0x11d2,{ 0x8f,0x2c,0x0,0xa0,0xc9,0xa6,0x18,0x6d } };
#endif

#undef INTERFACE
#if defined(_META_DATA_SCOPE_WRAPPER_)
#define INTERFACE IMetaDataRegImportOld
#else
#define INTERFACE IMetaDataRegImport
#endif
  DECLARE_INTERFACE_(INTERFACE,IUnknown) {
    STDMETHOD(OpenScope)(LPCWSTR szScope,DWORD dwOpenFlags,mdScope *pscope) PURE;
    STDMETHOD(OpenScopeOnStream)(IStream *pIStream,DWORD dwOpenFlags,mdScope *psc) PURE;
    STDMETHOD(OpenScopeOnMemory)(LPCVOID pData,ULONG cbData,mdScope *psc) PURE;
    STDMETHOD_(void,Close)(mdScope scope) PURE;
    STDMETHOD_(void,CloseEnum)(mdScope scope,HCORENUM hEnum) PURE;
    STDMETHOD(CountEnum)(mdScope scope,HCORENUM hEnum,ULONG *pulCount) PURE;
    STDMETHOD(ResetEnum)(mdScope scope,HCORENUM hEnum,ULONG ulPos) PURE;
    STDMETHOD(EnumTypeDefs)(mdScope scope,HCORENUM *phEnum,mdTypeDef rTypeDefs[],ULONG cMax,ULONG *pcTypeDefs) PURE;
    STDMETHOD(EnumInterfaceImpls)(mdScope scope,HCORENUM *phEnum,mdTypeDef td,mdInterfaceImpl rImpls[],ULONG cMax,ULONG *pcImpls) PURE;
    STDMETHOD(EnumTypeRefs)(mdScope scope,HCORENUM *phEnum,mdTypeRef rTypeRefs[],ULONG cMax,ULONG *pcTypeRefs) PURE;
    STDMETHOD(EnumCustomValues)(mdScope scope,HCORENUM *phEnum,mdToken tk,mdCustomValue rCustomValues[],ULONG cMax,ULONG *pcCustomValues) PURE;
    STDMETHOD(EnumResources)(mdScope scope,HCORENUM *phEnum,mdResource rResources[],ULONG cMax,ULONG *pcResources) PURE;
    STDMETHOD(EnumCategoryImpls)(mdScope scope,HCORENUM *phEnum,mdTypeDef td,mdCocatImpl rCocatImpls[],ULONG cMax,ULONG *pcCocatImpls) PURE;
    STDMETHOD(EnumRedirectProgIDs)(mdScope scope,HCORENUM *phEnum,mdTypeDef td,mdProgID rRedirectProgIDs[],ULONG cMax,ULONG *pcRedirectProgIDs) PURE;
    STDMETHOD(EnumMimeTypeImpls)(mdScope scope,HCORENUM *phEnum,mdTypeDef td,mdMimeTypeImpl rMimeTypeImpls[],ULONG cMax,ULONG *pcMimeTypeImpls) PURE;
    STDMETHOD(EnumFormatImpls)(mdScope scope,HCORENUM *phEnum,mdTypeDef td,mdFormatImpl rFormatImpls[],ULONG cMax,ULONG *pcFormatImpls) PURE;
    STDMETHOD(EnumRoleChecks)(mdScope scope,HCORENUM *phEnum,mdToken tk,mdRoleCheck rRoleChecks[],ULONG cMax,ULONG *pcRoleChecks) PURE;
    STDMETHOD(FindTypeDefByName)(mdScope scope,LPCWSTR szNamespace,LPCWSTR szTypeDef,mdTypeDef *ptd) PURE;
    STDMETHOD(FindTypeDefByGUID)(mdScope scope,const GUID *pguid,mdTypeDef *ptd) PURE;
    STDMETHOD(FindCustomValue)(mdScope scope,mdToken tk,LPCWSTR szName,mdCustomValue *pcv,DWORD *pdwValueType) PURE;
    STDMETHOD(GetScopeProps)(mdScope scope,LPWSTR szName,ULONG cchName,ULONG *pchName,GUID *ppid,GUID *pmvid,LCID *pLcid) PURE;
    STDMETHOD(GetModuleFromScope)(mdScope scope,mdModule *pmd) PURE;
    STDMETHOD(GetTypeDefProps)(mdScope scope,mdTypeDef td,LPWSTR szNamespace,ULONG cchNamespace,ULONG *pchNamespace,LPWSTR szTypeDef,ULONG cchTypeDef,ULONG *pchTypeDef,GUID *pguid,CLASSVERSION *pver,DWORD *pdwTypeDefFlags,mdToken *ptkExtends,DWORD *pdwExtendsFlags) PURE;
    STDMETHOD(GetClassSvcsContext)(mdScope es,mdTypeDef td,DWORD *pdwClassActivateAttr,DWORD *pdwThreadAttr,DWORD *pdwXactonAttr,DWORD *pdwSynchAttr) PURE;
    STDMETHOD(GetInterfaceImplProps)(mdScope scope,mdInterfaceImpl iiImpl,mdTypeDef *pClass,mdToken *ptkIface,DWORD *pdwFlags) PURE;
    STDMETHOD(GetCustomValueProps)(mdScope scope,mdCustomValue cv,LPWSTR szName,ULONG cchName,ULONG *pchName,DWORD *pdwValueType) PURE;
    STDMETHOD(GetCustomValueAsBlob)(mdScope scope,mdCustomValue cv,void const **ppBlob,ULONG *pcbSize) PURE;
    STDMETHOD(GetTypeRefProps)(mdScope scope,mdTypeRef tr,LPWSTR szTypeRef,ULONG cchTypeRef,ULONG *pchTypeRef,GUID *pGuid,DWORD *pdwBind) PURE;
    STDMETHOD(GetModuleRegProps)(mdScope scope,DWORD *pModuleRegAttr,GUID *pguid) PURE;
    STDMETHOD(GetClassRegProps)(mdScope scope,mdTypeDef td,LPWSTR szProgid,ULONG cchProgid,ULONG *pchProgid,LPWSTR szVIProgid,ULONG cchVIProgid,ULONG *pchVIProgid,LPWSTR szIconURL,ULONG cchIconURL,ULONG *pchIconURL,ULONG *pIconResource,LPWSTR szSmallIconURL,ULONG cchSmallIconURL,ULONG *pchSmallIconURL,ULONG *pSmallIconResource,LPWSTR szDefaultDispname,ULONG cchDefaultDispname,ULONG *pchDefaultDispname) PURE;
    STDMETHOD(GetIfaceRegProps)(mdScope scope,mdTypeDef td,DWORD *pdwIfaceSvcs,GUID *pProxyStub) PURE;
    STDMETHOD(GetResourceProps)(mdScope scope,mdResource rs,LPWSTR szURL,ULONG cchURL,ULONG *pchURL) PURE;
    STDMETHOD(GetCategoryImplProps)(mdScope scope,mdCocatImpl cocat,GUID *pguid,DWORD *pdwCocatImplAttr) PURE;
    STDMETHOD(GetRedirectProgIDProps)(mdScope scope,mdProgID progid,LPWSTR szProgID,ULONG cchProgID,ULONG *pchProgID) PURE;
    STDMETHOD(GetMimeTypeImplProps)(mdScope scope,mdMimeTypeImpl mime,LPWSTR szMime,ULONG cchMime,ULONG *pchMime) PURE;
    STDMETHOD(GetFormatImplProps)(mdScope scope,mdFormatImpl format,LPWSTR szFormat,ULONG cchFormat,ULONG *pchFormat,DWORD *pdwRegFormatAttr) PURE;
    STDMETHOD(GetRoleCheckProps)(mdScope scope,mdRoleCheck rc,LPWSTR szName,ULONG cchName,ULONG *pchName,DWORD *pdwRoleFlags) PURE;
    STDMETHOD(ResolveTypeRef)(mdScope is,mdTypeRef tr,mdScope *pes,mdTypeDef *ptd) PURE;
  };
#endif

#include <poppack.h>

#ifdef __cplusplus
}
#endif
#endif
