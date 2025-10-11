#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define ll long long

void solve() {
    string s;
    cin >> s;

    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : s) {
        freq[ch]++;
    }

    // Check if palindrome is possible and find center character
    char center = '\0';
    int oddCount = 0;
    for (const auto& [ch, count] : freq) {
        if (count % 2 == 1) {
            oddCount++;
            center = ch;
            if (oddCount > 1) {
                cout << "NO SOLUTION\n";
                return;
            }
        }
    }

    // Build the palindrome
    string result;
    result.reserve(s.length());  // Optimize memory allocation
    // First half
    for (const auto& [ch, count] : freq) {
        result.append(count / 2, ch);
    }
    // Add center character if exists (odd length palindromes)
    if (center != '\0') {
        result += center;
    }
    // Second half (reverse of first half, excluding center)
    int firstHalfSize = s.length()/2;
    // second half is 'first half reversed'
    for (int i = firstHalfSize - 1; i >= 0; i--) {
        result.push_back(result[i]);
    }

    cout << result << '\n';
}
// Time : O(n), Space : O(1)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
