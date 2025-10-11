#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define ll long long
#define ull unsigned long long

// Constants
const ll MOD = 1e9 + 7;
ll naive_2powN(ll N) {
    ll res = 1;
    for (int i = 1; i <= N; i++) {
        res = res * 2 % MOD;
    }
    return res;
    // Time: O(n), Space: O(1)
}

// iterative binary exponentiation
ll optimised_apowb(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        // if the kth bit is set
        if (b & 1) {
            res *= a;
            res %= MOD;
        }
        a = a * a % MOD;
        b = b >> 1;  // right shift by one
    }
    return res;
    // Time: O(log(b)), Space: O(1)
}

void solve() {
    int n;
    cin >> n;
    cout << optimised_apowb(2, n) << nl;
}

/*
 */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}