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

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> hour(n);
        for (int i = 0; i < n; i++) cin >> hour[i];

        vector<vector<int>> adj(n), par(n);
        vector<int> deg(n), time(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[a].push_back(b);
            deg[b]++;
//            par[b].push_back(a);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                time[i] = hour[i];
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int child : adj[node]) {
                deg[child]--;
                if (deg[child] == 0) q.push(child);
                // Calculate the max time they need to complete the quest
                int curr_time = time[node] % k;
                if (curr_time <= hour[child]) {
                    curr_time = (time[node] / k) * k + hour[child];
                } else curr_time = (time[node] / k + 1) * k + hour[child];
                time[child] = max(time[child], curr_time);
            }
        }

        int best = 0, mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            best = max(best, time[i]);
            mn = min(mn, time[i]);
        }
        cout << best - mn << '\n';
    }
}
