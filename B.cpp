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

        vector<pii> a(n);
        vector<int> cnt(2 * n + 1);

        set<int> mex;
        for (int i = 1; i <= 2 * n; i++) {
            mex.insert(i);
        }

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            a[i] = {l, r};
            if (l == r) {
                mex.erase(l);
                cnt[l]++;
            }
        }

        for (int i = 0; i < n; i++) {
            int l = a[i].first, r = a[i].second;
            if (l == r) {
                if (cnt[l] == 1) {
                    cout << '1';
                } else cout << '0';
            } else {
                auto it = mex.lower_bound(l);
                int val = INF;

                if (it != mex.end()) val = *it;
                if (val > r) {
                    cout << '0';
                } else cout << '1';
            }
        }
        cout << '\n';
    }
}
