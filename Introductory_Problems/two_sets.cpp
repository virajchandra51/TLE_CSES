#include <bits/stdc++.h>

using namespace std;

using namespace std;
#define nl '\n'  // newline
#define sp ' '   // space
#define ll long long
#define ull unsigned long long
#define len(x) int((x).size())

void solve() {
    int n;
    cin >> n;

    ull S = (n * 1LL * (n + 1)) / 2;
    if (S % 2 == 1) {
        cout << "NO" << nl;
        return;
    }

    S = S /= 2;  // target sum
    set<int> st1, st2;
    for (int i = n; i >= 1; i--) {
        if (S > 0 && i <= S) {
            st1.insert(i);
            S -= i;
        } else {
            st2.insert(i);
        }
    }

    cout << "YES" << nl;
    cout << len(st1) << nl;
    for (auto a : st1)
        cout << a << sp;
    cout << nl << len(st2) << nl;
    for (auto a : st2)
        cout << a << sp;
    cout << nl;
}
// Time : O(n*log(n)) , Space : O(n)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) solve();
}