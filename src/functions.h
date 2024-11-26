// functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <utility>

// Declaración de la función para leer un archivo y devolver su contenido como una cadena de texto
std::string readFile(const std::string& filename);

// Declaración de la función para verificar si un código malicioso está contenido en una transmisión
bool contains(const std::string& haystack, const std::string& needle, size_t& position);

// Declaración de la función para encontrar el palíndromo más largo en una cadena
std::pair<std::pair<int, int>, std::string> findLongestPalindrome(const std::string& s);

// Declaración de la función para encontrar la subcadena más larga común entre dos cadenas
std::pair<int, int> findLongestCommonSubstring(const std::string& s1, const std::string& s2);

#endif // FUNCTIONS_H
