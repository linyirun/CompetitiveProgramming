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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int available = 1;
        int curr_height = 1;
        int nxt_level = 1;

        for (int i = 2; i < n; i++) {
            if (a[i] > a[i - 1]) {
                // place it on the same node
                nxt_level++;
            } else {
                // have to use another node
                available--;
                // have to go to next level
                if (available == 0) {
                    curr_height++;
                    available = nxt_level;
                    nxt_level = 1;
                } else {
                    nxt_level++;
                }

            }
        }

        cout << curr_height << '\n';
    }
}
