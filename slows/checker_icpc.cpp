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

    map<string, vector<int>> mp;

    int MX = 99999;
    int THRESHOLD = 15;

    for (int a = 1; a <= MX; a++) {
        vector<int> v;
        v.push_back(a);
        int sz = to_string(a).size();
        int b = a + 1;
        while (sz < THRESHOLD && b <= 99999) {
            v.push_back(b);
            sz += to_string(b).size();
            b++;

            // create sequences
            for (int ignore = 0; ignore < v.size(); ignore++) {
                string seq;
                for (int i = 0; i < v.size(); i++) {
                    if (i != ignore) seq += to_string(v[i]);
                }
                mp[seq].push_back(v[ignore]);
            }
        }
    }


    vector<string> seqs;
    for (auto &p : mp) {
        seqs.push_back(p.first);
    }
    int tests = seqs.size();

    vector<string> strs(tests);
    // pick tests
    srand(0);
    for (int t = 0; t < tests; t++) {
//        int curr_rand = rand() % seqs.size();
//        while (seqs[curr_rand].size() > 15) {
//            curr_rand = rand() % seqs.size();
//        }
//        strs[t] = seqs[curr_rand];
        strs[t] = seqs[t];
    }

//     output tests
//    freopen("tests.txt", "w", stdout);
//    cout << tests << '\n';
//    for (string &s : strs) cout << s << '\n';

// do the checks
    freopen("out.txt", "r", stdin);
    for (int t = 0; t < tests; t++) {
        int k;
        cin >> k;
        vector<int> missing(k);
        for (int i = 0; i < k; i++) cin >> missing[i];

        vector<int> correct = mp[strs[t]];
        sort(correct.begin(), correct.end());
        if (correct != missing) {
            cout << "On test case " << strs[t] << '\n';
            cout << "Got ";
            for (int i : missing) cout << i << ' ';
            cout << '\n';
            cout << "Expected ";
            for (int i : correct) cout << i << ' ';
            cout << '\n';
        }

    }



}
