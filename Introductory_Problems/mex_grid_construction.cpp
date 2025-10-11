#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (i ^ j) << sp;
        }
        cout << nl;
    }
}//* Time: O(n*n), Space : O(1)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}