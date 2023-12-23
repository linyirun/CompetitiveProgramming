#include <bits/stdc++.h>
//#include <string>
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

    int q;
    cin >> q;

    const int MX = 33;
    vector<int> cnt(MX);
    while (q--) {
        int op, x;
        cin >> op >> x;

        if (op == 1) {
            cnt[x]++;
        } else {
            vector<int> cpy = cnt;
            bool can = true;
            for (int i = MX - 1; i >= 0; i--) {
                if (x & (1LL << i)) {
                    int need = 1;
                    for (int j = i; j >= 0; j--) {
                        int take = min(need, cpy[j]);
                        need -= take;
                        cpy[j] -= take;
                        if (!need) break;
                        need *= 2;
                    }
                    if (need) can = false;
                }
            }
            if (can) cout << "YES\n";
            else cout << "NO\n";

        }

    }
}
