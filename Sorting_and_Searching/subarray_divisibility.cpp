#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ll long long
#define vll vector<ll>

void solve() {
    int n;
    cin >> n;

    vll arr(n);
    for (int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        arr[i] = val;
    }

    map<ll, ll> psums;
    psums[0] = 1;
    ll cur_sum = 0;
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cur_sum += arr[i];
        int mod = (cur_sum % n + n) % n;

        //> all prefix sum with remainder 'mod' contribute to the answer
        total += psums[mod];

        psums[mod]++;
    }

    cout << total << nl;
}//* T: O(n*logn), S:O(n)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}