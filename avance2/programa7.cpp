// Escribe un programa que permita al usuario ingresar 10 números enteros en un arreglo. 
//Luego, rota los elementos una posición hacia la derecha, de modo que el último pase a ser el primero, 
//y muestra el resultado.
#include <iostream>
using namespace std;

int main(){
    int numeros[10];
    int numeros2[10];
    int j = 9;
    int i = 0;
    // 1 2 3 4 5 6 7 8 9 10
    cout<<"Ingrese 10 numeros: ";
    for(i = 0; i < 10; i++){
        cin>>numeros[i];
    }

    for(i = 1; i < 10; i++){
        numeros2[i] = numeros[i-1];
    }
    numeros2[0] = numeros[9];


    for(i = 0; i < 10; i++){
        cout<<numeros2[i]<<" ";
    }

    system("pause");
    return 0;
}