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

int n, m;

string simulate(char prev_char) {
    int red = n, blue = m;
    string res;
    if (prev_char == 'B') blue--;
    else red--;
    res += prev_char;

    bool turn = true;
    // true => want different
    while (red > 0 || blue > 0) {
        if (turn) {
            // want diff
            if (prev_char == 'B') {
                if (red) {
                    res += 'R';
                    red--;
                } else {
                    res += 'B';
                    blue--;
                }
            } else {
                if (blue) {
                    res += 'B';
                    blue--;
                } else {
                    res += 'R';
                    red--;
                }
            }
        } else {
            // want same
            if (prev_char == 'B') {
                if (blue) {
                    res += 'B';
                    blue--;
                } else {
                    res += 'R';
                    red--;
                }
            } else {
                if (red) {
                    res += 'R';
                    red--;
                } else {
                    res += 'B';
                    blue--;
                }
            }
        }
        turn = !turn;
        prev_char = res[res.size() - 1];
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // start with B
    char prev_char = 'R';
    string res = simulate(prev_char);

    int same = 0;
    for (int i = 1; i < res.size(); i++) {
        if (res[i] == res[i - 1]) same++;
    }

    prev_char = 'B';
    res = simulate(prev_char);
    int same2 = 0;
    for (int i = 1; i < res.size(); i++) {
        if (res[i] == res[i - 1]) same2++;
    }

    cout << max(same, same2) << ' ' << (int) res.size() - 1 - max(same, same2) << '\n';

}
