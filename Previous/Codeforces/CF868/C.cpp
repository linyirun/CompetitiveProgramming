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

void fac(int n, map<int, int> &mp) {
    while (n > 1) {
        bool found = false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                mp[i]++;
                n /= i;
                found = true;
                break;
            }
        }
        if (!found) break;
    }
    if (n > 1) mp[n]++;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            fac(x, mp);
        }

        int odd = 0, total = 0;
        for (pii p : mp) {
            odd += p.second % 2;
            total += p.second / 2;
        }

        cout << total + odd / 3 << '\n';

    }
}
