# test a Windows GUI application

import
  windows, shellapi, nb30, mmsystem, shfolder

#proc MessageBox(hWnd: int, lpText, lpCaption: CString, uType: uint): int
#  {stdcall, import: "MessageBox", header: "<windows.h>"}

discard MessageBox(0, "Hallo World!", "Nimrod GUI application", 0)
