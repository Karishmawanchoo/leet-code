#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
bool halvesAreAlike(string s) {
    int n = s.length();
    int half = n / 2;
    int vowelCount1 = 0, vowelCount2 = 0;

    for (int i = 0; i < half; ++i) {
        if (isVowel(s[i])) {
            ++vowelCount1;
        }
    }
    for (int i = half; i < n; ++i) {
        if (isVowel(s[i])) {
            ++vowelCount2;
        }
    }
    return vowelCount1 == vowelCount2;
}
int main() {
    string s1 = "book";
    string s2 = "textbook";
    cout << boolalpha;
    cout << "Are the halves alike in 'book'? " << halvesAreAlike(s1) << endl;
    cout << "Are the halves alike in 'textbook'? " << halvesAreAlike(s2) << endl;
    return 0;
}
