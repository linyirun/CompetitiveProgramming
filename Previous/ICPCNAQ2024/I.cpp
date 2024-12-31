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
bool is_safe(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

int count(int row, int col, vector<vector<char>> &grid) {
    int cnt = 0;

    // Go down
    for (int dest_x = row + 1, dest_y = col; is_safe(dest_x, dest_y); dest_x++) {
        if (grid[dest_x][dest_y] == '?') cnt++;
        if (grid[dest_x][dest_y] != '.') break;
    }
    // Go up
    for (int dest_x = row -1, dest_y = col; is_safe(dest_x, dest_y); dest_x--) {
        if (grid[dest_x][dest_y] == '?') cnt++;
        if (grid[dest_x][dest_y] != '.') break;
    }

    // Go right
    for (int dest_x = row, dest_y = col + 1; is_safe(dest_x, dest_y); dest_y++) {
        if (grid[dest_x][dest_y] == '?') cnt++;
        if (grid[dest_x][dest_y] != '.') break;
    }

    // Go left
    for (int dest_x = row, dest_y = col - 1; is_safe(dest_x, dest_y); dest_y--) {
        if (grid[dest_x][dest_y] == '?') cnt++;
        if (grid[dest_x][dest_y] != '.') break;
    }


    return cnt;
}

int count_adj(int row, int col, vector<vector<char>> &grid) {
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int dest_x = row + dx[i], dest_y = col + dy[i];
        if (!is_safe(dest_x, dest_y)) continue;
        cnt += grid[dest_x][dest_y] == '?';
    }
    return cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    bool can = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '?' && count(i, j, grid) != 0) {
                can = false;
            }
            if (grid[i][j] >= '0' && grid[i][j] <= '4') {
                int need = grid[i][j] - '0';
                if (count_adj(i, j, grid) != need) {
                    can = false;
                }
            }
            if (grid[i][j] == '.' && count(i, j, grid) == 0) {
                can = false;
            }
        }
    }

    if (can) cout << "1\n";
    else cout << "0\n";

}
