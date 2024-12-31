#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

//#define int ll
//const int MOD = 998244353;
const int MOD = 1000000007;
//const int INF = 1e15;

vector<int> to_state(int mask) {
    vector<int> rep(12);
    int curr = 1;
    for (int i = 1; i <= 11; i++) curr *= 3;
    for (int i = 11; i >= 0; i--) {
        if (mask >= 2 * curr) {
            rep[i] = 2;
            mask -= 2 * curr;
        } else if (mask >= curr) {
            rep[i] = 1;
            mask -= curr;
        }
        curr /= 3;
    }
    return rep;
}

int total_cards = 0;
vector<vector<int>> dp;
vector<int> cards;

int state_to_ternary(vector<int> &state) {
    int curr = 1;
    int mask = 0;
    for (int i = 0; i < state.size(); i++) {
        mask += curr * state[i];
        curr *= 3;
    }
    return mask;
}

bool memo(vector<int> &state, int turn) {
    int mask = state_to_ternary(state);
    if (dp[mask][turn] != -1) return dp[mask][turn];
    bool can_win = false;

    for (int i = 0; i < total_cards; i++) {
        if (state[i] == turn) {
            // Try putting this card on the table
            state[i] = 2;
            // See if you don't take a card
            can_win |= !memo(state, !turn);

            for (int j = 0; j < total_cards; j++) {
                // Don't put any cards
                if (state[j] == 2 && cards[j] < cards[i]) {
                    // Put card in hand
                    state[j] = turn;
                    can_win |= !memo(state, !turn);
                    // Put back on table
                    state[j] = 2;
                }
            }
            // put back in hand
            state[i] = turn;
        }
    }

    return dp[mask][turn] = can_win;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, l;
    cin >> n >> m >> l;

    int mx_state = 1;
    for (int i = 1; i <= 12; i++) mx_state*= 3;
    // 0 is T, 1 is A, 2 is on table

    dp = vector<vector<int>>(mx_state, vector<int>(2, -1));
    cards = vector<int>(n + m + l);

    vector<int> state(12);
    total_cards = n + m + l;
    for (int i = 0; i < n + m + l; i++) {
        cin >> cards[i];
        if (i < n) {

        } else if (i < n + m) {
//            curr_state += curr_ternary;
            state[i] = 1;
        } else {
//            curr_state += 2 * curr_ternary;
            state[i] = 2;
        }
//        curr_ternary *= 3;
    }

    if (memo(state, false)) {
        cout << "Takahashi\n";
    } else cout << "Aoki\n";
}
