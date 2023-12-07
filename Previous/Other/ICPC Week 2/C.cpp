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

    const int MX = 200001;
    vector<vector<int>> first(26, vector<int>(MX));

    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        int curr = s[i] - 'a';
        cnt[curr]++;
        first[curr][cnt[curr]] = i;
    }

    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        cnt = vector<int>(26);
        for (char c : s) cnt[c - 'a']++;
        int mn = 0;
        for (int i = 0; i < 26; i++) {
            mn = max(mn, first[i][cnt[i]]);
        }
        cout << mn + 1 << '\n';
    }
}
