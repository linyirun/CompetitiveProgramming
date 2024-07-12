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

vector<vector<pii>> adj;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    int H, E;
    cin >> n >> m >> k >> H >> E;
    H--, E--;
    adj.resize(n);

    map<pii, int> edges;

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--, v--;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});

        edges[{u, v}] = edges[{v, u}] = cost;
    }

    vector<int> tornado_path(k);

    map<pii, int> unstable_time;
    int curr_time_taken = 0;
    for (int i = 0; i < k; i++) {
        cin >> tornado_path[i];
        tornado_path[i]--;

        if (i) {
            pii edge = {tornado_path[i - 1], tornado_path[i]};
            pii backward_edge = {tornado_path[i], tornado_path[i - 1]};
            unstable_time[edge] = unstable_time[backward_edge] = curr_time_taken;
            curr_time_taken += edges[edge];
        }
    }

    vector<int> dist(n, INF);
    dist[H] = 0;
    // Dijkstra
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, H});

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        for (pii curr_edge : adj[node]) {
            int dest = curr_edge.first;
            int edge_cost = curr_edge.second;
            pii edge = {node, dest};
            bool can_take;
            if (unstable_time.find(edge) == unstable_time.end()) can_take = true;
            else can_take = dist[node] + edge_cost <= unstable_time[edge];

            if (can_take && dist[node] + edge_cost < dist[dest]) {
                dist[dest] = dist[node] + edge_cost;
                pq.push({dist[dest], dest});
            }
        }
    }

    if (dist[E] == INF) {
        cout << "-1\n";
    } else cout << dist[E] << '\n';
}
