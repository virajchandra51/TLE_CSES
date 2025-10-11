#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define ll long long
#define ull unsigned long long

// Constants
const ll MOD = 1e9 + 7;

void divide_apples(vector<ll>& weights, ll& ans, int idx, ll g1, ll g2) {
    // Base Condition : We distributed every apple
    if (idx == weights.size()) {
        ans = min(ans, abs(g1 - g2));
        return;
    }

    // Two choices
    // 1. Add current apple to g1
    divide_apples(weights, ans, idx + 1, g1 + weights[idx], g2);

    // 2. Add current apple to g2
    divide_apples(weights, ans, idx + 1, g1, g2 + weights[idx]);
}

void solve() {
    int n;
    cin >> n;

    vector<ll> weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    ll ans = 1e18;
    int start = 0;
    divide_apples(weights, ans, start, 0, 0);

    //* ans has stored optimal answer
    cout << ans << nl;
}// T: O(2^n) S: O(n)

/*
 */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}