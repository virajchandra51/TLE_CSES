#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '

bool is_safe(vector<string>& board, int r, int c) {
    //! can't put on a reserved cell
    if (board[r][c] == '*') return false;

    int i = r - 1, j = c - 1;
    // upper left diag
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'q') return false;
        i--;
        j--;
    }

    // left side of current row
    j = c - 1;
    while (j >= 0) {
        if (board[r][j] == 'q') return false;
        j--;
    }

    // bottom left diag
    i = r + 1, j = c - 1;
    while (i < 8 && j >= 0) {
        if (board[i][j] == 'q') return false;
        i++;
        j--;
    }

    // safe placement
    return true;
}

void count_placements(vector<string>& board, int c, int& count) {
    if (c == 8) {
        // successfully placed queens on all of the columns
        count++;
        return;
    }

    // Try placing queen on each row of current column 'c'
    for (int r = 0; r < 8; r++) {
        if (is_safe(board, r, c)) {
            // place a queen
            board[r][c] = 'q';

            count_placements(board, c + 1, count);

            // back-track
            board[r][c] = '.';
        }
    }
}

void solve() {
    vector<string> board(8);
    for (int i = 0; i < 8; i++)
        cin >> board[i];

    int count = 0;
    int col = 0;
    count_placements(board, col, count);

    cout << count << nl;
}  //* T: O(8*8^8) ~ O(1.3e7) S: O(64)

int main() {
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
