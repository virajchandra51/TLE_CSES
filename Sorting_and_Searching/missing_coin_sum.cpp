#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define ll long long
#define nl '\n'

void solve() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll k = 0;
    for (int i = 0; i < n; i++) {
        // ? can we make sum == k + 1

        //! if arr[i] > k + 1; definitely not
        if (arr[i] > k + 1) {
            cout << (k + 1) << nl;
            return;
        }

        //> now we can make all the sums in [0, k + arr[i]]
        k += arr[i];
    }
    //> we can create all the sums in range [0, sum(arr)]
    cout << k + 1 << nl;
}//* T: O(n*logn), S:O(1)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}