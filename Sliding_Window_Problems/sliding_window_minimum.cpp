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
    ll ans = 0;
    deque<pair<int, int>> q;
    for (int j = 0; j < n; j++) {
        //> arr[j] dominates all the elements greater than it
        while (!q.empty() && q.back().first > arr[j]) q.pop_back();
        q.push_back({arr[j], j});

        if (j - i + 1 < k) {
            continue;
        } else {
            ans = ans xor q.front().first;

            if (q.front().second == i) q.pop_front();
            i++;  //> slide the window
        }
    }
    cout << ans << '\n';
}  //* T:O(n), S: O(k)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}