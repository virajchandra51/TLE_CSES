#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define len(x) int((x).size())

vector<string> generate_gc(int n) {
    // Base Case: Gray Codes with 1 bit
    if (n == 1) {
        return {"0", "1"};
    }

    // First, Get all Graycodes with 'n-1' bits
    vector<string> gcodes_n_minus_1 = generate_gc(n - 1);
    // Take mirror: reverse them
    vector<string> mirrored;
    for (int i = len(gcodes_n_minus_1) - 1; i >= 0; i--)
        mirrored.push_back(gcodes_n_minus_1[i]);

    // Create Gray Codes of with 'n' bits
    vector<string> new_codes;
    for (int i = 0; i < len(gcodes_n_minus_1); i++)
        new_codes.push_back("0" + gcodes_n_minus_1[i]);
    for (int i = 0; i < len(mirrored); i++)
        new_codes.push_back("1" + mirrored[i]);

    return new_codes;
}

void solve() {
    int n;
    cin >> n;

    vector<string> gray_codes;
    // generate gray codes with 'n' bits
    gray_codes = generate_gc(n);
    for (auto gc : gray_codes)
        cout << gc << nl;
}  //* Time: O(n*2^n), Space: O(2^n + n)

int main() {
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}