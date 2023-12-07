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

bool test(vector<int> a) {
    bool can = false;
    int n = a.size();
    set<vector<int>> prev;
    for (int it = 0; it < 2 * n; it++) {
        bool has_one = accumulate(a.begin(),a.end(), 0LL);
        if (prev.count(a) and has_one) {
            can = true;
            break;
        }
        prev.insert(a);
        vector<int> new_arr(n);
        for (int i = 0; i < n; i++) {
            if (a[i]) new_arr[i] = 0;
            else {
                int x = 0;
                if (i) x ^= a[i - 1];
                if (i != n - 1) x ^= a[i + 1];
                new_arr[i] = x;
            }
        }
        a = new_arr;
//        for (int j : a) cout << j << ' ';
//        cout << '\n';
    }
    return can;
}

vector<int> convert(int n, int num) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (num >= (1 << i)) {
            a[n - i - 1] = 1;
            num -= (1 << i);
        }
    }
    return a;
}

bool solve(int n) {
    vector<int> a(n);
    bool can = false;
    for (int i = 0; i < n; i++) {
        a[i] = 1;
        if (i) a[i - 1] = 0;
        if (test(a)) {
            can = true;
            break;
        }
    }

    if (can) {
        return true;
    } else return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    vector<int> a = {1, 1, 0, 0, 1, 0};


    for (int i = 1; i <= 123; i++) {
//int i = 18;
        cout << i << ": " << solve(i);

        if (i <= 16) {
            // brute force
            bool can = false;
            for (int j = 0; j < (1 << i); j++) {
                can |= test(convert(i, j));
                if (can) break;
            }
            cout << ", " << can;
        }
        cout << '\n';
    }


//    bool can2 = solve(n);

//    if (can != can2) cout << "Diff";
//    cout << can << '\n';

}
