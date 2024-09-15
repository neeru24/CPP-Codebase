#include<iostream>
using namespace std;

bool checkPalindrome(string str, int i) {
    int n = str.length();

    // Base case
    if (i >= n / 2)
        return true;

    if (str[i] != str[n - i - 1])
        return false;

    // Recursive call
    return checkPalindrome(str, i + 1);
}

int main() {
    string name = "abbccbba";
    cout << endl;

    bool isPalindrome = checkPalindrome(name, 0);

    if (isPalindrome) {
        cout << "It's a Palindrome" << endl;
    }
    else {
        cout << "It's not a Palindrome" << endl;
    }

    return 0;
}
