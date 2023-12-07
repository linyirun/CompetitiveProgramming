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
vector<int> st;

int dfs_subtree(int idx) {
    st[idx] = 1;
    for (int child : adj[idx]) {
        st[idx] += dfs_subtree(child);
    }
    return st[idx];
}

int dfs(int node) {
    if (adj[node].empty()) {
        // Leaf node
        return 0;
    }

    int total_sz = 0;
    vector<int> st_sizes;
    int sum = 0;
    for (int child : adj[node]) {
        total_sz += st[child];
        st_sizes.push_back(st[child]);
        sum += dfs(child);
    }

    vector<bool> dp(total_sz + 1);
    dp[0] = true;
    for (int item : st_sizes) {
        for (int i = total_sz; i >= item; i--) {
            dp[i] = dp[i] || dp[i - item];
        }
    }

    int mx = 0;
    for (int i = 0; i <= total_sz; i++) {
        if (dp[i]) {
            mx = max(mx, (total_sz - i) * i);
        }
    }
    return sum + mx;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        int par;
        cin >> par;
        par--;
        adj[par].push_back(i);
    }

    st.resize(n);

    dfs_subtree(0);

    cout << dfs(0) << '\n';


}
