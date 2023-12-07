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

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    while (q--) {
        int k;
        cin >> k;
        int l = -INF, r = INF;
        int ans = l;
        while (l <= r) {
            int m = (l + r) / 2;
            bool can = true;

            if (k < n) {
                for (int i = 0; i < n; i++) {
                    if (v[i] + max(k - i, 0LL) < m) {
                        can = false;
                        break;
                    }
                }
            } else {
                int total_extra = 0;

                for (int i = 0; i < n; i++) {
                    if ((k - n) % 2 == 1 && i == n - 1) {
                        if (v[i] < m) can = false;
                        else total_extra += v[i] - m;
                        continue;
                    }
                    if (v[i] + k - i < m) {
                        can = false;
                        break;
                    } else {
                        total_extra += v[i] + k - i - m;
                    }
                }
                if (total_extra < (k - n + 1) / 2) can = false;
            }

            if (can) {
                ans = m;
                l = m + 1;
            } else r = m - 1;

        }

        cout << ans << ' ';
    }
    cout << '\n';
}

/*
4 1
5 2 8 4
7

 */