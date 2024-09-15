#include<iostream>
using namespace std;

void reverse(string& str, int i) {
    int n = str.length();
    cout << "call received for " << str << endl;

    // Base case
    if (i >= n / 2)
        return;

    // Swap characters
    swap(str[i], str[n - i - 1]);

    // Recursive call
    reverse(str, i + 1);
}

int main() {
    string name = "abcde";
    cout << endl;
    reverse(name, 0);
    cout << endl;
    cout << name << endl;

    return 0;
}
