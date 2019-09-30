#define UNICODE

#include <windows.h>
#include <string>

int WINAPI wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR     lpCmdLine,
	int       nShowCmd
)
{
	const std::wstring cmd = lpCmdLine;
	if (!cmd.empty()) {
		const std::wstring str = TEXT("cmd.exe /c start ") + cmd;
		STARTUPINFO info = { sizeof(info) };
		PROCESS_INFORMATION processInfo;
		CreateProcessW(
			NULL, const_cast<LPWSTR>(str.c_str()),
			NULL, NULL, false, 0, NULL, NULL, &info, &processInfo
		);
	}
	return EXIT_SUCCESS;
} 
