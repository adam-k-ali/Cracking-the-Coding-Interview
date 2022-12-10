#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

/*
    Function: isUnique
    -------------------
    Returns true if the string s contains all unique characters.
    Runs in O(n log n) time as it sorts the string first, then compares
    adjacent characters.

    Parameters
    ----------
    n (int): the length of the string
    s (string): the string to be checked

    Returns
    -------
    true if the string contains all unique characters, false otherwise
*/
bool isUnique(int n, string s) {
    if (n <= 1) return true;

    sort(s.begin(), s.end());

    // O(n)
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) return false;
    }
    return true;
}

int main() {
    // Run tests
    int errors = 0;
    errors += isUnique(0, "") == true ? 0 : 1;
    errors += isUnique(1, "a") == true ? 0 : 1;
    errors += isUnique(2, "ab") == true ? 0 : 1;
    errors += isUnique(4, "abca") == false ? 0 : 1;
    errors += isUnique(5, "adadd") == false ? 0 : 1;
    cout << "Tests run: " << 5 << endl;
    cout << "Errors: " << errors << endl;

    return 0;
}