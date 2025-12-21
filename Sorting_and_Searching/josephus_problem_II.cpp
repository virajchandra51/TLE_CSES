#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// find_by_order, order_of_key: 0 indexed
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

// Utils
#define len(x) int((x).size())

void solve() {
    int n, k;
    cin >> n >> k;

    //* similar to regular set<int>, but also has a function,
    //* find_by_order(pos) -> returns iterator to the element at 'pos' position(0-based)
    ordered_set nums;
    for (int i = 1; i <= n; i++)
        nums.insert(i);

    int pos = 0;  // start the game from '0'th child
    while (!nums.empty()) {
        //> find next guy to be removed
        pos = (pos + k) % len(nums);

        //> output and remove the child
        auto it = nums.find_by_order(pos);
        cout << *it << " ";
        nums.erase(it);
    }
}  //* T:O(n*logn), S:O(n)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
