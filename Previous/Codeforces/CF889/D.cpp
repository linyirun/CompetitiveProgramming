#include <bits/stdc++.h>

using namespace std;

void to_binary(int n) {

    string s;
    for (int i = 0; i < 11; i++) {
        if (n & (1 << i)) s += '1';
        else s += '0';
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

int main() {

    for (int i = 0; i < 100; i++) {
        int n = 6 * i;
        cout << i * 6 << ": ";
        to_binary(n);
    }
}