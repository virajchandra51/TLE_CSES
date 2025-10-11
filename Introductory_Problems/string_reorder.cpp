#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define len(x) int((x).size())
bool is_possible(map<char, int>& ft, char cur) {
    // Find highest occurring character
    char mode = cur;
    int total_left_to_fill = 0;
    for (auto& [ch, f] : ft) {
        if (f > ft[mode])
            mode = ch;
        total_left_to_fill += f;
    }
    return (ft[mode] <= (total_left_to_fill + 1) / 2) && (ft[cur] <= total_left_to_fill / 2);
}

void solve() {
    string s;
    cin >> s;
    int n = len(s);

    // Create Frequency Map
    map<char, int> ft;
    for (auto ch : s)
        ft[ch]++;

    string ans = "";
    char last = '\0';
    for (int i = 0; i < n; i++) {
        // Try Picking smallest character possible
        for (int i = 0; i < 26; i++) {
            char ch = 'A' + i;
            // don't consider 'last' placed character
            if (ft[ch] == 0 || ch == last) continue;

            ft[ch]--;
            if (is_possible(ft, ch)) {
                ans.push_back(ch);
                last = ch;
                break;
            } else {
                // unable to place 'ch' as current character; consider next smallest
                ft[ch]++;
            }
        }
    }

    if (len(ans) == n)
        cout << ans << nl;
    else
        cout << "-1" << nl;
}  //* T: O(26*n), S:O(26)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}