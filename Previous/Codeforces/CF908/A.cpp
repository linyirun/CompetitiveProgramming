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

char check(string &s, int X) {
    int cnt_a = 0, cnt_b = 0;
    int win_a = 0, win_b = 0;
    char last_win = '-';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') cnt_a++;
        else cnt_b++;

        if (cnt_a == X) {
            win_a++;
            cnt_a = 0;
            cnt_b = 0;
            last_win = 'A';
        } else if (cnt_b == X) {
            win_b++;
            cnt_a = 0;
            cnt_b = 0;
            last_win = 'B';
        }
    }

    if (cnt_a || cnt_b || win_a == win_b) return '?';
    if (win_a > win_b) {
        if (last_win != 'A') return '?';
        return 'A';
    }
    else {
        if (last_win != 'B') return '?';
        return 'B';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int win_a = 0, win_b = 0;
        for (int X = 1; X <= n; X++) {
            char res = check(s, X);
            if (res == 'A') win_a++;
            else if (res == 'B') win_b++;
        }

        if (win_a && win_b) cout << "?";
        else if (win_a) cout << "A";
        else if (win_b) cout << "B";
        cout << '\n';



    }
}
