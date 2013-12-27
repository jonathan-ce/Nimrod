#
#
#            Nimrod's Runtime Library
#        (c) Copyright 2012 Andreas Rumpf
#
#    See the file "copying.txt", included in this
#    distribution, for details about the copyright.
#

## This module implements a small wrapper for some needed Win API procedures,
## so that the Nimrod compiler does not depend on the huge Windows module.

const
  useWinUnicode* = not defined(useWinAnsi)

type
  THandle* = int
  LONG* = int32
  WINBOOL* = int32
  DWORD* = int32
  HDC* = THandle
  HGLRC* = THandle

  TSECURITY_ATTRIBUTES* {.final, pure.} = object
    nLength*: int32
    lpSecurityDescriptor*: pointer
    bInheritHandle*: WINBOOL
  
  TSTARTUPINFO* {.final, pure.} = object
    cb*: int32
    lpReserved*: cstring
    lpDesktop*: cstring
    lpTitle*: cstring
    dwX*: int32
    dwY*: int32
    dwXSize*: int32
    dwYSize*: int32
    dwXCountChars*: int32
    dwYCountChars*: int32
    dwFillAttribute*: int32
    dwFlags*: int32
    wShowWindow*: int16
    cbReserved2*: int16
    lpReserved2*: pointer
    hStdInput*: THANDLE
    hStdOutput*: THANDLE
    hStdError*: THANDLE

  TPROCESS_INFORMATION* {.final, pure.} = object
    hProcess*: THANDLE
    hThread*: THANDLE
    dwProcessId*: int32
    dwThreadId*: int32

  TFILETIME* {.final, pure.} = object ## CANNOT BE int64 BECAUSE OF ALIGNMENT
    dwLowDateTime*: DWORD
    dwHighDateTime*: DWORD
  
  TBY_HANDLE_FILE_INFORMATION* {.final, pure.} = object
    dwFileAttributes*: DWORD
    ftCreationTime*: TFILETIME
    ftLastAccessTime*: TFILETIME
    ftLastWriteTime*: TFILETIME
    dwVolumeSerialNumber*: DWORD
    nFileSizeHigh*: DWORD
    nFileSizeLow*: DWORD
    nNumberOfLinks*: DWORD
    nFileIndexHigh*: DWORD
    nFileIndexLow*: DWORD

when useWinUnicode:
  type TWinChar* = TUtf16Char
else:
  type TWinChar* = char

const
  STARTF_USESHOWWINDOW* = 1'i32
  STARTF_USESTDHANDLES* = 256'i32
  HIGH_PRIORITY_CLASS* = 128'i32
  IDLE_PRIORITY_CLASS* = 64'i32
  NORMAL_PRIORITY_CLASS* = 32'i32
  REALTIME_PRIORITY_CLASS* = 256'i32
  WAIT_OBJECT_0* = 0'i32
  WAIT_TIMEOUT* = 0x00000102'i32
  WAIT_FAILED* = 0xFFFFFFFF'i32
  INFINITE* = -1'i32

  STD_INPUT_HANDLE* = -10'i32
  STD_OUTPUT_HANDLE* = -11'i32
  STD_ERROR_HANDLE* = -12'i32

  DETACHED_PROCESS* = 8'i32
  
  SW_SHOWNORMAL* = 1'i32
  INVALID_HANDLE_VALUE* = THANDLE(-1)
  
  CREATE_UNICODE_ENVIRONMENT* = 1024'i32

proc closeHandle*(hObject: THANDLE): WINBOOL {.stdcall, dynlib: "kernel32",
    importc: "CloseHandle".}
    
proc readFile*(hFile: THandle, Buffer: pointer, nNumberOfBytesToRead: int32,
               lpNumberOfBytesRead: var int32, lpOverlapped: pointer): WINBOOL{.
    stdcall, dynlib: "kernel32", importc: "ReadFile".}
    
proc writeFile*(hFile: THandle, Buffer: pointer, nNumberOfBytesToWrite: int32,
                lpNumberOfBytesWritten: var int32, 
                lpOverlapped: pointer): WINBOOL{.
    stdcall, dynlib: "kernel32", importc: "WriteFile".}

proc createPipe*(hReadPipe, hWritePipe: var THandle,
                 lpPipeAttributes: var TSECURITY_ATTRIBUTES, 
                 nSize: int32): WINBOOL{.
    stdcall, dynlib: "kernel32", importc: "CreatePipe".}

when useWinUnicode:
  proc createProcessW*(lpApplicationName, lpCommandLine: widecstring,
                     lpProcessAttributes: ptr TSECURITY_ATTRIBUTES,
                     lpThreadAttributes: ptr TSECURITY_ATTRIBUTES,
                     bInheritHandles: WINBOOL, dwCreationFlags: int32,
                     lpEnvironment, lpCurrentDirectory: widecstring,
                     lpStartupInfo: var TSTARTUPINFO,
                     lpProcessInformation: var TPROCESS_INFORMATION): WINBOOL{.
    stdcall, dynlib: "kernel32", importc: "CreateProcessW".}

else:
  proc createProcessA*(lpApplicationName, lpCommandLine: cstring,
                       lpProcessAttributes: ptr TSECURITY_ATTRIBUTES,
                       lpThreadAttributes: ptr TSECURITY_ATTRIBUTES,
                       bInheritHandles: WINBOOL, dwCreationFlags: int32,
                       lpEnvironment: pointer, lpCurrentDirectory: cstring,
                       lpStartupInfo: var TSTARTUPINFO,
                       lpProcessInformation: var TPROCESS_INFORMATION): WINBOOL{.
      stdcall, dynlib: "kernel32", importc: "CreateProcessA".}


proc suspendThread*(hThread: THANDLE): int32 {.stdcall, dynlib: "kernel32",
    importc: "SuspendThread".}
proc resumeThread*(hThread: THANDLE): int32 {.stdcall, dynlib: "kernel32",
    importc: "ResumeThread".}

proc waitForSingleObject*(hHandle: THANDLE, dwMilliseconds: int32): int32 {.
    stdcall, dynlib: "kernel32", importc: "WaitForSingleObject".}

proc terminateProcess*(hProcess: THANDLE, uExitCode: int): WINBOOL {.stdcall,
    dynlib: "kernel32", importc: "TerminateProcess".}

proc getExitCodeProcess*(hProcess: THANDLE, lpExitCode: var int32): WINBOOL {.
    stdcall, dynlib: "kernel32", importc: "GetExitCodeProcess".}

proc getStdHandle*(nStdHandle: int32): THANDLE {.stdcall, dynlib: "kernel32",
    importc: "GetStdHandle".}
proc setStdHandle*(nStdHandle: int32, hHandle: THANDLE): WINBOOL {.stdcall,
    dynlib: "kernel32", importc: "SetStdHandle".}
proc flushFileBuffers*(hFile: THANDLE): WINBOOL {.stdcall, dynlib: "kernel32",
    importc: "FlushFileBuffers".}

proc getLastError*(): int32 {.importc: "GetLastError", 
    stdcall, dynlib: "kernel32".}

when useWinUnicode:
  proc formatMessageW*(dwFlags: int32, lpSource: pointer,
                      dwMessageId, dwLanguageId: int32,
                      lpBuffer: pointer, nSize: int32,
                      Arguments: pointer): int32 {.
                      importc: "FormatMessageW", stdcall, dynlib: "kernel32".}
else:
  proc formatMessageA*(dwFlags: int32, lpSource: pointer,
                    dwMessageId, dwLanguageId: int32,
                    lpBuffer: pointer, nSize: int32,
                    Arguments: pointer): int32 {.
                    importc: "FormatMessageA", stdcall, dynlib: "kernel32".}

proc localFree*(p: pointer) {.
  importc: "LocalFree", stdcall, dynlib: "kernel32".}

when useWinUnicode:
  proc getCurrentDirectoryW*(nBufferLength: int32, 
                             lpBuffer: widecstring): int32 {.
    importc: "GetCurrentDirectoryW", dynlib: "kernel32", stdcall.}
  proc setCurrentDirectoryW*(lpPathName: widecstring): int32 {.
    importc: "SetCurrentDirectoryW", dynlib: "kernel32", stdcall.}
  proc createDirectoryW*(pathName: widecstring, security: Pointer=nil): int32 {.
    importc: "CreateDirectoryW", dynlib: "kernel32", stdcall.}
  proc removeDirectoryW*(lpPathName: widecstring): int32 {.
    importc: "RemoveDirectoryW", dynlib: "kernel32", stdcall.}
  proc setEnvironmentVariableW*(lpName, lpValue: widecstring): int32 {.
    stdcall, dynlib: "kernel32", importc: "SetEnvironmentVariableW".}

  proc getModuleFileNameW*(handle: THandle, buf: wideCString, 
                           size: int32): int32 {.importc: "GetModuleFileNameW", 
    dynlib: "kernel32", stdcall.}
else:
  proc getCurrentDirectoryA*(nBufferLength: int32, lpBuffer: cstring): int32 {.
    importc: "GetCurrentDirectoryA", dynlib: "kernel32", stdcall.}
  proc setCurrentDirectoryA*(lpPathName: cstring): int32 {.
    importc: "SetCurrentDirectoryA", dynlib: "kernel32", stdcall.}
  proc createDirectoryA*(pathName: cstring, security: Pointer=nil): int32 {.
    importc: "CreateDirectoryA", dynlib: "kernel32", stdcall.}
  proc removeDirectoryA*(lpPathName: cstring): int32 {.
    importc: "RemoveDirectoryA", dynlib: "kernel32", stdcall.}
  proc setEnvironmentVariableA*(lpName, lpValue: cstring): int32 {.
    stdcall, dynlib: "kernel32", importc: "SetEnvironmentVariableA".}

  proc getModuleFileNameA*(handle: THandle, buf: CString, size: int32): int32 {.
    importc: "GetModuleFileNameA", dynlib: "kernel32", stdcall.}
  
const
  FILE_ATTRIBUTE_ARCHIVE* = 32'i32
  FILE_ATTRIBUTE_COMPRESSED* = 2048'i32
  FILE_ATTRIBUTE_NORMAL* = 128'i32
  FILE_ATTRIBUTE_DIRECTORY* = 16'i32
  FILE_ATTRIBUTE_HIDDEN* = 2'i32
  FILE_ATTRIBUTE_READONLY* = 1'i32
  FILE_ATTRIBUTE_SYSTEM* = 4'i32
  FILE_ATTRIBUTE_TEMPORARY* = 256'i32

  MAX_PATH* = 260
type
  TWIN32_FIND_DATA* {.pure.} = object
    dwFileAttributes*: int32
    ftCreationTime*: TFILETIME
    ftLastAccessTime*: TFILETIME
    ftLastWriteTime*: TFILETIME
    nFileSizeHigh*: int32
    nFileSizeLow*: int32
    dwReserved0: int32
    dwReserved1: int32
    cFileName*: array[0..(MAX_PATH) - 1, TWinChar]
    cAlternateFileName*: array[0..13, TWinChar]

when useWinUnicode:
  proc findFirstFileW*(lpFileName: widecstring,
                      lpFindFileData: var TWIN32_FIND_DATA): THANDLE {.
      stdcall, dynlib: "kernel32", importc: "FindFirstFileW".}
  proc findNextFileW*(hFindFile: THANDLE,
                     lpFindFileData: var TWIN32_FIND_DATA): int32 {.
      stdcall, dynlib: "kernel32", importc: "FindNextFileW".}
else:
  proc findFirstFileA*(lpFileName: cstring,
                      lpFindFileData: var TWIN32_FIND_DATA): THANDLE {.
      stdcall, dynlib: "kernel32", importc: "FindFirstFileA".}
  proc findNextFileA*(hFindFile: THANDLE,
                     lpFindFileData: var TWIN32_FIND_DATA): int32 {.
      stdcall, dynlib: "kernel32", importc: "FindNextFileA".}

proc findClose*(hFindFile: THANDLE) {.stdcall, dynlib: "kernel32",
  importc: "FindClose".}

when useWinUnicode:
  proc getFullPathNameW*(lpFileName: widecstring, nBufferLength: int32,
                        lpBuffer: widecstring, 
                        lpFilePart: var widecstring): int32 {.
                        stdcall, dynlib: "kernel32", 
                        importc: "GetFullPathNameW".}
  proc getFileAttributesW*(lpFileName: widecstring): int32 {.
                          stdcall, dynlib: "kernel32", 
                          importc: "GetFileAttributesW".}
  proc setFileAttributesW*(lpFileName: widecstring, 
                           dwFileAttributes: int32): WINBOOL {.
      stdcall, dynlib: "kernel32", importc: "SetFileAttributesW".}

  proc copyFileW*(lpExistingFileName, lpNewFileName: wideCString,
                 bFailIfExists: cint): cint {.
    importc: "CopyFileW", stdcall, dynlib: "kernel32".}

  proc getEnvironmentStringsW*(): widecstring {.
    stdcall, dynlib: "kernel32", importc: "GetEnvironmentStringsW".}
  proc freeEnvironmentStringsW*(para1: widecstring): int32 {.
    stdcall, dynlib: "kernel32", importc: "FreeEnvironmentStringsW".}

  proc getCommandLineW*(): wideCString {.importc: "GetCommandLineW",
    stdcall, dynlib: "kernel32".}

else:
  proc getFullPathNameA*(lpFileName: cstring, nBufferLength: int32,
                        lpBuffer: cstring, lpFilePart: var cstring): int32 {.
                        stdcall, dynlib: "kernel32", 
                        importc: "GetFullPathNameA".}
  proc getFileAttributesA*(lpFileName: cstring): int32 {.
                          stdcall, dynlib: "kernel32", 
                          importc: "GetFileAttributesA".}
  proc setFileAttributesA*(lpFileName: cstring, 
                           dwFileAttributes: int32): WINBOOL {.
      stdcall, dynlib: "kernel32", importc: "SetFileAttributesA".}

  proc copyFileA*(lpExistingFileName, lpNewFileName: CString,
                 bFailIfExists: cint): cint {.
    importc: "CopyFileA", stdcall, dynlib: "kernel32".}

  proc getEnvironmentStringsA*(): cstring {.
    stdcall, dynlib: "kernel32", importc: "GetEnvironmentStringsA".}
  proc freeEnvironmentStringsA*(para1: cstring): int32 {.
    stdcall, dynlib: "kernel32", importc: "FreeEnvironmentStringsA".}

  proc getCommandLineA*(): cstring {.
    importc: "GetCommandLineA", stdcall, dynlib: "kernel32".}

proc rdFileTime*(f: TFILETIME): int64 = 
  result = ze64(f.dwLowDateTime) or (ze64(f.dwHighDateTime) shl 32)

proc rdFileSize*(f: TWin32FindData): int64 = 
  result = ze64(f.nFileSizeLow) or (ze64(f.nFileSizeHigh) shl 32)

proc getSystemTimeAsFileTime*(lpSystemTimeAsFileTime: var TFILETIME) {.
  importc: "GetSystemTimeAsFileTime", dynlib: "kernel32", stdcall.}

proc sleep*(dwMilliseconds: int32){.stdcall, dynlib: "kernel32",
                                    importc: "Sleep".}

when useWinUnicode:
  proc shellExecuteW*(HWND: THandle, lpOperation, lpFile,
                     lpParameters, lpDirectory: widecstring,
                     nShowCmd: int32): THandle{.
      stdcall, dynlib: "shell32.dll", importc: "ShellExecuteW".}

else:
  proc shellExecuteA*(HWND: THandle, lpOperation, lpFile,
                     lpParameters, lpDirectory: cstring,
                     nShowCmd: int32): THandle{.
      stdcall, dynlib: "shell32.dll", importc: "ShellExecuteA".}
  
proc getFileInformationByHandle*(hFile: THandle,
  lpFileInformation: ptr TBY_HANDLE_FILE_INFORMATION): WINBOOL{.
    stdcall, dynlib: "kernel32", importc: "GetFileInformationByHandle".}

const
  WSADESCRIPTION_LEN* = 256
  WSASYS_STATUS_LEN* = 128
  FD_SETSIZE* = 64
  MSG_PEEK* = 2
 
  INADDR_ANY* = 0
  INADDR_LOOPBACK* = 0x7F000001
  INADDR_BROADCAST* = -1
  INADDR_NONE* = -1
  
  ws2dll = "Ws2_32.dll"

  WSAEWOULDBLOCK* = 10035
  WSAEINPROGRESS* = 10036

proc wsaGetLastError*(): cint {.importc: "WSAGetLastError", dynlib: ws2dll.}

type
  TSocketHandle* = distinct int

type
  TWSAData* {.pure, final, importc: "WSADATA", header: "Winsock2.h".} = object 
    wVersion, wHighVersion: int16
    szDescription: array[0..WSADESCRIPTION_LEN, char]
    szSystemStatus: array[0..WSASYS_STATUS_LEN, char]
    iMaxSockets, iMaxUdpDg: int16
    lpVendorInfo: cstring
    
  TSockAddr* {.pure, final, importc: "SOCKADDR", header: "Winsock2.h".} = object 
    sa_family*: int16 # unsigned
    sa_data: array[0..13, char]

  TInAddr* {.pure, final, importc: "IN_ADDR", header: "Winsock2.h".} = object
    s_addr*: int32  # IP address
  
  Tsockaddr_in* {.pure, final, importc: "SOCKADDR_IN", 
                  header: "Winsock2.h".} = object
    sin_family*: int16
    sin_port*: int16 # unsigned
    sin_addr*: TInAddr
    sin_zero*: array[0..7, char]

  Tin6_addr* {.pure, final, importc: "IN6_ADDR", header: "Winsock2.h".} = object 
    bytes*: array[0..15, char]

  Tsockaddr_in6* {.pure, final, importc: "SOCKADDR_IN6", 
                   header: "Winsock2.h".} = object
    sin6_family*: int16
    sin6_port*: int16 # unsigned
    sin6_flowinfo*: int32 # unsigned
    sin6_addr*: Tin6_addr
    sin6_scope_id*: int32 # unsigned

  Tsockaddr_in6_old* {.pure, final.} = object
    sin6_family*: int16
    sin6_port*: int16 # unsigned
    sin6_flowinfo*: int32 # unsigned
    sin6_addr*: Tin6_addr

  TServent* {.pure, final.} = object
    s_name*: cstring
    s_aliases*: cstringArray
    when defined(cpu64):
      s_proto*: cstring
      s_port*: int16
    else:
      s_port*: int16
      s_proto*: cstring

  Thostent* {.pure, final.} = object
    h_name*: cstring
    h_aliases*: cstringArray
    h_addrtype*: int16
    h_length*: int16
    h_addr_list*: cstringArray
  
  TFdSet* {.pure, final.} = object
    fd_count*: cint # unsigned
    fd_array*: array[0..FD_SETSIZE-1, TSocketHandle]
    
  TTimeval* {.pure, final.} = object
    tv_sec*, tv_usec*: int32
    
  TAddrInfo* {.pure, final.} = object
    ai_flags*: cint         ## Input flags. 
    ai_family*: cint        ## Address family of socket. 
    ai_socktype*: cint      ## Socket type. 
    ai_protocol*: cint      ## Protocol of socket. 
    ai_addrlen*: int        ## Length of socket address. 
    ai_canonname*: cstring  ## Canonical name of service location.
    ai_addr*: ptr TSockAddr ## Socket address of socket. 
    ai_next*: ptr TAddrInfo ## Pointer to next in list. 

  Tsocklen* = cuint

var
  SOMAXCONN* {.importc, header: "Winsock2.h".}: cint
  INVALID_SOCKET* {.importc, header: "Winsock2.h".}: TSocketHandle
  SOL_SOCKET* {.importc, header: "Winsock2.h".}: cint
  SO_DEBUG* {.importc, header: "Winsock2.h".}: cint ## turn on debugging info recording
  SO_ACCEPTCONN* {.importc, header: "Winsock2.h".}: cint # socket has had listen()
  SO_REUSEADDR* {.importc, header: "Winsock2.h".}: cint # allow local address reuse
  SO_KEEPALIVE* {.importc, header: "Winsock2.h".}: cint # keep connections alive
  SO_DONTROUTE* {.importc, header: "Winsock2.h".}: cint # just use interface addresses
  SO_BROADCAST* {.importc, header: "Winsock2.h".}: cint # permit sending of broadcast msgs
  SO_USELOOPBACK* {.importc, header: "Winsock2.h".}: cint # bypass hardware when possible
  SO_LINGER* {.importc, header: "Winsock2.h".}: cint # linger on close if data present
  SO_OOBINLINE* {.importc, header: "Winsock2.h".}: cint # leave received OOB data in line

  SO_DONTLINGER* {.importc, header: "Winsock2.h".}: cint
  SO_EXCLUSIVEADDRUSE* {.importc, header: "Winsock2.h".}: cint # disallow local address reuse

proc `==`*(x, y: TSocketHandle): bool {.borrow.}

proc getservbyname*(name, proto: cstring): ptr TServent {.
  stdcall, importc: "getservbyname", dynlib: ws2dll.}

proc getservbyport*(port: cint, proto: cstring): ptr TServent {.
  stdcall, importc: "getservbyport", dynlib: ws2dll.}

proc gethostbyaddr*(ip: ptr TInAddr, len: cuint, theType: cint): ptr THostEnt {.
  stdcall, importc: "gethostbyaddr", dynlib: ws2dll.}

proc gethostbyname*(name: cstring): ptr THostEnt {.
  stdcall, importc: "gethostbyname", dynlib: ws2dll.}

proc socket*(af, typ, protocol: cint): TSocketHandle {.
  stdcall, importc: "socket", dynlib: ws2dll.}

proc closesocket*(s: TSocketHandle): cint {.
  stdcall, importc: "closesocket", dynlib: ws2dll.}

proc accept*(s: TSocketHandle, a: ptr TSockAddr, addrlen: ptr TSockLen): TSocketHandle {.
  stdcall, importc: "accept", dynlib: ws2dll.}
proc bindSocket*(s: TSocketHandle, name: ptr TSockAddr, namelen: TSockLen): cint {.
  stdcall, importc: "bind", dynlib: ws2dll.}
proc connect*(s: TSocketHandle, name: ptr TSockAddr, namelen: TSockLen): cint {.
  stdcall, importc: "connect", dynlib: ws2dll.}
proc getsockname*(s: TSocketHandle, name: ptr TSockAddr, 
                  namelen: ptr TSockLen): cint {.
  stdcall, importc: "getsockname", dynlib: ws2dll.}
proc getsockopt*(s: TSocketHandle, level, optname: cint, optval: pointer,
                 optlen: ptr TSockLen): cint {.
  stdcall, importc: "getsockopt", dynlib: ws2dll.}
proc setsockopt*(s: TSocketHandle, level, optname: cint, optval: pointer,
                 optlen: TSockLen): cint {.
  stdcall, importc: "setsockopt", dynlib: ws2dll.}

proc listen*(s: TSocketHandle, backlog: cint): cint {.
  stdcall, importc: "listen", dynlib: ws2dll.}
proc recv*(s: TSocketHandle, buf: pointer, len, flags: cint): cint {.
  stdcall, importc: "recv", dynlib: ws2dll.}
proc recvfrom*(s: TSocketHandle, buf: cstring, len, flags: cint, 
               fromm: ptr TSockAddr, fromlen: ptr Tsocklen): cint {.
  stdcall, importc: "recvfrom", dynlib: ws2dll.}
proc select*(nfds: cint, readfds, writefds, exceptfds: ptr TFdSet,
             timeout: ptr TTimeval): cint {.
  stdcall, importc: "select", dynlib: ws2dll.}
proc send*(s: TSocketHandle, buf: pointer, len, flags: cint): cint {.
  stdcall, importc: "send", dynlib: ws2dll.}
proc sendto*(s: TSocketHandle, buf: pointer, len, flags: cint,
             to: ptr TSockAddr, tolen: Tsocklen): cint {.
  stdcall, importc: "sendto", dynlib: ws2dll.}

proc shutdown*(s: TSocketHandle, how: cint): cint {.
  stdcall, importc: "shutdown", dynlib: ws2dll.}
  
proc getnameinfo*(a1: ptr Tsockaddr, a2: Tsocklen,
                  a3: cstring, a4: Tsocklen, a5: cstring,
                  a6: Tsocklen, a7: cint): cint {.
  stdcall, importc: "getnameinfo", dynlib: ws2dll.}
  
proc inet_addr*(cp: cstring): int32 {.
  stdcall, importc: "inet_addr", dynlib: ws2dll.} 

proc WSAFDIsSet(s: TSocketHandle, FDSet: var TFDSet): bool {.
  stdcall, importc: "__WSAFDIsSet", dynlib: ws2dll.}

proc FD_ISSET*(Socket: TSocketHandle, FDSet: var TFDSet): cint = 
  result = if WSAFDIsSet(Socket, FDSet): 1'i32 else: 0'i32

proc FD_SET*(Socket: TSocketHandle, FDSet: var TFDSet) = 
  if FDSet.fd_count < FD_SETSIZE:
    FDSet.fd_array[int(FDSet.fd_count)] = Socket
    inc(FDSet.fd_count)

proc FD_ZERO*(FDSet: var TFDSet) =
  FDSet.fd_count = 0

proc WSAStartup*(wVersionRequired: int16, WSData: ptr TWSAData): cint {.
  stdcall, importc: "WSAStartup", dynlib: ws2dll.}

proc getaddrinfo*(nodename, servname: cstring, hints: ptr TAddrInfo,
                  res: var ptr TAddrInfo): cint {.
  stdcall, importc: "getaddrinfo", dynlib: ws2dll.}

proc freeaddrinfo*(ai: ptr TAddrInfo) {.
  stdcall, importc: "freeaddrinfo", dynlib: ws2dll.}

proc inet_ntoa*(i: TInAddr): cstring {.
  stdcall, importc, dynlib: ws2dll.}

const
  MAXIMUM_WAIT_OBJECTS* = 0x00000040

type
  TWOHandleArray* = array[0..MAXIMUM_WAIT_OBJECTS - 1, THANDLE]
  PWOHandleArray* = ptr TWOHandleArray

proc waitForMultipleObjects*(nCount: DWORD, lpHandles: PWOHandleArray,
                             bWaitAll: WINBOOL, dwMilliseconds: DWORD): DWORD{.
    stdcall, dynlib: "kernel32", importc: "WaitForMultipleObjects".}
    
    
# for memfiles.nim:

const
  GENERIC_READ* = 0x80000000'i32
  GENERIC_ALL* = 0x10000000'i32
  FILE_SHARE_READ* = 1'i32
  FILE_SHARE_DELETE* = 4'i32
  FILE_SHARE_WRITE* = 2'i32
 
  CREATE_ALWAYS* = 2'i32
  OPEN_EXISTING* = 3'i32
  FILE_BEGIN* = 0'i32
  INVALID_SET_FILE_POINTER* = -1'i32
  NO_ERROR* = 0'i32
  PAGE_READONLY* = 2'i32
  PAGE_READWRITE* = 4'i32
  FILE_MAP_READ* = 4'i32
  FILE_MAP_WRITE* = 2'i32
  INVALID_FILE_SIZE* = -1'i32

  FILE_FLAG_BACKUP_SEMANTICS* = 33554432'i32

# Error Constants
const
  ERROR_ACCESS_DENIED* = 5

when useWinUnicode:
  proc createFileW*(lpFileName: widecstring, dwDesiredAccess, dwShareMode: DWORD,
                    lpSecurityAttributes: pointer,
                    dwCreationDisposition, dwFlagsAndAttributes: DWORD,
                    hTemplateFile: THANDLE): THANDLE {.
      stdcall, dynlib: "kernel32", importc: "CreateFileW".}
  proc deleteFileW*(pathName: widecstring): int32 {.
    importc: "DeleteFileW", dynlib: "kernel32", stdcall.}
else:
  proc createFileA*(lpFileName: cstring, dwDesiredAccess, dwShareMode: DWORD,
                    lpSecurityAttributes: pointer,
                    dwCreationDisposition, dwFlagsAndAttributes: DWORD,
                    hTemplateFile: THANDLE): THANDLE {.
      stdcall, dynlib: "kernel32", importc: "CreateFileA".}
  proc deleteFileA*(pathName: cstring): int32 {.
    importc: "DeleteFileA", dynlib: "kernel32", stdcall.}

proc setEndOfFile*(hFile: THANDLE): WINBOOL {.stdcall, dynlib: "kernel32",
    importc: "SetEndOfFile".}

proc setFilePointer*(hFile: THANDLE, lDistanceToMove: LONG,
                     lpDistanceToMoveHigh: ptr LONG, 
                     dwMoveMethod: DWORD): DWORD {.
    stdcall, dynlib: "kernel32", importc: "SetFilePointer".}

proc getFileSize*(hFile: THANDLE, lpFileSizeHigh: ptr DWORD): DWORD{.stdcall,
    dynlib: "kernel32", importc: "GetFileSize".}

proc mapViewOfFileEx*(hFileMappingObject: THANDLE, dwDesiredAccess: DWORD,
                      dwFileOffsetHigh, dwFileOffsetLow: DWORD,
                      dwNumberOfBytesToMap: DWORD, 
                      lpBaseAddress: pointer): pointer{.
    stdcall, dynlib: "kernel32", importc: "MapViewOfFileEx".}

proc createFileMappingW*(hFile: THANDLE,
                       lpFileMappingAttributes: pointer,
                       flProtect, dwMaximumSizeHigh: DWORD,
                       dwMaximumSizeLow: DWORD, 
                       lpName: pointer): THANDLE {.
  stdcall, dynlib: "kernel32", importc: "CreateFileMappingW".}

when not useWinUnicode:
  proc createFileMappingA*(hFile: THANDLE,
                           lpFileMappingAttributes: pointer,
                           flProtect, dwMaximumSizeHigh: DWORD,
                           dwMaximumSizeLow: DWORD, lpName: cstring): THANDLE {.
      stdcall, dynlib: "kernel32", importc: "CreateFileMappingA".}

proc unmapViewOfFile*(lpBaseAddress: pointer): WINBOOL {.stdcall,
    dynlib: "kernel32", importc: "UnmapViewOfFile".}

