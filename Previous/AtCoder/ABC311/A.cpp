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

    int n;
    string s;
    cin >> n >> s;

    bool has_a = 0, has_b = 0, has_c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') has_a = true;
        if (s[i] == 'B') has_b = true;
        if (s[i] == 'C') has_c = true;
        if (has_a && has_b && has_c) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}
