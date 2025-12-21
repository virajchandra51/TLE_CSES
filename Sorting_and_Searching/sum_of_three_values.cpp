#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define ll long long
#define vii vector<pair<int, int>>

// Utils
#define len(x) int((x).size())
#define all(n) n.begin(), n.end()

void solve() {
    int n, x;
    cin >> n >> x;

    vii arr(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr[i] = {val, i + 1};
    }

    //* sort the array
    sort(all(arr));

    for (int i = 0; i < n - 2; i++) {
        ll tsum = x - arr[i].first;

        //* Two Sum : find j,k s.t arr[j] + arr[k] = x - arr[i]
        int j = i + 1, k = n - 1;

        while (j < k) {
            ll csum = arr[j].first + arr[k].first;
            if (csum > tsum) {
                k--;
            } else if (csum < tsum) {
                j++;
            } else {
                cout << arr[i].second << sp << arr[j].second << sp << arr[k].second << nl;
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" << nl;
}  // * T:O(n^2), S: O(1)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}