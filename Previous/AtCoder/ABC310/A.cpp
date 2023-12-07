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

    int n, p, q;
    cin >> n >> p >> q;

    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mn = min(mn, x);
    }

    cout << min(p, q + mn) << '\n';
}
