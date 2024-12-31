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

vector<int> dp;
vector<vector<int>> adj;
vector<int> deg;
vector<bool> has_leaf_neighbor;
int total = 0;

int dfs1(int node, int par) {
    if (!has_leaf_neighbor[node]) dp[node]++;
    for (int u : adj[node]) {
        if (u != par) {
            dp[node] += dfs1(u, node);
        }
    }
    return dp[node];
}

void reroot(int node, int par) {
    if (node == 11) {
        cout << "hi\n";
    }
    if (has_leaf_neighbor[node]) {
        // Can contribute to the total

//        int num_non_winning = 0;
        int sum_dp = 0;
        for (int u : adj[node]) {
            sum_dp += dp[u];
        }
        for (int u : adj[node]) {
            total += sum_dp - dp[u];
        }

//        total += num_non_winning * sum_dp - sum_dp;
    }

    // Reroot
    for (int v : adj[node]) {
        if (v != par) {
            dp[node] -= dp[v];
            reroot(v, node);
            dp[node] += dp[v];
        }
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

        total = 0;
        dp = vector<int>(n);
        adj.clear();
        adj = vector<vector<int>>(n);
        deg = vector<int>(n);
        has_leaf_neighbor = vector<bool>(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            deg[u]++;
            deg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int num_leaves = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) num_leaves++;
            for (int u : adj[i]) {
                if (deg[u] == 1 || deg[i] == 1) has_leaf_neighbor[i] = true;
            }
        }

        dfs1(0, 0);
        reroot(0, 0);


        cout << total + num_leaves * (n - num_leaves) << '\n';
    }
}
