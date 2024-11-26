#include <gtest/gtest.h>

// Función que vamos a probar
int suma(int a, int b) {
    return a + b;
}

// Prueba de unidad para la función suma
TEST(SumaTest, SumaPositivos) {
    EXPECT_EQ(suma(2, 3), 5);  // Prueba de suma de dos números positivos
}

TEST(SumaTest, SumaNegativos) {
    EXPECT_EQ(suma(-1, -1), -2);  // Prueba de suma de dos números negativos
}

TEST(SumaTest, SumaPositivoNegativo) {
    EXPECT_EQ(suma(5, -3), 2);  // Prueba de suma de un número positivo y uno negativo
}

TEST(SumaTest, SumaCero) {
    EXPECT_EQ(suma(0, 0), 0);  // Prueba de suma de dos ceros
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // Ejecuta todas las pruebas definidas
}
