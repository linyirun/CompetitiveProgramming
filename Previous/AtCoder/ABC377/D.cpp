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
    vector<pii> intervals(n);
    set<pii> s;

    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
        s.insert({intervals[i].second, intervals[i].first});
        mx = max(mx, intervals[i].second);
    }
    intervals.push_back({mx, m});
    sort(intervals.begin(), intervals.end());

    int prev_l = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (intervals[i].first != prev_l) {
            int smallest_r = (*s.begin()).first;

            int available = smallest_r - prev_l - 1;
            cnt += available * (available + 1) / 2;
        }

        prev_l = intervals[i].first;
        pii to_erase = {intervals[i].second, intervals[i].first};
        s.erase(to_erase);
    }

    int avail = m - prev_l;
    cnt += avail * (avail + 1) / 2;

    cout << cnt << '\n';
}
