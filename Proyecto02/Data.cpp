//
// Created by Harriett Guzmán on 11/11/23.
//

#include "Data.h"

Data::Data(const std::string& claveHasheada, const std::string& restoDeLinea)
        : claveHasheada(claveHasheada), restoDeLinea(restoDeLinea) {}

bool Data::esMenor(const Data& otro) const {
    return claveHasheada < otro.claveHasheada;
}
