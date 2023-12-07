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
vector<pii> bounds;
vector<vector<vector<int>>> dp;

int f(int i, int p1, int p2) {
    if (dp[i][p1][p2] != -1) return dp[i][p1][p2];
//    cout << "reached (" << i << ", " << p1 << ", " << p2 << '\n';
    int best = max(f(i + 1, p1, p2), f(i + 1, 0, 0));

//    if (i == 3 && p1 == 2 && p2 == 1) {
//        cout << "here" << '\n';
//    }

    // check that i can join the current team
    int l = max({bounds[i].first, bounds[p1].first, bounds[p2].first}), r = min({bounds[i].second, bounds[p1].second, bounds[p2].second});

    if ((l <= i && i <= r) && ((l <= p1 && p1 <= r) || !p1) && ((l <= p2 && p2 <= r) || !p2)) {
        best = max({best, f(i + 1, i, p1), f(i + 1, i, p2)});
        if (p1 != 0 && p2 != 0) {
            best = max(best, 1 + f(i + 1, 0, 0));
        }
    }
    return dp[i][p1][p2] = best;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    bounds = vector<pii>(n + 1);
    bounds[0] = {0, n + 1};

    dp = vector<vector<vector<int>>>(n + 2, vector<vector<int>>(n + 2, vector<int>(n + 2, -1)));
    for (int p1 = 0; p1 <= n; p1++) {
        for (int p2 = 0; p2 <= n; p2++) {
            dp[n + 1][p1][p2] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> bounds[i].first >> bounds[i].second;
    }

    cout << f(1, 0, 0) << '\n';

}
/*
6
1 3
1 3
2 3
4 6
5 6
5 6
 */
