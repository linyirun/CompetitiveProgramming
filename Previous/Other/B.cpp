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

    int best = 0;
    for (int i = 0; i * 2 <= n; i++) {
        bool can = true;
        for (int j = 0; j < i; j++) {
            if (s[j] != s[j + i]) can = false;
        }
        if (can) best = i;
    }

    cout << min(n, n - best + 1) << '\n';
}
