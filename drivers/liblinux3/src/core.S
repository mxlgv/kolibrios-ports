
    .file   "export.s"
    .intel_syntax

.text
    .global _AcpiGetRootPtr
    .global _AllocKernelSpace
    .global _AllocPage
    .global _AllocPages

    .global _AttachIntHandler

    .global _CancelTimerHS
    .global _ChangeTask
    .global _CreateEvent
    .global _CreateObject
    .global _CreateRingBuffer
    .global _CreateThread

    .global _Delay
    .global _DestroyEvent
    .global _DestroyObject

    .global _DiskAdd
    .global _DiskMediaChanged

    .global _FreeKernelSpace
    .global _FreePage

    .global _GetClockNs
    .global _GetCpuFreq
    .global _GetDisplay
    .global _GetEvent
    .global _GetPgAddr
    .global _GetPCIList
    .global _GetPid
    .global _GetService
    .global _GetStackBase
    .global _GetTimerTicks
    .global _GetWindowRect

    .global _KernelAlloc
    .global _KernelFree

    .global _MapIoMem

    .global _MapPage

    .global _MutexInit
    .global _MutexLock
    .global _MutexUnlock
    .global _InitRwsem
    .global _DownRead
    .global _DownWrite
    .global _UpRead
    .global _UpWrite

    .global _PciApi
    .global _PciRead16
    .global _PciRead32
    .global _PciRead8
    .global _PciWrite16
    .global _PciWrite32
    .global _PciWrite8

    .global _RaiseEvent

    .global _RegService

    .global _SetFramebuffer

    .global _SetKeyboardData
    .global _SetMouseData

    .global _SetScreen
    .global _SysMsgBoardStr

    .global _TimerHS

    .global _UserAlloc
    .global _UserFree

    .global _WaitEvent
    .global _WaitEventTimeout

    .global _FS_Service

    .def  _AcpiGetRootPtr;  .scl  2;  .type 32; .endef

    .def  _AllocKernelSpace;  .scl  2;  .type 32; .endef
    .def  _AllocPage;         .scl  2;  .type 32; .endef
    .def  _AllocPages;        .scl  2;  .type 32; .endef

    .def  _AttachIntHandler;  .scl  2;  .type 32; .endef

    .def  _CancelTimerHS;     .scl  2;  .type 32; .endef
    .def  _ChangeTask;        .scl  2;  .type 32; .endef
    .def  _CreateEvent;       .scl  2;  .type 32; .endef
    .def  _CreateObject;      .scl  2;  .type 32; .endef
    .def  _CreateRingBuffer;  .scl  2;  .type 32; .endef
    .def  _CreateThread;      .scl  2;  .type 32; .endef

    .def  _Delay;             .scl  2;  .type 32; .endef
    .def  _DestroyEvent;      .scl  2;  .type 32; .endef
    .def  _DestroyObject;     .scl  2;  .type 32; .endef

    .def  _DiskAdd;           .scl  2;  .type 32; .endef
    .def  _DiskMediaChanged;  .scl  2;  .type 32; .endef

    .def  _FreeKernelSpace;   .scl  2;  .type 32; .endef
    .def  _FreePage;          .scl  2;  .type 32; .endef

    .def  _GetClockNs;        .scl  2;  .type 32; .endef

    .def  _GetDisplay;        .scl  2;  .type 32; .endef

    .def  _GetDisplay;        .scl  2;  .type 32; .endef
    .def  _GetEvent;          .scl  2;  .type 32; .endef
    .def  _GetPCIList;        .scl  2;  .type 32; .endef
    .def  _GetPid;            .scl  2;  .type 32; .endef
    .def  _GetPgAddr;         .scl  2;  .type 32; .endef
    .def  _GetService;        .scl  2;  .type 32; .endef
    .def  _GetTimerTicks;     .scl  2;  .type 32; .endef
    .def  _GetStackBase;      .scl  2;  .type 32; .endef
    .def  _GetWindowRect;     .scl  2;  .type 32; .endef

    .def  _KernelAlloc;       .scl  2;  .type 32; .endef
    .def  _KernelFree;        .scl  2;  .type 32; .endef

    .def  _MapIoMem;          .scl  2;  .type 32; .endef

    .def  _MapPage;           .scl  2;  .type 32; .endef

    .def  _MutexInit;         .scl  2;  .type 32; .endef
    .def  _MutexLock;         .scl  2;  .type 32; .endef
    .def  _MutexUnlock;       .scl  2;  .type 32; .endef

    .def _InitRwsem;          .scl  2;  .type 32; .endef
    .def _DownRead;           .scl  2;  .type 32; .endef
    .def _DownWrite;          .scl  2;  .type 32; .endef
    .def _UpRead;             .scl  2;  .type 32; .endef
    .def _UpWrite;            .scl  2;  .type 32; .endef

    .def  _PciApi;            .scl  2;  .type 32; .endef
    .def  _PciRead16;         .scl  2;  .type 32; .endef
    .def  _PciRead32;         .scl  2;  .type 32; .endef
    .def  _PciRead8;          .scl  2;  .type 32; .endef
    .def  _PciWrite16;        .scl  2;  .type 32; .endef
    .def  _PciWrite32;        .scl  2;  .type 32; .endef
    .def  _PciWrite8;         .scl  2;  .type 32; .endef

    .def  _RaiseEvent;        .scl  2;  .type 32; .endef

    .def  _RegService;        .scl  2;  .type 32; .endef

    .def  _SetFramebuffer;    .scl  2;  .type 32; .endef
    .def  _SetKeyboardData;   .scl  2;  .type 32; .endef
    .def  _SetMouseData;      .scl  2;  .type 32; .endef
    .def  _SetScreen;         .scl  2;  .type 32; .endef
    .def  _SysMsgBoardStr;    .scl  2;  .type 32; .endef

    .def  _TimerHS;           .scl  2;  .type 32; .endef

    .def  _UserAlloc;         .scl  2;  .type 32; .endef
    .def  _UserFree;          .scl  2;  .type 32; .endef

    .def  _WaitEvent;         .scl  2;  .type 32; .endef
    .def  _WaitEventTimeout;  .scl  2;  .type 32; .endef
    
    .def _FS_Service;         .scl  2;  .type 32; .endef
    
_AcpiGetRootPtr:

_AllocKernelSpace:
_AllocPage:
_AllocPages:

_AttachIntHandler:

_CancelTimerHS:
_ChangeTask:
_CreateEvent:
_CreateObject:
_CreateRingBuffer:
_CreateThread:

_Delay:

_DestroyEvent:
_DestroyObject:

_DiskAdd:
_DiskMediaChanged:

_FreeKernelSpace:
_FreePage:

_GetClockNs:
_GetCpuFreq:
_GetDisplay:
_GetEvent:
_GetPCIList:
_GetPid:
_GetPgAddr:
_GetService:
_GetTimerTicks:
_GetStackBase:
_GetWindowRect:

_KernelAlloc:
_KernelFree:

_MapIoMem:

_MapPage:

_MutexInit:
_MutexLock:
_MutexUnlock:

_InitRwsem:
_DownRead:
_DownWrite:
_UpRead:
_UpWrite:

_PciApi:
_PciRead16:
_PciRead32:
_PciRead8:
_PciWrite16:
_PciWrite32:
_PciWrite8:

_RaiseEvent:
_RegService:

_SetFramebuffer:
_SetKeyboardData:
_SetMouseData:
_SetScreen:
_SysMsgBoardStr:

_TimerHS:

_UserAlloc:
_UserFree:
_WaitEvent:
_WaitEventTimeout:

_FS_Service:

_GetCurrentSlot:

        ret

.section .drectve

        .ascii " -export:AcpiGetRootPtr"       #
        .ascii " -export:AllocKernelSpace"     # stdcall

        .ascii " -export:AllocPage"            # gcc ABI
        .ascii " -export:AllocPages"           # gcc ABI

        .ascii " -export:AttachIntHandler"     # stdcall

        .ascii " -export:CancelTimerHS"        # stfcall
        .ascii " -export:ChangeTask"           #
        .ascii " -export:CreateEvent"          #
        .ascii " -export:CreateObject"         #
        .ascii " -export:CreateRingBuffer"     # stdcall
        .ascii " -export:CreateThread"         #

        .ascii " -export:Delay"                # stdcall
        .ascii " -export:DestroyEvent"
        .ascii " -export:DestroyObject"
        .ascii " -export:DiskAdd"              # stdcall
        .ascii " -export:DiskMediaChanged"     # stdcall

        .ascii " -export:FreeKernelSpace"      # stdcall
        .ascii " -export:FreePage"             #

        .ascii " -export:GetClockNs"           #
        .ascii " -export:GetCpuFreq"           #
        .ascii " -export:GetDisplay"           # stdcall
        .ascii " -export:GetEvent"             #
        .ascii " -export:GetPCIList"           #
        .ascii " -export:GetPid"               #
        .ascii " -export:GetPgAddr"            # stdcall
        .ascii " -export:GetService"           # stdcall
        .ascii " -export:GetTimerTicks"        #
        .ascii " -export:GetStackBase"         #
        .ascii " -export:GetWindowRect"        # fastcall


        .ascii " -export:KernelAlloc"          # stdcall
        .ascii " -export:KernelFree"           # stdcall

        .ascii " -export:MapIoMem"             # stdcall
        .ascii " -export:MapPage"              # stdcall

        .ascii " -export:MutexInit"            # fastcall
        .ascii " -export:MutexLock"            # fastcall
        .ascii " -export:MutexUnlock"          # fastcall

        .ascii " -export:InitRwsem"            # fastcall
        .ascii " -export:DownRead"             # fastcall
        .ascii " -export:DownWrite"            # fastcall
        .ascii " -export:UpRead"               # fastcall
        .ascii " -export:UpWrite"              # fastcall

        .ascii " -export:PciApi"               #
        .ascii " -export:PciRead16"            # stdcall
        .ascii " -export:PciRead32"            # stdcall
        .ascii " -export:PciRead8"             # stdcall
        .ascii " -export:PciWrite16"           # stdcall
        .ascii " -export:PciWrite32"           # stdcall
        .ascii " -export:PciWrite8"            # stdcall

        .ascii " -export:RaiseEvent"           #

        .ascii " -export:RegService"           # stdcall

        .ascii " -export:SetFramebuffer"       # fastcall
        .ascii " -export:SetKeyboardData"      # stdcall
        .ascii " -export:SetMouseData"         # stdcall
        .ascii " -export:SetScreen"            # stdcall
        .ascii " -export:SysMsgBoardStr"       # stdcall

        .ascii " -export:TimerHS"              # stdcall

        .ascii " -export:UserAlloc"            # stdcall
        .ascii " -export:UserFree"             # stdcall

        .ascii " -export:WaitEvent"            # stdcall
        .ascii " -export:WaitEventTimeout"     # stdcall
        .ascii " -export:FS_Service"           # watch system call 70
        .ascii " -export:GetCurrentSlot"
