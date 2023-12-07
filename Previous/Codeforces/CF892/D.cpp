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

pair<pii, pii> merge(pair<pii, pii> p1, pair<pii, pii> p2) {
    int l1 = p1.first.first, r1 = p1.first.second, a1 = p1.second.first, b1 = p1.second.second;
    int l2 = p2.first.first, r2 = p2.first.second, a2 = p2.second.first, b2 = p2.second.second;

    return {{min(l1, l2), max(r1, r2)}, {min(a1, a2), max(b1, b2)}};
}

bool _intersect(pair<pii, pii> &p1, pair<pii, pii> &p2) {
    int l1 = p1.first.first, r1 = p1.first.second, a1 = p1.second.first, b1 = p1.second.second;
    int l2 = p2.first.first, r2 = p2.first.second, a2 = p2.second.first, b2 = p2.second.second;

    if ((a2 <= r1 && a2 >= l1) || (b2 >= l1 && b2 <= r1)) return true;
    return false;
}

bool intersect(pair<pii, pii> p1, pair<pii, pii> p2) {
    return _intersect(p1, p2) || _intersect(p2, p1);
}
vector<pair<pii, pii>> intervals;

class Compare {
public:
    bool operator()(int &p1, int &p2) {
        return intervals[p1].first.second < intervals[p2].first.second;
    }
};

void assign(int &l, int &r, int &a, int &b, pair<pii, pii> &p) {
    l = p.first.first;
    r = p.first.second;
    a = p.second.first;
    b = p.second.second;
}

bool try_merging(set<pair<pii, pii>> &s) {
    auto it = --s.end();
    if (it == s.begin()) return false;
    auto it_prev = --it;
    it++;

    if (intersect(*it, *it_prev)) {
        auto ret = merge(*it, *it_prev);
        s.erase(*it);
        s.erase(*it_prev);
        s.insert(ret);
        return true;
    }
    if (it_prev == s.begin()) return false;
    auto it_prev2 = --it_prev;
    it_prev++;

    if (intersect(*it, *it_prev2)) {
        auto ret = merge(*it, *it_prev2);
        s.erase(*it);
        s.erase(*it_prev2);
        s.insert(ret);
        return true;
    }
    return false;

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        intervals = vector<pair<pii, pii>>(n);
        for (int i = 0; i < n; i++) {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            intervals[i] = {{l, r}, {a, b}};
        }
        sort(intervals.begin(), intervals.end());

        set<pair<pii, pii>> merged;
        merged.insert(intervals[0]);
        for (int i = 1; i < n; i++) {
            merged.insert(intervals[i]);
            bool can = true;
            while (can) {
                can = try_merging(merged);
            }
        }

        vector<pair<pii, pii>> l_first, neg_r_first;
        for (auto p : merged) {
            l_first.push_back(p);
            swap(p.first.first, p.first.second);
            p.first.first *= -1;
            neg_r_first.push_back(p);
        }
//        cout << "l_first:\n";
//        for (auto p : l_first) {
//            cout << p.first.first << ' ' << p.first.second << ' ' << p.second.first << ' ' << p.second.second << '\n';
//        }
//        cout << '\n';

        int num_pos;
        cin >> num_pos;
        for (int i = 0; i < num_pos; i++) {
            int start;
            cin >> start;
            pair<pii, pii> tmp = {{start, INT_MAX}, {INT_MAX, INT_MAX}};

            int curr_best = start;
            // first l before
            auto pos = upper_bound(l_first.begin(), l_first.end(), tmp);
            if (pos != l_first.begin()) {
                pos--;
                if ((*pos).first.second >= start) {
                    curr_best = max(curr_best, (*pos).second.second);
                }
            }

            tmp = {{-start, -INF}, {-INF, -INF}};
            auto pos2 = lower_bound(neg_r_first.begin(), neg_r_first.end(), tmp);
            if (pos2 != neg_r_first.end()) {
                if ((*pos2).first.second <= start) {
                    curr_best = max(curr_best, (*pos2).second.second);
                }
            }
            cout << curr_best << ' ';
        }
        cout << '\n';
    }
}

/*
1
5
18 24 18 24
1 8 2 4
11 16 14 14
26 32 28 30
5 10 6 8
9
15 14 13 27 22 17 31 1 7
 some are just one directional...
 */