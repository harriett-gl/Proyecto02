//
// Created by Harriett Guzmán on 11/11/23.
//

#ifndef PROYECTO02_HASH_H
#define PROYECTO02_HASH_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <functional>
#include "DobleLista.h"

class Hash {
public:
    Hash();
    std::string generarHash(const std::string& clave);
    void procesarArchivo(const std::string& rutaArchivo, DobleLista* listaHash, DobleLista* listaValores);
    std::vector<std::string> convertirAVector(std::string& cadena);

};

#endif //PROYECTO02_HASH_H