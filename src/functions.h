#pragma once

#include <string>
#include <vector>
#include <utility>

namespace utils {

// Función para cargar contenido desde un archivo
std::string cargarContenido(const std::string &rutaArchivo);

// Generar el arreglo LPS para el algoritmo de búsqueda de patrones
void generarLPS(const std::string &modelo, std::vector<int> &lpsAuxiliar);

// Algoritmo de Knuth-Morris-Pratt para buscar un patrón en un texto
bool buscarPatron(const std::string &texto, const std::string &modelo, size_t &ubicacion);

// Encontrar el palíndromo más extenso dentro de una cadena
std::pair<std::pair<int, int>, std::string> encontrarPalindromo(const std::string &cadena);

// Encontrar el substring común más largo entre dos cadenas
std::pair<std::pair<int, int>, std::string> substringComunLargo(const std::string &cadenaA, const std::string &cadenaB);

} // namespace utils
