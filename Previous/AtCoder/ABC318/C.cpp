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

    int n, d, p;
    cin >> n >> d >> p;

    vector<int> a(n);
    int curr_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        curr_sum += a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    int best = curr_sum;
    int ptr = 0;
    for (int i = 0; ptr < n; i++) {
        int end = min(n, ptr + d);
        curr_sum += p;
        while (ptr < end) {
            curr_sum -= a[ptr];
            ptr++;
        }
        best = min(curr_sum, best);
    }
    cout << best << '\n';
}
