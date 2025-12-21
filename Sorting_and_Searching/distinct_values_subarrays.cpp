#include <bits/stdc++.h>

using namespace std;
#define nl '\n'
#define vi vector<int>
#define ll long long
#define len(x) int((x).size())

void solve() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> mp;
    ll ans = 0;
    int i = 0, j = 0;
    while (j < n) {
        mp[arr[j]]++;  // add current element in the map

        while (mp[arr[j]] > 1) {  // *while a duplicated element is present; shrink wnd from Left
            mp[arr[i]]--;
            if (mp[arr[i]] == 0)
                mp.erase(arr[i]);
            i++;
        }
        //> mp.size() is the length of longest sequence of unique elements ending at index 'j'
        //> no. of subarrays ending at 'j' with unique elements = mp.size() + 1
        ans += len(mp); // or j - i + 1 as [i, j] has unique elements
        j++;
    }

    cout << ans << nl;
}  //* T: O(n*logn), S: O(n)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}