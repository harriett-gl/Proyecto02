//
// Created by Harriett Guzmán on 11/11/23.
//

#ifndef PROYECTO02_DOBLELISTA_H
#define PROYECTO02_DOBLELISTA_H

#include "Nodo.h"
#include "Data.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <iterator>
#include <limits>
#include <unordered_set>

class DobleLista {
private:
    Nodo* inicio;
    Nodo* fin;
    int tamano;

public:
    DobleLista();
    ~DobleLista();

    void imprimir();
    void busquedaBinaria(std::string valor);
    void limpiarLista();
    int tamanoLista();

    void agregarElemento(const Data& datos);
    void ordenarListaHash();


    void agregarVector(const std::vector<std::string>& arregloString);
    void imprimirListaVector();
    void busquedaBinariaVector(const std::string& valor);


};

#endif //PROYECTO02_DOBLELISTA_H