#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

//#pragma comment(linker, "/STACK:1073741824")
#define int ll
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INF = 1e15;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> vis;
int group = 0;

vector<vector<pii>> groups;
vector<int> group_size;
vector<set<pii>> free_sq;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

bool is_safe(int row, int col) {
    return 0 <= row && row < n && 0 <= col && col < m;
}

void dfs(int row, int col) {
    vis[row][col] = true;
    group_size[group]++;
    groups[group].push_back({row, col});

    for (int i = 0; i < 4; i++) {
        int dest_x = row + dx[i], dest_y = col + dy[i];

        if (is_safe(dest_x, dest_y)) {
            if (grid[dest_x][dest_y] == '.') free_sq[group].insert({dest_x, dest_y});
            else if (grid[dest_x][dest_y] == 'W' && !vis[dest_x][dest_y]) dfs(dest_x, dest_y);
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    freopen("a.txt", "r", stdin);
    freopen("a_out.txt", "w", stdout);


    int tt;
    cin >> tt;
    for (int test = 1; test <= tt; test++) {
        cout << "Case #" << test << ": ";
        cin >> n >> m;
        grid = vector<vector<char>>(n, vector<char>(m));
        vis = vector<vector<bool>>(n, vector<bool>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        groups.clear();
        free_sq.clear();
        group_size.clear();
        group = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 'W') {
                    groups.push_back({});
                    free_sq.push_back({});
                    group_size.push_back(0);
                    dfs(i, j);
                    group++;
                }
            }
        }

        map<pii, int> mp;
        for (int i = 0; i < free_sq.size(); i++) {
            set<pii> &s = free_sq[i];
            if (s.size() == 1) {
                mp[*s.begin()] += group_size[i];
            }
        }

        int best = 0;
        for (auto &p : mp) best = max(best, p.second);
        cout << best << '\n';



    }
}
