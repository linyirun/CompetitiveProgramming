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

// range add and range min
struct segtree {
#define LEFT 2 * idx + 1
#define RIGHT 2 * idx + 2
    int n, sz;
    vector<int> seg, lazy;

    const int INF = INT_MAX;
    segtree(int n, vector<int> &a) {
        this->n = n;
        sz = 1;
        while (sz < 4 * n) sz *= 2;
        build(0, 0, n - 1, a);
    }

    void build(int idx, int l, int r, vector<int> &a) {
        if (l == r) {
            seg[idx] = a[l];
            return;
        }
        int mp = (l + r) / 2;
        build(LEFT, l, mp, a);
        build(RIGHT, mp + 1, r, a);
        seg[idx] = min(seg[LEFT], seg[RIGHT]);
    }

    int get_min(int l, int r) {
        return get_min(0, 0, n - 1, l, r);
    }

    void add(int l, int r, int val) {
        add(0, 0, n - 1, l, r, val);
    }

private:
    void push_down(int idx) {
        seg[idx] += lazy[idx];
        lazy[LEFT] += lazy[idx];
        lazy[RIGHT] += lazy[idx];
        lazy[idx] = 0;
    }

    int get_min(int idx, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) {
            return INF;
        }
        if (ql <= l && r <= qr) {
            return seg[idx] + lazy[idx];
        }
        push_down(idx);
        int mp = (l + r) / 2;
        return min(get_min(LEFT, l, mp, ql, qr), get_min(RIGHT, mp + 1, r, ql, qr));
    }

    void add(int idx, int l, int r, int ql, int qr, int val) {
        if (r < ql || l > qr) return;
        else if (ql <= l && r <= qr) {
            lazy[idx] += val;
            return;
        }
        push_down(idx);
        int mp = (l + r) / 2;
        add(LEFT, l, mp, ql, qr, val);
        add(RIGHT, mp + 1, r, ql, qr, val);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int total_open = 0, total_closed = 0;
    vector<int> pref(n);
    set<int> ind;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') pref[i] = 1, total_open++;
        else pref[i] = -1, total_closed++;
        if (i) pref[i] += pref[i - 1];
        if (i != n - 1 && s[i] == s[i + 1] && s[i] == '(') ind.insert(i);
    }

    while (q--) {
        int i;
        cin >> i;
        i--;

        if (s[i] == '(') {
            total_open--;
            total_closed++;
            s[i] = ')';
            ind.erase(i);
            if (i && s[i - 1] == '(') ind.erase(i - 1);
        } else {
            total_closed--;
            total_open++;
            s[i] = '(';
            if (i && s[i - 1] == '(') ind.insert(i - 1);
            if (i != n - 1 && s[i] == s[i + 1]) ind.insert(i);
        }

        int k = n - 1;
        if ()
    }
}
