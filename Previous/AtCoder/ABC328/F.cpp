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

// dsu
struct DSU {
    vector<int> par, sz;

    DSU(int n) {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            sz[i] = 1;
            par[i] = i;
        }
    }

    int find_par(int x) {
        if (par[x] == x) return x;
        else return par[x] = find_par(par[x]);
    }

    int merge(int a, int b) {
        a = find_par(a);
        b = find_par(b);
        if (a == b) {
            cout << "BAD\n";
        }
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
        return b; // returns the smaller group
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> v(n, 0);
    DSU dsu(n);
    vector<vector<int>> group(n);
    for (int i = 0; i < n; i++) group[i].push_back(i);

    vector<int> S;

    for (int i = 0; i < q; i++) {
        int a, b, d;
//        cin >> a >> b >> d;
        a = (rand() + 1) % n;
        b = (rand() + 1) % n;
        d = rand() % (2 * n) - n;
        a--, b--;

        int par_a = dsu.find_par(a);
        int par_b = dsu.find_par(b);

//        for (int j = 0; j < n; j++) cout << "Node " << j << " has group " << dsu.find_par(j) << '\n';

        if (par_a == par_b) {
            // checking consistency
            // we need v[a] - v[b] = d
            if (v[a] - v[b] != d) continue;
        } else {
            // merging trees case
            int smaller = dsu.merge(a, b);

            if (smaller == a) {
                // smaller = a
                // thus, v[a] = v[b] + d
                int offset = v[b] + d - v[a];
                for (int node : group[par_a]) {
                    v[node] += offset;
                    group[par_b].push_back(node);
                }
                if (group[par_b].size() > n) cout << "BAD\n";

            } else {
                // smaller = b
                // thus, v[b] = v[a] - d
                int offset = v[a] - d - v[b];
                for (int node : group[par_b]) {
                    v[node] += offset;
                    group[par_a].push_back(node);
                }
                if (group[par_a].size() > n) cout << "BAD\n";
            }
        }

        S.push_back(i + 1);
    }

//    for (int i : S) cout << i << ' ';
    cout << '\n';
}
