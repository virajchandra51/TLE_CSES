#include <bits/stdc++.h>

using namespace std;
#define sp ' '
#define nl '\n'
#define vi vector<int>
#define len(x) int((x).size())

void josephus_1(vi& nums) {
    int n = len(nums);

    //* Base Condition: one size array
    if (n == 1) {
        cout << nums[0] << nl;
        return;
    }

    //* print elements at odd indices: 1,3,5,..
    for (int i = 1; i < n; i += 2)
        cout << nums[i] << sp;

    //* prepare list for next round
    vi narr;
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2)
            narr.push_back(nums[i]);
    } else {
        //* n is odd
        narr.push_back(nums[n - 1]);
        for (int i = 0; i < n - 1; i += 2)
            narr.push_back(nums[i]);
    }

    //* solve for remaining elements
    josephus_1(narr);
}

void solve() {
    int n;
    cin >> n;

    //* create the main list : 1,2,3,4,...,n
    vi nums(n);
    for (int i = 1; i <= n; i++)
        nums[i - 1] = i;

    josephus_1(nums);
}  //* T:O(n), S:O(n)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}