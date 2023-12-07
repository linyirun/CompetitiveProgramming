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
        int n;
        cin >> n;

        vector<vector<int>> grid(n, vector<int>(n)), dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                grid[i][j] = (c == '1');
            }
        }

        map<int, int> diag_down_right, diag_down_left;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int curr_par = (diag_down_left[i - j] + diag_down_right[n - i - j]);
                if (i) curr_par += dp[i - 1][j];
                if ((curr_par + grid[i][j])% 2 == 1) {
                    diag_down_left[i - j]++;
                    diag_down_right[n - i - j]++;
                    cnt++;
                    curr_par++;
                }
                dp[i][j] = curr_par;
            }
        }

        cout << cnt << '\n';

    }
}
