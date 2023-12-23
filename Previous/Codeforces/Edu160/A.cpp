//#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <cstdio>
#include <iostream>

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

#define int ll
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INF = 1e15;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;

        for (int i = 1; i < s.size(); i++) {
            // split at i
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);

            if (s2[0] != '0' && stoi(s1) < stoi(s2)) {
                cout << s1 << ' ' << s2 << '\n';
                goto done;
            }
        }

        cout << "-1\n";
        done:;
    }
}
