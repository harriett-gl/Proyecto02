//
// Created by Harriett Guzmán on 11/11/23.
//

#include "Hash.h"
#include "Data.h"


Hash::Hash() {
}

std::string Hash::generarHash(const std::string& clave) {
    std::hash<std::string> hashClave;
    std::size_t claveHasheada = hashClave(clave);
    return std::to_string(claveHasheada).substr(0, 10);
}

std::vector<std::string> Hash::convertirAVector(std::string& cadena) {
    std::vector<std::string> resultado;
    std::stringstream ss(cadena);
    std::string token;

    while (std::getline(ss, token, ',')) {
        resultado.push_back(token);
    }

    return resultado;
}

void Hash::procesarArchivo(const std::string& rutaArchivo, DobleLista* listaHash, DobleLista* listaValores) {
    std::ifstream archivo(rutaArchivo);

    if (!archivo) {
        std::cout << "No se pudo abrir el archivo: " << rutaArchivo << '\n';
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream flujoLinea(linea);
        std::string token, clave, restoDeLinea;

        if (std::getline(flujoLinea, token, ',')) {
            clave = token;
            restoDeLinea = linea;
        }

        std::string claveHasheada = generarHash(clave);
        Data datosLinea(claveHasheada, restoDeLinea);

        listaHash->agregarElemento(datosLinea);

        std::vector<std::string> resultado = convertirAVector(restoDeLinea);
        listaValores->agregarVector(resultado);
    }

    archivo.close();
}