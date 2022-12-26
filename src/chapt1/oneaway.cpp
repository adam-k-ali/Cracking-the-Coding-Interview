#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

using namespace std;

int one_away(string *s1, string *s2) {
    // If the difference in their lengths is greater than 1,
    // They are more than one edit away
    int len1 = s1->length();
    int len2 = s2->length();
    if (abs(len1 - len2) > 1) {
        return 0;
    }

    // If the lengths are the same, all characters must be the same, except for one
    if (len1 == len2) {
        int diff = 0;
        for (int i = 0; i < len1; i++) {
            if (s1->at(i) != s2->at(i)) {
                diff++;
            }
            if (diff > 1) {
                return 0;
            }
        }
        return 1;
    }

    // If the lengths are one away, all the characters in the shorter string must be in the longer string
    if (len1 < len2) {
        for (int i = 0; i < len1; i++) {
            if (s2->find(s1->at(i)) == string::npos) {
                return 0;
            }
        }
    } else {
        for (int i = 0; i < len2; i++) {
            if (s1->find(s2->at(i)) == string::npos) {
                return 0;
            }
        }
    }

    return 1;
}

int run_tests() {
    // Test cases
    string s1 = "pale";
    string s2 = "ple";
    assert(one_away(&s1, &s2) == 1);

    s1 = "pales";
    s2 = "paler";
    assert(one_away(&s1, &s2) == 1);

    s1 = "pale";
    s2 = "paleds";
    assert(one_away(&s1, &s2) == 0);

    s1 = "pale";
    s2 = "bales";
    assert(one_away(&s1, &s2) == 0);

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