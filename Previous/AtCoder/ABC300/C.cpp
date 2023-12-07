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
vector<vector<char>> grid;

bool is_safe(int row, int col) {
    return 0 <= row && row < h && 0 <= col && col < w;
}

int cross_size(int row, int col) {
    if (grid[row][col] == '.') return 0;
    int sz = 0;
    for (int i = 1; i <= min(h, w); i++) {
        if (!is_safe(row + i, col + i) || grid[row + i][col + i] == '.') break;
        if (!is_safe(row - i, col + i) || grid[row - i][col + i] == '.') break;
        if (!is_safe(row + i, col - i) || grid[row + i][col - i] == '.') break;
        if (!is_safe(row - i, col - i) || grid[row - i][col - i] == '.') break;
        sz = i;
    }
    return sz;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    grid = vector<vector<char>>(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> grid[i][j];
    }

    vector<int> sizes(min(h, w) + 1);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            sizes[cross_size(i, j)]++;
        }
    }

    for (int i = 1; i <= min(h, w); i++) {
        cout << sizes[i] << ' ';
    }
}
