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
vector<int> a, b;

vector<vector<int>> dp;

int memo(int i, int j) {
    if (i >= n || j >= m) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    // Match this
    int diff = abs(a[i] - b[j]);
    int points = 0;
    if (diff <= 15) points = 7;
    else if (diff <= 23) points = 6;
    else if (diff <= 43) points = 4;
    else if (diff <= 102) points = 2;

    return dp[i][j] = max({points + memo(i + 1, j + 1), memo(i + 1, j), memo(i, j + 1)});
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a = vector<int>(n);
    b = vector<int>(m);
    dp = vector<vector<int>>(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << memo(0, 0) << '\n';

}
