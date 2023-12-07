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
        map<char, int> mp;
        int mx = 0;
        for (int i = 0; i < 4; i++) {
            char c;
            cin >> c;
            mp[c]++;
            mx = max(mx, mp[c]);
        }
        if (mx == 4) cout << "-1\n";
        else if (mx == 3) cout << "6\n";
        else cout << "4\n";
    }

}
