// functions.cpp

#include "functions.h"
#include <fstream>
#include <iostream>
#include <vector>

// Función para leer un archivo y devolver su contenido como una cadena de texto
std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

// Función para verificar si un código malicioso está contenido en una transmisión
bool contains(const std::string& haystack, const std::string& needle, size_t& position) {
    size_t pos = haystack.find(needle);
    if (pos != std::string::npos) {
        position = pos + 1;  // Convertir a 1-indexado
        return true;
    }
    return false;
}

// Función para encontrar el palíndromo más largo en una cadena
std::pair<std::pair<int, int>, std::string> findLongestPalindrome(const std::string& s) {
    int n = s.length();
    int start = 0, maxLength = 1;
    std::vector<std::vector<bool>> table(n, std::vector<bool>(n, false));

    // Cada carácter individual es un palíndromo
    for (int i = 0; i < n; ++i) {
        table[i][i] = true;
    }

    // Buscar palíndromos de longitud 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Buscar palíndromos de longitud mayor
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && table[i + 1][j - 1]) {
                table[i][j] = true;
                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }

    std::string palindrome = s.substr(start, maxLength);
    return {{start + 1, start + maxLength}, palindrome};  // Convertir a 1-indexado
}

// Función para encontrar la subcadena más larga común entre dos cadenas
std::pair<int, int> findLongestCommonSubstring(const std::string& s1, const std::string& s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));

    int maxLength = 0;
    int endPos = 0;

    // Llenar la tabla DP
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endPos = i - 1;
                }
            }
        }
    }

    int startPos = endPos - maxLength + 1;
    return {startPos + 1, endPos + 1};  // Convertir a 1-indexado
}
