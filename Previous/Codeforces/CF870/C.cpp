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

    const int MAX = 1e6 + 1;
    vector<int> smallest_divisor(MAX, MAX);

    // sieve
    for (int i = 2; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            smallest_divisor[j] = min(smallest_divisor[j], i);
        }
    }

    while (tt--) {
        int n, m;
        cin >> n >> m;

        if (m == 1 || n == 1) {
            cout << "YES\n";
            continue;
        }

        if (smallest_divisor[n] <= m) cout << "NO\n";
        else cout << "YES\n";

    }
}
