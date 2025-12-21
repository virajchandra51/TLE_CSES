#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define nl '\n'
#define sp ' '

void solve() {
    int n;
    cin >> n;

    stack<pii> vals;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        //> remove all the elements greater than equal (>=) to current num
        while (!vals.empty() && vals.top().first >= num)
            vals.pop();

        if (vals.empty())
            cout << 0 << sp;
        else
            cout << vals.top().second << sp;
        //> push current num
        vals.push({num, i});
    }
}  //* T:O(n), S:O(n)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}