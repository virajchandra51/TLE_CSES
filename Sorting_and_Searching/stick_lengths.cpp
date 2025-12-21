#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define ll long long
#define len(x) int((x).size())
#define all(n) n.begin(), n.end()

void solve() {
    int n;
    cin >> n;

    vector<ll> lens(n);
    for (int i = 0; i < n; i++)
        cin >> lens[i];

    sort(all(lens));
    ll med = lens[n / 2];

    ll ops = 0;
    for (auto l : lens)
        ops += abs(l - med);
    cout << ops << nl;
}//* T: O(n*logn), S:O(1)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}