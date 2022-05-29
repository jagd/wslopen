@echo off
cl /permissive- /GS /GL /W3 /Gy /Zc:wchar_t /Zi /Gm- /O2 /sdl /Zc:inline /fp:precise /WX- /Zc:forScope /Gd /Oi /MD /FC /EHsc /nologo /DUNICODE /c main.cc

link  /OUT:"open.exe" /LTCG /MANIFEST /NXCOMPAT /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /DEBUG:FULL /MACHINE:X64 /OPT:REF /SUBSYSTEM:CONSOLE /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /OPT:ICF /TLBID:1 main.obj

REM /SUBSYSTEM:WINDOWS for WinMain()
