#include "functions.h"
#include <vector>
#include <string>
#include <utility>

using namespace std;

pair<pair<int, int>, string> findLongestPalindrome(const string &s) {
    size_t n = s.length();
    if (n == 0) return {{0, 0}, ""};

    vector<vector<bool>> table(n, vector<bool>(n, false));
    size_t start = 0;
    size_t maxLength = 1;

    for (size_t i = 0; i < n; ++i) {
        table[i][i] = true;
    }

    for (size_t i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (size_t len = 3; len <= n; ++len) {
        for (size_t i = 0; i < n - len + 1; ++i) {
            size_t j = i + len - 1;
            if (s[i] == s[j] && table[i + 1][j - 1]) {
                table[i][j] = true;
                start = i;
                maxLength = len;
            }
        }
    }

    string palindrome = s.substr(start, maxLength);
    return {{start, static_cast<int>(start + maxLength - 1)}, palindrome};
}

pair<int, int> findLongestCommonSubstring(const string &s1, const string &s2) {
    size_t n1 = s1.length();
    size_t n2 = s2.length();

    if (n1 == 0 || n2 == 0) return {0, 0};

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    size_t maxLength = 0;
    size_t endIndex = 0;

    for (size_t i = 1; i <= n1; ++i) {
        for (size_t j = 1; j <= n2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > static_cast<int>(maxLength)) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    return {static_cast<int>(endIndex - maxLength + 1), static_cast<int>(endIndex)};
}
