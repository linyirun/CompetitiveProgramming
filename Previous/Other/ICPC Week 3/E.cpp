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

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int curr = 0;
    int curr_pos = 0;

    while (curr_pos < n) {
        curr++;
        curr_pos = lower_bound(a.begin(), a.end(), a[curr_pos] + k) - a.begin();
    }

    cout << curr << '\n';
}

