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

int cnt(string &a, string &b, int start_b) {
    int need = a.size();

    int i = 0; // end index of ptr on b
    int ptr_a = 0;
    for (i = start_b; i < b.size(); i++) {
        while (ptr_a < a.size() && a[ptr_a] != b[i]) {
            ptr_a++;
        }
        if (ptr_a >= a.size()) break;
        ptr_a++;
    }

    int left = b.size() - i;
    return start_b + need + left;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        string a, b;
        cin >> a >> b;

        int best = INT_MAX;
        for (int i = 0; i <= b.size(); i++) {
            best = min(best, cnt(a, b, i));
        }
        cout << best << '\n';

    }
}
