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
vector<int> a, depth;
map<pii, int> dp;

void dfs(int node, int dep) {
    depth[node] = dep;
    for (int child : adj[node]) {
        if (depth[child] > depth[node]) {
            dfs(child, dep + 1);
        }
    }
}

int calc(int u, int v) {
    if (dp.count({u, v})) return dp[{u, v}];
    int ans = a[u] * a[v];
    return dp[{u, v}] = ans + calc(par[u], par[v]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    a = vector<int>(n + 1);
    depth = vector<int>(n + 1, n + 10);
    adj = vector<vector<int>>(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dp[{0, 0}] = 0;
    while (q--) {
        int u, v;
        cin >> u >> v;

        cout << calc(u, v) << '\n';
    }
}
