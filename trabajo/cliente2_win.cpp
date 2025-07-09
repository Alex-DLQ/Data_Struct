#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char buffer[1024] = {0};
    string ip;

    cout << "[CLIENTE 2] Inicializando Winsock..." << endl;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    cout << "[CLIENTE 2] Ingresa IP del servidor (ej. 127.0.0.1): ";
    cin >> ip;

    server.sin_addr.s_addr = inet_addr(ip.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);

    connect(sock, (struct sockaddr *)&server, sizeof(server));
    cout << "[CLIENTE 2] Conectado. Esperando resultado..." << endl;

    recv(sock, buffer, sizeof(buffer), 0);
    cout << "[CLIENTE 2] Resultado recibido: " << buffer << endl;

    closesocket(sock);
    WSACleanup();
    return 0;
}