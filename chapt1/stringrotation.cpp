//
// Created by Adam Ali on 25/12/2022.
//
#include <iostream>
#include <string>

using namespace std;

bool isRotation(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    if (s1.length() == 0) {
        return true;
    }

    s1 += s1;
    if (s1.find(s2) != std::string::npos) {
        return true;
    }
    return false;
}

int main() {
    cout << isRotation("waterbottle", "erbottlewat") << endl;
}