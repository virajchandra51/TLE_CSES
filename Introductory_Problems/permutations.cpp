#include <bits/stdc++.h>

using namespace std;
#define nl '\n'  // newline
#define sp ' '   // space

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << nl;
    } else if (n <= 3) {
        cout << "NO SOLUTION" << nl;
    } else {
        // n >= 4
        // put all the even elements first
        for (int i = 2; i <= n; i += 2) {
            cout << i << sp;
        }
        // put all the odd elements
        for (int i = 1; i <= n; i += 2) {
            cout << i << sp;
        }
    }
}
/* Time: O(n) , Space : O(1)
 */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
