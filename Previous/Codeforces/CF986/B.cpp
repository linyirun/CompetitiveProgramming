#include <bits/stdc++.h>
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
        int n, b, c;
        cin >> n >> b >> c;

        if (b == 0) {
            if (c >= n - 2) {
                cout << n - (c < n) << '\n';
            }
            else cout << "-1\n";
            continue;
        }

        int mult = (n - c - 1) / b + 1;
        if (c >= n) mult = 0;
        cout << n - min(mult, n) << '\n';

    }
}
