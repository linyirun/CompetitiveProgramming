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

const int MX = 5000000;
//const int MX = 50000;

//int dp[MX][42], nxt[MX][42];
vector<vector<int>> dp(MX, vector<int>(42, -1)), nxt(MX, vector<int>(42, -1));

pair<int, int> memo(int n, int sum_left) {
    if (dp[n][sum_left] != -1) return {dp[n][sum_left], nxt[n][sum_left]};
    if (sum_left == 0) {
        if (n == 1) {
            dp[n][sum_left] = 0;
            return {dp[n][sum_left], nxt[n][sum_left]};
        }
    }

    int curr_best = INT_MAX, val = 0;
    for (int d = 1; d <= sum_left; d++) {
        if (n % d == 0) {
            pii res = memo(n / d, sum_left - d);
            int curr = res.first + 1;
            if (curr < curr_best) {
                curr_best = curr;
                val = d;
            }
        }
    }
    dp[n][sum_left] = curr_best;
    nxt[n][sum_left] = val;
    return {dp[n][sum_left], nxt[n][sum_left]};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("b.txt", "r", stdin);
    freopen("b_out.txt", "w", stdout);

    int tt;
    cin >> tt;



//    for (int sum = 1; sum <= 41; sum++) {
//        dp[1][sum] = sum;
//        nxt[1][sum] = 1;
//    }
// cout << memo(7, 1).first;

    for (int test = 1; test <= tt; test++) {
        cout << "Case #" << test << ": ";
        int n;
        cin >> n;

        if (n >= MX) {
            cout << "-1\n";
            continue;
        }

        int sum = 41, curr = n;
        bool can = true;
        vector<int> ans;
        while (sum != 0) {
            pii p = memo(curr, sum);
            ans.push_back(p.second);
            if (p.second) curr /= p.second;
            sum -= p.second;

            if (ans.size() > 41) {
                can = false;
                break;
            }
        }

        if (!can || curr != 1) cout << "-1\n";
        else {
            cout << ans.size() << ' ';
            for (int i : ans) cout << i << ' ';
            cout << '\n';
        }


    }
}
