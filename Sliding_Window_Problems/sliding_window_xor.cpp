#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    //! Note: C-style array is highly likely to fail
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        if (i == 0)
            arr[i] = x;
        else
            arr[i] = (a * arr[i - 1] + b) % c;
    }

    int i = 0;
    ll wxor = 0, ans = 0;

    for (int j = 0; j < n; j++) {
        wxor ^= arr[j];

        if (j - i + 1 < k) {
            continue;
        } else {
            ans = ans xor wxor;
            wxor ^= arr[i];
            i++;  //> slide the window
        }
    }
    cout << ans << '\n';
}  //* T:O(n), S: O(1)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}