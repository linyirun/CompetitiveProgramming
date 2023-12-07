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

    set<int> uncalled, called;
    for (int i = 1; i <= n; i++) uncalled.insert(i);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            called.insert(*uncalled.begin());
            uncalled.erase(uncalled.begin());
        } else if (type == 2) {
            int x;
            cin >> x;
            called.erase(x);
        } else {
            cout << *called.begin() << '\n';
        }
    }
}
