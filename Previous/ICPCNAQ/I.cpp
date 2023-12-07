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

// returns 0 if matches
// returns the number if it matches but just needs one extra number
// returns -1 if it doesn't work at all
int last = -1;
int check(int a, string &s) {
    int missing = 0;

    int ptr = 0;
    while (ptr < s.size()) {
        bool changed = false;
        string curr_str = to_string(a);
        string nxt_str = s.substr(ptr, curr_str.size());
        string plus1 = to_string(a + 1);
        last = stoi(nxt_str);
//        cout << s.substr(ptr, nxt_str.size()) << '\n';
        if (nxt_str != curr_str) {
            if (plus1 != s.substr(ptr, plus1.size()) || missing != 0) return -1;
            else {
                // assume this is missing
                missing = a;
                changed = true;
            }
        }
        a++;
        if (!changed) ptr += curr_str.size();
    }

    return missing;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    cout << check(8, "89101112");

//    freopen("tests.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;

        int n = s.size();

        set<int> possible;
        // check beginning
        for (int sz = 1; sz < min(n + 1, 6LL); sz++) {
            int to_check = stoi(s.substr(0, sz));
            if (check(to_check, s) == 0) {
                if (to_check != 1) possible.insert(to_check - 1);
                if (last != 99999) possible.insert(last + 1);
            }
            int res = check(to_check, s);
            if (res != -1 && res != 0) possible.insert(res);
        }

//        sort(possible.begin(), possible.end());
        cout << possible.size() << '\n';
        for (int i : possible) cout << i << ' ';
        cout << '\n';
    }
}

/*
 * 1
123456781011
 */