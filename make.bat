@echo off
cl /nologo /W4 /FC /Od /GL /Gy /GS- /Gm- /sdl- /Zc:inline /EHsc /c main.c

link /OUT:"wslopen.exe" /MACHINE:X64 /MANIFEST:NO /nologo ^
     /DEBUG:NONE /OPT:REF /LTCG /DYNAMICBASE:NO ^
     /RELEASE /SUBSYSTEM:CONSOLE /NODEFAULTLIB ^
     /MERGE:.rdata=.text /MERGE:.pdata=.text /MERGE:.data=.text /STUB:stub.bin ^
     kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ^
     main.obj

dumpbin /DEPENDENTS wslopen.exe
