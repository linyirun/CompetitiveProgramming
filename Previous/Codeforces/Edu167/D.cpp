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
    vector<int> a, diff;
    vector<int> b(n);
    a = diff = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pii> srt(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        diff[i] = a[i] - b[i];
        srt[i] = {a[i], diff[i]};
    }

    sort(srt.begin(), srt.end());

    // Create new array based off marked
    vector<int> new_a, new_diff;
    int best_diff = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (srt[i].second < best_diff) {
            best_diff = srt[i].second;
            new_a.push_back(srt[i].first);
            new_diff.push_back(srt[i].second);
        }
    }

    a = new_a;
    diff = new_diff;
    n = a.size();
    // a is strictly decreasing
    // diff should be strictly increasing

    int tot = 0;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        int rem = max(0LL, (k - a[n - 1]) / diff[n - 1]);
        tot += rem * 2;
        k -= rem * diff[n - 1];

        auto up_bd = upper_bound(a.begin(), a.end(), k);
        while (up_bd != a.begin()) {
            up_bd--;
            int pos = up_bd - a.begin();
            tot += 2;
            k -= diff[pos];
            up_bd = upper_bound(a.begin(), a.end(), k);
        }


    }

    cout << tot << '\n';


}
