#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
    Function: urlify
    ----------------
    Replaces all spaces in the string s with %20. The string is assumed to
    have sufficient space at the end to hold the additional characters.
    The function runs in-place, modifying the string s.
    The function runs in O(n) time, as it iterates through the string once.

    Parameters
    ----------
    s (string): the string to modify
*/
void urlify(string *s, int n) {
    *s = s->substr(0, n);

    // Replace spaces with %20
    for (int i = 0; i < n; i++) {
        if ((*s)[i] == ' ') {
            (*s)[i] = '%';
            s->insert(i + 1, "20");
            i += 2;
            n += 2;
        }
    }
}

int main() {
    // Run tests
    int errors = 0;
    string s1 = "Mr John Smith    ";
    string s2 = "Mr%20John%20Smith";
    urlify(&s1, 13);
    errors += s1 == s2 ? 0 : 1;

    cout << "Tests run: " << 1 << endl;
    cout << "Errors: " << errors << endl;

    return 0;
}