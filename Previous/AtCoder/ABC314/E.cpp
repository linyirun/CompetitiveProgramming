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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> points(n);
    vector<int> cost(n), zero(n);

    for (int i = 0; i < n; i++) {
        int c, p;
        cin >> c >> p;
        cost[i] = c;
        for (int j = 0; j < p; j++) {
            int x;
            cin >> x;
            if (x == 0) zero[i]++;
            else points[i].push_back(x);
        }
    }

    vector<ld> dp(m + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        ld curr_best = INT_MAX;
        for (int j = 0; j < n; j++) {
            ld prob = (ld) 1 / (points[j].size() + zero[j]);
            ld curr_sum = cost[j];
            for (int k : points[j]) {
                if (i - k > 0) curr_sum += prob * dp[i - k];
            }
            curr_sum /= (1 - prob * zero[j]);
            curr_best = min(curr_best, curr_sum);
        }
        dp[i] = curr_best;
    }

    cout.precision(10);
    cout << fixed << dp[m] << '\n';


}
