#include <windows.h>
#include <shellapi.h>
#include <string>
#include <iostream>

int WINAPI wWinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPWSTR    lpCmdLine,
        int       nShowCmd
        )
{
    std::wstring filename = lpCmdLine;
    // for future: better solution than this?
    for (wchar_t& c : filename) {
        if (c == L'/') {
            c = L'\\';
        }
    }
    if (!filename.empty()) {
#ifdef DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2
        SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
#endif
        CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
        // HINSTANCE to int according to MSDN doc
        const auto rcode = reinterpret_cast<ptrdiff_t>(
                ShellExecuteW(NULL, L"open", filename.c_str(), NULL, NULL, SW_SHOWNORMAL)
                );
        LPCWSTR rstr;
        if (32 > rcode) {
            switch (rcode) {
                case 0: rstr = L"The operating system is out of memory or resources."; break;
                case ERROR_FILE_NOT_FOUND: rstr = L"The specified file was not found."; break;
                case ERROR_PATH_NOT_FOUND: rstr = L"The specified path was not found."; break;
                case ERROR_BAD_FORMAT: rstr = L"The .exe file is invalid (non-Win32 .exe or error in .exe image)."; break;
                case SE_ERR_ACCESSDENIED: rstr = L"The operating system denied access to the specified file."; break;
                case SE_ERR_ASSOCINCOMPLETE: rstr = L"The file name association is incomplete or invalid."; break;
                case SE_ERR_DDEBUSY: rstr = L"The DDE transaction could not be completed because other DDE transactions were being processed."; break;
                case SE_ERR_DDEFAIL: rstr = L"The DDE transaction failed."; break;
                case SE_ERR_DDETIMEOUT: rstr = L"The DDE transaction could not be completed because the request timed out."; break;
                case SE_ERR_DLLNOTFOUND: rstr = L"The specified DLL was not found."; break;
                case SE_ERR_NOASSOC: rstr = L"There is no application associated with the given file name extension. This error will also be returned if you attempt to print a file that is not printable."; break;
                case SE_ERR_OOM: rstr = L"There was not enough memory to complete the operation."; break;
                case SE_ERR_SHARE: rstr = L"A sharing violation occurred. "; break;
                default:
                    rstr = L"Unknown error";
            }
            MessageBoxW(NULL, (L"Failed to open " + filename + static_cast<wchar_t>('\n') + rstr).c_str(), L"Failed", MB_OK);
        }
    }
    return EXIT_SUCCESS;
}
