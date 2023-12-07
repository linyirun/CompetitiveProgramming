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

    int n, a, b;
    cin >> n >> a >> b;

    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    vector<int> possible;
    for (int i = 1; i <= 50; i++) {
        if (min(mn, i) == a && max(mx, i) == b) {
            possible.push_back(i);
        }
    }

    if (possible.empty()) cout << "-1\n";
    else {
        for (int i : possible) cout << i << '\n';
    }
}
