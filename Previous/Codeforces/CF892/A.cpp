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
        int n;
        cin >> n;

        vector<int> a(n), b, c;
        int biggest = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            biggest = max(a[i], biggest);
        }
        for (int i : a) {
            if (i == biggest) c.push_back(i);
            else b.push_back(i);
        }

        if (b.empty()) cout << "-1\n";
        else {
            cout << b.size() << ' ' << c.size() << '\n';
            for (int i : b) cout << i << ' ';
            cout << '\n';
            for (int i : c) cout << i << ' ';
            cout << '\n';
        }
    }
}
