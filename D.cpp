#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

#define int ll
const int MOD = 998244353;
//const int MOD = 1000000007;
const int INF = 1e15;

ll binpow(ll base, ll exp) {
    if (exp == 0) return 1;
    ll tmp = binpow(base, exp / 2);
    if (exp % 2 == 1) return (tmp * tmp) % MOD * base % MOD;
    else return (tmp * tmp) % MOD;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, q;
        cin >> n >> q;

        vector<pii> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
            b[i].second = i;
        }
        for (int i = 0; i < n; i++) cin >> b[i].first;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Index to sorted index
        vector<int> idx_to_idx_A(n), idx_to_idx_B(n);
        for (int i = 0; i < n; i++) {
            idx_to_idx_A[a[i].second] = i;
            idx_to_idx_B[b[i].second] = i;
        }

        int prod = 1;
        for (int i = 0; i < n; i++) {
            prod = (prod * min(a[i].first, b[i].first)) % MOD;
        }
        cout << prod << ' ';

        while (q--) {
            int o, x;
            cin >> o >> x;
            x--;

            if (o == 1) {
                // Update a[x]++;
                int a_idx_in_sorted = idx_to_idx_A[x];
                auto last_elem = --upper_bound(a.begin(), a.end(), (pii) {a[a_idx_in_sorted].first, INF});
                int last_elem_idx = (*last_elem).second;
                // Swap both and swap the mapping
                swap(a[idx_to_idx_A[x]], a[idx_to_idx_A[last_elem_idx]]);
                swap(idx_to_idx_A[x], idx_to_idx_A[last_elem_idx]);

                a_idx_in_sorted = idx_to_idx_A[x];

                int inv = binpow(min(a[a_idx_in_sorted].first, b[a_idx_in_sorted].first), MOD - 2);
                prod = (prod * inv) % MOD;

                a[a_idx_in_sorted].first++;
                prod = (prod * min(a[a_idx_in_sorted].first, b[a_idx_in_sorted].first)) % MOD;
            } else {
                // Update b[x]++;
                // Update a[x]++;
                int b_idx_in_sorted = idx_to_idx_B[x];
                auto last_elem = --upper_bound(b.begin(), b.end(), (pii) {b[b_idx_in_sorted].first, INF});

                int last_elem_idx = (*last_elem).second;
                // Swap both and swap the mapping
                swap(b[idx_to_idx_B[x]], b[idx_to_idx_B[last_elem_idx]]);
                swap(idx_to_idx_B[x], idx_to_idx_B[last_elem_idx]);

                b_idx_in_sorted = idx_to_idx_B[x];

                int inv = binpow(min(a[b_idx_in_sorted].first, b[b_idx_in_sorted].first), MOD - 2);
                prod = (prod * inv) % MOD;

                b[b_idx_in_sorted].first++;
                prod = (prod * min(a[b_idx_in_sorted].first, b[b_idx_in_sorted].first)) % MOD;
            }

            cout << prod << ' ';
        }
        cout << '\n';

    }

}

/*
1
6 8
1 4 2 7 3 5
7 6 5 6 3 3
2 5
1 6
1 5
 */