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

        vector<int> quad(4);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;

            if (x >= 0) quad[0]++;
            if (x <= 0) quad[1]++;
            if (y >= 0) quad[2]++;
            if (y <= 0) quad[3]++;
        }

        bool can = false;
        for (int i = 0; i < 4; i++) {
            if (quad[i] == n) can = true;
        }
        if (can) cout << "YES\n";
        else cout << "NO\n";

    }
}
