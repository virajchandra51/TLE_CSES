#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define len(x) int((x).size())

// check if cell 'i,j' is inbouds of the grid n x m.
bool is_valid(int n, int m, int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            set<char> not_allowed;

            not_allowed.insert(grid[i][j]);  // current cell
            if (is_valid(n, m, i - 1, j))    // top
                not_allowed.insert(grid[i - 1][j]);
            if (is_valid(n, m, i, j - 1))  // left
                not_allowed.insert(grid[i][j - 1]);

            bool filled = false;
            for (int k = 0; k < 4; k++) {
                char ch = 'A' + k;
                if (not_allowed.find(ch) == not_allowed.end()) {
                    grid[i][j] = ch;
                    filled = true;
                    break;
                }
            }
            // if we are unable to fill a cell(NEVER Happens)
            if (!filled) {
                cout << "IMPOSSIBLE" << nl;
                return;
            }
        }
    }

    // if all cells were filled
    for (int i = 0; i < n; i++) {
        cout << grid[i] << nl;
    }
}  //* T: O(nxm) S:O(1)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}
