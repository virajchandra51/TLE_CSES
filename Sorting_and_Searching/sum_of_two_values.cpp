#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define ll long long
#define vii vector<pair<int, int>>

// Utils
#define len(x) int((x).size())
#define all(n) n.begin(), n.end()

void solve_using_map() {
    int n, x;
    cin >> n >> x;

    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        if (mp.find(x - num) != mp.end()) {
            cout << mp[x - num] << sp << i << nl;
            return;
        } else {
            mp[num] = i;
        }
    }

    cout << "IMPOSSIBLE" << nl;
}  // * T:O(n*logn), S:O(n)

void solve() {
    int n, x;
    cin >> n >> x;

    vii arr(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr[i] = {val, i + 1};
    }

    //* sort the array
    sort(all(arr));

    int i = 0, j = n - 1;
    while (i < j) {
        ll cur_sum = arr[i].first + arr[j].first;
        if (cur_sum == x) {
            cout << arr[i].second << sp << arr[j].second << nl;
            return;
        } else if (cur_sum > x) {
            j--;
        } else {
            i++;
        }
    }

    cout << "IMPOSSIBLE" << nl;
}  // * T:O(n*logn), S: O(1)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}