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

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        bool found = false;
        for (int cnt_truth = 0; cnt_truth <= n; cnt_truth++) {
            int cnt_liars = n - cnt_truth;
            bool can = true;
            for (int i = 0; i < n; i++) {
                if (i < cnt_truth && cnt_liars < a[i]) can = false;
                if (i >= cnt_truth && cnt_liars >= a[i]) can = false;
            }
            if (can) {
                found = true;
                cout << cnt_liars << '\n';
                break;
            }
        }
        if (!found) cout << "-1\n";
    }
}
