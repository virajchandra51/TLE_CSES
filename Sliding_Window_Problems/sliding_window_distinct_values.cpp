#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto& a : arr) cin >> a;

    int i = 0;
    map<int, int> wnd_map;
    for (int j = 0; j < n; j++) {
        //> element enters
        wnd_map[arr[j]]++;

        if (j - i + 1 < k) {
            continue;
        } else {
            cout << wnd_map.size() << " ";

            if (wnd_map[arr[i]] == 1)
                wnd_map.erase(arr[i]);
            else
                wnd_map[arr[i]]--;
            i++;  //> slide the window
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