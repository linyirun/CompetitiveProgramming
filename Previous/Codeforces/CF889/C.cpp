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

vector<pii> ans;
int n;


void ans_pos() {
    // all positive
    for (int i = 1; i < n; i++) {
        ans.push_back({i, i - 1});
    }
}
void ans_neg() {
    // all neg
    for (int i = n - 2; i >= 0; i--) {
        ans.push_back({i, i + 1});
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

//    int worst = 0;

    while (tt--) {

        cin >> n;
//n = 20;
        int non_neg = 0, non_pos = 0;
        vector<int> a(n);

        int biggest_pos = 0, biggest_neg = 0;
        int cnt_neg = 0, cnt_pos = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
//            a[i] = (rand() % 40) - 20;
            if (a[i] >= 0) non_neg++;
            if (a[i] <= 0) non_pos++;
            if (a[i] > 0) cnt_pos++;
            if (a[i] < 0) cnt_neg++;
            if (a[i] > a[biggest_pos]) biggest_pos = i;
            if (a[i] < a[biggest_neg]) biggest_neg = i;
        }
        ans.clear();


        if (non_neg == n) {
            ans_pos();
            cout << ans.size() << '\n';
            for (pii p : ans) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
            continue;
        }
        if (non_pos == n) {
            ans_neg();
            cout << ans.size() << '\n';
            for (pii p : ans) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
            continue;
        }

        int tmp = a[biggest_pos];
        int needed_pos = 0, needed_neg = 0;
        while (tmp < abs(a[biggest_neg])) {
            needed_pos++;
            tmp *= 2;
        }

        int tmp2 = a[biggest_neg];

        while (abs(tmp2) < abs(a[biggest_pos])) {
            needed_neg++;
            tmp2 *= 2;
        }

        if (needed_pos + cnt_neg <= needed_neg + cnt_pos) {
            while (a[biggest_pos] < abs(a[biggest_neg])) {
                a[biggest_pos] *= 2;
                ans.push_back({biggest_pos, biggest_pos});
            }

            for (int i = 0; i < n; i++) {
                if (a[i] < 0) {
                    ans.push_back({i, biggest_pos});
                    a[i] += a[biggest_pos];
                }
            }
            ans_pos();

        } else {
            while (abs(a[biggest_neg]) < abs(a[biggest_pos])) {
                a[biggest_neg] *= 2;
                ans.push_back({biggest_neg, biggest_neg});
            }

            for (int i = 0; i < n; i++) {
                if (a[i] > 0) {
                    ans.push_back({i, biggest_neg});
                    a[i] += a[biggest_neg];
                }
            }
            ans_neg();
        }


//        worst = max(worst, (ll) ans.size());

        cout << ans.size() << '\n';
        for (pii p : ans) cout << p.first + 1 << ' ' << p.second + 1 << '\n';

    }

//    cout << worst << '\n';

}
