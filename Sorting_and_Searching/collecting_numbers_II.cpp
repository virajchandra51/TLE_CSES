#include <bits/stdc++.h>

using namespace std;
#define nl '\n'
#define vi vector<int>

void solve() {
    int n, m;
    cin >> n >> m;

    //> position map: can use a vector as well
    unordered_map<int, int> pos;
    pos[0] = 0;
    pos[n + 1] = n + 1;

    vi arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    //> count number of rounds without any operations: O(n)
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) rounds++;
    }

    //> O(m * C) where C is a constant
    while (m--) {
        int i, j;
        cin >> i >> j;
        if (i > j) swap(i, j);

        int x = arr[i];
        int y = arr[j];

        if (pos[x + 1] > i && pos[x + 1] < j) rounds++;
        if (pos[x - 1] > i && pos[x - 1] < j) rounds--;
        if (pos[y + 1] > i && pos[y + 1] < j) rounds--;
        if (pos[y - 1] > i && pos[y - 1] < j) rounds++;

        //> case when consecutive elements
        if (x == (y + 1)) rounds--;  // {...,2,...,1,...}
        if (x == (y - 1)) rounds++;  // {...,1,...,2,...}

        cout << rounds << nl;

        //> perform the operation
        swap(arr[i], arr[j]);
        pos[x] = j;
        pos[y] = i;
    }
}//* T: O(n + m), S:O(n)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}