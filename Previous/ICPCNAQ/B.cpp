#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

#define int ll
//const int MOD = 998244353;
const int MOD = 9302023;
const int INF = 1e15;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> s;
    n = s.size();

    vector<int> dp(n + 2, INF), ways(n + 2);

    dp[n] = dp[n + 1] = 0, ways[n] = ways[n + 1] = 1;

    vector<string> words = {
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine",
            "-"
    };

    for (int i = n - 1; i >= 0; i--) {
        for (string curr : words) {
            if (curr == "-" || s.substr(i, curr.length()) == curr) {
                int len = curr.length();
                if (1 + dp[i + len] < dp[i]) {
                    dp[i] = 1 + dp[i + len];
                    ways[i] = ways[i + len];
                } else if (1 + dp[i + len] == dp[i]) {
                    ways[i] = (ways[i] + ways[i + len]) % MOD;
                }
            }
        }


    }

    cout << dp[0] << '\n';
    cout << ways[0] << '\n';

}
