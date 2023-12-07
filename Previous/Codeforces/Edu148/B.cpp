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

        vector<int> a(n), pref(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            pref[i] = a[i];
            if (i) pref[i] += pref[i - 1];
        }

        int best = 0;
        for (int take = 0; take <= k; take++) {
            if (take) sum -= a[n - take];

            int left = (k - take) * 2 - 1;
            int tmp = 0;
            if (left >= 0) tmp = pref[left];

            best = max(best, sum - tmp);
        }

        cout << best << '\n';

    }
}
