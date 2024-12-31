#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>

//#define int ll
//const int MOD = 998244353;
const int MOD = 1000000007;
//const int INF = 1e15;



using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) continue;
            int best = i * j;
            for (int k = 1; k < i; k++) best = min(best, dp[k][j] + dp[i - k][j] + 1);
            for (int k = 1; k < j; k++) best = min(best, dp[i][k] + dp[i][j - k] + 1);
            dp[i][j] = best;
        }
    }
    cout << dp[n][m] << '\n';


}
