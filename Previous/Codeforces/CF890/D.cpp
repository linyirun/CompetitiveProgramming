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

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        int first_ans = ask(n - 1, n);
        if (first_ans == -1) return 0;

        int curr_biggest = 0;
        if (first_ans == 1) {
            curr_biggest = n - 1;
        } else curr_biggest = n;

        for (int i = n - 2; i >= 1; i--) {
            int add = 2;
            // compare to next elem
            int res = ask(i, i + 1);
            if (!res) {
                continue;
            } else {
                if (curr_biggest == i + 1) {
                    curr_biggest = i;
                    continue;
                }
            }

            bool is_biggest = true;
            while (true) {
                int prev = ask(i + 1, min(curr_biggest, i + add));

                int curr = ask(i, min(curr_biggest, i + add));
                if (curr - prev != min(curr_biggest, i + add) - i) {
                    is_biggest = false;
                    break;
                }

                if (i + add >= curr_biggest) {
                    break;
                }
                add *= 2;
            }

            if (is_biggest) curr_biggest = i;
        }


        cout << "! " << curr_biggest << '\n';
        cout.flush();
    }
}
