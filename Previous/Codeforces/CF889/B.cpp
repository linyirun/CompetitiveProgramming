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

        int chain = -1, best = 0;
        for (int i = 1; i <= 100; i++) {
            if (n % i == 0) {
                if (chain == -1) chain = 1;
                else chain++;
                best = max(chain, best);
            } else chain = -1;
        }
        cout << best << '\n';
    }
}
