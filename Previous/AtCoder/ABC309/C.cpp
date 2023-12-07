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

    int n, k;
    cin >> n >> k;

    vector<pii> a(n);

    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    int l = 1, r = 1e9 + 1;
    int ans = -1;
    while (l <= r) {
        int mp = (l + r) / 2;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].first >= mp) curr += a[i].second;
        }

        if (curr <= k) {
            ans = mp;
            r = mp - 1;
        } else {
            l = mp + 1;
        }
    }

    cout << ans << '\n';
}
