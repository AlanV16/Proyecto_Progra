#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main(){
    int opcion;
    vector<string> embutidos;
    cout<<"Bienvenido al inventario de comida FIIA"<<endl;
    cout<<"1.Categorias"<<endl;
    cout<<"2.Almacen"<<endl;
    cout<<"Ingrese una opcion"<<endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        short int opcion;
        cout<<"1.Embutidos"<<endl;
        cout<<"2.Nectares"<<endl;
        cout<<"3.Agregar nueva categoria"<<endl;
        cout<<"4.Elimnar categoria"<<endl;
        cout<<"5.Regresar al incio"<<endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout<<"La lista de embutidos son: "<<endl;
            for(const auto& embutidos : embutidos){
                cout<<"";
            }
            break;
        case 2:
            cout<<"La lista de nectares son: "<<endl;
            for(const auto& embutidos : embutidos){
                cout<<"";
            }
            break;
        
        default:
            break;
        }
        
    case 2:
        int opcion1;
        cout<<"1.Ver categorias"<<endl;
        cout<<"2.Regresar al incio"<<endl;
        cin>>opcion;
        switch (opcion1)
        {
        case 1:
            cout<<"1.Frutas"<<endl;
            cout<<"2.Carnes"<<endl;
            cout<<"3.Verduras"<<endl;
            cout<<"4.Lacteos"<<endl;
            cout<<"5.Añadir"<<endl;
            cout<<"6.Eliminar"<<endl;
            cout<<"7. regresar al inicio"<<endl;
            break;
        
        default:
            break;
        }
    default:
        break;
    }
}