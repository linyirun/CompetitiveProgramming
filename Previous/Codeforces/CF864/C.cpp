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

bool flipped = false;
int ask(int row, int col) {
    if (flipped) cout << "? " << col << ' ' << row << '\n';
    else cout << "? " << row << ' ' << col << '\n';
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void print_ans(int row, int col) {
    if (flipped) swap(row, col);
    cout << "! " << row << ' ' << col << '\n';
    cout.flush();

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        flipped = false;
        int r, c;
        cin >> r >> c;

        if (r < c) {
            swap(r, c);
            flipped = true;
        }

        int first = ask(1, 1);
        if (first == 0) {
            print_ans(1, 1);
            continue;
        }
        first++;

        if (c >= first) {
            int second = ask(first, first);
            if (second == 0) {
                print_ans(first, first);
                continue;
            }

            int third = ask(first, first - 1);
            if (third < second) {
                print_ans(first, first - second);
            } else {
                print_ans(first - second, first);
            }
        } else {
            int offset = ask(first, 1);
            print_ans(first, offset + 1);
        }

    }
}
