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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        // {-val, ind}
        set<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= k;
            if (a[i] == 0) a[i] = k;
            s.insert({-a[i], i});
        }

        vector<int> order;
        while (!s.empty()) {
            auto p = *s.begin();
            s.erase(s.begin());
            order.push_back(p.second + 1);
        }
        for (int i : order) cout << i << ' ';
        cout << '\n';


    }
}
