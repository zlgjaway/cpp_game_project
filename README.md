
# setup guide

Install MSYS2: https://www.msys2.org/

Install MinGW + SFML:

    pacman -S mingw-w64-ucrt-x86_64-gcc
    pacman -S mingw-w64-ucrt-x86_64-sfml
    pacman -S mingw-w64-ucrt-x86_64-gdb


Open the project in VS Code.

Press Ctrl+Shift+B to build the game.

Copy SFML DLLs from C:/msys64/ucrt64/bin/ to bin/.

Press F5 to run the game.

