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

bool in(char c) {
    string s = "atcoder";
    for (char ch : s) {
        if (ch == c) return true;
    } return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    map<char, int> mp;
    int cnt = 0;
    for (char c : s) {
        if (c == '@') cnt++;
        else mp[c]++;
    }

    bool can = true;
    for (char c : t) {
        if (c == '@') continue;
        if (mp[c] == 0) {
            if (!in(c)) can = false;
            cnt--;
            if (cnt < 0) can = false;
        }
        else {

            mp[c]--;
            if (mp[c] < 0) can = false;
        }
    }

    for (auto p : mp) {
        if (p.second != 0 && !in(p.first)) {
            can = false;
        }
    }

    if (can) cout << "Yes\n";
    else cout << "No\n";
}
