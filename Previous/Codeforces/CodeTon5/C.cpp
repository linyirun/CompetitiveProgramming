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
vector<int> a;
vector<vector<int>> dp;

map<int, vector<int>> pos;

int memo(int idx, int can_continue) {
    if (idx == n) return 0;
    if (dp[idx][can_continue] != -1) return dp[idx][can_continue];

//    if (idx == 3 && can_continue == 0) {
//        cout << '1';
//    }
    int curr;
    if (!can_continue) {
        curr = memo(idx + 1, 0);
    } else curr = 1 + memo(idx + 1, 0);

    auto it = upper_bound(pos[a[idx]].begin(), pos[a[idx]].end(), idx);
    if (it != pos[a[idx]].end()) {
        int curr_pos = *it;
        curr = max(curr, curr_pos - idx + memo(curr_pos, 1));
    }
    return dp[idx][can_continue] = curr;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {

        pos.clear();
        cin >> n;
        a = vector<int>(n);
        dp = vector<vector<int>>(n, vector<int>(2, -1));

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        cout << memo(0, 0) << '\n';

//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < 2; j++) {
//                cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << '\n';
//            }
//        }

    }
}
