#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")  // Vincular la librería de Winsock

using namespace std;

int main() {
    WSADATA wsa;
    SOCKET servidor, cliente1, cliente2;
    struct sockaddr_in server, client;
    int c, numero_servidor;
    char buffer[1024];

    // 🔢 Solicita al servidor su número
    cout << "[SERVIDOR] Ingresa tu número: ";
    cin >> numero_servidor;

    cout << "[SERVIDOR] Iniciando Winsock..." << endl;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        cout << "WSAStartup falló: " << WSAGetLastError() << endl;
        return 1;
    }

    // 🧱 Crear socket
    servidor = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor == INVALID_SOCKET) {
        cout << "Error al crear el socket: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(12345);

    // 🔗 Enlazar
    if (bind(servidor, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        cout << "Error en bind: " << WSAGetLastError() << endl;
        closesocket(servidor);
        WSACleanup();
        return 1;
    }

    listen(servidor, 3);

    cout << "[SERVIDOR] Esperando Cliente 1 (quien envía el número)..." << endl;
    c = sizeof(struct sockaddr_in);
    cliente1 = accept(servidor, (struct sockaddr *)&client, &c);
    if (cliente1 == INVALID_SOCKET) {
        cout << "Fallo en aceptar Cliente 1" << endl;
        closesocket(servidor);
        WSACleanup();
        return 1;
    }
    cout << "[SERVIDOR] Cliente 1 conectado." << endl;

    // 📥 Recibir número de Cliente 1
    memset(buffer, 0, sizeof(buffer));
    recv(cliente1, buffer, sizeof(buffer), 0);
    int numero_cliente1 = atoi(buffer);
    cout << "[SERVIDOR] Número recibido de Cliente 1: " << numero_cliente1 << endl;

    // ➕ Sumar ambos números
    int resultado = numero_servidor + numero_cliente1;

    // Esperar Cliente 2
    cout << "[SERVIDOR] Esperando Cliente 2 (quien recibirá el resultado)..." << endl;
    cliente2 = accept(servidor, (struct sockaddr *)&client, &c);
    if (cliente2 == INVALID_SOCKET) {
        cout << "Fallo en aceptar Cliente 2" << endl;
        closesocket(servidor);
        WSACleanup();
        return 1;
    }
    cout << "[SERVIDOR] Cliente 2 conectado." << endl;

    // 📤 Enviar resultado
    string mensaje_resultado = to_string(resultado);
    send(cliente2, mensaje_resultado.c_str(), mensaje_resultado.size(), 0);
    cout << "[SERVIDOR] Resultado enviado a Cliente 2: " << resultado << endl;

    // 🧹 Cerrar sockets
    closesocket(cliente1);
    closesocket(cliente2);
    closesocket(servidor);
    WSACleanup();

    return 0;
}
