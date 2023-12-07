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

    int n, q;
    cin >> n >> q;

    int ans = n;
    vector<set<int>> adj(n + 1);

    while (q--) {
        int op;
        cin >> op;
        if (op == 2) {
            int u;
            cin >> u;
            for (int v : adj[u]) {
                adj[v].erase(u);
                if (adj[v].empty()) ans++;
            }
            if (!adj[u].empty()) ans++;
            adj[u].clear();
        } else {
            int u, v;
            cin >> u >> v;
            if (adj[u].empty()) ans--;
            if (adj[v].empty()) ans--;

            adj[u].insert(v);
            adj[v].insert(u);
        }

        cout << ans << '\n';
    }
}
