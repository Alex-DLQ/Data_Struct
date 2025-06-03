// suma y multiplicaion de arreglos
#include <iostream>
using namespace std;
int main(){
    int n = 5;
    int a[n], b[n];
    int suma[n], mult = 0;

    for(int i = 0; i < n; i++){
        cin>>a[i]>>b[i];
    }
    for(int i = 0; i < n; i++){
        suma[i] = a[i] + b[i];
        mult += a[i] * b[i];
        cout<<suma[i]<<endl;
    }
    cout<<mult<<endl;
    
}