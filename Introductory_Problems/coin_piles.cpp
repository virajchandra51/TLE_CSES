#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define ll long long
#define ull unsigned long long

// Constants
const ll MOD = 1e9 + 7;

void solve() {
    ll a, b;
    cin >> a >> b;

    if ((2 * a - b) % 3 == 0) {
        ll y = (2 * a - b) / 3;
        if (y >= 0 && (b - y) % 2 == 0) {
            ll x = (b - y) / 2;
            if (x >= 0) {
                cout << "YES" << nl;
                return;
            }
        }
    }
    cout << "NO" << nl;
}

/* Time: O(t), Space : O(1)
 */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}