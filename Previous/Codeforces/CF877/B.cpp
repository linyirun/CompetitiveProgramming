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

        vector<int> a(n);
        int pos_1 = 0, pos_2 = 0, pos_n = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) pos_1 = i + 1;
            else if (x == 2) pos_2 = i + 1;
            else if (x == n) pos_n = i + 1;
        }

        if (pos_n < pos_1 && pos_1 < pos_2) cout << pos_1 << ' ' << pos_n;
        else if (pos_n < pos_2 && pos_2 < pos_1) cout << pos_2 << ' ' << pos_n;
        else if (pos_1 < pos_2 && pos_2 < pos_n) cout << pos_2 << ' ' << pos_n;
        else if (pos_2 < pos_1 && pos_1 < pos_n) cout << pos_1 << ' ' << pos_n;
        else cout << "1 1";
        cout << '\n';

    }
}
