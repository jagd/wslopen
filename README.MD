# `open` Command in WSL as in Mac

## Why & What is this
With DRVFS enabled, the executable files in the system directories cannot be `chmod +x`. The most unexpected consequence is that the `explorer.exe` cannot be started from WSL.

## Compile
Compile the file `main.cc` and copy to WSL folder e.g. as `/usr/local/bin/open` (no `.exe` extension is needed)

## Usage
Examples:
- `open .` opens the current folder in Explorer.exe
- `open video.mp4` to play a video
- `open calc` to start the windows calculator
