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
bool check(vector<vector<char>> &grid, vector<vector<int>> &a) {
    for (int row = 0; row < n; row++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (grid[row][j] == '.') continue;
            if (a[row][j]) cnt++;
            else cnt--;
        }
        if (cnt != 0) return false;
    }

    for (int col = 0; col < m; col++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][col] == '.') continue;
            if (a[i][col]) cnt++;
            else cnt--;
        }
        if (cnt != 0) return false;
    }

    // check valid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'D' && a[i - 1][j] == a[i][j]) return false;
            if (grid[i][j] == 'R' && a[i][j - 1] == a[i][j]) return false;
        }
    }
    return true;
}

vector<int> cnt_row, cnt_col;
void set_col(int i, int j, int col, vector<vector<char>> &grid, vector<vector<int>> &a) {
    if (col == 0) {
        // white
//        grid[i][j] = 'W';
        cnt_row[i]--;
        cnt_col[j]--;
    } else {
//        grid[i][j] = 'B';
        cnt_row[i]++;
        cnt_col[j]++;
    }
    a[i][j] = col;
}

void debug(vector<vector<char>> &grid, vector<vector<int>> &a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') cout << '.';
            else if (a[i][j]) cout << "B";
            else cout << "W";
        }
        cout << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        cin >> n >> m;

        vector<vector<char>> grid(n, vector<char>(m));
        vector<vector<int>> a(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> grid[i][j];
        }

        cnt_row = vector<int>(n);
        cnt_col = vector<int>(m);

        // assign black adds, white subtracts

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L') set_col(i, j, 0, grid, a);
                if (grid[i][j] == 'R') set_col(i, j, 1, grid, a);
                if (grid[i][j] == 'U') {
                    set_col(i, j, 0, grid, a);
                }
                if (grid[i][j] == 'D') {
                    set_col(i, j, 1, grid, a);
                }

            }

        }

        // 1st: swap rows if needed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cnt_row[i] < 0 && grid[i][j] == 'U') {
                    swap(a[i][j], a[i + 1][j]);
                    cnt_row[i] += 2, cnt_row[i + 1] -= 2;
                }
//                cout << i << ", " << j <<": " << '\n';
//                debug(grid, a);
            }
        }

        // 2nd: swap cols if needed
        for (int col = 0; col < m; col++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][col] == 'L') {
                    if (cnt_col[col] < 0) {
                        // need black
                        swap(a[i][col], a[i][col + 1]);
                        cnt_col[col] += 2;
                        cnt_col[col + 1] -= 2;
                    }
                }
            }
        }

//        debug(grid, a);
        if (check(grid, a)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '.') cout << '.';
                    else if (a[i][j]) cout << "B";
                    else cout << "W";
                }
                cout << '\n';
            }
        } else {
            cout << "-1\n";
        }

    }
}

/*
..BW..
WBWW..
BBWBWW
..BWBB
 */
