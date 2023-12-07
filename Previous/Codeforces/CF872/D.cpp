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
vector<int> ans, subtree;
int n;
ll dfs1(int node = 1, int par = 1) {
    subtree[node] = 1;
    ll curr_ans = 0;
    for (int child : adj[node]) {
        if (child == par) continue;
        curr_ans += dfs1(child, node) + subtree[child];
        subtree[node] += subtree[child];
    }
    return curr_ans;
}

void dfs2(int node, int par) {
    for (int child : adj[node]) {
        if (child == par) continue;
        ans[child] = ans[node] + n - 2 * subtree[child];
        dfs2(child, node);
    }
}

// binexp
ll binpow(ll base, ll exp) {
    if (exp == 0) return 1;
    ll tmp = binpow(base, exp / 2);
    if (exp % 2 == 1) return (tmp * tmp) % MOD * base % MOD;
    else return (tmp * tmp) % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> n >> k;
    ans = subtree = vector<int>(n + 1);

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (k == 1 || k == 3) {
        cout << "1\n";
        return 0;
    }

    ans[1] = dfs1(1, 1);
    dfs2(1, 1);

    int sum = 0;
    for (int i = 1; i <= n; i++) sum = (sum + ans[i] + n - 1) % MOD;

    int total = (n * n - n) % MOD;
    cout << sum * binpow(total, MOD - 2) % MOD << '\n';

}
