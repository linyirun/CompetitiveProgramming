#include <bits/stdc++.h>
#include <string>
//#include <cmath>
//#include <cstdio>
//#include <iostream>

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
        int n = s.size();

        int s0 = 0, s1 = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') s0++;
            else s1++;
         }

        int curr0 = 0, curr1 = 0;
        int best = n;
        for (int i = 0; i <= n; i++) {
            if (s1 >= curr0 && s0 >= curr1) {
                best = n - i;
            }

            if (i < n) {
                if (s[i] == '0') curr0++;
                else curr1++;
            }
        }
        cout << best << '\n';

    }
}
