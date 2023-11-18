//
// Created by Harriett Guzmán on 11/11/23.
//

#ifndef PROYECTO02_DOBLELISTA_H
#define PROYECTO02_DOBLELISTA_H

#include "Nodo.h"
#include "Data.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
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
    int tamanio;

public:
    DobleLista();
    ~DobleLista();

    void imprimir(); // Función de prueba
    void busquedaBinaria(std::string value);
    void limpiarLista();
    int tamanioDeLista();
    void agregarElemento(const Data& data);
    void ordenarListaHash();

    void busquedaBinariaVector(const std::string& value);
    void imprimirVector();
    void agregarVector(const std::vector<std::string>& stringArray);
};

#endif //PROYECTO02_DOBLELISTA_H
