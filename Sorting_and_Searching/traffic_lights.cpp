#include <bits/stdc++.h>

using namespace std;
#define nl '\n'

void solve() {
    int x, n;
    cin >> x >> n;

    multiset<int> plens;
    set<int> pos;

    // > two boundary poles
    pos.insert(0);
    pos.insert(x);
    // > initally, only one passage : [0,x]
    plens.insert(x);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;

        auto right = pos.upper_bound(p);
        auto left = right;
        left--;
        int l = *left, r = *right;

        //* passage in [l, r] splits into two [l,p] + [p,r]
        plens.erase(plens.find(r - l));  //! first 'find' then erase
        plens.insert(p - l);
        plens.insert(r - p);

        //* print max passage length
        cout << *plens.rbegin() << " ";

        //* place the traffic light at position 'p'
        pos.insert(p);
    }

    cout << nl;
}  //* T:O(nlogn), S:O(n)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}