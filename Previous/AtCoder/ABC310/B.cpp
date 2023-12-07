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

    int n, m;
    cin >> n >> m;

    vector<int> price(n), sz(n);
    vector<set<int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i] >> sz[i];
//        v[i] = vector<int>(sz[i]);
        for (int j = 0; j < sz[i]; j++) {
            int x;
            cin >> x;
            v[i].insert(x);
        }
    }

    bool can = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            bool good = true;
            for (int x : v[i]) {
                if (!v[j].count(x)) good = false;
            }

            bool has_extra = false;
            for (int x : v[j]) {
                if (!v[i].count(x)) has_extra = true;
            }
            if (good && price[i] >= price[j] && (price[i] > price[j] || has_extra)) {
                can = true;
            }
        }
    }

    if (can) cout << "Yes\n";
    else cout << "No\n";


}
