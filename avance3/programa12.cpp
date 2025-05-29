//el operador de puntero ->
#include <iostream>
using namespace std;

struct Persona {
    std::string nombre;
    int edad;
    void saludar() {
    cout << "Hola, mi nombre es "<<endl;;
    cout<< nombre << " y tengo "<<endl;
    cout<< edad << " anios." << endl;
    cout<< endl;
}
};
int main() {
    Persona *ptrPersona = new Persona();
    ptrPersona->nombre = "Juan";
    ptrPersona->edad = 30;
    std::cout << "Nombre: " << ptrPersona->nombre << std::endl;
    std::cout << "Edad: " << ptrPersona->edad << std::endl;
    ptrPersona->saludar();
    delete ptrPersona;
    return 0;
}