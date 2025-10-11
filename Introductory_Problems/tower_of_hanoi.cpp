#include <bits/stdc++.h>

using namespace std;

void TH(int discs, int start, int end, int aux) {
    // Base Condition: one disc can be directly moved
    if (discs == 1) {
        cout << start << " " << end << endl;
        return;
    }

    // move n-1 discs from A-->C using 'B'
    TH(discs - 1, start, aux, end);

    // move nth (largest) disc from A-->C
    cout << start << " " << end << endl;

    // move n-1 discs from B-->C using 'A'
    TH(discs - 1, aux, end, start);
}  //* T: O(2^n) S: O(n)

int main() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << endl;
    TH(n, 1, 3, 2);
}