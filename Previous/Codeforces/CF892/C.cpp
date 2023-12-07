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

int get(vector<int> &a) {
    int n = a.size();
    int mx_pair = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (i + 1) * a[i];
        mx_pair = max(mx_pair, (i + 1) * a[i]);
    }
    return sum - mx_pair;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        int mx = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = i + 1;
        mx = max(mx, get(a));

        for (int threshold = n - 1; threshold >= 0; threshold--) {
            sort(a.begin() + threshold, a.end(), greater<int>());
            mx = max(mx, get(a));
        }
        cout << mx << '\n';

    }
//    vector<int> a = {1, 2, 3, 4, 5, 6, 10, 9, 8, 7};
//    cout << get(a);
}
