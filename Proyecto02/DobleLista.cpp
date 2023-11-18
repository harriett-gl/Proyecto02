//
// Created by Harriett Guzmán on 11/11/23.
//

#include "DobleLista.h"
#include "Data.h"

DobleLista::DobleLista() : inicio(nullptr), fin(nullptr), tamano(0) {}

DobleLista::~DobleLista() {
    limpiarLista();
}

void DobleLista::limpiarLista() {
    Nodo* actual = inicio;
    while (actual) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    inicio = nullptr;
    fin = nullptr;
    tamano = 0;
}

void DobleLista::imprimir() {
    Nodo* actual = inicio;
    while (actual) {
        std::cout << actual->datos.claveHasheada << std::endl;
        actual = actual->siguiente;
    }
}

void DobleLista::busquedaBinaria(std::string valor) {
    int bajo = 0;
    int alto = tamano - 1;
    bool encontrado = false;

    int medio = bajo + (alto - bajo) / 2;
    Nodo* actual = inicio;
    for (int i = 0; i < medio; i++) {
        actual = actual->siguiente;
    }

    Nodo*Izquierdo = actual;
    Nodo*Derecho = actual->siguiente;

    while (bajo <= alto) {
        if (Izquierdo->datos.claveHasheada == valor) {
            encontrado = true;
            std::cout << "Encontrado: " << Izquierdo->datos.restoDeLinea << std::endl;
            return;
        }
        else if (Derecho -> datos.claveHasheada == valor) {
            encontrado = true;
            std::cout << "Encontrado: " << Derecho->datos.restoDeLinea << std::endl;
            return;
        }
        else
        {
            bajo--;
            alto++;
            Izquierdo = Izquierdo -> anterior;
            Derecho = Derecho -> siguiente;
        }
    }
    std::cout << "No encontrado" << std::endl;
}

int DobleLista::tamanoLista() {
    return tamano;
}

void DobleLista::agregarElemento(const Data& datos) {
    Nodo* nuevoNodo = new Nodo{datos};
    if (inicio == nullptr) {
        inicio = nuevoNodo;
        fin = nuevoNodo;
    } else {
        nuevoNodo->anterior = fin;
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
    tamano++;
}

void DobleLista::ordenarListaHash() {
    std::vector<Data> elementos;

    while (inicio != nullptr) {
        elementos.push_back(inicio->datos);
        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        if (inicio) {
            inicio->anterior = nullptr;
        }
        delete temp;
    }

    std::sort(elementos.begin(), elementos.end());
    limpiarLista();

    for (const Data& elemento : elementos) {
        agregarElemento(elemento);
    }
}

void DobleLista::agregarVector(const std::vector<std::string>& arregloString) {
    Nodo* nuevoNodo = new Nodo{arregloString};
    if (inicio == nullptr) {
        inicio = nuevoNodo;
        fin = nuevoNodo;
    } else {
        nuevoNodo->anterior = fin;
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
    tamano++;
}

void DobleLista::imprimirListaVector() {
    Nodo* actual = inicio;
    while (actual) {
        for (int i = 0; i < actual->arregloString.size(); ++i) {
            std::cout << actual->arregloString[i] << ",";
        }
        std::cout << std::endl;
        actual = actual->siguiente;
    }
}

void DobleLista::busquedaBinariaVector(const std::string& valor) {
    Nodo* actual = inicio;
    bool encontrado = false;

    while (actual) {
        if (!actual->arregloString.empty()) {
            std::vector<std::string>& arreglo = actual->arregloString;
            std::sort(arreglo.begin(), arreglo.end());

            if (std::binary_search(arreglo.begin(), arreglo.end(), valor)) {
                encontrado = true;
                std::cout << "Vector completo: ";
                for (const auto& elemento : arreglo) {
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