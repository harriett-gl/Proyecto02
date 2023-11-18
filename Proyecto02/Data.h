//
// Created by Harriett Guzmán on 11/11/23.
//

#ifndef PROYECTO02_DATA_H
#define PROYECTO02_DATA_H

#include "iostream"
#include <string>

class Data {
public:
    std::string claveHasheada;
    std::string restoDeLinea;

    Data() : claveHasheada(""), restoDeLinea("") {}
    Data(const std::string& claveHasheada, const std::string& restoDeLinea);

    bool esMenor(const Data& otro) const;

    int valor;

    // Define el operador < para comparar objetos Data basados en el campo 'valor'
    bool operator<(const Data& other) const {
        return valor < other.valor;
    }
};

#endif //PROYECTO02_DATA_H