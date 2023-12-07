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

        set<char> set;
        for (int i = 0; i < s.size(); i++) {
            if (s.size() % 2 == 1 && i == s.size() / 2) continue;
            set.insert(s[i]);
        }

        if (set.size() > 1) cout << "YES\n";
        else cout << "NO\n";
    }
}
