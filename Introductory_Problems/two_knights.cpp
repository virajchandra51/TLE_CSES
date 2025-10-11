#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        long long t_cells = k * k;
        if (k == 1)
            cout << 0 << endl;
        else {
            // total ways to place two knights
            long long total = (t_cells * (t_cells - 1)) / 2;

            // number of 2x3 and 3x2 slabs : no. of attacking positions
            long long slabs = (k - 2) * (k - 1) * 2 * 2;
            cout << total - slabs << endl;
        }
    }

    return 0;
}
// Time : O(n), Space : O(1)