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

bool same(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[0]) return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int d = 1; d <= x; d++) {
            if (same(to_string(i) + to_string(d))) sum++;
        }
    }
    cout << sum << '\n';
}
