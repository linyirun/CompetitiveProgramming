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
vector<bool> has;
vector<int> days;

void dfs(int node, int num) {
    num = max(num, days[node]);
    if (num > 0) has[node] = true;

    for (int i : adj[node]) {
        dfs(i, max(num - 1, days[node]));
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    has = vector<bool>(n);
    days = vector<int>(n);

    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int x, d;
        cin >> x >> d;
        x--;
        days[x] = max(days[x], d);
    }

    dfs(0, 0);

    int total = 0;
    for (int i = 0; i < n; i++) total += has[i];
    cout << total << '\n';

}
