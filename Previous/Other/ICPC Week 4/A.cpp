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

    do {
        int val = n % 10;
        n /= 10;
        string res;
        if (val >= 5) {
            res = "-O|";
            val -= 5;
        } else res = "O-|";

        for (int i = 0; i < val; i++) res += "O";
        res += "-";
        for (int i = 0; i < 4 - val; i++) res += "O";
        cout << res << '\n';
    } while (n != 0);

}
