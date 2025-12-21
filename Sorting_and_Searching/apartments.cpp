#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define vi vector<int>

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vi wishes(n);
    for (int i = 0; i < n; i++)
        cin >> wishes[i];

    vi sizes(m);
    for (int i = 0; i < m; i++)
        cin >> sizes[i];

    sort(wishes.begin(), wishes.end());
    sort(sizes.begin(), sizes.end());

    int total = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (sizes[j] < wishes[i] - k) {
            j++;  // no matching candidate for this apartment size

        } else if (sizes[j] > wishes[i] + k) {
            i++;  // no matching apartment for this candidate
        } else {
            // we have a matching apartment
            total++;
            i++;
            j++;
        }
    }
    cout << total << nl;
}//* T: O(nlogn + mlogm), S:O(1)

int main() {
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
