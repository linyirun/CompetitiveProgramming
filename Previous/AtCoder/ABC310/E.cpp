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

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = s[i] - '0';

    vector<vector<int>> cnt(n, vector<int>(2));

    int total = 0;

    for (int i = 0; i < n; i++) {
        cnt[i][a[i]] = 1;
        if (i) {
            if (a[i] == 0) {
                cnt[i][1] += cnt[i - 1][0] + cnt[i - 1][1];
            } else {
                cnt[i][0] += cnt[i - 1][1];
                cnt[i][1] += cnt[i - 1][0];
            }
        }
        total += cnt[i][1];
    }
    cout << total << '\n';

}
