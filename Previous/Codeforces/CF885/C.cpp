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

//    int a, b, it;
//    cin >> a >> b >> it;
//    cout << a << ' ' << b << '\n';
//    for (int i = 0; i < it; i++) {
//        int c = abs(a - b);
//        a = b;
//        b = c;
//        cout << a << ' ' << b << '\n';
//    }

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

//        vector<int> cpy_a = a, cpy_b = b;
//        while (true) {
//            bool done = true;
//            for (int i = 0; i < n; i++) {
//                if (cpy_a[i] != 0) done = false;
//            }
//            if (done) break;
//            for (int i = 0; i < n; i++) {
//                int c = abs(cpy_a[i] - cpy_b[i]);
//                cpy_a[i] = cpy_b[i];
//                cpy_b[i] = c;
//            }
//            for (int i = 0; i < n; i++) cout << cpy_a[i] << ' ';
//            cout << '\n';
//            for (int i = 0; i < n; i++) cout << cpy_b[i] << ' ';
//            cout << "\n\n";
//        }

        vector<int> mod3(3);
        for (int i = 0; i < n; i++) {
            int total = 0;

            while (a[i] != 0) {
                if (a[i] <= (2 * b[i]) || b[i] == 0) {
                    total++;
                    int c = abs(b[i] - a[i]);
                    a[i] = b[i];
                    b[i] = c;
                } else {
                    int rem = a[i] % (2 * b[i]);
                    a[i] = rem;
                }
            }

            if (b[i] == 0) {
                mod3[0]++;
                mod3[1]++;
                mod3[2]++;
            } else mod3[total % 3]++;
        }

        if (mod3[0] == n || mod3[1] == n || mod3[2] == n) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
}

/*
5 19 20
5 19
19 14
14 5
5 9
9 4
4 5
5 1
1 4
4 3
3 1
1 2
2 1
1 1
1 0
0 1
1 1
1 0
0 1
1 1
1 0
0 1
 */