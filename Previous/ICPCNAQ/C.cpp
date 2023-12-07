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

    int n, k;
    cin >> n >> k;

    vector<pii> day(n);
    for (int i = 0; i < n; i++) {
        cin >> day[i].first >> day[i].second;
        day[i].second--;
    }

    const ld ep = 1e-10;

    ld l = 0, r = 1e9 + 10;
    ld ans = 0;
    for (int iteration = 0; iteration < 100; iteration++) {
        ld mp = (l + r) / 2;

        // simulate if this is possible
        bool can = true;

        // stores {day, value}
        priority_queue<pair<int, ld>, vector<pair<int, ld>>, greater<pair<int, ld>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({day[i].second, day[i].first});

            ld need = mp * k;
            while (need > ep && !pq.empty()) {
                ld val = pq.top().second;
                int time = pq.top().first;
                pq.pop();

                if (i > time) continue;
                ld take = min(need, val);

                if (abs(take - val) < ep) {
                    // we use all of it
                    need -= take;
                } else {
                    // otherwise, use some of it
                    need -= take;
                    pq.push({time, val - take});
                }
            }

            if (need > ep) {
                can = false;
                break;
            }
        }
        if (can) {
            ans = mp;
            l = mp;
        } else {
            r = mp;
        }

    }

    if (ans < ep) cout << -1 << '\n';
    else {
        cout.precision(15);
        cout << fixed << ans << '\n';
    }

}
