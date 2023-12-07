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

    int n;
    cin >> n;
    vector<int> nxt(n);
    for (int i = 0; i < n; i++) {
        cin >> nxt[i];
        nxt[i]--;
    }

    vector<bool> in_q(n), vis(n), in_cycle(n);

    for (int start_node = 0; start_node < n; start_node++) {
        int curr_node = start_node;
        while (!in_q[curr_node] && !vis[curr_node]) {
            in_q[curr_node] = true;
            curr_node = nxt[curr_node];
        }

        if (!vis[curr_node]) {
            // Everything here is in a cycle
            int tmp = curr_node;
            vis[curr_node] = in_cycle[curr_node] = true;
            curr_node = nxt[curr_node];
            while (curr_node != tmp) {
                vis[curr_node] = in_cycle[curr_node] = true;
                curr_node = nxt[curr_node];
            }
        }

        // Mark everything from start_node as not in a cycle
        curr_node = start_node;
        while (!vis[curr_node]) {
            vis[curr_node] = true;
            curr_node = nxt[curr_node];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += in_cycle[i];
    cout << cnt << '\n';
}
