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

bool check(int a, int i) {
    return a & (1 << i);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int total = 0;
    for (int bit = 0; bit < 31; bit++) {
        // int cnt_xor0 = 0, total_sum0 = 0, cnt_xor1 = 0, total_sum1 = 0;

        vector<int> cnt(n); // only need to keep track of total_sum1
        int cnt_xor0 = 0, total_sum0 = 0, cnt_xor1 = 0, total_sum1 = 0;
        for (int i = 0; i < n; i++) {
            if (check(a[i], bit)) {
                // bit is 1

                // # of subarrays with 0 = # of subarrays of 1
                // # of subarrays with 1 = # of subarrays of 0, + 1

                swap(cnt_xor0, cnt_xor1);
                swap(total_sum0, total_sum1);
                cnt_xor1++;
                total_sum0 += cnt_xor0;
                total_sum1 += cnt_xor1;

            } else {
                // bit is 0
                cnt_xor0++;
                total_sum0 += cnt_xor0;
                total_sum1 += cnt_xor1;

                // # of subarrays with xor 0 is prev 0 + 1
                // # of subarrays with xor 1 is prev xor 1
            }
            total_sum0 %= MOD;
            total_sum1 %= MOD;
            cnt_xor0 %= MOD;
            cnt_xor1 %= MOD;
            cnt[i] = total_sum1;
        }

        for (int i = 0; i < n; i++) {
            total += cnt[i] * (1 << bit) % MOD;
            total %= MOD;
        }
    }
    cout << total << '\n';
}
