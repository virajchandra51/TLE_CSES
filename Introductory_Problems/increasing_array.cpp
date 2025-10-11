#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

void solve() {
    int n;
    cin >> n;
    vll arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll moves = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1]) continue;

        int diff = abs(arr[i] - arr[i - 1]);
        moves += diff;
        arr[i] += diff;
    }
    cout << moves << '\n';
}
/*
TC: O(n)
SC: O(1)
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
