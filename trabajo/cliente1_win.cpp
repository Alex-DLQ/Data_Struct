#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    string ip;
    int numero;

    cout << "[CLIENTE 1] Inicializando Winsock..." << endl;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    cout << "[CLIENTE 1] Ingresa IP del servidor (ej. 127.0.0.1): ";
    cin >> ip;

    server.sin_addr.s_addr = inet_addr(ip.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);

    connect(sock, (struct sockaddr *)&server, sizeof(server));
    cout << "[CLIENTE 1] Conectado al servidor." << endl;

    cout << "[CLIENTE 1] Ingresa el número a enviar: ";
    cin >> numero;

    string mensaje = to_string(numero);
    send(sock, mensaje.c_str(), mensaje.size(), 0);

    closesocket(sock);
    WSACleanup();
    return 0;
}