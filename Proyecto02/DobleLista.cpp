//
// Created by Harriett Guzmán on 11/11/23.
//

#include "DobleLista.h"
#include "iostream"

DobleLista::DobleLista() : inicio(nullptr), fin(nullptr), tamanio(0) {} // Constructor
DobleLista::~DobleLista() { //Destructor
    limpiarLista();
}

void DobleLista::limpiarLista() { //Limpiar
    Nodo* actual = inicio;
    while (actual) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    inicio = nullptr;
    fin = nullptr;
    tamanio = 0;
}

void DobleLista::imprimir() {
    Nodo* actual = inicio;
    while (actual) {
        std::cout << actual->datos.claveHasheada << std::endl;
        actual = actual->siguiente;
    }
}

void DobleLista::busquedaBinaria(const std::string valor) { //Binaria Hash
    int bajo = 0;
    int alto = tamanio - 1;
    bool encontrado = false;

    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;
        Nodo* actual = inicio;
        for (int i = 0; i < medio; i++) {
            actual = actual->siguiente;
        }

        if (actual->datos.claveHasheada == valor) {
            encontrado = true;
            std::cout << "Encontrado: " << actual->datos.restoDeLinea << std::endl;

            Nodo* izquierda = actual->anterior;
            while (izquierda && izquierda->datos.claveHasheada == valor) {
                std::cout << "Encontrado: " << izquierda->datos.restoDeLinea << std::endl;
                izquierda = izquierda->anterior;
            }

            Nodo* derecha = actual->siguiente;
            while (derecha && derecha->datos.claveHasheada == valor) {
                std::cout << "Encontrado: " << derecha->datos.restoDeLinea << std::endl;
                derecha = derecha->siguiente;
            }
            break;
        } else if (actual->datos.claveHasheada < valor) {
            bajo = medio + 1;
        } else {
            alto = medio - 1;
        }
    }

    if (!encontrado) {
        std::cout << "No encontrado" << std::endl;
    }
}

int DobleLista::tamanioDeLista() { //Tamaño
    return tamanio;
}

void DobleLista::agregarElemento(const Data &data) {
    Nodo* nuevoNodo = new Nodo{data};
    if (inicio == nullptr) {
        inicio = nuevoNodo;
        fin = nuevoNodo;
    } else {
        nuevoNodo->anterior = fin;
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
    tamanio++;
}

void DobleLista::ordenarListaHash() { //Ordenar
    std::vector<Data> elementos;

    while (inicio != nullptr) { //Datos del vector
        elementos.push_back(inicio->datos);
        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        if (inicio) {
            inicio->anterior = nullptr;
        }
        delete temp;
    }

    std::sort(elementos.begin(), elementos.end()); //Ordenar
    limpiarLista(); //Limpiar la lista

    for (const Data& elemento : elementos) { //Insertar ordenados
        agregarElemento(elemento);
    }
}

void DobleLista::agregarVector(const std::vector<std::string>& stringArray) { //Vector a la lista

    Nodo *nuevoNodo = new Nodo{stringArray};
    if (inicio == nullptr) {
        inicio = nuevoNodo;
        fin = nuevoNodo;
    } else {
        nuevoNodo->anterior = fin;
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
    tamanio++;
}

void DobleLista::imprimirVector() { //Imprimir la lista [pruebas]
    Nodo* actual = inicio;
    while (actual) {
        for (int i = 0; i < actual->stringCadenas.size(); ++i) {
            std::cout << actual->stringCadenas[i] << ",";
        }
        std::cout << std::endl;
        actual = actual->siguiente;
    }
}

void DobleLista::busquedaBinariaVector(const std::string &valor) { //Valor
    Nodo* actual = inicio;
    bool encontrado = false;

    while (actual) { //Recorrer
        if (!actual->stringCadenas.empty()) { //n/a
            std::vector<std::string>& array = actual->stringCadenas;

            // Ordenar el vector
            std::sort(array.begin(), array.end());

            // Buscar el valor en el vector ordenado
            if (std::binary_search(array.begin(), array.end(), valor)) {
                encontrado = true;
                std::cout << "Vector completo: ";
                for (const auto& elemento : array) {
                    std::cout << elemento << " ";
                }
                std::cout << std::endl;
            }
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        std::cout << "Valor no encontrado." << std::endl;
    }
}

