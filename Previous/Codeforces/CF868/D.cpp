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

int pick_next(int curr, int cant, vector<bool> &vis, int mx) {
    for (int i = 1; i < mx; i++) {
        if ((i + curr) % mx != cant && !vis[(i + curr) % mx]) return (i + curr) % mx;
    }
    return 1 / 0;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;

        vector<int> x(k), c(k);
        for (int i = 0; i < k; i++) {
            cin >> x[i];
//            x[i] = 3 + i * 10;
        }
//        x[k - 1] = n;
        for (int i = 0; i < k; i++) {
            cin >> c[i];
//            c[i] = 3 + i;
        }
        // Check if possible
        bool possible = c[0] <= x[0];
        for (int i = 1; i < k; i++) {
            if (c[i] - c[i - 1] > x[i] - x[i - 1]) possible = false;
        }

        if (!possible) {
            cout << "NO\n";
            continue;
        } else {
            cout << "YES\n";
        }

        // Construct the string
        // Have to start with abc... in the beginning of the str
        vector<bool> vis(26);
        int chars = 3, cnt = 3;
        string res = "abc";

        for (int i = 0; i < k; i++) {
            while (res.size() < x[i]) {
                int last = (int) res.size() - 1;
                if (cnt < c[i]) {
                    // Add a new character if possible
                    if (chars < min(c[k - 1], 25LL)) {
                        // Add a new char
                        res += (char) ('a' + chars);
                        chars++;
                    } else {
                        // just add the previous character
                        vis[res[last] - 'a'] = true;
                        res += res[last];
                    }
                    cnt++;
                } else {
                    // otherwise, cycle through
                    int curr_char = res[last] - 'a';
                    curr_char = pick_next(curr_char, res[last - 1] - 'a', vis, chars);
                    res += (char) ('a' + curr_char);
                }
            }
        }
        cout << res << '\n';

    }
}
