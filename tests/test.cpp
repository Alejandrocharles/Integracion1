// test.cpp

#include <iostream>
#include "functions.h"
#include <cassert>  // Usamos assert para pruebas unitarias

void testReadFile() {
    std::string content = readFile("testfile.txt");
    // Asegúrate de que el archivo de prueba contenga el texto esperado
    assert(content == "Este es un archivo de prueba.\n");
    std::cout << "testReadFile passed." << std::endl;
}

void testContains() {
    size_t position;
    
    std::string transmission = "Esto es una transmisión de prueba.";
    std::string code = "transmisión";
    
    bool result = contains(transmission, code, position);
    // Verificamos que la palabra "transmisión" se encuentra en la cadena
    assert(result == true && position == 6);  // La posición debería ser 6 (1-indexed)
    
    code = "inexistente";
    result = contains(transmission, code, position);
    // Verificamos que la palabra "inexistente" no se encuentra en la cadena
    assert(result == false);
    
    std::cout << "testContains passed." << std::endl;
}

void testFindLongestPalindrome() {
    std::string transmission = "madam, in Eden, I'm Adam";
    
    auto palindromeResult = findLongestPalindrome(transmission);
    
    // Verificamos que el palíndromo encontrado sea correcto
    assert(palindromeResult.second == "madam");
    assert(palindromeResult.first.first == 1);  // Posición 1 (1-indexed)
    assert(palindromeResult.first.second == 5);  // Posición 5 (1-indexed)
    
    std::cout << "testFindLongestPalindrome passed." << std::endl;
}

void testFindLongestCommonSubstring() {
    std::string s1 = "abcabc";
    std::string s2 = "cabca";
    
    auto result = findLongestCommonSubstring(s1, s2);
    
    // Verificamos que la subcadena común más larga es "abc" (posiciones 1-3)
    assert(result.first == 1 && result.second == 3);
    
    std::cout << "testFindLongestCommonSubstring passed." << std::endl;
}

int main() {
    std::cout << "Running tests..." << std::endl;

    // Ejecutar todas las pruebas
    testReadFile();
    testContains();
    testFindLongestPalindrome();
    testFindLongestCommonSubstring();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
