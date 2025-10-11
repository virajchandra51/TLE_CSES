#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

void solve_0() {
    int n;
    cin >> n;

    vector<int> flag(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int val;
        cin >> val;
        flag[val] = 1;//found
    }

    for (int i = 1; i <= n; i++) {
        if (flag[i] == 0) {
            cout << i << endl;
            return;
        }
    }
    // TC: O(n) = O(2e5)
    // SC: O(n) = O(2e5)
}

// total_sum = n*(n+1)/2
// sum <- sum of all input nums
// missing number =  total - sum
void solve() {
    int n;
    cin >> n;

    ull sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int val;
        cin >> val;
        sum += val;
    }

    ull total = (n * 1LL * (n + 1)) / 2;
    cout << total - sum << endl;

    // TC: O(1) (Don't consider time taken for input)
    // SC: O(1)
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
