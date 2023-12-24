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
        int n;
        cin >> n;

        set<int> l;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            l.insert(-x);
        }

        vector<int> r(n);
        for (int i = 0; i < n; i++) cin >> r[i];
        sort(r.begin(), r.end());

        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        sort(c.begin(), c.end(), greater<int>());

        int total = 0;
        vector<int> ranges;
        for (int rightmost : r) {
            int left = *l.upper_bound(-rightmost);

            ranges.push_back(rightmost + left);

            l.erase(left);
        }
        sort(ranges.begin(), ranges.end());
        for (int i = 0; i < n; i++) total += c[i] * ranges[i];

        cout << total << '\n';
    }
}
