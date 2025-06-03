// estructuras de datos
#include <iostream>
#include <cstdlib>
using namespace std;

struct lapicero {
    char tipo_punta[20];
    char color[20];
    char marca[20];
    float precio;
} lapicero1[3];

struct carpeta {
    char color[20];
    char forma[20]; // corregido: antes estaba mal escrito como "formar"
    float precio;
    char marca[20];
} carpeta1[3];

struct mochila {
    char tamanio[20];
    char forma[20];
    char marca[20];
    float precio;
} mochila1[3];

struct lenguaje {
    char nombre[20];
    char tipado[20];
} lenguaje1[3];

struct laptop {
    char almacenamiento[20];
    char procesador[20];
    char memoria[20];
    float precio;
    char marca[20];
} laptop1[3];

struct servidorWeb {
    char escalabilidad[20];
    char disponibilidad[20];
} servidorWeb1[3];

struct usb {
    char marca[20];
    char version[20];
    char almacenamiento[20];
} usb1[3];

struct cableUTP {
    char categoria[20];
    char velocidad[20];
    char marca[20];
    float precio;
} cableUTP1[3];

int main() {
    int opcion;
    cout << "Digite un valor para realizar la secuencia de relleno de estructuras" << endl;
    cout << "(1 = lapicero) (2 = carpeta) (3 = mochila) (4 = lenguaje)" << endl;
    cout << "(5 = laptop) (6 = servidor web) (7 = usb) (8 = cable utp)" << endl;
    cin >> opcion;
    cin.ignore(); // Limpia el buffer después de leer int

    switch (opcion) {
        case 1:
            for (int i = 0; i < 3; i++) {
                cout << "Ingrese el tipo de punta " << i + 1 << ": ";
                cin >> lapicero1[i].tipo_punta;
                cout << "Ingrese el color " << i + 1 << ": ";
                cin >> lapicero1[i].color;
                cout << "Ingrese la marca " << i + 1 << ": ";
                cin >> lapicero1[i].marca;
                cout << "Ingrese el precio " << i + 1 << ": ";
                cin >> lapicero1[i].precio;
                cin.ignore();
                cout << endl;
            }
            cout << "\nDatos registrados con éxito.\n";
            break;
        case 2:
            for (int i = 0; i < 3; i++) {
                cout << "Ingrese el color " << i + 1 << ": ";
                cin >> carpeta1[i].color;
                cout << "Ingrese la forma " << i + 1 << ": ";
                cin >> carpeta1[i].forma;
                cout << "Ingrese el precio " << i + 1 << ": ";
                cin >> carpeta1[i].precio;
                cin.ignore();
                cout << "Ingrese la marca " << i + 1 << ": ";
                cin >> carpeta1[i].marca;
                cout << endl;
            }
            cout << "\nDatos registrados con éxito.\n";
            break;
        case 3:
            for (int i = 0; i < 3; i++) {
                cout << "Ingrese el tamanio " << i + 1 << ": ";
                cin >> mochila1[i].tamanio;
                cout << "Ingrese la forma " << i + 1 << ": ";
                cin >> mochila1[i].forma;
                cout << "Ingrese la marca " << i + 1 << ": ";
                cin >> mochila1[i].marca;
                cout << "Ingrese el precio " << i + 1 << ": ";
                cin >> mochila1[i].precio;
                cin.ignore();
                cout << endl;
            }
            cout << "\nDatos registrados con éxito.\n";
            break;
        case 4:
            for (int i = 0; i < 3; i++) {
                cout << "Ingrese el nombre " << i + 1 << ": ";
                cin >> lenguaje1[i].nombre;
                cout << "Ingrese el tipado " << i + 1 << ": ";
                cin >> lenguaje1[i].tipado;
                cin.ignore();
                cout << endl;
            }
            cout << "\nDatos registrados con éxito.\n";
            break;
        case 5:
            for (int i = 0; i < 3; i++) {
                cout << "Ingrese el almacenamiento " << i + 1 << ": ";
                cin >> laptop1[i].almacenamiento;
                cout << "Ingrese el procesador " << i + 1 << ": ";
                cin >> laptop1[i].procesador;
                cout << "Ingrese la memoria " << i + 1 << ": ";
                cin >> laptop1[i].memoria;
                cout << "Ingrese el precio " << i + 1 << ": ";
                cin >> laptop1[i].precio;
                cin.ignore();
                cout << "Ingrese la marca " << i + 1 << ": ";
                cin >> laptop1[i].marca;
                cout << endl;
            }
            cout << "\nDatos registrados con éxito.\n";
            break;
        case 6:
            for (int i = 0; i < 3; i++) {
                cout << "Ingrese la escalabilidad " << i + 1 << ": ";
                cin >> servidorWeb1[i].escalabilidad;
                cout << "Ingrese la disponibilidad " << i + 1 << ": ";
                cin >> servidorWeb1[i].disponibilidad;
                cin.ignore();
                cout << endl;
            }
            cout << "\nDatos registrados con éxito.\n";
            break;
        case 7:
            for (int i = 0; i < 3; i++) {
                cout << "Ingrese la marca " << i + 1 << ": ";
                cin >> usb1[i].marca;
                cout << "Ingrese la version " << i + 1 << ": ";
                cin >> usb1[i].version;
                cout << "Ingrese el almacenamiento " << i + 1 << ": ";
                cin >> usb1[i].almacenamiento;
                cin.ignore();
                cout << endl;
            }
            cout << "\nDatos registrados con éxito.\n";
            break;
        case 8:
            for (int i = 0; i < 3; i++) {
                cout << "Ingrese la categoria " << i + 1 << ": ";
                cin >> cableUTP1[i].categoria;
                cout << "Ingrese la velocidad " << i + 1 << ": ";
                cin >> cableUTP1[i].velocidad;
                cout << "Ingrese la marca " << i + 1 << ": ";
                cin >> cableUTP1[i].marca;
                cout << "Ingrese el precio " << i + 1 << ": ";
                cin >> cableUTP1[i].precio;
                cin.ignore();
                cout << endl;
            }
            cout << "\nDatos registrados con exito.\n";
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
    }

    system("pause");
    cout << endl;
    return 0;
}

