#include <iostream>
#include <cstring>
#include <limits>

#include "DobleLista.h"
#include "Hash.h"

using namespace std;

void menuPrincipal();
DobleLista *listaHash = new DobleLista();
DobleLista *listaValue = new DobleLista();
Hash *hashear = new Hash();

void pruebas() {
    listaValue->imprimirListaVector();
}

void Datos() {
    string nombreArchivo;
    cout << "Archivo: " << endl;
    std::cin.ignore();
    std::getline(std::cin, nombreArchivo);
    hashear->procesarArchivo(nombreArchivo, listaHash, listaValue);
    cout << "Orden" << endl;
    listaHash->ordenarListaHash();

    cout << "Tamanio: " << endl;
    cout << listaHash->tamanoLista() << endl;
    cout << listaValue->tamanoLista() << endl;

    menuPrincipal();
}

void Llave() {
    string key, result;
    cout << "Ingrese la key que desea buscar: " << endl;
    std::cin.ignore();
    std::getline(std::cin, key);

    result = hashear->generarHash(key);
    listaHash->busquedaBinaria(result);
    menuPrincipal();
}

void Valor() {
    string valor, result;
    cout << "Ingrese el valor que desea buscar: " << endl;
    std::cin.ignore();
    std::getline(std::cin, valor);

    listaValue->busquedaBinariaVector(valor);
    menuPrincipal();
}

void Fin() {
    cout << "Fin" << endl;
    exit(0);
}

void menuPrincipal() {
    int opcion;
    char entrada[100];

    cout << "1. Archivo" << endl;
    cout << "2. Por Llave" << endl;
    cout << "3. Por Valor" << endl;
    cout << "4. Fin" << endl;

    cout << "Escoja un opción: ";
    cin >> entrada;
    if (strlen(entrada) > 1 || !isdigit(entrada[0])) {
        cout << "Incorrecto" << '\n';
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        menuPrincipal();
    } else {
        opcion = atoi(entrada);
        switch (opcion) {
            case 1:
                Datos();
                break;
            case 2:
                Llave();
                break;
            case 3:
                Valor();
                break;
            case 4:
                Fin();
                break;
            default:
                cout << "Incorrecto" << '\n';
                menuPrincipal();
                break;
        }
    }
}

int main() {
    menuPrincipal();
    return 0;
}

