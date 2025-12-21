#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define len(x) int(x.size())

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto& a : arr) cin >> a;

    int i = 0;
    map<int, int> wnd_fm;
    map<int, set<int>> wnd_ifm;

    for (int j = 0; j < n; j++) {
        //> update freq map
        int old_f = wnd_fm[arr[j]]++;
        //> update inv freq map
        if (old_f >= 1)
            wnd_ifm[old_f].erase(arr[j]);
        if (len(wnd_ifm[old_f]) == 0)
            wnd_ifm.erase(old_f);
        wnd_ifm[old_f + 1].insert(arr[j]);

        if (j - i + 1 < k) {
            continue;
        } else {
            //> print smallest element of largest freq
            auto& [_, ele] = *rbegin(wnd_ifm);
            cout << *begin(ele) << " ";

            //> update frequency map
            int fr = wnd_fm[arr[i]]--;
            if (wnd_fm[arr[i]] == 0)
                wnd_fm.erase(arr[i]);

            //> update inverse frequency map
            wnd_ifm[fr].erase(arr[i]);
            if (len(wnd_ifm[fr]) == 0)
                wnd_ifm.erase(fr);
            if (fr > 1)
                wnd_ifm[fr - 1].insert(arr[i]);

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