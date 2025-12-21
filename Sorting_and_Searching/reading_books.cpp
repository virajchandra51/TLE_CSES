#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define ll long long
#define vll vector<ll>

void solve() {
    int n;
    cin >> n;

    vll times(n);
    for (int i = 0; i < n; i++)
        cin >> times[i];

    ll min_total_time = accumulate(times.begin(), times.end(), 0LL);
    ll max_time = *max_element(times.begin(), times.end());

    cout << max(2 * max_time, min_total_time) << nl;

}  //* T: O(n), S:O(1)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}