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

    int q;
    cin >> q;
    int ptr = 1, ptr1 = 0, ptr2 = 0;
    int cnt = 1;
    while (q--) {
        char op;
        int k;
        cin >> op >> k;

        if (op == 'P') {
            // Could potentially add 1
            if (ptr1 < ptr2 && ptr1 + k >= ptr2) {
                // count the person with the gravy
                cnt++;
                ptr++;
            }

            ptr1 += k;
        } else {
            ptr2 += k;
            cnt += max(0LL, min(ptr1, ptr2) - ptr + 1);

            if (ptr2 >= ptr1) ptr = max(ptr, ptr2);
            else {
                ptr = min(ptr2, ptr1 + 1);
            }
        }
    }
    cout << cnt << '\n';
}
