#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ll long long
#define vll vector<ll>

void solve() {
    int n;
    cin >> n;
    ll x;
    cin >> x;

    vll arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<ll, ll> psum_count;
    psum_count[0] = 1;
    ll cur_sum = 0;
    ll total = 0;
    for (int i = 0; i < n; i++) {
        //> find p[i]
        cur_sum += arr[i];

        //> all prefix sum with sum p[i] - x contribute to answer
        total += psum_count[cur_sum - x];

        //> increment count of p[i]
        psum_count[cur_sum]++;
    }

    cout << total << nl;
}//* T:O(n*logn), S:O(n)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}