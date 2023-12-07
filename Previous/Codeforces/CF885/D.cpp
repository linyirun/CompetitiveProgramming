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
//
//    int n;
//    cin >> n;
//
//    cout << n << '\n';
//    while (n % 10 != 0 && n < 1000) {
//        n += n % 10;
//        cout << n << '\n';
//    }

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;

        int curr = n;
        int best = 0, best_idx = 0;
        for (int i = 0; i <= k; i++) {
            int rem = k - i;
            curr += curr % 10;
//            cout << i << ": " << rem * curr << '\n';
            int res = rem * curr;
            if (res > best) {
                best = res;
                best_idx = i;
            }
        }
        cout << best_idx << ", " << best << '\n';


    }
}
