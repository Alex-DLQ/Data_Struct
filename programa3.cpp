//area de un circulo
#include <iostream>
using namespace std;

int area(int radio){
    float pi = 3.14;
    int resultado = pi * radio * radio;
    return resultado;
}

int main(){
    int p;

    cout<<"Ingresa el radio del circulo: ";
    cin>>p;
    int res = area(p);
    cout<<"El area es "<<res<<endl;
    return 0;
}
