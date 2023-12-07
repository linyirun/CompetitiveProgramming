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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int _ = 0; _ < 100; _++) {
        // testing k = 3
        set<int> chosen;
        while (chosen.size() < k) {
            int c = rand() % n + 1;
            if (!chosen.count(c)) chosen.insert(c);
        }

        int cnt = 0, mn_dist = INF;
        for (int i = 1; i <= n; i++) {
            vector<int> dist(n + 1, INF);
            dist[i] = 0;
            int total = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int u: adj[node]) {
                    if (dist[u] > dist[node] + 1) {
                        dist[u] = dist[node] + 1;
                        q.push(u);
                    }
                }
            }

            for (int node: chosen) total += dist[node];
            if (total < mn_dist) {
                cnt = 1;
                mn_dist = total;
            } else if (total == mn_dist) cnt++;
        }

        cout << cnt << '\n';
    }
}

/*
7 3
1 2
1 3
1 4
1 5
1 6
1 7

 */