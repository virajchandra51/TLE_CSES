#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define len(x) int((x).size())
using namespace std;
using namespace __gnu_pbds;

// find_by_order, order_of_key: 0 indexed
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// allows duplicate values
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto& a : arr) cin >> a;

    int i = 0;
    ordered_set<pair<int, int>> wnd_st;
    ll inv = 0;
    for (int j = 0; j < n; j++) {
        //> element enters
        wnd_st.insert({arr[j], j});
        int pos = wnd_st.order_of_key({arr[j], j});
        inv += len(wnd_st) - pos - 1;

        if (j - i + 1 < k) {
            continue;
        } else {
            cout << inv << " ";

            //> element leaves/exits
            pos = wnd_st.order_of_key({arr[i], i});
            inv -= pos;
            wnd_st.erase({arr[i], i});
            i++;  
        }
    }
}  //* T:O(n*logk), S: O(k)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}