#include <windows.h>
#include <string>

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
)
{
	const std::string cmd = (lpCmdLine);
	if (!cmd.empty()) {
		const std::string str = "cmd.exe /c start " + cmd;
		STARTUPINFO info = { sizeof(info) };
		PROCESS_INFORMATION processInfo;
		CreateProcess(
			NULL, const_cast<LPSTR>(str.c_str()),
			NULL, NULL, false, 0, NULL, NULL, &info, &processInfo
		);
	}
	return EXIT_SUCCESS;
} 
