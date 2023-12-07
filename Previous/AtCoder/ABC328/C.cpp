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

vector<int> pref;
int get(int i) {
    if (i < 0) return 0;
    else return pref[i];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    string s;
    cin >> n >> q >> s;

    pref = vector<int>(n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) pref[i]++;
        if (i) pref[i] += pref[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << get(r - 1) - get(l - 1) << '\n';

    }
}
