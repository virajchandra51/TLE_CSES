#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto& a : arr) cin >> a;

    //> initially, we haven't seen any one of [0,..,k]
    set<int> not_seen;
    for (int x = 0; x <= k; x++) not_seen.insert(x);

    int i = 0;
    map<int, int> wnd_map;
    for (int j = 0; j < n; j++) {
        //> element enters
        wnd_map[arr[j]]++;
        if (wnd_map[arr[j]] == 1) not_seen.erase(arr[j]);

        if (j - i + 1 < k) {
            continue;
        } else {
            //> output: smallest unseen element in range [0...k]
            cout << *begin(not_seen) << " ";

            //> element exits
            if (wnd_map[arr[i]] == 1) {
                wnd_map.erase(arr[i]);
                not_seen.insert(arr[i]);
            } else {
                wnd_map[arr[i]]--;
            }
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