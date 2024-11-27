#include <iostream>
#include "functions.h"

using namespace std;
using namespace utils;

int main() {
    string trama1 = cargarContenido("transmission1.txt");
    if (trama1.empty()) return 1;

    string trama2 = cargarContenido("transmission2.txt");
    if (trama2.empty()) return 1;

    string codigo1 = cargarContenido("mcode1.txt");
    if (codigo1.empty()) return 1;

    string codigo2 = cargarContenido("mcode2.txt");
    if (codigo2.empty()) return 1;

    string codigo3 = cargarContenido("mcode3.txt");
    if (codigo3.empty()) return 1;

    size_t indice;
    cout << "Parte 1: Verificación de códigos maliciosos:\n";
    cout << (buscarPatron(trama1, codigo1, indice) ? "true " + to_string(indice + 1) : "false") << endl;
    cout << (buscarPatron(trama1, codigo2, indice) ? "true " + to_string(indice + 1) : "false") << endl;
    cout << (buscarPatron(trama1, codigo3, indice) ? "true " + to_string(indice + 1) : "false") << endl;
    cout << (buscarPatron(trama2, codigo1, indice) ? "true " + to_string(indice + 1) : "false") << endl;
    cout << (buscarPatron(trama2, codigo2, indice) ? "true " + to_string(indice + 1) : "false") << endl;
    cout << (buscarPatron(trama2, codigo3, indice) ? "true " + to_string(indice + 1) : "false") << endl;

    auto palindromo1 = encontrarPalindromo(trama1);
    auto palindromo2 = encontrarPalindromo(trama2);
    cout << "Parte 2: Palíndromo más largo:\n";
    cout << palindromo1.first.first + 1 << " " << palindromo1.first.second + 1 << " " << palindromo1.second << endl;
    cout << palindromo2.first.first + 1 << " " << palindromo2.first.second + 1 << " " << palindromo2.second << endl;

    auto subCadenaComun = substringComunLargo(trama1, trama2);
    cout << "Parte 3: Substring común más largo:\n";
    cout << subCadenaComun.first.first << " " << subCadenaComun.first.second << " " << subCadenaComun.second << endl;

    return 0;
}
