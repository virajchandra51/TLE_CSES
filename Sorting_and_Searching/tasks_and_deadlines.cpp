#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define nl '\n'
#define ll long long
void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> duration_deadline;
    for (int i = 0; i < n; i++) {
        int dur, dl;
        cin >> dur >> dl;
        duration_deadline.push_back({dur, dl});
    }

    sort(duration_deadline.begin(), duration_deadline.end());

    ll ft = 0;
    ll reward = 0;
    for (auto& [dur, dl] : duration_deadline) {
        ft += dur;
        reward += (dl - ft);
    }
    cout << reward << nl;
}//* T: O(n*logn), S:O(1)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}