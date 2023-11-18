//
// Created by Harriett Guzmán on 11/11/23.
//

#include "Nodo.h"
#include "Data.h"

Nodo::Nodo(){}

Nodo::Nodo(const Data& nuevosDatos)
        : datos(nuevosDatos), siguiente(nullptr), anterior(nullptr) {}

Nodo::Nodo(const std::vector<std::string>& arregloString)
        : arregloString(arregloString), siguiente(nullptr), anterior(nullptr) {}
