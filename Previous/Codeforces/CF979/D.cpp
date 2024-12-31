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

// segtree (sum)
struct segtree {
    vector<ll> seg;
    int n, sz;

    segtree(int N, vector<ll> &v) {
        n = N;
        sz = 1;
        while (sz < 4 * n) sz *= 2;
        seg.assign(sz, 0);
        build(0, 0, n - 1, v);
    }

    void build(int idx, int l, int r, vector<ll> &v) {
        if (l == r) {
            seg[idx] = v[l];
            return;
        }
        int mp = (l + r) / 2;
        build(2 * idx + 1, l, mp, v);
        build(2 * idx + 2, mp + 1, r, v);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void set(int idx, ll v) {
        set(0, 0, n - 1, idx, v);
    }

    void set(int idx, int l, int r, int setIdx, ll v) {
        if (l == r) {
            seg[idx] = v;
            return;
        }
        int mp = (l + r) / 2;
        if (setIdx <= mp) set(2 * idx + 1, l, mp, setIdx, v);
        else set(2 * idx + 2, mp + 1, r, setIdx, v);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    ll get(int l, int r) {
        return get(0, 0, n - 1, l, r);
    }

    ll get(int idx, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        else if (l >= ql && r <= qr) return seg[idx];
        int mp = (l + r) / 2;
        return get(2 * idx + 1, l, mp, ql, qr) + get(2 * idx + 2, mp + 1, r, ql, qr);
    }
};


vector<pii> intervals;
vector<bool> vis;

vector<int> a;

void dfs(int node, int l, int r) {
    vis[node] = true;
    if (a[node] == node) return;
    l = min(l, node);
    r = max(r, node);

    if (vis[a[node]]) {
        // Add this interval
        intervals.push_back({l, r});
        return;
    }
    dfs(a[node], l, r);
}


bool is_good(pii bound, segtree &segL, segtree &segR) {
    int l = bound.first, r = bound.second;
    if (segR.get(l, r - 1) == r - l || segL.get(l + 1, r) == r - l) {
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
        int n, q;
        cin >> n >> q;

        intervals.clear();
        vis = vector<bool>(n);
        a = vector<int>(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }

        vector<char> edges(n);
        for (int i = 0; i < n; i++) cin >> edges[i];


        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, i, i);
            }
        }

        if (intervals.empty()) {
            for (int i = 0; i < q; i++) {
                int idx;
                cin >> idx;
                cout << "YES\n";
            }
            continue;
        }


        // Merge the intervals (overlap of 1 is ok)
        // {2, 4}, {3, 5}. If (i2.l >= i1.r - 1), just go to i2
        sort(intervals.begin(), intervals.end());

        vector<pii> bounds;
        pii curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first >= curr.second - 1) {
                bounds.push_back(curr);
                curr = intervals[i];
            } else {
                curr.second = intervals[i].second;
            }
        }
        bounds.push_back(curr);


        vector<bool> good(bounds.size());
        int cnt_bad = 0;

        // Build segtree on Rs and Ls
        vector<int> Rs(n), Ls(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] == 'L') Ls[i] = 1;
            else Rs[i] = 1;
        }

        segtree segR(n, Rs);
        segtree segL(n, Ls);

        for (int i = 0; i < bounds.size(); i++) {
            // Check if this bound is satisfied
            if (is_good(bounds[i], segL, segR)) {
                good[i] = true;
            } else {
                cnt_bad++;
            }
        }

        for (int query = 0; query < q; query++) {
            int idx;
            cin >> idx;
            idx--;

            // Change the idx
            if (edges[idx] == 'L') {
                edges[idx] = 'R';
                segL.set(idx, 0);
                segR.set(idx, 1);
            } else {
                edges[idx] = 'L';
                segR.set(idx, 0);
                segL.set(idx, 1);
            }

            // Check the bound
            // Find the first interval that contains idx
            pii p = {idx, -1};
            auto it = lower_bound(intervals.begin(), intervals.end(), p);

            if (it != intervals.end()) {
                // Check if this interval has changed
                int i = it - intervals.begin();
                if (is_good(*it, segL, segR)) {
                    if (!good[i]) {
                        good[i] = true;
                        cnt_bad--;
                    }
                } else {
                    if (good[i]) {
                        good[i] = false;
                        cnt_bad++;
                    }
                }

                it++;
                if (it != intervals.end() && (*it).first <= idx && (*it).second >= idx) {
                    i = it - intervals.begin();
                    if (is_good(*it, segL, segR)) {
                        if (!good[i]) {
                            good[i] = true;
                            cnt_bad--;
                        }
                    } else {
                        if (good[i]) {
                            good[i] = false;
                            cnt_bad++;
                        }
                    }
                }
            }

            if (cnt_bad == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }

        }
    }
}
