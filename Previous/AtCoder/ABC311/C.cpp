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

vector<int> nxt, curr;
vector<bool> vis;
int cycle_start = -1;

void dfs(int node) {
    vis[node] = true;
    curr.push_back(node);
    if (vis[nxt[node]]) {
        cycle_start = nxt[node];
        return;
    }
    dfs(nxt[node]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    nxt = vector<int>(n);
    vis = vector<bool>(n);
    for (int i = 0; i < n; i++) {
        cin >> nxt[i];
        nxt[i]--;
    }

    dfs(0);
    vector<int> cycle;
    bool found = false;
    for (int i = 0; i < curr.size(); i++) {
        if (curr[i] == cycle_start) found = true;
        if (found) cycle.push_back(curr[i]);
    }

    cout << cycle.size() << '\n';
    for (int i : cycle) cout << i + 1 << ' ';

}
