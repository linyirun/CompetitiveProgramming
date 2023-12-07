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

string s = "snuke";
int h, w;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

vector<vector<vector<bool>>> vis;
vector<vector<char>> grid;

bool is_safe(int row, int col) {
    return 0 <= row && row < h && 0 <= col && col < w;
}

void dfs(int row, int col, int idx) {
    vis[row][col][idx] = true;
    for (int i = 0; i < 4; i++) {
        int dest_x = row + dx[i], dest_y = col + dy[i];
        if (is_safe(dest_x, dest_y) && grid[dest_x][dest_y] == s[idx] && !vis[dest_x][dest_y][(idx + 1) % 5]) {
            dfs(dest_x, dest_y, (idx + 1) % 5);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    vis = vector<vector<vector<bool>>>(h, vector<vector<bool>>(w, vector<bool>(5)));
    grid = vector<vector<char>>(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> grid[i][j];
    }

    if (grid[0][0] == 's') dfs(0, 0, 1);

    bool can = false;
    for (int i = 0; i < 5; i++) {
        can |= vis[h - 1][w - 1][i];
    }

    if (can) cout << "Yes\n";
    else cout << "No\n";

}
