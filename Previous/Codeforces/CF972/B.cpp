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
        int n, m, q;
        cin >> n >> m >> q;

        vector<int> b(m), quer(q);
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < q; i++) cin >> quer[i];

        sort(b.begin(), b.end());

        for (int i = 0; i < q; i++) {
            int a = quer[i];

            int d_l = -1, d_r = -1;
            auto it = lower_bound(b.begin(), b.end(), a);

            if (it != b.end()) d_r = *it - a;
            if (it != b.begin()) d_l = a - *(--it);

            int ans = 0;
            if (d_l == -1) {
                ans = a - 1 + d_r;
            } else if (d_r == -1) {
                ans = n - a + d_l;
            } else {
                ans = (d_l + d_r) / 2;
            }

            cout << ans << '\n';
        }


    }
}
