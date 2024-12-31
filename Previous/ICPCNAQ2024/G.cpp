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

    map<int, vector<int>> mp;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        mp[a].push_back(b);
    }

    ld total = 0;
    for (auto &p : mp) {
        vector<int> v = p.second;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() / 2; i++) {
            total += log(v[v.size() - i - 1]) - log(v[i]);
        }
    }
    cout.precision(10);
    cout << fixed << total << '\n';
}
