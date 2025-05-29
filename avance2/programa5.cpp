// Diseña un programa que lea las calificaciones de 30 estudiantes, 
//las almacene en un arreglo y calcule el promedio general. Además, 
//muestra cuántos estudiantes están por encima del promedio.
#include <iostream>
using namespace std;

int main(){
    int numEstudiantes = 30;
    int calificacion[numEstudiantes];
    float promedio = 0;
    int promedioGeneral = 0;
    int numEstudiantesPorEncimar = 0;

    cout<<"Ingrese las calificaciones de los estudiantes: ";
    for(int i = 0; i < numEstudiantes; i++){
        cin>>calificacion[i];
    }
    for(int i = 0; i < numEstudiantes; i++){
        promedio += calificacion[i];
    }
    promedio = promedio / numEstudiantes;
    for(int i = 0; i < numEstudiantes; i++){
        if(calificacion[i] > promedio){
            numEstudiantesPorEncimar++;
        }
    }

    promedioGeneral = numEstudiantesPorEncimar * promedio;
    cout<<"El promedio general es "<<promedioGeneral<<endl;
    cout<<"Los estudiantes por encima del promedio son "<<numEstudiantesPorEncimar<<endl;

    system("pause");
    return 0;
}