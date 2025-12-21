#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define ll long long
#define vi vector<int>
// Utils
#define len(x) int((x).size())
#define all(n) n.begin(), n.end()

void solve() {
    int n, x;
    cin >> n >> x;

    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // store all the possible {a[i], a[j]}
    set<tuple<int, int, int>> pair_sums;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            pair_sums.insert({arr[i] + arr[j], i, j});
        }
    }

    //> for every {a[i], a[j]} attempt to find {a[k], a[l]} s.t
    //> a[i] + a[j] + a[k] + a[l] = x
    for (int i = 0; i < n; i++) {
        //- remove all the pair sum where first element is a[i]
        for (int j = i + 1; j < n; j++) {
            pair_sums.erase({arr[i] + arr[j], i, j});
        }

        //- for every possible a[i], a[j] where j is in [0,i-1]
        //> attempt to find a[k] + a[l] == x - (a[i] + a[j])
        for (int j = i - 1; j >= 0; j--) {
            int diff = x - arr[i] - arr[j];

            auto it = pair_sums.lower_bound({diff, -1, -1});
            if (it == pair_sums.end()) continue;  // all sums are less than diff

            auto [sum, k, l] = *it;
            if (sum != diff) continue;

            cout << (i + 1) << sp << (j + 1) << sp << (k + 1) << sp << (l + 1) << nl;
            return;
        }
    }

    cout << "IMPOSSIBLE" << nl;
}  // * T:O(n^2*log(n)), S: O(n^2)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}