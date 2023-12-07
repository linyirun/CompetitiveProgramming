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
        for (int i = 0; i < n; i++) a[i] = i + 1;

        do {
            bool can = true;
            for (int i = 0; i < n; i++) {
                int sum = a[i];
                for (int j = i + 1; j < n; j++) {
                    sum += a[j];
                    if (sum % (j - i + 1) == 0) can = false;
                }
            }

            if (can) {
                for (int i = 0; i < n; i++) {
                    cout << a[i] << ' ';
                } cout << '\n';
            }
        } while (next_permutation(a.begin(), a.end()));
    }
}
