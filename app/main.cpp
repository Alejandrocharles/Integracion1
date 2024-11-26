#include <iostream>
#include "functions.h"

int main() {
    std::string transmission1 = readFile("transmission1.txt");
    std::string transmission2 = readFile("transmission2.txt");
    std::string mcode1 = readFile("mcode1.txt");
    std::string mcode2 = readFile("mcode2.txt");
    std::string mcode3 = readFile("mcode3.txt");

    // Parte 1: Verificar si el código malicioso está en las transmisiones
    std::cout << "Parte 1" << std::endl;
    size_t position;
    std::cout << (contains(transmission1, mcode1, position) ? "true " + std::to_string(position) : "false") << std::endl;
    std::cout << (contains(transmission1, mcode2, position) ? "true " + std::to_string(position) : "false") << std::endl;
    std::cout << (contains(transmission1, mcode3, position) ? "true " + std::to_string(position) : "false") << std::endl;
    std::cout << (contains(transmission2, mcode1, position) ? "true " + std::to_string(position) : "false") << std::endl;
    std::cout << (contains(transmission2, mcode2, position) ? "true " + std::to_string(position) : "false") << std::endl;
    std::cout << (contains(transmission2, mcode3, position) ? "true " + std::to_string(position) : "false") << std::endl;

    // Parte 2: Encontrar el palíndromo más largo en los archivos de transmisión
    std::cout << "\n" <<  "Parte 2" << std::endl;
    std::pair<std::pair<int, int>, std::string> palindromeTransmission1 = findLongestPalindrome(transmission1);
    std::pair<std::pair<int, int>, std::string> palindromeTransmission2 = findLongestPalindrome(transmission2);

    std::cout << palindromeTransmission1.first.first << " " << palindromeTransmission1.first.second << " " << palindromeTransmission1.second << std::endl;
    std::cout << palindromeTransmission2.first.first << " " << palindromeTransmission2.first.second << " " << palindromeTransmission2.second << std::endl;

    // Parte 3: Encontrar la subcadena común más larga entre las transmisiones
    std::cout << "Parte 3" << std::endl;
    std::pair<int, int> longestCommonSubstring = findLongestCommonSubstring(transmission1, transmission2);
    std::cout << longestCommonSubstring.first << " " << longestCommonSubstring.second << " ";
    std::cout << transmission1.substr(longestCommonSubstring.first - 1, longestCommonSubstring.second - longestCommonSubstring.first + 1) << std::endl;

    return 0;
}
