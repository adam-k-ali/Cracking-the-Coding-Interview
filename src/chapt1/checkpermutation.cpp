#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
    Function: isPermutation
    -----------------------
    Returns true if the strings s1 and s2 are permutations of each other.
    Runs in O(n log n) time as it sorts the strings first, then compares
    adjacent characters.

    Parameters
    ----------
    s1 (string): the first string
    s2 (string): the second string

    Returns
    -------
    true if the strings are permutations of each other, false otherwise
*/
bool isPermutation(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    // O(n log n)
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    // O(n)
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}

int main() {
    // Run tests
    int errors = 0;
    errors += isPermutation("abc", "cba") == true ? 0 : 1;
    errors += isPermutation("abc", "cbaa") == false ? 0 : 1;
    errors += isPermutation("abcd", "cbad") == true ? 0 : 1;
    errors += isPermutation("abcd", "cbad ") == false ? 0 : 1;
    errors += isPermutation("abcd ", "cbad") == false ? 0 : 1;

    cout << "Tests run: " << 5 << endl;
    cout << "Errors: " << errors << endl;

    return 0;
}