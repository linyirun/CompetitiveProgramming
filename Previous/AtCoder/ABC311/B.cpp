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

    int n, d;
    cin >> n >> d;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int best = 0;
    int chain = 0;
    for (int i = 0; i < d; i++) {
        bool can = true;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == 'x') can = false;
        }
        if (can) {
            chain++;
            best = max(best, chain);
        } else {
            chain = 0;
        }
    }
    cout << best << '\n';
}
