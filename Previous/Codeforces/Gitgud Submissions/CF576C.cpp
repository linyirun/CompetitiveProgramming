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

ll count_ways(int n);

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;

        vector<pii> edges(m);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges[i] = {u, v};
        }

        vector<bool> vis(3 * n);
        vector<int> taken_edges;
        for (int i = 0; i < m; i++) {
            int u = edges[i].first, v = edges[i].second;
            if (!vis[u] && !vis[v]) {
                taken_edges.push_back(i);
                vis[u] = vis[v] = true;
            }
        }

        if (taken_edges.size() >= n) {
            cout << "Matching\n";
        } else {
            cout << "IndSet\n";
            taken_edges.clear();
            int taken = 0;
            for (int i = 0; i < 3 * n; i++) {
                if (taken == n || vis[i]) continue;
                taken_edges.push_back(i);
                taken++;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << taken_edges[i] + 1 << ' ';
        }
        cout << '\n';
    }

}



