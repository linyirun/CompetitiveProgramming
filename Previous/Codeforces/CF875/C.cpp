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

vector<vector<int>> adj;
map<pii, int> mp;
vector<int> dist;

void dfs(int node, int par) {
    for (int dest : adj[node]) {
        if (dest == par) continue;
        if (node && mp[{node, par}] < mp[{node, dest}]) {
            dist[dest] = dist[node];
        } else dist[dest] = dist[node] + 1;
        dfs(dest, node);
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        adj.clear();
        mp.clear();

        adj = vector<vector<int>>(n);
        dist = vector<int>(n);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            mp[{u, v}] = mp[{v, u}] = i;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dist[0] = 0;

        dfs(0, 0);
        int mx = 1;
        for (int d : dist) mx = max(mx, d);
        cout << mx << '\n';
    }
}
