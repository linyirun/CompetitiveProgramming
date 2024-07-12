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

vector<vector<bool>> vis;
vector<pii> songs;
int n;

void dfs(int msk, int curr_song) {
    if (vis[msk][curr_song]) return;
    vis[msk][curr_song] = true;

    for (int i = 0; i < n; i++) {
        if (!((1 << i) & msk)) {
            if (songs[i].first == songs[curr_song].first || songs[i].second == songs[curr_song].second) {
                dfs(msk | (1 << i), i);
            }
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        cin >> n;

        map<string, int> mp;
        vector<pair<string, string>> org_songs(n);
        songs = vector<pii>(n);
        vector<string> names;
        for (int i = 0; i < n; i++) {
            string genre, writer;
            cin >> genre >> writer;
            org_songs[i] = {genre, writer};
            names.push_back(genre);
            names.push_back(writer);
        }

        sort(names.begin(), names.end());
        names.resize(unique(names.begin(), names.end()) - names.begin());

        for (int i = 0; i < n; i++) {
            songs[i].first = lower_bound(names.begin(), names.end(), org_songs[i].first) - names.begin();
            songs[i].second = lower_bound(names.begin(), names.end(), org_songs[i].second) - names.begin();
        }

        // DP
        int MSK = 1 << n;
        vis = vector<vector<bool>>(MSK, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dfs(1 << i, i);
        }

        int best = 0;
        for (int i = 0; i < MSK; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) {
                    best = max(best, (ll) __builtin_popcount(i));
                }
            }
        }

        cout << n - best << '\n';

    }
}
