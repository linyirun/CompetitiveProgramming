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
int n, m, k;
int cnt = 0;

int cnt_range(vector<int> &v, int l, int r) {
    int top_ptr = upper_bound(v.begin(), v.end(), r) - v.begin();
    top_ptr--;
    int low_ptr = lower_bound(v.begin(), v.end(), l) - v.begin();
    return max(0LL, top_ptr - low_ptr + 1);
}

// Both vertical and horizontal are sorted
int compute(vector<int> vertical, vector<int> horizontal, vector<pii> points) {
    vector<int> pref(cnt + 1); // Prefix for vertical

    vector<vector<int>> column_count(cnt + 1);
    for (pii &p : points) {
        pref[p.second]++;
        column_count[p.first].push_back(p.second);
    }

    for (vector<int> &v : column_count) sort(v.begin(), v.end());

    for (int i = 1; i <= cnt; i++) pref[i] += pref[i - 1];
    int total = 0;

    for (int i = 0; i < k; i++) {
        int x = points[i].first, y = points[i].second;
        auto it = lower_bound(horizontal.begin(), horizontal.end(), y);
        auto it2 = lower_bound(vertical.begin(), vertical.end(), x);
        // This needs to be on a vertical line and not intersect horizontal
        if (it != horizontal.end() && *it == y || (it2 == vertical.end() || *it2 != x)) continue;

        int top_bound_ptr = upper_bound(horizontal.begin(), horizontal.end(), y) - horizontal.begin();
        int top_bound = horizontal[top_bound_ptr];
        int low_bound = horizontal[top_bound_ptr - 1];

        if (top_bound) total += pref[top_bound - 1];
        total -= pref[low_bound];

        total -= cnt_range(column_count[x], low_bound + 1, top_bound - 1);
    }
    return total;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        cin >> n >> m >> k;
        cnt = 0;
        set<int> important;
        vector<int> vertical(n), horizontal(m);
        vector<pii> points(k);

        for (int i = 0; i < n; i++) {
            cin >> vertical[i];
            important.insert(vertical[i]);
        }
        for (int i = 0; i < m; i++) {
            cin >> horizontal[i];
            important.insert(horizontal[i]);
        }

        // Read points
        for (int i = 0; i < k; i++) {
            cin >> points[i].first >> points[i].second;
            important.insert(points[i].first);
            important.insert(points[i].second);
        }

        // Coordinate compress both
        map<int, int> mp;
        for (int i : important) {
            mp[i] = cnt++;
        }

        // Compress
        for (int &i : vertical) i = mp[i];
        for (int &i : horizontal) i = mp[i];
        for (pii &p : points) {
            p.first = mp[p.first];
            p.second = mp[p.second];
        }

        int total = compute(vertical, horizontal, points);
        // flip
        for (int i = 0; i < k; i++) {
            swap(points[i].first, points[i].second);
        }

        swap(n, m);
        total += compute(horizontal, vertical, points);

        cout << total / 2 << '\n';
    }
}

/*
 *
1
2 3 3
0 10
0 5 10
0 6
10 6
10 7

2
2 2 4
0 10
0 10
1 0
10 1
9 10
0 9
 */