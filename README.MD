# Replacement for `xdg-open` and mailcap `open` for better interoperability with Windows

## Installation

In WSL:

```bash
mkdir -p ~/.local/bin
curl -L https://github.com/jagd/wslopen/releases/download/v1/open-x64-vs2019.exe -o ~/.local/bin/wslopen.exe
curl -L https://raw.githubusercontent.com/jagd/wslopen/master/xdg-open -o ~/.local/bin/xdg-open
chmod +x ~/.local/bin/{xdg-open,wslopen.exe}
cp ~/.local/bin/{xdg-,}open
```

## Why you will need this

- A drop-in replacement for `xdg-open` to open files on windows side
- With DrvFS enabled, the WSL user cannot grant individual `.exe` files in
  system directory executable permission by `chmod +x`.  Therefore,
  `explorer.exe <folder>` does not work from WSL.

## Usage examples

- `open .` or `xdg-open .` opens the current folder in `explorer.exe`.
- `open video.mp4` or `xdg-open video.mp4` to play a video in windows.
- `open https://github.com` or `xdg-open https://github.com` to browse
   the URL in the default windows web browser.
- `open calc` or `xdg-open calc` to start the calculator.
- `xdg-open services.msc` works, too.
