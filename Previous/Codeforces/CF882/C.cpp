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

int xor_arr(vector <int> & nums){
    int mx = 0;
    //Max Value
    int mask = 0;
    // Prefix Mask -> 10000, 11000, 11100, 11110, 11111
    set <int> se;

    for(int bit=9;bit >=0;--bit){
        mask |= (1 << bit);
        for(int i=0;i<nums.size();++i){
            se.insert(nums[i] & mask);
            //this is important such that binary representation of num (from nums) only includes till
            //ith bit.
        }

        int newMax = mx | (1 << bit);
        // Check whether we can improve mx value by turning on the ith bit in mx
        // such that newMax is obtained
        // if a^b = x then a^x = b;
        for(auto prefix : se){

            if(se.count(newMax ^ prefix)){
                mx = newMax;
                break;
            }
        }

        se.clear();
    }
    return mx;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int best = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            best = max(best, a[i]);
        }

        vector<bool> reachable(256);
        int curr = 0;
        for (int i = n - 1; i >= 0; i--) {
            curr ^= a[i];
            reachable[curr] = true;
            best = max(best, curr);
        }

        vector<int> arr;
        for (int i = 0; i < 256; i++) {
            if (reachable[i]) {
                arr.push_back(i);
                arr.push_back(i);
            }
        }
        best = max(best, xor_arr(arr));
        cout << best << '\n';
    }
}
