# CMPT 225


## Development environment

- Visual Studio 2019 Community Version
- Visual Studio 2019 Linux Development Environment add-on
- Ubuntu 18.04 Windows Subsystem Linux (WSL)
- g++ compiler with C++11 standard on WSL
- Valgrind
- Text editing with Visual Studio Code (Occasionally)

## Development Setup

1. Install Linux environment on Visual Studio as add-on
2. Set up Visual Studio with WSL as follows:

Once you setup WSL (which is not covered here), run the following commands in WSL.

`sudo apt update`

`sudo apt install g++ gdb make ninja-build rsync zip`

Then, open the Visual Studio. Create the new project with Linux platform. Go to Properties > General > Platform Toolset. Then, select the GCC for Windows Subsystem for Linux. 

Then, you can compile with usual Visual Studio features (e.g. <kbd>ctrl</kbd> + <kbd>F5</kbd>).

Or you can then compile from the command line in WSL:

`g++ -o <FILENAME> <SOMECODE.cpp> -std=c++11`

`./a.out`

For more detail, see https://devblogs.microsoft.com/cppblog/c-with-visual-studio-2019-and-windows-subsystem-for-linux-wsl/.

### Valgrind setup on WSL:

The software to perform memory leak check. follow the following instruction to install Valgrind on WSL.

**Steps 1 to 6 may not be necessary...**

1. Install the latest version from https://valgrind.org/downloads/current.html. Simply, execute on WSL: `wget https://sourceware.org/pub/valgrind/valgrind-3.17.0.tar.bz2` 

2. On the WSL root directory to extract the folder: `tar -xvjf valgrind-3.17.0.tar.bz2`

3. To configure, execute:

`cd valgrind-3.17.0` (go to the folder)

`./configure`

4. On the same directory, execute: `make`

5. `make check`

6. Install Valgrind, `sudo make install`

For more detail, see https://stackoverflow.com/questions/40355474/valgrind-does-not-work-with-wsl.

7. `sudo apt install valgrind`

Then you can run the program with memory check e.g.:

`valgrind ./a.out`

## Compiling and Running
To compile,
`g++ -o <FILENAME.out> <ALL of .cpp> -std=c++11`

To run,
`valgrind ./a.out`


___
## Notes


