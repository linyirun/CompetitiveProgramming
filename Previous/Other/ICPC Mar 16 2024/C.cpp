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

#define RIGHT "right\n"
#define LEFT "left\n"
#define BOTTOM "bottom\n"
#define TOP "top\n"

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;

    int xs, ys, xr, yr;
    cin >> xs >> ys >> xr >> yr;

    int dx = xr - xs;
    int dy = yr - ys;

    if (dx == 0) {
        if (dy > 0) cout << TOP;
        else cout << BOTTOM;
    } else if (dy == 0) {
        if (dx > 0) cout << RIGHT;
        else cout << LEFT;
    } else {
        // both non-zero
        int vert_dist, horz_dist;
        if (dy > 0) vert_dist = y2 - ys;
        else vert_dist = ys - y1;

        if (dx > 0) horz_dist = x2 - xs;
        else horz_dist = xs - x1;

        // first check if they are equal
        if (abs(dx * vert_dist) == abs(dy * horz_dist)) {
            if (dy > 0) cout << "top-";
            else cout << "bottom-";
            if (dx > 0) cout << RIGHT;
            else cout << LEFT;
        } else {
            // vertical is hit first
            if (abs(dx * vert_dist) < abs(dy * horz_dist)) {
                if (dy > 0) cout << TOP;
                else cout << BOTTOM;
            } else {
                if (dx > 0) cout << RIGHT;
                else cout << LEFT;
            }
        }

    }
}
