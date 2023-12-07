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

    int n1, n2, m;
    cin >> n1 >> n2 >> m;

    vector<vector<int>> adj(n1 + n2);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n1 + n2, INF);
    queue<int> q;
    q.push(0);
    q.push(n1 + n2 - 1);
    dist[0] = dist[n1 + n2 - 1] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int dest : adj[node]) {
            if (dist[node] + 1 < dist[dest]) {
                dist[dest] = dist[node] + 1;
                q.push(dest);
            }
        }
    }

    int mx_1 = 0, mx_2 = 0;
    for (int i = 0; i < n1; i++) mx_1 = max(mx_1, dist[i]);
    for (int i = n1; i < n1 + n2; i++) mx_2 = max(mx_2, dist[i]);

    cout << mx_1 + mx_2 + 1 << '\n';
}
