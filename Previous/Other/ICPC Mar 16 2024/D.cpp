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
int total = 0;
bool check(vector<vector<char>> &grid) {
    // check for a row/col
    for (int i = 0; i < n; i++) {
        bool good_row = true;
        bool good_col = true;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 'X') good_row = false;
            if (grid[j][i] != 'X') good_col = false;
        }

        if (good_row || good_col) return true;
    }

    // check diagonals
    bool left_diag = true, right_diag = true;
    for (int i = 0; i < n; i++) {
        if (grid[i][i] != 'X') left_diag = false;
        if (grid[i][n - i - 1] != 'X') right_diag = false;
    }

    if (left_diag || right_diag) return true;

    return false;
}

void recur(int row, int col, vector<vector<char>> &grid) {
    if (row == n) {
        total += check(grid);
        return;
    }

    int next_row = row, next_col = col + 1;
    if (col == n) {
        next_col = 0;
        next_row++;
    }

    // Go next
    recur(next_row, next_col, grid);

    if (grid[row][col] == '.') {
        grid[row][col] = 'X';
        recur(next_row, next_col, grid);
        grid[row][col] = '.';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
//            cin >> grid[i][j];
            grid[i][j] = '.';
        }
    }

    recur(0, 0, grid);
    cout << total << '\n';

}
