//
// Created by Harriett Guzmán on 11/11/23.
//

#ifndef PROYECTO02_HASH_H
#define PROYECTO02_HASH_H

#include "DobleLista.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <functional>

class Hash {
public:
    Hash();
    // Función para generar hash de una clave
    std::string generarHash(const std::string& clave);

    // Procesa un archivo y carga los datos en las listas
    void procesarArch(const std::string& rutaArchivo, DobleLista* listaHash, DobleLista* listaValor);
    // Convierte una cadena en un vector de strings
    std::vector<std::string> convertirAVector(std::string& cadena);
};

#endif //PROYECTO02_HASH_H