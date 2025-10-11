#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define len(x) int((x).size())
#define ll long long

void solve() {
    int q;
    cin >> q;

    while (q--) {
        ll k;
        cin >> k;

        ll dig_len = 1;  // Current digit length
        ll count = 9;    // Count of numbers with 'dig_len' digits
        ll start = 1;    // Starting position for numbers with 'digit_len' digits

        // Find which digit-length group contains position k
        while (k > start + dig_len * count - 1) {
            start += dig_len * count;  // Move to next group's starting position
            dig_len++;                 // Increment digit length
            count *= 10;               // Next group has 10x more numbers
        }

        // Now we know k is in the group of 'dig_len'-digit numbers
        ll first_num = pow(10, dig_len - 1);  // First number with 'dig_len' digits
        ll num_offset = (k - start) / dig_len; 
        ll target_num = first_num + num_offset;   // The actual number containing position k

        // Find which digit within target_num
        string num_str = to_string(target_num);
        ll digit_offset = k - start;
        ll pos_in_num = digit_offset % dig_len;

        cout << num_str[pos_in_num] << "\n";
    }
}//* T:(q*log(k)) ~ O(1e3 x 18) ~ O(1e4), S: O(1)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}