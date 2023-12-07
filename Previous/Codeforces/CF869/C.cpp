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

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> pref(n);
    pref[0] = 1;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i]) cnt++;
        else {
            if (i == 1 || a[i - 2] < a[i - 1]) cnt++;
        }
        pref[i] = cnt;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = pref[r];
        if (l) ans -= pref[l - 1];
        if (r == l) ans = max(1LL, ans);
        if (r == l + 1) ans = max(2LL, ans);
        cout << ans << '\n';
    }
}