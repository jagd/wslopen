#define UNICODE

#include <windows.h>

DWORD open(LPCTSTR filename) {
  DWORD exitCode = EXIT_FAILURE;

  if (lstrlen(filename) > 0) {
    SHELLEXECUTEINFO ShExecInfo = {0};
    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    ShExecInfo.fMask = SEE_MASK_DOENVSUBST | SEE_MASK_NOCLOSEPROCESS |
                       SEE_MASK_NOASYNC | SEE_MASK_WAITFORINPUTIDLE;
    ShExecInfo.hwnd = NULL;
    ShExecInfo.lpVerb = L"open";
    ShExecInfo.lpFile = filename;
    ShExecInfo.lpParameters = L"";
    ShExecInfo.lpDirectory = NULL;
    ShExecInfo.nShow = SW_SHOW;
    ShExecInfo.hInstApp = (HINSTANCE)SE_ERR_DDEFAIL;
    ShellExecuteEx(&ShExecInfo);
    if (ShExecInfo.hProcess) {
      WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
      GetExitCodeProcess(ShExecInfo.hProcess, &exitCode);
      CloseHandle(ShExecInfo.hProcess);
    }
  }
  return exitCode;
}

void mainCRTStartup() {
  TCHAR *p = GetCommandLine();
  while (*p) {
    if (*p == '\'' || *p == '"') {
      TCHAR quote = *p;
      ++p;
      while (*p && *p != quote)
        ++p;
    }
    ++p;
    if (*p == ' ') {
      while (*p == ' ')
        ++p;
      break;
    }
  }
  ExitProcess((*p == '\0') ? 1 : open(p));
}
