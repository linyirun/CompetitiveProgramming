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


int n, m;
vector<string> strs;
vector<vector<vector<int>>> pref;

map<char, int> mp;
vector<char> ch_order = {'n', 'a', 'r', 'e', 'k'};

bool check(char c) {
    return c == 'n' || c == 'a' || c == 'r' || c == 'e' || c == 'k';
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    mp['n'] = 0;
    mp['a'] = 1;
    mp['r'] = 2;
    mp['e'] = 3;
    mp['k'] = 4;

    int tt;
    cin >> tt;

    while (tt--) {
        cin >> n >> m;

        strs = vector<string>(n);
        for (int i = 0; i < n; i++) {
            cin >> strs[i];
        }

        pref = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(5)));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check(strs[i][j])) {
                    pref[i][j][mp[strs[i][j]]]++;
                }
                for (int k = 0; k < 5; k++) {
                    if (j) pref[i][j][k] += pref[i][j - 1][k];
                }
            }
        }


        vector<vector<int>> dp(n + 1, vector<int>(5, INT_MIN));
        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                int curr_ch = j;
                if (dp[i][j] <= INT_MIN) continue;
                // Don't take this string
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);


                // Take this string - calculate for all possible ending characters
                int curr_score = dp[i][j];
                for (int pos = 0; pos < m; pos++) {
                    if (strs[i][pos] == ch_order[curr_ch]) {
                        curr_ch++;
                        if (curr_ch == 5) {
                            curr_ch = 0;
                            curr_score += 5;
                        }
                        // Calculate the score given all the untaken characters
                        int untaken_score = 0;
                        for (int k = 0; k < 5; k++) {
                            untaken_score += pref[i][m - 1][k] - pref[i][pos][k];
                        }

                        dp[i + 1][curr_ch] = max(dp[i + 1][curr_ch], curr_score - untaken_score);
                    } else if (check(strs[i][pos])) {
                        curr_score--;
                    }
                }


            }
        }

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int k = 0; k < 5; k++) {
                ans = max(ans, dp[i][k] - k);
            }
        }
        cout << ans << '\n';
    }
}
