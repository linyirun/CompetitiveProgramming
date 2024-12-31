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

    vector<int> cnt(26);
    string s;
    cin >> s;
    bool can = true;
    for (char c : s) {
        cnt[c - 'A']++;
        if (c - 'A' >= 3) can = false;
    }
    for (int i = 0; i < 3; i++) {
        if (cnt[i] != 1) can = false;
    }
    if (can) cout << "Yes\n";
    else cout << "No\n";
}

