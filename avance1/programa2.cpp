// aprovado o desaprovado
#include <iostream>
using namespace std;
int main(){
    int nota;
    cout<<"Ingrese su nota: ";
    cin>>nota;

    if(nota >= 11){
        cout<<"Aprovado"<<endl;
    }
    else{
        cout<<"Desaprobado"<<endl;
    }
    return 0;
}