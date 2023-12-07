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

// dsu
struct DSU {
    vector<int> par, sz;

    DSU(int n) {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            sz[i] = 1;
            par[i] = i;
        }
    }

    int find_par(int x) {
        if (par[x] == x) return x;
        else return par[x] = find_par(par[x]);
    }

    bool merge(int a, int b) {
        a = find_par(a);
        b = find_par(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
        return true;
    }
};

vector<vector<int>> adj;
vector<pair<pii, int>> edges;
int n, m, k;
int best = LLONG_MAX;

vector<bool> vis;

void dfs(int node) {
    vis[node] = true;
    for (int u : adj[node]) {
        if (!vis[u]) dfs(u);
    }
}

void simulate(int msk) {
    vis = vector<bool>(n);
    adj.clear();
    adj = vector<vector<int>>(n);

    int curr_cost = 0;
    for (int i = 0; i < m; i++) {
        if (msk & (1 << i)) {
            curr_cost += edges[i].second;
            curr_cost %= k;
            int u = edges[i].first.first, v = edges[i].first.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    dfs(0);

    bool done = true;
    for (int i = 0; i < n; i++) done &= vis[i];

    if (done) best = min(best, curr_cost);

}
//set<pii> vis_msk;
void recur(int msk, int pos, DSU dsu, int cost) {

    int left = n - 1 - __builtin_popcount(msk);
//    if (vis_msk.count({msk, pos})) return;
//    vis_msk.insert({msk, pos});
    if (left == 0) {
//        simulate(msk);
        if (dsu.sz[dsu.find_par(0)] == n) {
            best = min(best, cost);
        }
        return;
    }
    if (pos == m) return;

    recur(msk, pos + 1, dsu, cost);
    dsu.merge(edges[pos].first.first, edges[pos].first.second);
    recur(msk | (1 << pos), pos + 1, dsu, (cost + edges[pos].second) % k);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    edges.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges[i] = {{u - 1, v - 1}, cost};
    }

    DSU dsu(n);
    recur(0, 0, dsu, 0);
    cout << best << '\n';
//    cout << cnt << '\n';
}
