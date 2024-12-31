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
    const int MX = 25;

    while (tt--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;

        int x = 0, y = 0;
        bool found = (x == a) && (y == b);

        for (int i = 0; i < 25; i++) {
            for (char c: s) {
                if (c == 'N') y += 1;
                else if (c == 'E') x += 1;
                else if (c == 'S') y -= 1;
                else x -= 1;

                if (x == a && y == b) {
                    found = true;
                    break;
                }
            }
        }
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }

}
