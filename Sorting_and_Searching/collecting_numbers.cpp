#include <bits/stdc++.h>

using namespace std;
#define nl '\n'

void solve() {
    int n;
    cin >> n;

    map<int, int> pos;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        pos[num] = i;
    }

    // pick '1' and round 1 begins
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        //* if 'x' is found before 'x-1'
        if (pos[i] < pos[i - 1]) rounds++;
    }
    cout << rounds << nl;
}  //* T:O(n*logn), S:O(n)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}