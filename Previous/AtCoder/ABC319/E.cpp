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

    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n), t(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> p[i] >> t[i];
    }

    int LCM = 840;
    vector<vector<int>> dp(n, vector<int>(LCM));
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < LCM; j++) {
            int wait = p[i] - (j % p[i]);
            if (j % p[i] == 0) wait = 0;
            dp[i][j] = wait + t[i] + dp[i + 1][(j + wait + t[i]) % LCM];
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;

        cout << dp[0][(q + x) % LCM] + x + y + q << '\n';
    }
}
