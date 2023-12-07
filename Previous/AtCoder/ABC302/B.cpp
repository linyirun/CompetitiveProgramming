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
bool is_safe(int row, int col) {
    return 0 <= row && row < h && 0 <= col && col < w;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; i++) cin >> grid[i];

    vector<pair<string, vector<pii>>> ans;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            vector<string> s(4);
            vector<vector<pii>> v(4);
            for (int k = 0; k < 5; k++) {
                if (is_safe(i + k, j)) {
                    s[0] += grid[i + k][j];
                    v[0].push_back({i + 1 + k, j + 1});
                }
                if (is_safe(i, j + k)) {
                    s[1] += grid[i][j + k];
                    v[1].push_back({i + 1, j + 1 + k});
                }
                if (is_safe(i + k, j + k)) {
                    s[2] += grid[i + k][j + k];
                    v[2].push_back({i + 1 + k, j + 1 + k});
                }
                if (is_safe(i - k, j + k)) {
                    s[3] += grid[i - k][j + k];
                    v[3].push_back({i + 1 - k, j + 1 + k});
                }
            }
            for (int k = 0; k < 4; k++) ans.push_back({s[k], v[k]});
        }
    }

    string s = "snuke", s_b = "ekuns";

    for (auto p : ans) {
        if (p.first == s) {
            for (auto l : p.second) cout << l.first << ' ' << l.second << '\n';
            return 0;
        }

        if (p.first == s_b) {
            reverse(p.second.begin(), p.second.end());
            for (auto l : p.second) cout << l.first << ' ' << l.second << '\n';
            return 0;
        }
    }

}
