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

    string s;
    int n;
    cin >> s >> n;

    reverse(s.begin(), s.end());
    int curr = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') curr += (1LL << i);
    }

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '?' && curr + (1LL << i) <= n) curr += (1LL << i);
    }

    if (curr > n) cout << "-1\n";
    else cout << curr << '\n';
}
