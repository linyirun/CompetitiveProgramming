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
int h, w;

vector<vector<char>> apply(vector<vector<char>> grid, int row_op, int col_op) {
    for (int it = 0; it < col_op; it++) {
        for (int i = 0; i < h; i++) {
            char tmp = grid[i][0];
            for (int j = 0; j < w - 1; j++) {
                grid[i][j] = grid[i][j + 1];
            }
            grid[i][w - 1] = tmp;
        }
    }

    for (int it = 0; it < row_op; it++) {
        for (int col = 0; col < w; col++) {
            char tmp = grid[0][col];
            for (int row = 0; row < h - 1; row++) {
                grid[row][col] = grid[row + 1][col];
            }
            grid[h - 1][col] = tmp;
        }
    }
    return grid;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w)), b(h, vector<char>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> a[i][j];
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> b[i][j];
    }
    bool can = false;
    for (int row_op = 0; row_op < h; row_op++) {
        for (int col_op = 0; col_op < w; col_op++) {
            if (apply(a, row_op, col_op) == b) {
                can = true;
                break;
            }
        }
    }

    if (can) cout << "Yes\n";
    else cout << "No\n";
}
