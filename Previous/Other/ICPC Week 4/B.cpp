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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int curr_sum = 0;
    int best_ind = 0;
    for (int i = 0; i < k; i++) curr_sum += a[i];
    int best_sum = curr_sum;

    for (int i = k; i < n; i++) {
        curr_sum -= a[i - k];
        curr_sum += a[i];

        if (curr_sum < best_sum) {
            best_sum = curr_sum;
            best_ind = i - k + 1;
        }
    }

    cout << best_ind + 1 << '\n';



}
