#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    // Total Points cannot be more than 'n'
    if (a + b > n) {
        cout << "NO" << nl;
        return;
    }
    // exactly one player cannot have '0' points
    if ((a == 0 || b == 0) && (a + b != 0)) {
        cout << "NO" << nl;
        return;
    }

    cout << "YES" << nl;
    // prints turns of first player : (1...n)
    for (int i = 1; i <= n; i++) cout << i << sp;
    cout << nl;

    // print turns of second player: a+1,a+2,..a+b,1,2,...a,a+b+1...n
    for (int i = a + 1; i <= a + b; i++) cout << i << sp;
    for (int i = 1; i <= a; i++) cout << i << sp;
    for (int i = a + b + 1; i <= n; i++) cout << i << sp;
    cout << nl;
}

int main() {
    int t = 1;
    cin >> t;

    while (t--)
        solve();
}  //* Time: O(n*t) = O(1e5), Space : O(1)
