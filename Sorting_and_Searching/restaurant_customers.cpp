#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define nl '\n'

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int st, et;
        cin >> st >> et;
        times.push_back({st, 1});
        times.push_back({et, -1});
    }
    sort(times.begin(), times.end());

    ll max_c = 0;
    ll cur_c = 0;
    for (int i = 0; i < 2 * n; i++) {
        cur_c += times[i].second;
        max_c = max(cur_c, max_c);
    }
    cout << max_c << nl;
}  //* T:O(n*logn), S:O(1) or O(n) for labels

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}