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

    vector<string> c(n), d(m);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    map<string, int> mp;
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }

    int d0;
    cin >> d0;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        mp[d[i]] = x;
    }

    int total = 0;
    for (string &s : c) {
        if (!mp.count(s)) total += d0;
        else total += mp[s];
    }
    cout << total << '\n';
}
