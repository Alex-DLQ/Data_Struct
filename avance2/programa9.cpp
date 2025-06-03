//Crea un programa que permita llenar dos arreglos de 10 elementos cada uno. 
//Compara ambos y determina cuántos elementos en las mismas posiciones son iguales
#include <iostream>
using namespace std;

int main(){
    int arreglo1[10];
    int arreglo2[10];
    int i = 0;
    int iguales = 0;

    cout<<"Ingrese 10 elementos: ";
    for(i = 0; i < 10; i++){
        cin>>arreglo1[i];
    }
    cout<<"Ingrese 10 elementos: ";
    for(i = 0; i < 10; i++){
        cin>>arreglo2[i];
    }

    for(i = 0; i < 10; i++){
        if(arreglo1[i] == arreglo2[i]){
            iguales++;
        }
    }
    
    cout<<"El numero de elementos iguales es "<<iguales<<endl;
    system("pause");
    return 0;
}