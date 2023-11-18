//
// Created by Harriett Guzmán on 11/11/23.
//

#include "DobleLista.h"
#include "iostream"


DobleLista::DobleLista() : inicio(nullptr), fin(nullptr), tamanio(0) {} // Constructor
DobleLista::~DobleLista() { //Destructor
    limpiarLista();
}

void DobleLista::limpiarLista() { //Función para limpiar la lista
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

void DobleLista::busquedaBinaria(const std::string valor) { //Búsqueda binaria por llaveHasheada
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

            // Buscar hacia la izquierda
            Nodo* izquierda = actual->anterior;
            while (izquierda && izquierda->datos.claveHasheada == valor) {
                std::cout << "Encontrado: " << izquierda->datos.restoDeLinea << std::endl;
                izquierda = izquierda->anterior;
            }

            // Buscar hacia la derecha
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

int DobleLista::tamanioDeLista() { //Función para obtener el tamaño de la lista
    return tamanio;
}

void DobleLista::agregarElemento(const Data &data) {
    Nodo* nuevoNodo = new Nodo{data};
    if (inicio == nullptr) {
        inicio = nuevoNodo;
        fin = nuevoNodo;
    } else {
        nuevoNodo->anterior = fin;
        inicio->siguiente = nuevoNodo;
        inicio = nuevoNodo;
    }
    tamanio++;
}

void DobleLista::ordenarListaHash() { //Función para ordenar la lista
    std::vector<Data> elementos;

    while (inicio != nullptr) { //Insertar los datos en el vector
        elementos.push_back(inicio->datos);
        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        if (inicio) {
            inicio->anterior = nullptr;
        }
        delete temp;
    }

    std::sort(elementos.begin(), elementos.end()); //Ordenar el vector
    limpiarLista(); //Limpiar la lista

    for (const Data& elemento : elementos) { //Insertar los datos ordenados en la lista
        agregarElemento(elemento);
    }
}

void DobleLista::imprimirVector() { //Imprimir la lista [pruebas]
    Nodo* actual = inicio;
    while (actual) {
        for (int i = 0; i < actual->Cadenas.size(); ++i) {
            std::cout << actual->Cadenas[i] << ",";
        }
        std::cout << std::endl;
        actual = actual->siguiente;
    }
}

void DobleLista::busquedaBinariaVector(const std::string &valor) { //Búsqueda binaria por valor
    Nodo* actual = inicio;
    bool encontrado = false;

    while (actual) { //Recorrer la lista
        if (!actual->Cadenas.empty()) { //Si el vector no está vacío
            std::vector<std::string>& array = actual->Cadenas;

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

    // Si no se encontró el valor
    if (!encontrado) {
        std::cout << "Valor no encontrado." << std::endl;
    }
}

void DobleLista::agregarVector(const std::vector<std::string>& stringArray) { //Función para agregar un vector a la lista

    Nodo* nuevoNodo = new Nodo{stringArray};
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