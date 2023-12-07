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

int n, t, m;
vector<pii> edges;
int total = 0;

void recur(int idx, vector<int> col, int mx_col) {
    int ppl_left = n - idx;
    set<int> cols;
    for (int i = 0; i < t; i++) cols.insert(i);
    for (int i = 0; i < idx; i++) cols.erase(col[i]);
    if (ppl_left < cols.size()) return;
    if (idx == n) {
        for (pii &p : edges) {
            if (col[p.first] == col[p.second]) return;
        }
        total++;
        return;
    }
    for (int new_col = 0; new_col <= mx_col; new_col++) {
        col[idx] = new_col;
        recur(idx + 1, col, mx_col);
    }

    if (mx_col != t - 1) {
        col[idx] = mx_col + 1;
        recur(idx + 1, col, mx_col + 1);
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t >> m;
    edges = vector<pii>(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u - 1, v - 1};
    }

    vector<int> col(n);
    recur(0, col, -1);

    cout << total << '\n';
}
