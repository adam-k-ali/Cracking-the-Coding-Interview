#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
    Function: isPalindromePermutation
    ---------------------------------
    Check if there's a possible permutation of the string that is a palindrome.
    Runs in O(n) time, where n is the length of the string.
    Requires no additional space.

    Parameters
    ----------
    s: string
        The string to check.
    
    Returns
    -------
    bool
        True if there is a possible permutation of the string that is a palindrome.
*/
bool isPalindromePermutation(string *s) {
    // Remove non-letter characters and convert to lowercase
    unordered_map<char, int> charCount;
    for (int i = 0; i < s->length(); i++) {
        if (!isalpha((*s)[i])) {
            s->erase(i, 1);
            i--;
        } else {
            (*s)[i] = tolower((*s)[i]);
            charCount[(*s)[i]]++;
        }
    }
    
    // Check if string is a palindrome permutation.
    // All characters must appear an even number of times, except for one character
    bool oddFound = false;
    for (pair<char, int> entry : charCount) {
        if (entry.second % 2 != 0 && oddFound) {
            return false;
        }

        if (entry.second % 2 != 0) { 
            oddFound = true;
        }
    }

    return true;
}

int main() {
    // Run tests
    string s1 = "Tact Coa";
    int errors = 0;
    errors += !isPalindromePermutation(&s1);
    string s2 = "Tact Coaa";

    errors += isPalindromePermutation(&s2);

    cout << "Tests run: " << 2 << endl;
    cout << "Errors: " << errors << endl;
    return 0;
}