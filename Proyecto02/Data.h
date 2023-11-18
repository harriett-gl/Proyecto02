//
// Created by Harriett Guzmán on 11/11/23.
//

#ifndef PROYECTO02_DATA_H
#define PROYECTO02_DATA_H

#include <string>

class Data {
public:
    std::string claveHasheada;
    std::string restoDeLinea;

    Data(): claveHasheada(""), restoDeLinea("") {}
    Data(const std::string& claveHasheada, const std::string& restoDeLinea);

    bool operator<(const Data& otro) const;
};

#endif //PROYECTO02_DATA_H
