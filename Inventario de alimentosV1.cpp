#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

//Estructuras:
struct Alimento{
    string nombre;
    double temperatura;
    double humedad;
    int cantidad;
    string ingreso;
};

struct Categorias{
    string nombre;
    vector <Alimento> alimentos;
};

//Declaramos funciones:
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
        cout<<"1. Categorias"<<endl;
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
            cout<<"Opcion invalida, vuelva a intentar"<<endl;
        }
    }while(opcion!=0);

    return 0;
}

//=========================================================================================================================

void MostrarMenu(vector <Categorias> &categoria){
    cout<<"=============================="<<endl;
    cout<<"====Categorias disponibles===="<<endl;
    cout<<"=============================="<<endl;
    for(size_t i=0; i<categoria.size();i++){
        cout<<i+1<<"."<<categoria[i].nombre<<endl;
    }

    if(categoria.empty()){
        cout<<"No hay categorias disponibles"<<endl;
        system("pause");
        system("cls");
        return;
    }

    int OpcionCategoria;
    cout<<"Selencione el numero de una categoria: ";
    cin >> OpcionCategoria;
    if(OpcionCategoria>=1 && OpcionCategoria<=categoria.size()){
        Categorias& categoriaSeleccion= categoria[OpcionCategoria-1];
        int opcionCategoriaDetallado;
        do{
            cout<<"==================================================="<<endl;
            cout<<"===="<<"\t"<<categoriaSeleccion.nombre<<"\t"<<"===="<<endl;
            cout<<"==================================================="<<endl;
            cout<<"1. Mostrar alimentos"<<endl;
            cout<<"2. Agregar alimentos"<<endl;
            cout<<"3. Eliminar alimento"<<endl;
            cout<<"0. regresar al inicio"<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>opcionCategoriaDetallado;

            switch(opcionCategoriaDetallado){
                case 1:
                    MostrarAlimentosCategoria(categoriaSeleccion);
                    break;
                case 2:
                    AgregarAlimentos(categoriaSeleccion);
                    break;
                case 3:
                    EliminarAlimentos(categoriaSeleccion);
                case 0:
                    system("cls");
                    break;
                default:
                    cout<<"Opcion invalida"<<endl;  
            }
        }while(opcionCategoriaDetallado !=0);
    }
    else if(OpcionCategoria==0){
        return;
    }
    else{
        cout<<"Opcion invalida"<<endl;
    }
}

//=========================================================================================================================

void MostrarAlimentosCategoria(const Categorias& categoria){
    cout<<"======================================================="<<endl;
    cout<<"====Alimentos en "<<"\t"<<categoria.nombre<<"\t"<<"===="<<endl;
    cout<<"======================================================="<<endl;
    for(const Alimento& alimento:categoria.alimentos){
        int i=0;
        cout<<i+1<<". "<<alimento.nombre<<" : "<<alimento.cantidad<<" unidades"<<endl;
        i++;
    }
    system("pause");
    system("cls");
}

//=========================================================================================================================

void AgregarAlimentos(Categorias& categoria){
    Alimento nuevoAlimento;
    cout<<"Ingrese el nombre del nuevo alimento: ";
    cin>>nuevoAlimento.nombre;
    cout<<"Ingrese las unidades disponibles: ";
    cin>>nuevoAlimento.cantidad;
    cout<<"Ingrese la temperatura a guardar: ";
    cin>>nuevoAlimento.temperatura;
    cout<<"Ingrese a cuanta humedad debe de estar expuesta: ";
    cin>>nuevoAlimento.humedad;
    cout<<"Fecha de ingreso (colocar --/--/--): ";
    cin>>nuevoAlimento.ingreso;
    categoria.alimentos.push_back(nuevoAlimento);
    cout<<"Nuevo alimento agregado con exito"<<endl;
}

//=========================================================================================================================

void EliminarAlimentos(Categorias& categoria){
    if(categoria.alimentos.empty()){
        cout<<"No hay Alimentos para eliminar"<<endl;
        system("pause");
        system("cls");
        return;
    }
    cout<<"======================================================="<<endl;
    cout<<"====Alimentos disponibles en "<<categoria.nombre<<"===="<<endl;
    cout<<"======================================================="<<endl;
    for(size_t i=0; i<categoria.alimentos.size(); i++){
        cout<<i+1<<". "<<categoria.alimentos[i].nombre<<endl;
    }

    int opcionEliminar;
    cout<<"Ingrese el numero de un alimento para eliminar (0 para cancelar la accion): ";
    cin>>opcionEliminar;

    if(opcionEliminar>=1 && opcionEliminar<=categoria.alimentos.size()){
        categoria.alimentos.erase(categoria.alimentos.begin()+ opcionEliminar-1);
        cout<<"El alimento ha sido eliminado con exito"<<endl;
    }
    else if(opcionEliminar==0){
        return;
    }
    else{
        cout<<"Opcion invalidad"<<endl;
    }    
}

//=========================================================================================================================

void AgregarCategoria(vector<Categorias>& categoria){
    Categorias NuevaCategoria;
    cout<<"Ingrese el nombre de la nueva categoria: ";
    cin>>NuevaCategoria.nombre;
    categoria.push_back(NuevaCategoria);
    cout<<"La categoria ha sido agregado con exito"<<endl;
    system("pause");
    system("cls");
}

//=========================================================================================================================

void EliminarCategoria(vector<Categorias>& categoria){
    if(categoria.empty()){
        cout<<"No hay categorias para eliminar"<<endl;
        system("pause");
        system("cls");
        return;
    }

    cout<<"================================"<<endl;
    cout<<"==== Categorias disponibles ===="<<endl;
    cout<<"================================"<<endl;
    for(size_t i=0; i<categoria.size(); i++){
        cout<<i+1<<". "<<categoria[i].nombre<<endl;
    }

    int opcionEliminar;
    cout<<"Seleccione el numero de la categoria a eliminar (0 para cancelar la accion): ";
    cin >> opcionEliminar;

    if(opcionEliminar >=1 && opcionEliminar<=categoria.size()){
        categoria.erase(categoria.begin()+opcionEliminar-1);
        cout<<"Categoria eliminada con exito"<<endl;
    }
    else if(opcionEliminar == 0){
        return;
    }
    else{
        cout<<"Opcion invalida"<<endl;
    }
}

//=========================================================================================================================

void Almacen(vector<Categorias>& categoria){
    cout<<"================="<<endl;
    cout<<"==== Almacen ===="<<endl;
    cout<<"================="<<endl;

    if(categoria.empty()){
        cout<<"El Almacen esta vacio"<<endl;
        system("pause");
        system("cls");
        return;
    }
    cout<<"Categorias disponibles en almacen: "<<endl;
    for(size_t i=0; i<categoria.size(); i++){
        cout<<i+1<<". "<<categoria[i].nombre<<endl;
    }

    int opcionCategoria;
    cout<<"Ingrese la opcion de una categoria (0 para volver al menu principal): ";
    cin>> opcionCategoria;
     if(opcionCategoria>=1 && opcionCategoria<=categoria.size()){
        const Categorias& categoriaSeleccion = categoria[opcionCategoria-1];
        cout<<"====Alimentos en la categoria "<<categoriaSeleccion.nombre<<"===="<<endl;
        cout<<"\n";
        cout<<"Nombre\tCantidad\tFecha Ingreso\tTemperatura\tHumedad"<<endl;
        cout<<"------------------------------------------------------------------------------------------------"<<endl;
        for(const Alimento& alimento: categoriaSeleccion.alimentos){
            cout<<alimento.nombre<<"\t"<<alimento.cantidad<<" unidades\t"<<alimento.ingreso<<"\t"<<alimento.temperatura<<"\t"<<"\t"<<alimento.temperatura<<endl;
            cout<<"------------------------------------------------------------------------------------------------"<<endl;
        }
        system("pause");
        system("cls");
     }
     else if(opcionCategoria == 0){
        return;
     }
     else{
        cout<<"Opncion Invalida"<<endl;
     }
}