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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int out = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] % k != i % k) out++;
        }

        if (!out) cout << "0\n";
        else if (out == 2) cout << "1\n";
        else cout << "-1\n";
    }
}
