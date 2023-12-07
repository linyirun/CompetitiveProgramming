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

    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;

    vector<int> pref(n + 1);
    int cnt_x = 0;
    for (int i = 0; i < n; i++) {
        pref[i] = s[i] == 'x';
        if (i) pref[i] += pref[i - 1];
        if (s[i] == 'x') cnt_x++;
    }

    int best = 0;
    for (int start_pos = 0; start_pos < n; start_pos++) {
        int l = 1, r = n * m - start_pos; // non-inclusive
        int ans = 0;
        while (l <= r) {
            int mp = (l + r) / 2;
            int pos = max(0LL, start_pos + mp - 1);
            int need = pref[min(n - 1, pos)];
            if (start_pos) need -= pref[start_pos - 1];

            int cycles = (mp - (n - start_pos) - 1) / n;
            cycles = max(cycles, 0LL);
            need += cnt_x * cycles;
            int left = max(0LL, mp - (n - start_pos) - n * cycles);
            if (left) need += pref[left - 1];

            if (need <= k) {
                ans = mp;
                l = mp + 1;
            } else {
                r = mp - 1;
            }

        }
        best = max(best, ans);
    }
    cout << best << '\n';
}
