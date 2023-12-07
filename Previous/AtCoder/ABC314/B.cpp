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

    vector<pair<int, vector<int>>> bets(37, {INF, {}});
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            if (bets[x].first == c) {
                bets[x].second.push_back(i);
            } else if (bets[x].first > c) {
                bets[x] = {c, {i}};
            }
        }
    }

    for (auto &v : bets) sort(v.second.begin(), v.second.end());
    int X;
    cin >> X;
    cout << bets[X].second.size() << '\n';
    for (int i : bets[X].second) cout << i + 1 << ' ';
    cout << '\n';
}
