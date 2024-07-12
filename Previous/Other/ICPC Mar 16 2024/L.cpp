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

    int n, q;
    cin >> n >> q;

    map<string, string> mp;
    for (int i = 0; i < n; i++) {
        string first, last;
        cin >> first >> last;

        string check;
        check += first[0];
        check += last[0];

        if (mp.find(check) != mp.end()) {
            mp[check] = "ambiguous";
        } else {
            mp[check] = first + ' ' + last;
        }
    }

    while (q--) {
        string inits;
        cin >> inits;

        if (mp.find(inits) == mp.end()) {
            cout << "nobody\n";
        } else {
            cout << mp[inits] << '\n';
        }
    }
}
