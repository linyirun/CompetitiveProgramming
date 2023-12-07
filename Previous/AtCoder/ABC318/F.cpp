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

    int n;
    cin >> n;

    vector<int> x(n), l(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> l[i];
    sort(l.begin(), l.end());

    set<int> important;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            important.insert(x[i] - l[i]);
            important.insert(x[i] + l[i]);
        }
    }

    vector<int> points;
    for (int i : important) points.push_back(i);

    int total = 0;
    int curr_pos = -3e18;
    while (true) {
        

        vector<int> d(n);
        for (int j = 0; j < n; j++) d[j] = abs(x[j] - curr_pos);
        sort(d.begin(), d.end());
        bool can = true;
        for (int j = 0; j < n; j++) {
            if (d[j] > l[j]) can = false;
        }

        if (can) total += sz;
    }
    cout << total << '\n';
}
