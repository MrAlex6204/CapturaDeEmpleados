#include <iostream>
#include <list>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//Declaracion de las estructuras
struct empleadoInfo{
    //Esta estructura nos permite capturar la y mostrar la informacion del empleado.
    private :
        float hrs,precio_x_hra;
        string nombre;
    public ://Declaramos los metodos que tiene esta estructura
        float sueldo;
        void capturar();
        void mostrarInfo();
};

const float EMPTY = -1;
const int CAPTURAR_EMPLEADO = 1;
const int MOSTRAR_EMPLEADOS = 2;
const int MOSTRAR_EMPLEADO_CN_MENOR_SUELDO = 3;
const int SALIR = 4;

typedef list<empleadoInfo> Lista;//Creamos una definicion para nuestra linked list
void menuPrincipal();
void limpiarPantalla();
//Creamos esta funcion para obtener el empleado con menor sueldo
empleadoInfo obtenerEmpleadoCnMenorSueldo(Lista lstDeNomina);

int main()
{
    //Lista que contendra la informacion de cada empleado
    Lista lstDeNomina;
    int opcion = -1;

    //Mostrar el menu en pantalla hasta que seleccione la opcion salir.
    while(opcion != SALIR ){

        limpiarPantalla();
        menuPrincipal();//Mostrar menu principal
        cin>>opcion;

            if(opcion==CAPTURAR_EMPLEADO){ //Captura de empleados

                limpiarPantalla();
                cout<<"\t\t** Captura de Empleados **\n\n";
                empleadoInfo empleado;//Creamos un nuevo objeto tipo empleadoInfo para agregar a la lista
                empleado.capturar();//Capturar la informacion del empleado
                lstDeNomina.push_back(empleado);//Agregar a la lista el regitro del empleado
                cout<<"\n\t[PRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU]\n";
                cin.ignore();
                getchar();

            }else if(opcion==MOSTRAR_EMPLEADOS){//Mostrar lista de alumnos

                limpiarPantalla();
                cout<<"\t\t** Empleados registrados **\n";
                cout<<"\n\n\tSe encuantran "<<lstDeNomina.size()<<" registrados.\n\n";

                if(lstDeNomina.size() > 0){//Mostrar la lista solo si hay alumnos agregados.

                    for(Lista::iterator iEmpleado = lstDeNomina.begin();iEmpleado!= lstDeNomina.end();iEmpleado++ ){
                       cout<<"\n\n";
                       iEmpleado->mostrarInfo();
                       cout<<"\n=================================================";
                    }

                }
                cout<<"\n\t[PRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU]\n";
                cin.ignore();//Limpiamos el buffer de caracteres.
                getchar();


            }else if(opcion==MOSTRAR_EMPLEADO_CN_MENOR_SUELDO){//Mostrar el empleado con menor sueldo

                //Obtener el empleado con menor sueldo
                empleadoInfo empleado = obtenerEmpleadoCnMenorSueldo(lstDeNomina);

                limpiarPantalla();
                cout<<"\t\t** Empleado con menor sueldo **\n";

                if(lstDeNomina.size() > 0 ){
                    empleado.mostrarInfo();
                }else{
                    cout<<"\n\n\tSe encuantran "<<lstDeNomina.size()<<" registrados.\n\n";
                }

                cout<<"\n\t[PRESIONE CUALQUIER TECLA PARA REGRESAR AL MENU]\n";
                cin.ignore();
                getchar();

            }else if(opcion == SALIR){

                cout<<"\n\t\t[GRACIAS POR USAR EL SISTEMA]\n";

            }else{
            cout<<"\n\t\t[OPCION INVALIDA]\n";
            cin.ignore();
            getchar();
            }

    }

    return 0;
}

//Menu Principal
void menuPrincipal(){
    cout<<"\t\t.::Menu::.          "<<endl;
    cout<<"\t 1.-Captura de Empleados"<<endl;
    cout<<"\t 2.-Mostrar Empleados   "<<endl;
    cout<<"\t 3.-Mostrar empleado con menor sueldo  "<<endl;
    cout<<"\t 4.-Salir             "<<endl;
    cout<<"Opcion:";
}

void limpiarPantalla(){
    //Comentar segun sea el OS en el que van a compilar
    system("clear");//Limpiar pantalla en linux
    //system("cls");//Limpiar pantalla en windows


}

empleadoInfo obtenerEmpleadoCnMenorSueldo(Lista lstDeNomina){
    empleadoInfo empleado;

    empleado.sueldo =  EMPTY;

    for(Lista::iterator iEmpleado = lstDeNomina.begin();iEmpleado!= lstDeNomina.end();iEmpleado++ ){

        if(empleado.sueldo == EMPTY){
            empleado = *iEmpleado;
        }else{
            if(iEmpleado->sueldo < empleado.sueldo ){
                empleado = *iEmpleado;
            }
        }

    }



    return empleado;
}

//Implementacion de las funciones de las estructuras
void empleadoInfo::capturar(){

    cout<<"Nombre del empleado:";
    cin.ignore();
    getline(cin,nombre);
    cout<<"Precio por hra : $";
    cin>>precio_x_hra;
    cout<<"Teclee las hras laboradas :";
    cin>>hrs;

    sueldo = (precio_x_hra *  hrs);

}

void empleadoInfo::mostrarInfo(){

    cout<<"\tEmpleado"<<endl;
    cout<<"\t"<<nombre<<endl;
    cout<<"\tSueldo x hra     :"<<precio_x_hra<<endl;
    cout<<"\tHras laboradas   :"<<hrs<<endl;
    cout<<"\t-----------------"<<endl;
    cout<<"\t Total a pagar  :$"<<sueldo<<endl<<endl;

}


