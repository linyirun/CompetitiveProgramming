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

    int n, h, c;
    cin >> n >> h >> c;

    vector<vector<int>> a(n, vector<int>(h)), pref(n, vector<int>(h));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        for (int j = 0; j < h; j++) {
            pref[i][j] = a[i][j];
            if (j) pref[i][j] += pref[i][j - 1];
        }
    }
    int best = 0;
    for (int l = 0; l < h; l++) {
        int left = c;
        int cheapest_pref = LLONG_MAX, cheapest_idx = -1;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (pref[i][l] < cheapest_pref ||
            (pref[i][l] == cheapest_pref && a[i][l] < a[cheapest_idx][l])) {
                cheapest_pref = pref[i][l];
                cheapest_idx = i;
            }
        }

        left -= cheapest_pref;
        curr = l + 1;

        // Buy l - 1 from everyone else
        vector<int> can_buy;
        for (int i = 0; i < n; i++) {
            if (i != cheapest_idx) {
                if (l) left -= pref[i][l - 1];
                can_buy.push_back(a[i][l]);
            }
        }

        curr += l * (n - 1);

        if (left < 0) break;
        int cnt = 0;
        // We have money left, just greedily buy
        sort(can_buy.begin(), can_buy.end());
        for (int item : can_buy) {
            if (item <= left) {
                curr++;
                left -= item;
            } else break;
        }

        best = max(best, curr);

    }
    cout << best << '\n';


}
