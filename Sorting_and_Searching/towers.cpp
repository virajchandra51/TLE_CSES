#include <bits/stdc++.h>

using namespace std;
#define nl '\n'
#define vi vector<int>
#define len(x) int((x).size())

void solve_using_multiset() {
    int n;
    cin >> n;

    multiset<int> tower_heads;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        auto it = tower_heads.upper_bound(h);

        if (it == tower_heads.end()) {
            //> no towers present Or all tower heads <= 'h'
            tower_heads.insert(h);
        } else {
            //> update tower head where we place 'h'
            tower_heads.erase(it);
            tower_heads.insert(h);
        }
    }

    cout << len(tower_heads) << nl;
}  //* T:O(n*logn), S:O(n)

void solve() {
    int n;
    cin >> n;

    //* NOTE: tower_heads are sorted; courtesy our way of insertion
    vi tower_heads;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        if (len(tower_heads) == 0) {
            tower_heads.push_back(h);
        } else {
            auto it = upper_bound(tower_heads.begin(), tower_heads.end(), h);
            if (it == tower_heads.end())
                //> all tower heads are <= 'h'; create new tower
                tower_heads.push_back(h);
            else
                *it = h;  //> update tower head where 'h' is placed
        }
    }

    cout << len(tower_heads) << nl;
}  //* T:O(nlogn), S:O(n)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}