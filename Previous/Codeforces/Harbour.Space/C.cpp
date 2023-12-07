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

int largest_below(int x) {
    for (int i = 32; i >= 0; i--) {
        if (x >= (1LL << i)) return 1LL << i;
    } return 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int x;
        cin >> x;

        vector<int> res;
        res.push_back(1);
        int curr = 1;

        while (curr * 2 <= x) {
            curr *= 2;
            res.push_back(curr);
        }

        while (curr != x) {
            int s = largest_below(x - curr);
            curr += s;
            res.push_back(curr);
        }

        reverse(res.begin(), res.end());
        cout << res.size() << '\n';
        for (int i : res) cout << i << ' ';
        cout << '\n';


    }
}
