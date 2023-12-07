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

int n, m;
vector<int> a;

int solve() {
    sort(a.begin(), a.end());
    int curr = (n - 1) * (m - 1) * (a[n * m - 1] - a[0]);
    curr += (n - 1) * (a[n * m - 1] - a[1]) + (m - 1) * (a[n * m - 1] - a[0]);
    return curr;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        cin >> n >> m;
        a = vector<int>(n * m);
        if (n > m) swap(n, m);
        for (int i = 0; i < n * m; i++) cin >> a[i];

        int best = solve();
        for (int i = 0; i < n * m; i++) a[i] = -a[i];

        cout << max(best, solve()) << '\n';
    }
}
