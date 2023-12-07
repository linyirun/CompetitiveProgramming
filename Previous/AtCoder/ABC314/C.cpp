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

    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<vector<int>> pos(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x - 1].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        if (pos[i].empty()) continue;
        char last_char = s[pos[i][pos[i].size() - 1]];
        for (int j = pos[i].size() - 1; j >= 1; j--) {
            s[pos[i][j]] = s[pos[i][j - 1]];
        }
        s[pos[i][0]] = last_char;
    }
    cout << s << '\n';
}
