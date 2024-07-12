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

    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;

    vector<int> max_val(t);
    max_val[t - 1] = v2;
    for (int i = t - 2; i >= 0; i--) {
        max_val[i] = max_val[i + 1] + d;
    }

    int speed = v1;
    int total = 0;
    for (int i = 0; i < t; i++) {
        total += speed;
//        cout << speed << '\n';
        speed = min(speed + d, max_val[i + 1]);
    }
    cout << total << '\n';
}
