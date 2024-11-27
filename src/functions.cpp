#include "functions.h"
#include <iostream>
#include <fstream>

namespace utils {

std::string cargarContenido(const std::string &rutaArchivo) {
    std::ifstream entrada(rutaArchivo);
    if (!entrada) {
        std::cerr << "No se pudo abrir el archivo: " << rutaArchivo << std::endl;
        return "";
    }
    return std::string((std::istreambuf_iterator<char>(entrada)), std::istreambuf_iterator<char>());
}

void generarLPS(const std::string &modelo, std::vector<int> &lpsAuxiliar) {
    int largoActual = 0;
    size_t idx = 1;
    lpsAuxiliar[0] = 0;

    while (idx < modelo.length()) {
        if (modelo[idx] == modelo[largoActual]) {
            largoActual++;
            lpsAuxiliar[idx] = largoActual;
            idx++;
        } else {
            if (largoActual != 0) {
                largoActual = lpsAuxiliar[largoActual - 1];
            } else {
                lpsAuxiliar[idx] = 0;
                idx++;
            }
        }
    }
}

bool buscarPatron(const std::string &texto, const std::string &modelo, size_t &ubicacion) {
    int tamTexto = texto.length();
    int tamModelo = modelo.length();
    std::vector<int> lps(tamModelo, 0);
    generarLPS(modelo, lps);

    int i = 0, j = 0;
    while (i < tamTexto) {
        if (modelo[j] == texto[i]) {
            i++;
            j++;
        }
        if (j == tamModelo) {
            ubicacion = i - j;
            return true;
        } else if (i < tamTexto && modelo[j] != texto[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false;
}

std::pair<std::pair<int, int>, std::string> encontrarPalindromo(const std::string &cadena) {
    int longitud = cadena.size();
    if (longitud == 0) {
        return {{0, 0}, ""};
    }

    std::pair<int, int> posicion = {0, 0};
    int tamMax = 1;
    std::string resultadoPalindromo = cadena.substr(0, 1);

    for (int centro = 0; centro < longitud; ++centro) {
        int izquierda = centro, derecha = centro;
        while (izquierda >= 0 && derecha < longitud && cadena[izquierda] == cadena[derecha]) {
            if (derecha - izquierda + 1 > tamMax) {
                tamMax = derecha - izquierda + 1;
                posicion = {izquierda, derecha};
                resultadoPalindromo = cadena.substr(izquierda, derecha - izquierda + 1);
            }
            izquierda--;
            derecha++;
        }

        izquierda = centro, derecha = centro + 1;
        while (izquierda >= 0 && derecha < longitud && cadena[izquierda] == cadena[derecha]) {
            if (derecha - izquierda + 1 > tamMax) {
                tamMax = derecha - izquierda + 1;
                posicion = {izquierda, derecha};
                resultadoPalindromo = cadena.substr(izquierda, derecha - izquierda + 1);
            }
            izquierda--;
            derecha++;
        }
    }

    return {posicion, resultadoPalindromo};
}

std::pair<std::pair<int, int>, std::string> substringComunLargo(const std::string &cadenaA, const std::string &cadenaB) {
    int tamA = cadenaA.size(), tamB = cadenaB.size();
    if (tamA == 0 || tamB == 0) {
        return {{0, 0}, ""};
    }

    std::vector<std::vector<int>> tablaDP(tamA + 1, std::vector<int>(tamB + 1, 0));
    int tamMayor = 0, finPosA = 0;
    std::string subCadena;

    for (int i = 1; i <= tamA; ++i) {
        for (int j = 1; j <= tamB; ++j) {
            if (cadenaA[i - 1] == cadenaB[j - 1]) {
                tablaDP[i][j] = tablaDP[i - 1][j - 1] + 1;
                if (tablaDP[i][j] > tamMayor) {
                    tamMayor = tablaDP[i][j];
                    finPosA = i;
                    subCadena = cadenaA.substr(i - tamMayor, tamMayor);
                }
            }
        }
    }

    if (tamMayor == 0) {
        return {{0, 0}, ""};
    }

    return {{finPosA - tamMayor + 1, finPosA}, subCadena};
}

} // namespace utils
