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

        vector<int> a(n), pos(n + 1, -1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            pos[a[i]] = i;
        }

        int curr_elem = 0, need = 0;
        while (curr_elem != n) {
            if (pos[curr_elem] < pos[curr_elem + 1]) {

            } else need++;
            curr_elem++;
        }

        cout << need - 1 << '\n';

    }
}
