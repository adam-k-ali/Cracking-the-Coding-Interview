#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

string compress(string s) {
    string compressed = "";
    for (int i = 0; i < s.length(); i++) {
        int count = 1;
        char c = s[i];
        while (i < s.length() - 1 && s[i] == s[i + 1]) {
            count++;
            i++;
        }
        compressed += c + to_string(count);
    }

    if (compressed.length() > s.length()) {
        return s;
    }
    return compressed;
}

int run_tests() {
    string s = "aabcccccaaa";
    string compressed = compress(s);
    cout << "Test 1: " << compressed << endl;
    assert(compressed == "a2b1c5a3");

    s = "abcd";
    compressed = compress(s);
    cout << "Test 2: " << compressed << endl;
    assert(compressed == "abcd");

    s = "";
    compressed = compress(s);
    cout << "Test 3: " << compressed << endl;
    assert(compressed == "");

    return 0;
}

int main() {
    if (run_tests() == 0) {
        cout << "All tests passed" << endl;
    } else {
        cout << "Tests failed" << endl;
    }
    return 0;
}