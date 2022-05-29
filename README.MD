# Replacement for `xdg-open` and mailcap `open` for better interoperability with Windows

## What's new

- Version 2:
  - The `exe` file is minimized (2048 Bytes)
  - Avoid CRT DLLs

## Installation on WSL

- Copy the content of the
  [zip file](https://github.com/jagd/wslopen/releases/download/v2/wslopen.zip)
  into any folder of PATH (e.g. `~/.local/bin`)
- `chmod +x` on these files

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
