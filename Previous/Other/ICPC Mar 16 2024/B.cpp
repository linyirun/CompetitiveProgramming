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

    int n, k;
    cin >> n >> k;
    int total = 0;

    for (int i = 0; i < n; i++) {
        set<string> has;
        for (int j = 0; j < k; j++) {
            string s;
            cin >> s;
            if (has.count(s)) total++;
            has.insert(s);
        }
    }

    cout << total << '\n';
}
