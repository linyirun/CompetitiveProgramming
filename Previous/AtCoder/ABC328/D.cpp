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

void modify(stack<char> &s) {
    if (s.size() < 3) return;
    char s3 = s.top();
    s.pop();
    char s2 = s.top();
    s.pop();
    char s1 = s.top();
    s.pop();

    if (s1 == 'A' && s2 == 'B' && s3 == 'C') return;
    s.push(s1);
    s.push(s2);
    s.push(s3);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        stk.push(s[i]);
        modify(stk);
    }
    string res;
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';

}
