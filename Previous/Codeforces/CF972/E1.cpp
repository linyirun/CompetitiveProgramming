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

int l, n, m;

bool is_valid(int r, int c, int k) {
    return r >= 0 && r < n && c >= 0 && c < m && k < l;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {

        cin >> l >> n >> m;

        vector<int> a(l);
        for (int i = 0; i < l; i++) cin >> a[i];

        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> b[i][j];
            }
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(l)));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int k = l - 1; k >= 0; k--) {
                    if (b[i][j] == a[k]) {
                        if (!is_valid(i + 1, j + 1, k + 1)) {
                            // We win
                            dp[i][j][k] = true;
                        } else {
                            dp[i][j][k] = !dp[i + 1][j + 1][k + 1];
                        }
                    }

                    if (is_valid(i + 1, j, k)) {
                        dp[i][j][k] |= dp[i + 1][j][k];
                    }
                    if (is_valid(i, j + 1, k)) {
                        dp[i][j][k] |= dp[i][j + 1][k];
                    }
                }
            }
        }

        if (dp[0][0][0]) {
            cout << "T\n";
        } else cout << "N\n";
    }
}
