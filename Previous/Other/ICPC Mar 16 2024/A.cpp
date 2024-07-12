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
    cin >> n;

    vector<string> check(3);
    vector<bool> has(3);
    check[0] = "keys";
    check[1] = "phone";
    check[2] = "wallet";

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++) {
            if (check[j] == s) has[j] = true;
        }
    }

    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (!has[i]) {
            cout << check[i] << '\n';
            cnt = 1;
        }
    }

    if (cnt == 0) {
        cout << "ready\n";
    }

}
