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
        int h, w;
        cin >> w >> h;
        int best = 0;
        for (int i = 0; i < 4; i++) {
            int k;
            cin >> k;
            int mn = INT_MAX, mx = INT_MIN;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                mn = min(x, mn);
                mx = max(x, mx);
            }

            int mult = h;
            if (i >= 2) mult = w;
            best = max(best, (mx - mn) * mult);
        }

        cout << best << '\n';
    }
}
