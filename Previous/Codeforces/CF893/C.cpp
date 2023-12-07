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
    const int MAX = 1e5 + 1;

    vector<bool> is_prime(MAX, true);
    is_prime[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j < MAX; j += i) is_prime[j] = false;
    }

    while (tt--) {
        int n;
        cin >> n;

        vector<int> a(n);
        a[0] = 1;
        set<int> left;
        for (int i = 2; i <= n; i++) left.insert(i);
        int base_num = 2, curr_num = 2;
        int i = 1;
        for (; i < n; i++) {
            if (left.count(curr_num)) {
                a[i] = curr_num;
                left.erase(curr_num);
                curr_num *= 2;
            } else {
                base_num++;
                while (base_num < n && !left.count(base_num)) base_num++;
                if (!left.count(base_num)) break;

                curr_num = base_num;
                a[i] = curr_num;
                left.erase(curr_num);
                curr_num *= 2;
            }
        }
        for (int j = i; j < n; j++) {
            a[j] = *left.begin();
            left.erase(left.begin());
        }
        for (int j : a) cout << j << ' ';
        cout << '\n';
    }
}
