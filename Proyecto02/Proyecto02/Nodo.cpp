//
// Created by Harriett Guzmán on 11/11/23.
//

#include "Nodo.h"

Nodo::Nodo() : siguiente(nullptr), anterior(nullptr) {}

Nodo::Nodo(const Data& datitos) : datos(datitos), siguiente(nullptr), anterior(nullptr) {}

Nodo::Nodo(const std::vector<std::string>& Cadenas) : Cadenas(Cadenas), siguiente(nullptr), anterior(nullptr) {}