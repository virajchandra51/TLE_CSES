#include <bits/stdc++.h>

using namespace std;
#define nl '\n'
#define vi vector<int>

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        mp[num]++;
    }

    ll total = 1;
    for(auto& [num,freq]: mp){
        total *= (freq + 1);
        total %= MOD;
    }
    //! Note: we also counted 'empty subsequence'; minus 1 for non empty subsequences.
    cout << (total - 1) << nl;
}  //* T: O(n*logn), S: O(n)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}