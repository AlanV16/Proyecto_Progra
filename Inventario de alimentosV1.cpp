#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Estructuras:

struct Categorias{
    string nombre;
    vector <Alimento> alimentos;
};

struct Alimento{
    string nombre;
    float temperatura;
    float humedad;
    int cantidad;
};

//funciones:
void MostrarMenu(vector <Categorias>& categoria );
void MostrarAlimentosCategoria(const Categorias& categoria);
void AgregarAlimentos(Categorias& categoria);
void EliminarAlimentos(Categorias& categoria);
void AgregarCategoria(vector <Categorias>& categoria);
void EliminarCategoria(vector <Categorias>& categoria);
void Almacen(vector <Categorias>& categoria);

int main(){
    vector <Categorias> categoria;
    int opcion;
    do{
        cout<<"================================================"<<endl;
        cout<<"====BIENVENIDO AL INVENTARIO DE INGREDIENTES===="<<endl;
        cout<<"================================================"<<endl;
        cout<<"1. Catgeorias"<<endl;
        cout<<"2. Agregar Categoria"<<endl;
        cout<<"3. Eliminar Catgeoria"<<endl;
        cout<<"4. Almacen"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch (opcion){
        case 1:
            MostrarMenu(categoria);
            break;

        case 2:
            AgregarCategoria(categoria);
            break;

        case 3:
            EliminarCategoria(categoria);
            break;

        case 4:
            Almacen(categoria);
            break;

        case 0:
            cout<<"Gracias por utilizar el programa"<<endl;
            break;

        default:
            break;
        }
    }while(opcion!=0);

    return 0;
}

