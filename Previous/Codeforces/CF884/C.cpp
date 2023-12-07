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
        int n;
        cin >> n;

        vector<int> a(n), pref(n), suff(n);
        for (int i = 0; i < n; i++) cin >> a[i];


        if (n == 1) {
            cout << a[0] << '\n';
            continue;
        } else if (n == 2) {
            cout << max(a[0], a[1]) << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            pref[i] = a[i];
            if (i >= 2) pref[i] = max(pref[i], a[i] + pref[i - 2]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suff[i] = a[i];
            if (i + 2 < n) suff[i] = max(suff[i], a[i] + suff[i + 2]);
        }

        int ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            ans = max({ans, a[i], pref[i], suff[i]});
            if (i != n - 1) {
                ans = max(ans, suff[i + 1]);
            }
            if (i != 0) {
                ans = max(ans, pref[i - 1]);
            }
            if (i != 0 && i != n - 1) {
                ans = max(ans, pref[i - 1] + suff[i + 1]);
            }
        }
        cout << ans << '\n';

    }
}

/*
1
5
4 -1000 -1 5 3

1
5
20 -1 -1 -1 20

40

 */