#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "functions.h"

// Pruebas para readFile
TEST_CASE("readFile - Leer contenido de archivo") {
    std::string content = readFile("test_file.txt");
    REQUIRE(content == "Esto es una prueba.\n");
}

// Pruebas para contains
TEST_CASE("contains - Buscar subcadenas") {
    std::string text = "abcde";
    std::string sub1 = "bcd";
    std::string sub2 = "xyz";
    size_t position;

    SECTION("Subcadena encontrada") {
        REQUIRE(contains(text, sub1, position));
        REQUIRE(position == 2); // 1-indexado
    }

    SECTION("Subcadena no encontrada") {
        REQUIRE_FALSE(contains(text, sub2, position));
    }
}

// Pruebas para findLongestPalindrome
TEST_CASE("findLongestPalindrome - Palíndromo más largo") {
    std::string text = "babad";

    auto result = findLongestPalindrome(text);

    REQUIRE(result.first.first == 1);  // Posición inicial (1-indexado)
    REQUIRE(result.first.second == 3); // Posición final (1-indexado)
    REQUIRE(result.second == "bab");  // Palíndromo encontrado
}

// Pruebas para findLongestCommonSubstring
TEST_CASE("findLongestCommonSubstring - Subcadena común más larga") {
    std::string s1 = "abcdef";
    std::string s2 = "zcdemf";

    auto result = findLongestCommonSubstring(s1, s2);

    REQUIRE(result.first == 3); // Inicio (1-indexado)
    REQUIRE(result.second == 4); // Final (1-indexado)
    REQUIRE(s1.substr(result.first - 1, result.second - result.first + 1) == "cde");
}
