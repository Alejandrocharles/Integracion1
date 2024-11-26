#include "functions.h"
#include <iostream>

using namespace std;

int main() {
    // Ejemplo de prueba para `findLongestPalindrome`
    string testStr = "babad";
    auto longestPalindrome = findLongestPalindrome(testStr);
    cout << "Palíndromo más largo: " << longestPalindrome.second << endl;
    cout << "Índices: (" << longestPalindrome.first.first << ", "
         << longestPalindrome.first.second << ")" << endl;

    // Ejemplo de prueba para `findLongestCommonSubstring`
    string s1 = "abcdef";
    string s2 = "zabcde";
    auto longestCommonSubstring = findLongestCommonSubstring(s1, s2);
    cout << "Subcadena común más larga: "
         << s1.substr(longestCommonSubstring.first,
                      longestCommonSubstring.second - longestCommonSubstring.first + 1)
         << endl;
    cout << "Índices: (" << longestCommonSubstring.first << ", "
         << longestCommonSubstring.second << ")" << endl;

    return 0;
}
