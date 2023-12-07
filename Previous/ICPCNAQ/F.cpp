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

    string s;
    cin >> s;

    int cnt_vowel = 0, cnt_y = 0;
    for (char c : s) {
        if (c == 'y') cnt_y++;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt_vowel++;
    }

    cout << cnt_vowel << ' ' << cnt_vowel + cnt_y << '\n';
}
