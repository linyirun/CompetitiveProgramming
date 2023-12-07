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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        string s1, s2;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) s1 += s[i];
            else s2 += s[i];
        }

        if (k % 2 == 1) {
            string res;
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) res += s1[i / 2];
                else res += s2[i / 2];
            }
            cout << res << '\n';
        } else {
            sort(s.begin(), s.end());
            cout << s << '\n';
        }

    }
}
