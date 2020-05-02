#include <windows.h>
#include <shellapi.h>
#include <string>
#include <iostream>

std::wstring lasterrToString()
{
    //Get the error message, if any.
    DWORD errorMessageID = ::GetLastError();
    if(errorMessageID == 0)
        return std::wstring();
    LPWSTR messageBuffer = nullptr;
    size_t size = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                 NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&messageBuffer, 0, NULL);

    std::wstring message(messageBuffer, size);
    LocalFree(messageBuffer);

    return message;
}

DWORD open(std::wstring filename)
{
    DWORD exitCode = EXIT_FAILURE;
    // for future: better solution than this?
    for (wchar_t& c : filename) {
        if (c == L'/') {
            c = L'\\';
        }
    }
    if (!filename.empty()) {
        SHELLEXECUTEINFO ShExecInfo = { 0 };
        ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
        ShExecInfo.fMask = SEE_MASK_DOENVSUBST | SEE_MASK_NOCLOSEPROCESS | SEE_MASK_NOASYNC | SEE_MASK_WAITFORINPUTIDLE;
        ShExecInfo.hwnd = NULL;
        ShExecInfo.lpVerb = L"open";
        ShExecInfo.lpFile = static_cast<LPCWSTR>(filename.c_str());
        ShExecInfo.lpParameters = L"";
        ShExecInfo.lpDirectory = NULL;
        ShExecInfo.nShow = SW_SHOW;
        ShExecInfo.hInstApp = (HINSTANCE) SE_ERR_DDEFAIL;
        ShellExecuteEx(&ShExecInfo);
        if (ShExecInfo.hProcess) {
            ::WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
            ::GetExitCodeProcess(ShExecInfo.hProcess, &exitCode);
            ::CloseHandle(ShExecInfo.hProcess);
        }
    }
    return exitCode;
}


void init()
{
#ifdef DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2
        SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
#endif
        CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
}

int WINAPI wWinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPWSTR    lpCmdLine,
        int       nShowCmd
        )
{
    init();
    DWORD exitCode = open(lpCmdLine);
    return exitCode;
}

int wmain(int argc, wchar_t *argv[], wchar_t *envp[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " file" << std::endl;
        return 1;
    }
    init();
    DWORD exitCode = open(argv[1]);
    return exitCode;
}
