#include <Windows.h>

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

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPWSTR lpCmdLine, int nShowCmd) {
  DWORD exitCode = open(lpCmdLine);
  return exitCode;
}

int wmain(int argc, wchar_t *argv[], wchar_t *envp[]) {
  return (argc <= 1) ? 1 : open(argv[1]);
}
