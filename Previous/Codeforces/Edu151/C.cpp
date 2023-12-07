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

string s;
int m, n;
vector<pii> bounds;
vector<vector<int>> nxt;
bool can = false;

vector<vector<int>> vis;

void dfs(int char_idx, int subseq_idx) {
    if (subseq_idx >= n + 1) can = true;
    if (char_idx == m || subseq_idx >= n + 1) return;
    vis[char_idx][subseq_idx] = true;

    for (int possible = bounds[char_idx].first; possible <= bounds[char_idx].second; possible++) {
        int next_idx = nxt[subseq_idx][possible];
        if (!vis[char_idx + 1][next_idx + 1]) dfs(char_idx + 1, next_idx + 1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        cin >> s >> m;
        bounds = vector<pii>(m);
        n = s.size();
        can = false;
        string l, r;
        cin >> l >> r;
        for (int i = 0; i < m; i++) {
            bounds[i] = {l[i] - '0', r[i] - '0'};
        }
        nxt = vector<vector<int>>(n + 10, vector<int>(10, n)); // inclusive as well

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 10; j++) {
                if (s[i] - '0' == j) nxt[i][j] = i;
                else nxt[i][j] = nxt[i + 1][j];
            }
        }

        vis = vector<vector<int>>(m + 1, vector<int>(n + 10, false));
        dfs(0, 0);
        if (can) cout << "YES\n";
        else cout << "NO\n";
    }
}
