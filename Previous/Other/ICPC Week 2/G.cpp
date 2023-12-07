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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, INF)));

    for (int i = 0; i < n; i++) {
        dp[0][0][0] = dp[0][0][1] = 0;
    }

    for (int len = 0; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            int j = i + len;
            if (i) {
                dp[i - 1][j][0] = min(dp[i - 1][j][0], dp[i][j][0] + (a[i - 1] != a[i]));
                dp[i - 1][j][0] = min(dp[i - 1][j][0], dp[i][j][1] + (a[i - 1] != a[j]));
            }
            if (j + 1 < n) {
                dp[i][j + 1][1] = min(dp[i][j + 1][0], dp[i][j][0] + (a[j + 1] != a[i]));
                dp[i][j + 1][1] = min(dp[i][j + 1][0], dp[i][j][1] + (a[j + 1] != a[j]));
            }
        }
    }

    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << '\n';
}
