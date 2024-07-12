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

int a = -1, b = -1, c = -1;

void set_arr(vector<int> &arr) {
    int test_a = arr[0] - arr[2] + arr[3] - arr[0];
    int test_b = arr[2] - arr[3] + arr[0];
    int test_c = arr[3] - arr[0];
    if (test_a > 0 && test_b > 0 && test_c > 0 &&
            test_a + test_b == arr[0] && test_a + test_c == arr[1] && test_b + test_c == arr[2] &&
            test_a + test_b + test_c == arr[3]) {
        a = test_a;
        b = test_b;
        c = test_c;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
//    cin >> tt;
    tt = 1;
    while (tt--) {
        vector<int> arr(4);
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

        sort(arr.begin(), arr.end());

        do {
            set_arr(arr);
        } while (next_permutation(arr.begin(), arr.end()));

        cout << a << ' ' << b << ' ' << c << '\n';
    }
}
