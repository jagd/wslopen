


# `open` Command in WSL as in Mac

# Install
In WSL:
```bash
sudo curl -L https://github.com/jagd/wslopen/releases/download/v1/open-x64-vs2019.exe -o /usr/local/bin/open
sudo curl -L https://raw.githubusercontent.com/jagd/wslopen/master/xdg-open -o /usr/local/bin/xdg-open
sudo chmod +x /usr/local/bin/{xdg-,}open
```

## What is this & Why you will need it
With DrvFS enabled, the executable files in the system directories cannot be `chmod +x`. The most unexpected consequence is that the `explorer.exe` cannot be started from WSL.

## Compile
The little program has only a single source file `main.cc`. It can be compiled by using `make.bat` from the VisualStudio cmd prompt. C++11 is needed.

## Usage
- Copy the compiled `open.exe` to WSL path e.g. as `/usr/local/bin/open` (no `.exe` extension needed).
- Copy `xdg-open` to `/usr/local/bin` overriding the `xdg-open` on the linux side.

Usage examples:
- `open .` or `xdg-open .` opens the current folder in `explorer.exe`.
- `open video.mp4` or `xdg-open video.mp4` to play a video in windows.
- `open https://github.com` or `xdg-open https://github.com` to browse a URL in the default windows web browser.
- `open calc` or `xdg-open calc` to start the calculator.
- `xdg-open services.msc` works, too.
