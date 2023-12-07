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

void get_max_int(int n, int k, vector<int> &max_subarr, vector<int> &a) {
    deque<int> dq; // stores indices of the biggest elems
    // process first k
    int i;
    for (i = n - 1; i >= n - k; i--) {
        while (!dq.empty() && a[dq.back()] < a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        max_subarr[i] = a[dq.front()];
    }
    // process rest of array
    for (; i >= 0; i--) {
        while (!dq.empty() && dq.front() >= i + k) {
            dq.pop_front();
        }

        while (!dq.empty() && a[dq.back()] < a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        max_subarr[i] = a[dq.front()];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> prev(n, -INF), max_subarr(n, -INF);
    for (int i = n - k; i < n; i++) {
        prev[i] = a[i];
    }

    for (int iteration = 2; iteration <= x; iteration++) {
        get_max_int(n, k, max_subarr, prev);
        for (int i = 0; i < n - 1; i++) {
            prev[i] = a[i] + max_subarr[i + 1];
        }
        prev[n - 1] = a[n - 1];
    }

    int best = -INF;
    for (int i = 0; i < k; i++) {
        best = max(best, prev[i]);
    }

    if (best < 0) cout << "-1\n";
    else cout << best << '\n';

}
