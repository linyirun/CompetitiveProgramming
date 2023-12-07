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

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n)), cpy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            grid[i][j] = (c == '1');
        }
    }
    cpy = grid;

    for (int i = 1; i < n; i++) {
        grid[0][i] = cpy[0][i - 1];
        grid[i][n - 1] = cpy[i - 1][n - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        grid[n - 1][i] = cpy[n - 1][i + 1];
        grid[i][0] = cpy[i + 1][0];
    }

    grid[0][0] = cpy[1][0];
    grid[0][n - 1] = cpy[0][n - 2];
    grid[n - 1][n - 1] = cpy[n - 2][n - 1];
    grid[n - 1][0] = cpy[n - 1][1];

    for (vector<int> &v : grid) {
        for(int i : v) cout << i;
        cout << '\n';
    }
}
