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

int n;
vector<vector<int>> adj;
vector<int> dp;

int memo(int msk) {
    if (dp[msk] != -1) return dp[msk];
    int curr_best = 0;
    for (int i = 0; i < n; i++) {
        if ((1 << i) & msk) continue;
        for (int j = i + 1; j < n; j++) {
            if ((1 << j) & msk) continue;
            curr_best = max(curr_best, adj[i][j] + memo(msk | (1 << i) | (1 << j)));
        }
    }
    return dp[msk] = curr_best;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    adj = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cost;
            cin >> cost;
            adj[i][j] = adj[j][i] = cost;
        }
    }

    int MX = 1 << n;
    dp = vector<int>(MX, -1);
    cout << memo(0) << '\n';
}
