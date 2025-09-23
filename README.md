
# Setup Guide for Element Fusion Game
1️⃣ Install MSYS2

Download and install: https://www.msys2.org/

Open MSYS2 terminal and update packages:

    pacman -Syu

2️⃣ Install MinGW, SFML, and GDB
    pacman -S mingw-w64-ucrt-x86_64-gcc
    pacman -S mingw-w64-ucrt-x86_64-sfml
    pacman -S mingw-w64-ucrt-x86_64-gdb


This installs the compiler, SFML libraries, and debugger.

3️⃣ Clone the project
    git clone https://github.com/<your-repo>.git
    cd <repo-name>
    git checkout <branch-name>

4️⃣ Open the project in VS Code

Open the project folder.

Make sure .vscode/tasks.json and .vscode/launch.json are present.

5️⃣ Create output folder

Make sure the bin/ folder exists:

    mkdir bin


This is where the compiled game and SFML DLLs will go.

6️⃣ Build the game

Press Ctrl+Shift+B in VS Code → select Build Game

Or manually:

    g++ src/main.cpp src/game.cpp -I${SFML_PATH}/include -L${SFML_PATH}/lib -lsfml-graphics -lsfml-window -lsfml-system -o bin/game.exe


If using an environment variable, set it first:

    setx SFML_PATH "C:/msys64/ucrt64"

7️⃣ Copy SFML DLLs

Copy all SFML DLLs from C:/msys64/ucrt64/bin/ to bin/:

    sfml-graphics-2.dll
    sfml-window-2.dll
    sfml-system-2.dll
    sfml-audio-2.dll
    sfml-network-2.dll


These are required at runtime.

8️⃣ Run the game

Press F5 in VS Code to launch.

A window should appear and the game will run.