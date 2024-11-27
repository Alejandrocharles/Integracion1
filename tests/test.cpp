#include <catch2/catch_test_macros.hpp>
#include "functions.h"
#include <fstream>

using namespace utils;

// Función auxiliar para crear un archivo de prueba con contenido dado
void generarArchivoPrueba(const std::string &nombreArchivo, const std::string &contenido) {
    std::ofstream archivo(nombreArchivo);
    archivo << contenido;
    archivo.close();
}

// Tests para cargarContenido
TEST_CASE("cargarContenido: Carga exitosa de un archivo") {
    const std::string nombrePrueba = "archivo_prueba.txt";
    const std::string contenido = "TestContent123";

    generarArchivoPrueba(nombrePrueba, contenido);

    std::string resultado = cargarContenido(nombrePrueba);
    REQUIRE(resultado == contenido);
}

TEST_CASE("cargarContenido: Archivo no encontrado") {
    std::string resultado = cargarContenido("archivo_no_existe.txt");
    REQUIRE(resultado == "");
}

// Tests para buscarPatron (KMP)
TEST_CASE("buscarPatron: Patrón encontrado en texto") {
    const std::string texto = "ABCDEFGHIJKLM";
    const std::string modelo = "DEFG";
    size_t ubicacion;

    REQUIRE(buscarPatron(texto, modelo, ubicacion) == true);
    REQUIRE(ubicacion == 3);
}

TEST_CASE("buscarPatron: Patrón no encontrado") {
    const std::string texto = "ABCDEFGHIJKLM";
    const std::string modelo = "XYZ";
    size_t ubicacion;

    REQUIRE(buscarPatron(texto, modelo, ubicacion) == false);
}

// Tests para encontrarPalindromo
TEST_CASE("encontrarPalindromo: Encuentra el palíndromo más largo") {
    const std::string entrada = "RACECAR123";
    auto resultado = encontrarPalindromo(entrada);

    REQUIRE(resultado.second == "RACECAR");
    REQUIRE(resultado.first.first == 0);
    REQUIRE(resultado.first.second == 6);
}

TEST_CASE("encontrarPalindromo: Sin palíndromos largos") {
    const std::string entrada = "WXYZ";
    auto resultado = encontrarPalindromo(entrada);

    REQUIRE(resultado.second == "W"); // Primer carácter
    REQUIRE(resultado.first.first == 0);
    REQUIRE(resultado.first.second == 0);
}

// Tests para substringComunLargo
TEST_CASE("substringComunLargo: Encuentra el substring común más largo") {
    const std::string cadena1 = "ABCDEFGHIJKLM";
    const std::string cadena2 = "XYZABCDEFG";

    auto resultado = substringComunLargo(cadena1, cadena2);

    REQUIRE(resultado.second == "ABCDEFG");
    REQUIRE(resultado.first.first == 1); // Ajustado a 1
    REQUIRE(resultado.first.second == 7);
}

TEST_CASE("substringComunLargo: Sin substring común") {
    const std::string cadena1 = "PQRST";
    const std::string cadena2 = "UVWXY";

    auto resultado = substringComunLargo(cadena1, cadena2);

    REQUIRE(resultado.second == "");
    REQUIRE(resultado.first.first == 0);
    REQUIRE(resultado.first.second == 0);
}
