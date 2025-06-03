//operadoes * y &
#include <iostream>
using namespace std;
int main() {
    int num = 13; 
    int *pNum = &num;

    cout<<"El valor de la variable es: "<<num<<endl;
    cout<<"La posicion de memoria que ocuapa la variables es: "<<pNum<<endl;
    cout<<"El valor que ocupa la posicion de memoria es: "<<*pNum<<endl;
    cout<<"La posicion de memoria es: "<<&num<<endl;
    return 0;
}