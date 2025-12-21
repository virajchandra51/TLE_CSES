#include <bits/stdc++.h>

using namespace std;
#define nl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> prices;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        prices.insert(p);
    }

    for (int i = 0; i < m; i++) { 
        int th;
        cin >> th;

        //* find smallest exceeding threshold
        auto it = prices.upper_bound(th);

        if (it == prices.begin()) {
            //! all available are greater than threshold or set is empty
            cout << "-1" << nl;
        } else {
            it--;
            cout << *it << nl;
            prices.erase(it);
        }
    }
}  // * T: O(n*logn + m*log(n)), S:O(n)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}