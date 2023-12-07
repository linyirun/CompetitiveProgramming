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

    int n, m, d;
    cin >> n >> m >> d;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());

    int best = -1;
    for (int i = 0; i < n; i++) {
        auto top_it = upper_bound(b.begin(), b.end(), a[i] + d);
        auto low_it = lower_bound(b.begin(), b.end(), a[i] - d);

        if (top_it != b.begin() && abs(*(--top_it) - a[i]) <= d) best = max(best, a[i] + *(top_it));
        if (low_it != b.end() && abs(*low_it - a[i]) <= d) best = max(best, a[i] + *(low_it));
    }
    cout << best << '\n';

}
