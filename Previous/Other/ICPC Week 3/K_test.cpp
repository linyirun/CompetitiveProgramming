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

bool test(vector<int> a) {
    bool can = false;
    int n = a.size();
    set<vector<int>> prev;
    for (int it = 0; it < 2 * n; it++) {
        bool has_one = accumulate(a.begin(),a.end(), 0LL);
        if (prev.count(a) and has_one) {
            can = true;
            break;
        }
        prev.insert(a);
        vector<int> new_arr(n);
        for (int i = 0; i < n; i++) {
            if (a[i]) new_arr[i] = 0;
            else {
                int x = 0;
                if (i) x ^= a[i - 1];
                if (i != n - 1) x ^= a[i + 1];
                new_arr[i] = x;
            }
        }
        a = new_arr;
//        for (int j : a) cout << j << ' ';
//        cout << '\n';
    }
    return can;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    bool can = false;
    for (int i = 0; i < n; i++) {
        a[i] = 1;
        if (i) a[i - 1] = 0;
        if (test(a)) {
            can = true;
            break;
        }
    }

    if (can) {
        for (int i : a) cout << i;
        cout << '\n';
    } else cout << "Unlucky\n";

}
