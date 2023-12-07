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

bool is_valid(string &s1, string &s2) {
    int diff = 0;
    for (int i = 0; i < s1.size(); i++) {
        diff += s1[i] != s2[i];
    }
    return diff == 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    do {
        bool can = true;
        for (int i = 0; i < n - 1; i++) {
            if (!is_valid(s[i], s[i + 1])) can = false;
        }
        if (can) {
            cout << "Yes\n";
            return 0;
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << "No\n";
}
