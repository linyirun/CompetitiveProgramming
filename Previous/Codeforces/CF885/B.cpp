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

        vector<vector<int>> ind(k, vector<int>());
        for (int i = 0; i < k; i++) ind[i].push_back(-1);
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            ind[c - 1].push_back(i);
        }
        for (int i = 0; i < k; i++) ind[i].push_back(n);
        vector<multiset<int>> gaps(k);
        int best = n;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j + 1 < ind[i].size(); j++) {
                gaps[i].insert(ind[i][j + 1] - ind[i][j]);
            }

            int biggest = *(--gaps[i].end());
            gaps[i].erase(gaps[i].find(biggest));
            gaps[i].insert((biggest + 1) / 2);
            int curr_biggest = *(--gaps[i].end());
            best = min(best, curr_biggest);
        }

        cout << best - 1 << '\n';
    }
}
