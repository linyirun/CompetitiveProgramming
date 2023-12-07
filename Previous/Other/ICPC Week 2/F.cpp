#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

#define int ll
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INF = 2e18;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        vector<int> a(n), cost(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> cost[i];

        vector<vector<int>> dp(n, vector<int>(3, INF));
        dp[0][0] = 0, dp[0][1] = cost[0], dp[0][2] = 2 * cost[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int prev_j = 0; prev_j < 3; prev_j++) {
                    if (a[i] + j != a[i - 1] + prev_j) {
                        dp[i][j] = min(dp[i][j], cost[i] * j + dp[i - 1][prev_j]);
                    }
                }
            }
        }
        cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
    }
}
