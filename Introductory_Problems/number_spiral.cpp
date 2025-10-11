#include <iostream>
using namespace std;
#define ll long long
/*
Spiral Matrix (5x5)

         Columns →
       1    2    3    4    5
     +----+----+----+----+----+
Row 1 |  1 |  2 |  9 | 10 | 25 |
     +----+----+----+----+----+
Row 2 |  4 |  3 |  8 | 11 | 24 |
     +----+----+----+----+----+
Row 3 |  5 |  6 |  7 | 12 | 23 |
     +----+----+----+----+----+
Row 4 | 16 | 15 | 14 | 13 | 22 |
     +----+----+----+----+----+
Row 5 | 17 | 18 | 19 | 20 | 21 |
     +----+----+----+----+----+

*/

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll x, y;
        cin >> x >> y;  // Read coordinates (x, y)

        ll ans;
        if (x <= y) {
            // Vertical Line Values : Border Cell -- Top Right

            if (y % 2 == 0) {
                ans = (y - 1) * (y - 1) + x;
            } else {
                ans = y * y - x + 1;
            }

        } else {
            // Horizontal Line Values : Border Cell -- Bottom Left
            if (x % 2 == 0) {
                ans = x * x - y + 1;
            } else {
                ans = (x - 1) * (x - 1) + y;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

/*
    Time Complexity:
    ----------------
    O(t) — where t is the number of test cases.
    Each test case is handled in constant time O(1).

    Space Complexity:
    -----------------
    O(1) — Only a constant amount of extra space is used regardless of input size.
*/