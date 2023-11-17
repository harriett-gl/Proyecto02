#include <iostream>
#include <cstring>
#include <limits>

#include "DobleLista.h"
#include "Hash.h"

using namespace std;

// Creación de variables en el heap porque se requiere conservar las funciones y listas
void menuPrincipal();
DobleLista *listaHash = new DobleLista();
DobleLista *listaValor = new DobleLista();
Hash *hashing = new Hash();


void pruebas(){ // pruebas de las listas
    listaValor->imprimir();
}

void subirDatos(){ // Función para procesar el archivo y cargar los datos en las listas

    string nombreArch;
    cout<<"Nombre del Archivo "<<endl;
    std::cin.ignore();
    std::getline(std::cin, nombreArch);
    hashing->procesarArch(nombreArch, listaHash, listaValor);
    cout<<"Orden "<<endl;
    listaHash->ordenarListaHash();

    cout<<"Tamanio "<<endl;
    cout<<listaHash->tamanioDeLista()<<endl;
    cout<<listaValor->tamanioDeLista()<<endl;

    menuPrincipal();
}

void Llave(){ // Función para buscar por llave
    string llave, resultado;
    cout<<"Llave a buscar "<<endl;
    std::cin.ignore();
    std::getline(std::cin, llave);

    resultado = hashing->generarHash(llave);
    listaHash->busquedaBinaria(resultado);
    menuPrincipal();
}

void Valor(){ // Función para buscar por valor
    string valor, resultado;
    cout<<"Valor a buscar "<<endl;
    std::cin.ignore();
    std::getline(std::cin, valor);

    listaValor->busquedaBinaria(valor);
    menuPrincipal();
}

void Salir(){ // Función para salir del programa
    cout<<"Fin"<<endl;
    exit(0);
}

void menuPrincipal(){ // Función para mostrar el menú principal

    int opcion;
    char entrada[100];

    cout << "1. Archivo" << endl;
    cout << "2. Nombre de la llave" << endl;
    cout << "3. Por valor" << endl;
    cout << "4. Salir" << endl;

    cout << "Escoge una opcion: ";
    cin >> entrada;
    if (strlen(entrada) > 1 || !isdigit(entrada[0])) {
        cout << "Ingresa un valor valido." << '\n';
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        menuPrincipal();
    }
    else {
        opcion = atoi(entrada);
        switch (opcion) {
            case 1:
                subirDatos();
                break;
            case 2:
                Llave();
                break;
            case 3:
                Valor();
                break;
            case 4:
                Salir();
                break;
            default:
                cout << "Opción incorrecta." << '\n';
                menuPrincipal();
                break;
        }
    }
}

int main() {
    menuPrincipal();

    return 0;
}

