#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace __gnu_pbds;
using namespace std;

#define int ll
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INF = 1e15;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen("tests.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int total = 0;
        for (int l = 0; l < n; l++) {
            int unsorted_l = INT_MAX, unsorted_r = 0;
            ordered_set s;
            for (int r = l; r < n; r++) {
//                unsorted_l = min(unsorted_l, l + r);
                s.insert(a[r]);
                int l_index = s.order_of_key(a[r]);

//                cout << "a[" << r << "]: " << a[r] << '\n';
//                cout << "s.order_of_key(" << a[r] << "): " << l_index << '\n';
                // if it's not the biggest element, then update the unsorted range
                if (l_index < s.size() - 1) {
                    unsorted_r = r - l;
                    unsorted_l = min(unsorted_l, l_index);
                }
//                cout << "l: " << l << ", r: " << r << '\n';
//                cout << "unsorted_l: " << unsorted_l << ", unsorted_r: " << unsorted_r << '\n';

                total += max(0LL, unsorted_r - unsorted_l);
//                cout << total << '\n';
            }

        }
        cout << total << '\n';
    }
}
