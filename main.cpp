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
        int no_empleado;
        float sueldo;
        void capturar();
        void mostrarInfo();
};

const float EMPTY = -1;
const int CAPTURAR_EMPLEADO = 1;
const int MOSTRAR_EMPLEADOS = 2;
const int MOSTRAR_EMPLEADO_CN_MENOR_SUELDO = 3;
const int ELIMINAR_EMPLEADOS = 4;
const int SALIR = 5;

typedef list<empleadoInfo> Lista;//Creamos una definicion para nuestra linked list
void menuPrincipal();
void limpiarPantalla();

//Eliminar empleado especificdo
bool eliminarEmpleado(Lista *lstDeNomina,empleadoInfo empleado);
//Buscar empleado por su No. de Id
empleadoInfo buscarEmpleado(Lista lstDeNomina,int no_empleado);
//Definimos esta funcion para obtener el empleado con menor sueldo
empleadoInfo obtenerEmpleadoCnMenorSueldo(Lista lstDeNomina);
//Definimos esta funcion para mostrar la lista de empleados y reutilizarla varias veces
void mostrarEmpleados(Lista lstDeNomina);


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

                mostrarEmpleados(lstDeNomina);

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

            } else if(opcion==ELIMINAR_EMPLEADOS){//Eliminar empleados

                int no_empleado;//No de empleado a buscar para eliminar
                empleadoInfo empleado;//Informacion del No. de empleado encontrado

                limpiarPantalla();

                mostrarEmpleados(lstDeNomina);//Mostrar la lista de empleado

                if(lstDeNomina.size() > 0){
                //Intentar eliminar un empleado solo si hay empleados en la lista
                 cout<<"Teclee el No. de empleado a eliminar:";
                 cin>>no_empleado;

                 //Realizar la busqueda del empleado a buscar
                 empleado = buscarEmpleado(lstDeNomina,no_empleado);

                 if(empleado.no_empleado!=(int)EMPTY){
                    //Eliminar empleado si fue encontrado
                    empleado.mostrarInfo();//Mostrar la informacion del empleado antes de eliminar


                    //Intentar eliminar el empleado especificado
                    if(eliminarEmpleado(&lstDeNomina,empleado)){//Pasar la referencia de la lista
                        cout<<"\t[ EMPLEADO ELIMINADO ]"<<endl;
                    }else{
                        cout<<"\t[ NO SE PUDO ELIMINAR EMPLEADO ]"<<endl;
                    }

                 }else{
                    cout<<"\t [ NO SE ENCONTRO EL NO. DE EMPLEADO ESPECIFICADO ]"<<endl;
                 }


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
    cout<<"\t 4.-Eliminar empleados"<<endl;
    cout<<"\t 5.-Salir             "<<endl;
    cout<<"Opcion:";
}

void limpiarPantalla(){
    //Comentar segun sea el OS en el que van a compilar
    system("clear");//Limpiar pantalla en linux
    //system("cls");//Limpiar pantalla en windows
}

//Mostrar la lista de empleados en pantalla
void mostrarEmpleados(Lista lstDeNomina){

    cout<<"\n\n\tSe encuantran "<<lstDeNomina.size()<<" registrados.\n\n";

    if(lstDeNomina.size() > 0){//Mostrar la lista solo si hay alumnos agregados.

        for(Lista::iterator iEmpleado = lstDeNomina.begin();iEmpleado!= lstDeNomina.end();iEmpleado++ ){
            cout<<"\n\n";
            iEmpleado->mostrarInfo();
            cout<<"\n=================================================";
        }
        cout<<endl;

    }

}

//Buscar en la lista el empleado con menor sueldo.
empleadoInfo obtenerEmpleadoCnMenorSueldo(Lista lstDeNomina){
    empleadoInfo empleado;//Empleado con menor sueldo

    empleado.sueldo =  EMPTY;

    //Recorrer la lista de empleados hasta buscar el que tenga el menor sueldo
    for(Lista::iterator iEmpleado = lstDeNomina.begin();iEmpleado!= lstDeNomina.end();iEmpleado++ ){

        if(empleado.sueldo == EMPTY){//Si el empleado con menor sueldo esta vacio
            empleado = *iEmpleado;//Asignar el primer elemento de la lista si esta vacio
        }else{
            if(iEmpleado->sueldo < empleado.sueldo ){
                empleado = *iEmpleado;//Asignar la informacion del empleado que tiene el menor sueldo
            }
        }

    }


    return empleado;
}


//Buscar empleado por su No. de Id
empleadoInfo buscarEmpleado(Lista lstDeNomina,int no_empleado){
    empleadoInfo empleado;//Empleado con menor sueldo

    empleado.no_empleado =  (int)EMPTY;

    //Recorrer la lista de empleados hasta encontrar el empleado
    for(Lista::iterator iEmpleado = lstDeNomina.begin();iEmpleado!= lstDeNomina.end();iEmpleado++ ){

    //Verificar si el no de empleado es igual al que se busca
      if(iEmpleado->no_empleado == no_empleado){
        empleado = *iEmpleado;
        break;//Salir del for por que encontro al empleado
      }

    }

    return empleado;
}

//Eliminar el empleado especificado
bool eliminarEmpleado(Lista *lstDeNomina,empleadoInfo empleado){
    bool fueEliminado = false;

    //Recorrer la lista de empleados hasta encontrar el empleado
    for(Lista::iterator iEmpleado = lstDeNomina->begin();iEmpleado!= lstDeNomina->end();iEmpleado++ ){

      //Verificar si el empleado es igual al que se busca
      if(iEmpleado->no_empleado == empleado.no_empleado){

        lstDeNomina->erase(iEmpleado);//Quitar empleado de la lista original

        fueEliminado = true;
        break;//Salir del for por que fue eliminado
      }

    }

    return fueEliminado;//Regresar si el empleado fue eliminado
}




//Implementacion de las funciones de las estructuras
void empleadoInfo::capturar(){

    cout<<"No. de empleado :";
    cin>>no_empleado;
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

    cout<<"\tNo. de Empleado  :"<<no_empleado<<endl;
    cout<<"\tNombre           :"<<nombre<<endl;
    cout<<"\tSueldo x hra     :"<<precio_x_hra<<endl;
    cout<<"\tHras laboradas   :"<<hrs<<endl;
    cout<<"\t-----------------"<<endl;
    cout<<"\t Total a pagar  :$"<<sueldo<<endl<<endl;

}


