#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;  // a , c, g, t

    // find longest run of same character
    int cur_len = 1;
    int longest_len = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            cur_len++;
        } else {
            // s[i] != s[i-1]: breakage detected
            longest_len = max(longest_len, cur_len);
            cur_len = 1;
        }
    }
    // consider run of last unique character in 's' too!
    longest_len = max(longest_len, cur_len);

    cout << longest_len << '\n';
}

/*
Time complexity : O(n)
Space Complexity: O(1)
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
