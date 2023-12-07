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
        int n, k, g;
        cin >> n >> k >> g;

        int tmp = (g - 1) / 2;
        int left = k * g - tmp * n;
        if (left <= 0) {
            cout << k * g << '\n';
            continue;
        }

        int total = (n - 1) * tmp;
        int p1 = (left + tmp) % g;
        if (p1 >= (g + 1) / 2) {
            total -= g - (p1 % g);
        } else total += p1 % g;
        cout << max(0LL, total) << '\n';

    }
}
