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
        int n, x;
        cin >> n >> x;

        vector<pii> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        multiset<int> s;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            b[i] = num;
            s.insert(num);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> ans(n);

        bool can = true;

        // first x elements, need a[n - i - 1] > b[n - i - 1]
        int cnt = 0;
        for (int i = n - 1; i >= n - x; i--) {
            int num = b[x - cnt - 1];

            if (num >= a[i].first) {
                can = false;
                break;
            } else {
                ans[a[i].second] = num;
                s.erase(s.find(num));
            }
            cnt++;
        }

        for (int i = n - x - 1; i >= 0; i--) {
            auto it = s.lower_bound(a[i].first);

            if (it == s.end()) {
                can = false;
                break;
            } else {
                ans[a[i].second] = *it;
                s.erase(it);
            }
        }

        if (can) {
            cout << "YES\n";
            for (int i : ans) cout << i << ' ';
            cout << '\n';

        } else {
            cout << "NO\n";
        }
    }
}
