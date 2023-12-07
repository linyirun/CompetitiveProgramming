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

const int MAX_K = 19;

// BIT
struct BIT {
    vector<int> bit;
    int n;

    BIT(int n) {
        bit.assign(n + 1, 0);
        this->n = n + 1;
    }

    void add(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    void add_single(int idx, int val) {
        range_add(idx, idx, val);
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};

vector<vector<int>> adj;
vector<int> tin, tout, depth;

vector<vector<int>> lift;
int timer = 0;

vector<int> dist;
map<pii, int> edge_w; // storing the edge weights

// Is u an ancestor of v?
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int find_lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = MAX_K - 1; i >= 0; i--) {
        if (!is_ancestor(lift[u][i], v)) {
            u = lift[u][i];
        }
    }
    return lift[u][0];
}

void dfs(int node, int par, int dep, int d) {
    tin[node] = timer++;
    depth[node] = dep;
    lift[node][0] = par;
    dist[node] = d;

    for (int child : adj[node]) {
        if (child != par) dfs(child, node, dep + 1, d + edge_w[{node, child}]);
    }
    tout[node] = timer - 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // 0-based indexing for edges

    vector<pii> edges(n - 1);
    tin = tout = depth = dist = vector<int>(n);
    adj.resize(n + 1);
    lift = vector<vector<int>>(n, vector<int>(MAX_K));

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
        edge_w[{u, v}] = edge_w[{v, u}] = w;
    }

    // Do euler tour, compute depth
    dfs(0, 0, 0, 0);

    // Implementing LCA
    // Binary lifting:
    for (int up = 1; up < MAX_K; up++) {
        for (int node = 0; node < n; node++) {
            lift[node][up] = lift[ lift[node][up - 1] ][up - 1];
        }
    }

    // We need to compute distances
    BIT bit(n + 1);
    for (int i = 0; i < n; i++) {
        bit.add_single(tin[i], dist[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
             int i, w;
             cin >> i >> w;
             i--;

             int u = edges[i].first, v = edges[i].second;
             if (depth[u] > depth[v]) swap(u, v);
             int diff = w - edge_w[{u, v}];
             edge_w[{u, v}] = edge_w[{v, u}] = w;

             // Update the entire range of subtree v
             bit.range_add(tin[v], tout[v], diff);

        } else if (op == 2) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            int lca = find_lca(u, v);
            cout << bit.point_query(tin[u]) + bit.point_query(tin[v]) - 2 * bit.point_query(tin[lca]) << '\n';
        }
    }


}
