//
// Created by Harriett Guzmán on 11/11/23.
//

#ifndef PROYECTO02_NODO_H
#define PROYECTO02_NODO_H

#include "Data.h"
#include <string>
#include <vector>

class Nodo {
public:
    Data datos;
    std::string valor;
    std::vector<std::string> stringCadenas;

    Nodo* siguiente;
    Nodo* anterior;

    Nodo();
    Nodo(const Data& datitos);
    Nodo(const std::vector<std::string>& stringCadenas);
};


#endif //PROYECTO02_NODO_H
