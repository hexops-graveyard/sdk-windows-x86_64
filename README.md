# Windows-x86_64 SDK for Mach Engine

This repository contains native system headers and libraries required to build [Mach Engine](https://github.com/hexops/mach) for Windows (x86_64), from any host OS.

## Updated DirectX headers for MinGW/Zig

We have a small fork of the win32metadata repository which contains the IDL files for Windows SDK:

https://github.com/slimsag/win32metadata

This fork has changes which enable at least the DirectX headers to be compiled with the Wine WIDL compiler. See that repository's commit history for details on what that involves.

Also see this detailed write-up: https://github.com/ziglang/zig/issues/9998#issuecomment-997088467

The files are then copied into this repository:

```sh
rm -rf include/*
cp -R win32metadata/generation/WinSDK/RecompiledIdlHeaders/**/d3d*.h include/
cp -R win32metadata/generation/WinSDK/RecompiledIdlHeaders/**/dx*.h include/
rm include/dxgi*
cp win32metadata/generation/WinSDK/RecompiledIdlHeaders/shared/rpcndr.h include/
```

`rpcndr.h` has a single `#include "rpcndr_hack.h"` line applied which adds a few missing defines.

## Libraries

`lib/` contains runtime libraries from the MinGW-w64 project, namely:

```sh
cp /mnt/c/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/lib/libdxgi.a lib/dxgi.lib
cp /mnt/c/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/lib/libdxguid.a lib/dxguid.lib
```


## LICENSE

This repository only distributes non-copyleft, permissively licensed files.

* `include/` is derived from [win32metadata IDL files](https://github.com/microsoft/win32metadata/tree/master/generation/WinSDK/RecompiledIdlHeaders) which are MIT licensed.
* `lib/` is licensed under the MinGW-w64-runtime licenses, a copy of which is provided in `COPYING.MinGW-w64-runtime.txt`
