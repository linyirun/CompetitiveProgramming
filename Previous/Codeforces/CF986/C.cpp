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
        int n, m, v;
        cin >> n >> m >> v;

        vector<int> a(n), pref_sum(n), suff(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pref_sum[i] = a[i];
            if (i) pref_sum[i] += pref_sum[i - 1];
        }

        int curr = 0, num_subarrs = 0;
        for (int i = n - 1; i >= 0; i--) {
            curr += a[i];
            if (curr >= v) {
                num_subarrs++;
                curr = 0;
            }
            suff[i] = num_subarrs;
        }
        pref_sum.push_back(pref_sum[n - 1]);
        suff.push_back(0);


        curr = 0, num_subarrs = 0;
        int best = 0;
        int r = 0;
        if (suff[0] < m) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            curr += a[i];
            while (r < n && suff[r + 1] >= m - num_subarrs) {
                r++;
            }
            if (suff[r] + num_subarrs >= m) {
                // alice can get piece [i, r - 1]
                int sub = 0;
                if (i) sub = pref_sum[i - 1];
                if (r) best = max(best, pref_sum[r - 1] - sub);
            }

            if (curr >= v) {
                curr = 0;
                num_subarrs++;
            }

        }
        cout << best << '\n';
    }
}
