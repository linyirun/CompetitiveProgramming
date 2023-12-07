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

    const ll SWAP = 1e12;
    const ll DELETE = 1e12 + 1;

    while (tt--) {
        string s;
        cin >> s;
        int n = (int) s.size();

        vector<vector<int>> dp(n, vector<int>(4, INF));
        /* 0: 00
         * 1: 01
         * 2: 11
         * 3: empty
         */

        // Base case:
        if (s[0] == '0') {
            dp[0][0] = 0;
        } else {
            dp[0][1] = dp[0][2] = 0;
        }
        dp[0][3] = DELETE;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                // Delete this character
                dp[i][j] = dp[i - 1][j] + DELETE;
            }

            if (s[i] == '0') {
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + SWAP);
                dp[i][0] = min({dp[i][0], dp[i - 1][0], dp[i - 1][3]});
            } else {
                dp[i][1] = min(dp[i][1], dp[i - 1][0]);
                dp[i][2] = min({dp[i][2], dp[i - 1][1], dp[i - 1][2]});
            }
        }
        int best = INF;
        for (int j = 0; j < 4; j++) {
            best = min(best, dp[n - 1][j]);
        }
        cout << best << '\n';

    }
}
