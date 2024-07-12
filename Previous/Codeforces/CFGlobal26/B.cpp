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
        string s;
        cin >> s;
        bool can = true;
        for (int i = 1; i + 1 < s.size(); i++) {
            if (s[i] == '0') can = false;
        }
        if (can && s[0] == '1' && s[s.size() - 1] != '9') {
            cout << "YES\n";
        } else cout << "NO\n";

    }
}
