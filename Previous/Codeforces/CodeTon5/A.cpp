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

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < n && ptr2 < m) {
            int x = a[ptr1];
            a[ptr1] -= b[ptr2];
            b[ptr2] -= x;
            if (a[ptr1] <= 0) ptr1++;
            if (b[ptr2] <= 0) ptr2++;
        }

        if (ptr1 < n && ptr2 == m) cout << "Tsondu\n";
        else if (ptr1 == n && ptr2 < m) cout << "Tenzing\n";
        else cout << "Draw\n";
    }
}
