#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define ll long long
#define vll vector<ll>

bool is_possible(vll& times, ll nprod_to_make, ll maxT) {
    ll total_products = 0;
    for (auto k : times) {
        total_products += maxT / k;

        if (total_products >= nprod_to_make) return true;
    }

    return false;
}

void solve() {
    int n;
    cin >> n;
    ll t;
    cin >> t;

    vll times(n);
    for (int i = 0; i < n; i++)
        cin >> times[i];

    //> search space: F F F F F T T T T T 
    //> Find the first 'T'
    ll max_t = (*max_element(times.begin(), times.end())) * t;//- or 1e18
    ll ans = max_t;
    ll lo = 1, hi = max_t;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;

        if (is_possible(times, t, mid)) {
            hi = mid - 1;
            ans = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << nl;
}//* T: O(n*log(M)) where M = 1e18, S: O(1)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}