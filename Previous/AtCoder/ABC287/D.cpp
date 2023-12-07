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

    string s, t;
    cin >> s >> t;
    int T = t.size();
    int S = s.size();

    vector<bool> can(T), ans(T);
    for (int i = 1; i <= T; i++) {
        if (s[S - i] == '?' || t[T - i] == '?' || s[S - i] == t[T - i]) {
            can[T - i] = true;
        } else break;
    }

    for (int i = 0; i < T; i++) {
        if (s[i] == t[i] || s[i] == '?' || t[i] == '?') {
            if (i == T - 1 || can[i + 1]) {
                ans[i] = true;
            }
        } else break;
    }
    if (can[0]) cout << "Yes\n";
    else cout << "No\n";

    for (int i = 0; i < T; i++) {
        if (ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}
