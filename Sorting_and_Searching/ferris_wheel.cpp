#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define vi vector<int>

void solve() {
    int n, x;
    cin >> n >> x;

    vi weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    sort(weights.begin(), weights.end());

    int i = 0, j = n - 1;
    int cnt = 0;
    while (i <= j) {
        if (i != j) {
            //* pair up a heavy guy with lighter one
            if (weights[i] + weights[j] <= x) {
                i++;
                j--;
            } else { //! just assign a gondola to a heavy guy
                j--;
            }
        } else { //* last person remaining
            i++;
            j--;
        }

        cnt++;
    }
    cout << cnt << nl;
}//* T: O(n*logn), S: O(1)

int main() {
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
